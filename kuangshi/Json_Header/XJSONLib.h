#pragma once
#if TARGET_OS_IOS == 1
#define OS_IOS 1
#endif

#ifdef WIN32
#ifdef XJSON_EXPORTS
#define XJSON_API __declspec(dllexport)
#define XJSON_TEMPLATE __declspec(dllexport)
#else
#define XJSON_API __declspec(dllimport)
#define XJSON_TEMPLATE
#endif
#define CALLBACK __stdcall
#else
#define XJSON_API
#define CALLBACK
#endif

#if (defined(WIN32)||defined(_WIN32) ||defined(__WIN32__)||defined(__NT__))
#define OS_WIN32
#else
#define OS_LINUX
//#define OS_IOS
#endif

#if defined(_MSC_VER)
#define CC_MSVC
#endif

#ifdef OS_WIN32
//#define _WIN32_WINNT  0x0400
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN
#else
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <pthread.h>
#endif

// 一般库建议都加上命名空间，以防冲突
// 命名空间快速定义 开始与结束
#define NS_XJSON_BEGIN namespace XJSON_LIB {
#define NS_XJSON_END_AND_USE }using namespace XJSON_LIB;

#define NS_BEGIN(Name) namespace Name {
#define NS_END_AND_USE(Name) }using namespace Name;
#define NS_END }

#pragma warning(disable: 4251)
#pragma warning(disable: 4244)
#pragma warning(disable: 4275)
#pragma warning(disable: 4514)
#pragma warning(disable: 4800)
#pragma warning(disable: 4097)
#pragma warning(disable: 4706)
#pragma warning(disable: 4786)
#pragma warning(disable: 4660)
#pragma warning(disable: 4355)
#pragma warning(disable: 4231)
#pragma warning(disable: 4710)
#pragma warning(disable: 4530)
#pragma warning(disable: 4996)

#ifndef uint64
#if defined( WIN32 )
typedef unsigned __int64	uint64;
#define FORMAT_INT64 "%I64d"
#else
typedef unsigned long long	uint64;
#define FORMAT_INT64 "%lld"
#endif
#endif

#ifndef int64
#ifdef WIN32
typedef __int64	int64;
#else
typedef long long	int64;
#endif
#endif

#ifndef Bool
#define Bool int
#endif


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif


#ifndef uchar
typedef unsigned char uchar;
#endif

#ifndef uint
typedef unsigned int uint;
#endif