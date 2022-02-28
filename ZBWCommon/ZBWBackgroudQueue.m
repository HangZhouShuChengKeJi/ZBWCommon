//
//  ZBWBackgroudQueue.m
//  Common-iOS
//
//  Created by 朱博文 on 2019/1/14.
//  Copyright © 2019年 朱博文. All rights reserved.
//

#import "ZBWBackgroudQueue.h"

dispatch_queue_t zbw_backgroundSycQueue()
{
    static dispatch_once_t onceToken;
    static dispatch_queue_t bgQueue;
    dispatch_once(&onceToken, ^{
        bgQueue = dispatch_queue_create("com.orange.background.sycqueue", DISPATCH_QUEUE_SERIAL);
    });
    return bgQueue;
}

dispatch_queue_t zbw_IOSycQueue()
{
    static dispatch_once_t onceToken;
    static dispatch_queue_t ioQueue;
    dispatch_once(&onceToken, ^{
        ioQueue = dispatch_queue_create("com.orange.io.sycqueue", DISPATCH_QUEUE_SERIAL);
    });
    return ioQueue;
}
