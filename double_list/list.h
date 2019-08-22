#ifndef __LIST_H__
#define __LIST_H__

//#define MACRO_OPT 
#define NO_ERROR              0x00000000  // 操作成功
#define ERROR_PARAMTERS_NULL  0xC000E001  // 参数为NULL
#define ERROR_REALLOC_FAILD   0xC000E002  // 内存分配失败
#define ERROR_NO_FULL_BUFFER  0xC000E003  // 获取空缓冲区失败

#define FORCEINLINE  __inline

typedef struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, *RESTRICTED_POINTER;

void FORCEINLINE InitializeListHead(PLIST_ENTRY ListHead) {
    ListHead->Flink = ListHead->Blink = ListHead;
}

#define IsListEmpty(ListHead)((ListHead)->Flink == (ListHead))


PLIST_ENTRY FORCEINLINE RemoveHeadList(PLIST_ENTRY ListHead) {
    if (nullptr == ListHead) return nullptr;
    if (IsListEmpty(ListHead)) return nullptr;

    PLIST_ENTRY Flink = nullptr;
    PLIST_ENTRY Entry = nullptr;

    do {
        Entry = ListHead->Flink;
        if (nullptr == Entry) break;
        Flink = Entry->Flink;
        ListHead->Flink = Flink;
        if (nullptr == Flink) break;
        Flink->Blink = ListHead;

    } while (false);
    return Entry;
}

PLIST_ENTRY FORCEINLINE RemoveTailList(PLIST_ENTRY ListHead) {
    if (nullptr == ListHead) return nullptr;
    if (IsListEmpty(ListHead)) return nullptr;

    PLIST_ENTRY Blink = nullptr;
    PLIST_ENTRY Entry = nullptr;

    do {
        Entry = ListHead->Blink;
        if (nullptr == Entry) break;
        Blink = Entry->Blink;
        ListHead->Blink = Blink;
        if (nullptr == Blink) break;
        Blink->Flink = ListHead;
    } while (false);

    return Entry;
}

void FORCEINLINE InsertTailList(PLIST_ENTRY ListHead, PLIST_ENTRY Entry) {
    PLIST_ENTRY Blink = nullptr;
    do {
        Blink = ListHead->Blink;
        Entry->Flink = ListHead;
        Entry->Blink = Blink;
        if (nullptr == Blink) break;
        Blink->Flink = Entry;
        ListHead->Blink = Entry;
    } while (false);
}

void FORCEINLINE InsertHeadList(PLIST_ENTRY ListHead, PLIST_ENTRY Entry) {
    if (nullptr == ListHead || nullptr == Entry) return;

    PLIST_ENTRY Flink;

    do {
        Flink = ListHead->Flink;
        Entry->Flink = Flink;
        Entry->Blink = ListHead;
        if (nullptr == Flink) break;
        Flink->Blink = Entry;
        ListHead->Flink = Entry;
    } while (false);
}

//#endif //MACRO_OPT

#endif