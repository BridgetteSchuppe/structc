﻿#include "thread.h"

static pthread_attr_t attr;

static pthread_attr_t rtta;

// 
// pthread_init - thread 使用方需要手动初始化
// attr     : pthread_attr_t 变量
// return   : void
//
void pthread_init(void) {
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_attr_init(&rtta);
}

//
// pthread_async - 启动无需等待的线程
// frun     : node_f or ... 运行主体
// arg      : 运行参数
// return   : 0 is success, -1 is error
// 
inline int 
pthread_async(void * frun, void * arg) {
    pthread_t id;
    return pthread_create(&id, &attr, frun, arg);
}


//
// pthread_run - 启动线程
// p        : 指向线程 id 的指针
// frun     : node_f or ... 运行主体
// arg      : 运行参数
// return   : 0 is success, -1 is error
//
inline int 
pthread_run(pthread_t * p, void * frun, void * arg) {
    return pthread_create(p, &rtta, frun, arg);
}