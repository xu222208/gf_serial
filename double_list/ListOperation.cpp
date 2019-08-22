//
// Created by carl on 18-7-10.
//

#include "ListOperation.h"

ListOperation::ListOperation() {

}

ListOperation::~ListOperation() {

}

// 初始化链表
void ListOperation::OperateLISTInit(POPERATE_LIST pList, CLENA_FUNCTION pClean, void *pParam) {
    if (nullptr == pList) return;
    //内存加锁
    OperateLock(pList);
    InitializeListHead(&pList->root);

    pList->size = 0;
    pList->Clean = pClean;
    pList->pParam = pParam;
    //内存解锁
    OperateUnlock(pList);
}

// 清理链表
void ListOperation::OperateLISTRelease(POPERATE_LIST pList) {

    PLIST_ENTRY pTempList = nullptr;
    if (nullptr == pList) return;
    //内存加锁
    OperateLock(pList);
    while (!IsListEmpty(&pList->root)) {
        pTempList = RemoveHeadList(&pList->root);
        // 释放链表项
        pList->Clean(pTempList, pList->pParam);
        pList->size--;
        if (0 == pList->size) break;
    }
    //内存解锁
    OperateUnlock(pList);
}

// 加锁函数
void ListOperation::OperateLock(POPERATE_LIST pList) {
    if (nullptr == pList) return;
    pList->io_mutex_list.lock();
}

// 解锁函数
void ListOperation::OperateUnlock(POPERATE_LIST pList) {
    if (nullptr == pList) return;
    pList->io_mutex_list.unlock();
}

// 首部插入
void ListOperation::OperateInsert(POPERATE_LIST pList, PLIST_ENTRY plistEntry) {
    if (nullptr == pList) return;
    //内存加锁
    OperateLock(pList);
    InsertHeadList(&pList->root, plistEntry);
    pList->size++;
    //内存解锁
    OperateUnlock(pList);
}

// 尾部移除
PLIST_ENTRY ListOperation::OperateRemove(POPERATE_LIST pList) {
    if (nullptr == pList) return nullptr;

    PLIST_ENTRY plistEntry = nullptr;
    //内存加锁
    OperateLock(pList);
    if (0 != pList->size) {
        plistEntry = RemoveTailList(&pList->root);
        pList->size--;
    }
    //内存解锁
    OperateUnlock(pList);

    return plistEntry;
}

//头部移除
PLIST_ENTRY ListOperation::OperateRemoveHead(POPERATE_LIST pList) {
    if (nullptr == pList) return nullptr;

    PLIST_ENTRY plistEntry = nullptr;
    //内存加锁
    OperateLock(pList);
    if (0 != pList->size) {
        plistEntry = RemoveHeadList(&pList->root);
        pList->size--;
    }
    //内存解锁
    OperateUnlock(pList);
    return plistEntry;
}