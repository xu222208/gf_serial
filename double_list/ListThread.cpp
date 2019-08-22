//
// Created by carl on 18-7-10.
//
#include <boost/filesystem.hpp>
#include "SendQueue.h"
#include "ListThread.h"
#include "../log4cpp/CLog.h"

ListThread::ListThread(void)
        : m_nBufferCount(0), m_bIsInit(false) {
    InitBufer();
}

ListThread::~ListThread() {
    ReleaseBuffer();
}

void ListThread::ReleaseBuffer() {
    if (!m_bIsInit) return;

    for (int i = 0; i < reset; i++) {
        m_listOperation.OperateLISTRelease(&m_lList[i]);
    }

    if (m_pBuffer) {
        delete[]m_pBuffer;
        m_pBuffer = nullptr;
    }
    m_bIsInit = false;
}

// 初始化缓冲区信息
void ListThread::InitBufer() {
    ReleaseBuffer();

    for (int i = 0; i < reset; i++) {
        m_listOperation.OperateLISTInit(&m_lList[i], BufferClean, nullptr);
    }

    m_pBuffer = new LIST_BUFFER[m_nBufferCount];
    if (m_pBuffer) {
        memset(m_pBuffer, 0, sizeof(LIST_BUFFER) * m_nBufferCount);
    }
    m_bIsInit = true;
}

// 重置缓冲区
unsigned long ListThread::ResetBuffer(uint64_t nBackSize, uint64_t nFaceSize, uint64_t nBufferCount) {

    if (m_nBufferCount != nBufferCount) {
        m_nBufferCount = nBufferCount;

        InitBufer();

        if (nullptr == m_pBuffer) goto MY_ERROR;

        for (int i = 0; i < m_nBufferCount; i++) {
            //获取buffer开辟空间大小
            m_pBuffer[i].nBackBufferSize = nBackSize;
            m_pBuffer[i].nFaceBufferSize = nFaceSize;
            m_pBuffer[i].nShowBufferSize = nFaceSize;

            //申请背景图片内存
            m_pBuffer[i].camerasPic.pBackBuffer = (uchar *) realloc(m_pBuffer[i].camerasPic.pBackBuffer, nBackSize);
            if (nullptr == m_pBuffer[i].camerasPic.pBackBuffer) {
                goto MY_ERROR;
            }

            //申请人脸子图内存
            m_pBuffer[i].camerasPic.pFaceBuffer = (uchar *) realloc(m_pBuffer[i].camerasPic.pFaceBuffer, nFaceSize);
            if (nullptr == m_pBuffer[i].camerasPic.pFaceBuffer) {
                goto MY_ERROR;
            }

            //申请展示图片内存
            m_pBuffer[i].camerasPic.pShowBuffer = (uchar *) realloc(m_pBuffer[i].camerasPic.pShowBuffer, nFaceSize);
            if (nullptr == m_pBuffer[i].camerasPic.pShowBuffer) {
                goto MY_ERROR;
            }

            m_pBuffer[i].status = empty;
            m_listOperation.OperateInsert(&m_lList[empty], &m_pBuffer[i].list);
        }
    } else {
        for (int i = 0; i < m_nBufferCount; i++) {
            PLIST_BUFFER pfcBuffer = nullptr;
            GetBuffer(&pfcBuffer, full);
            if (nullptr == pfcBuffer) break;

            memset(m_pBuffer[i].camerasPic.pBackBuffer, 0, nBackSize);
            memset(m_pBuffer[i].camerasPic.pFaceBuffer, 0, nFaceSize);
            memset(m_pBuffer[i].camerasPic.pShowBuffer, 0, nFaceSize);
            PutBuffer(pfcBuffer, empty);
        }
    }


    return NO_ERROR;
    MY_ERROR:
    // 错误处理
    ReleaseBuffer();
    return ERROR_REALLOC_FAILD;
}


// 获取缓冲区
unsigned long ListThread::GetBuffer(PLIST_BUFFER *ppBuffer, BUFFER_STATUS status) {
    LOCKCB_THREAD;
    {
        *ppBuffer = nullptr;

        if (!m_bIsInit) {
            return ERROR_PARAMTERS_NULL;
        }

        if (nullptr == ppBuffer) {
            return ERROR_PARAMTERS_NULL;
        }

        if (IsListEmpty(&m_lList[status].root)) {
            return ERROR_NO_FULL_BUFFER;
        }

        PLIST_BUFFER pBuffer = (PLIST_BUFFER) m_listOperation.OperateRemove(&m_lList[status]);
        *ppBuffer = pBuffer;
    }

    return NO_ERROR;
}

