//
// Created by carl on 18-7-10.
//

#ifndef FACEPICTURECLIENT_LISTTHREAD_H
#define FACEPICTURECLIENT_LISTTHREAD_H

#include "ListOperation.h"
#define BAKE_PIC_TAG 0
#define FACE_PIC_TAG 1
#define SHOW_PIC_TAG 2

class ListThread {
public:
    ListThread(void);
    ~ListThread();

private:
    // 初始化缓冲区信息
    void InitBufer();
    // 清理缓冲区
    void ReleaseBuffer();
public:
    //检查内存空间
    unsigned long CheckBuffer(uint64_t nSize,int nTag ,PLIST_BUFFER pBuffer);
    // 重置缓冲区
    unsigned long ResetBuffer(uint64_t nBackSize, uint64_t nFaceSize, uint64_t nBufferCount);
    // 获取缓冲区
    unsigned long GetBuffer(PLIST_BUFFER *ppBuffer, BUFFER_STATUS status);
    //获取头部缓冲区
    unsigned long GetHeadBuffer(PLIST_BUFFER *ppBuffer, BUFFER_STATUS status);
    // 归还缓冲区
    unsigned long PutBuffer(PLIST_BUFFER pBuffer, BUFFER_STATUS status);
    // 清理缓冲区函数
    static void BufferClean(PLIST_ENTRY pList, void *pParam);
public:
    int nFaceID;          //add

    char stContent[160];   //add
private:
    OPERATE_LIST    m_lList[reset];       // 缓冲区链表队列
    LIST_BUFFER		*m_pBuffer;			  // 缓冲区结构数组
    ListOperation   m_listOperation;      //创建列表操作对象
    uint64_t	    m_nBufferCount;	      // 缓冲区结构数组大小
    bool			m_bIsInit;			  // 是否初始化
    //检查满队列是否有数据,若没有进行加锁
    bool m_isLocked = true;
#define LOCKCB_THREAD boost::mutex::scoped_lock lock(io_mutex)

    boost::mutex io_mutex;
};


#endif //FACEPICTURECLIENT_LISTTHREAD_H
