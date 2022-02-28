//
//  ZBWGlobalTimer.m
//  HaiHuSDK
//
//  Created by 朱博文 on 16/12/5.
//  Copyright © 2016年 leixun. All rights reserved.
//

#import "ZBWGlobalTimer.h"
#import "NSTimer+ZBWWeakTimer.h"
#import "ZBWBackgroudQueue.h"



@interface ZBWTargetActionPair : NSObject

@property (nonatomic, weak) id target;
@property (nonatomic) SEL       selector;
@property (nonatomic) BOOL      mainThread;

+ (instancetype)targetActionPairWithTarget:(id)target selector:(SEL)selector  mainThread:(BOOL)mainThread;

@end

@implementation ZBWTargetActionPair

+ (instancetype)targetActionPairWithTarget:(id)target selector:(SEL)selector mainThread:(BOOL)mainThread
{
    ZBWTargetActionPair *pair = [[ZBWTargetActionPair alloc] init];
    pair.target = target;
    pair.selector = selector;
    pair.mainThread = mainThread;
    
    return pair;
}

@end


NSMutableDictionary *zbwGT_setsDic()
{
    static NSMutableDictionary *dic = nil;
    if (!dic) {
        dic = [NSMutableDictionary dictionaryWithCapacity:1];
    }
    return dic;
}

NSMutableSet * zbwGT_targetActionPairSet(CGFloat time)
{
    NSMutableDictionary *dic = zbwGT_setsDic();
    
    NSMutableSet *set = dic[@(time)];
    if (!set) {
        set = [NSMutableSet setWithCapacity:3];
        dic[@(time)] = set;
    }
    
    return set;
}

NSMutableDictionary *zbwGT_globalTimerDic()
{
    static NSMutableDictionary *dic = nil;
    if (!dic) {
        dic = [NSMutableDictionary dictionaryWithCapacity:1];
    }
    return dic;
}

void zbwGT_destroyTimer(CGFloat time)
{
    NSMutableDictionary *dic = zbwGT_globalTimerDic();
    NSTimer *timer = dic[@(time)];
    if (timer) {
        [dic removeObjectForKey:@(time)];
        [timer invalidate];
        timer = nil;
    }
}

NSTimer *zbwGT_globalTimer(CGFloat time)
{
    NSMutableDictionary *dic = zbwGT_globalTimerDic();
    
    NSTimer *timer = dic[@(time)];
    if (!timer || ![timer isValid]) {
        timer = [NSTimer zbw_timerWithTimeInterval:time block:^(id userInfo) {
            
            NSMutableSet *set = zbwGT_targetActionPairSet(time);
            NSMutableSet *invaildSet = [NSMutableSet setWithCapacity:3];
            [set enumerateObjectsUsingBlock:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
                ZBWTargetActionPair *pair = obj;
                if (!pair.target) {
//                    [set removeObject:pair];
                    [invaildSet addObject:pair];
                } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
                    if (pair.mainThread) {
                        [pair.target performSelectorOnMainThread:pair.selector withObject:nil waitUntilDone:NO];
                    } else {
                        dispatch_async(zbw_backgroundSycQueue(), ^{
                            [pair.target performSelector:pair.selector withObject:nil];
                        });
                    }
#pragma clang diagnostic pop
                }
            }];
            
            // 删除无用的监听器
            [invaildSet enumerateObjectsUsingBlock:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
                [set removeObject:obj];
            }];
            
            if (set.count == 0) {
                zbwGT_destroyTimer(time);
            }
            
        } userInfo:nil repeats:YES];
        
        [[NSRunLoop mainRunLoop] addTimer:timer forMode:NSRunLoopCommonModes];
        
        dic[@(time)] = timer;
    }
    
    return timer;
}


@implementation ZBWGlobalTimer

+ (void)addTarget:(id)target selector:(SEL)selector
{
    [self addTarget:target selector:selector type:ZBWGlobalTimerType_OneSecond callbackToMainThread:YES];
}

+ (void)addTarget:(id)target selector:(SEL)selector callbackToMainThread:(BOOL)mainThread
{
    [self addTarget:target selector:selector type:ZBWGlobalTimerType_OneSecond callbackToMainThread:mainThread];
}

+ (void)removeTarget:(id)target
{
    [self removeTarget:target type:ZBWGlobalTimerType_OneSecond];
    
    dispatch_async(zbw_backgroundSycQueue(), ^{
        NSMutableDictionary *dic = zbwGT_setsDic();
        [dic enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
            [self removeTarget:target type:[key floatValue]];
        }];
    });
}


+ (void)addTarget:(id)target selector:(SEL)selector type:(float)type
{
    [self addTarget:target selector:selector type:type callbackToMainThread:YES];
}
+ (void)addTarget:(id)target selector:(SEL)selector type:(float)type callbackToMainThread:(BOOL)mainThread
{
    if (![target respondsToSelector:selector]) {
        return;
    }
    
    dispatch_async(zbw_backgroundSycQueue(), ^{
        // 获取set
        NSMutableSet *set = zbwGT_targetActionPairSet(type);
        
        // 校验是否已经添加过
        __block BOOL isExist = NO;
        [set enumerateObjectsUsingBlock:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
            ZBWTargetActionPair *pair = obj;
            if (pair.target == target) {
                isExist = YES;
                *stop = YES;
            }
        }];
        // 添加到set
        if (!isExist) {
            [set addObject:[ZBWTargetActionPair targetActionPairWithTarget:target selector:selector mainThread:mainThread]];
        }
        
        // 如果timer没有启动，启动timer
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
        NSTimer *timer = zbwGT_globalTimer(type);
#pragma clang diagnostic pop
        //        [timer fire];
    });
}

+ (void)removeTarget:(id)target type:(float)type
{
    if (!target) {
        return;
    }
    
    dispatch_async(zbw_backgroundSycQueue(), ^{
        // 获取set
        NSMutableSet *set = zbwGT_targetActionPairSet(type);
        
        // 校验是否已经添加过
        __block ZBWTargetActionPair *targetPair = nil;
        [set enumerateObjectsUsingBlock:^(id  _Nonnull obj, BOOL * _Nonnull stop) {
            ZBWTargetActionPair *pair = obj;
            if (pair.target == target) {
                targetPair = pair;
//                [set removeObject:obj];
                *stop = YES;
            }
        }];
        
        if (targetPair) {
            [set removeObject:targetPair];
        }
        
        if (set.count == 0) {
            // 销毁timer
            zbwGT_destroyTimer(type);
        }
    });
}

@end