//获取头部缓冲区
unsigned long ListThread::GetHeadBuffer(PLIST_BUFFER *ppBuffer, BUFFER_STATUS status) {
    LOCKCB_THREAD;
    {
        *ppBuffer = nullptr;

        if (!m_bIsInit) {
            return ERROR_NO_FULL_BUFFER;
        }

        if (nullptr == ppBuffer) {
            return ERROR_PARAMTERS_NULL;
        }

        if (IsListEmpty(&m_lList[status].root)) {
            return ERROR_NO_FULL_BUFFER;
        }

        PLIST_BUFFER pBuffer = (PLIST_BUFFER) m_listOperation.OperateRemoveHead(&m_lList[status]);
        *ppBuffer = pBuffer;
    }
    return NO_ERROR;
}

// 归还缓冲区
unsigned long ListThread::PutBuffer(PLIST_BUFFER pBuffer, BUFFER_STATUS status) {
    LOCKCB_THREAD;
    {
        if (!m_bIsInit) {
            return ERROR_NO_FULL_BUFFER;
        }

        if (nullptr == pBuffer) {
            return ERROR_PARAMTERS_NULL;
        }

        pBuffer->status = status;

        m_listOperation.OperateInsert(&m_lList[status], &pBuffer->list);
    }

    return NO_ERROR;
}

//检查内存空间
unsigned long ListThread::CheckBuffer(uint64_t nSize, int nTag, PLIST_BUFFER pBuffer) {

    if (nullptr == pBuffer) {
        return ERROR_PARAMTERS_NULL;
    }
    //背景图片标签
    switch (nTag) {
        case BAKE_PIC_TAG: {
            if (pBuffer->nBackBufferSize < nSize) {
                pBuffer->nBackBufferSize = nSize;
                //重新申请内存
                pBuffer->camerasPic.pBackBuffer = (uchar *) realloc(pBuffer->camerasPic.pBackBuffer, nSize);
                if (nullptr == pBuffer->camerasPic.pBackBuffer) {
                    goto MY_ERROR;
                }
                logDebug("背景图片重新申请内存空间!");
            }

        }
            break;
        case FACE_PIC_TAG: {
            logDebug("pBuffer->nFaceBufferSize:"+to_string(pBuffer->nFaceBufferSize));
            if (pBuffer->nFaceBufferSize < nSize) {
                pBuffer->nFaceBufferSize = nSize;
                //重新申请内存
                pBuffer->camerasPic.pFaceBuffer = (uchar *) realloc(pBuffer->camerasPic.pFaceBuffer, nSize);
                if (nullptr == pBuffer->camerasPic.pFaceBuffer) {
                    goto MY_ERROR;
                }
                logDebug("人脸子图重新申请内存空间!");
            }
        }
            break;
        case SHOW_PIC_TAG: {
            if (pBuffer->nShowBufferSize < nSize) {
                pBuffer->nShowBufferSize = nSize;
                //重新申请内存
                pBuffer->camerasPic.pShowBuffer = (uchar *) realloc(pBuffer->camerasPic.pShowBuffer, nSize);
                if (nullptr == pBuffer->camerasPic.pShowBuffer) {
                    goto MY_ERROR;
                }
                logDebug("人脸展示子图重新申请内存空间!");
            }
        }
            break;
        default:
            logError("无申请内存空间标签!");
            break;
    }

    return NO_ERROR;
    MY_ERROR:
    // 错误处理
    ReleaseBuffer();
    return ERROR_REALLOC_FAILD;
}

//清理缓冲区
void ListThread::BufferClean(PLIST_ENTRY pList, void *pParam) {
    if (nullptr == pList) return;

    PLIST_BUFFER pBuffer = (PLIST_BUFFER) pList;

    pBuffer->status = reset;

    //释放内存
    if (pBuffer->camerasPic.pBackBuffer) {
        free(pBuffer->camerasPic.pBackBuffer);
    }

    if (pBuffer->camerasPic.pFaceBuffer) {
        free(pBuffer->camerasPic.pFaceBuffer);
    }

    if (pBuffer->camerasPic.pShowBuffer) {
        free(pBuffer->camerasPic.pShowBuffer);
    }
    memset(pBuffer, 0, sizeof(LIST_BUFFER));
}
