//
//  ZBWGlobalTimer.h
//  HaiHuSDK
//
//  Created by 朱博文 on 16/12/5.
//  Copyright © 2016年 leixun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>


#define ZBWGlobalTimerType_OneSecond  1.0
#define ZBWGlobalTimerType_ThreeSecond  3.0
#define ZBWGlobalTimerType_FiveSeconds  5.0


/**
 【ZBWGlobalTimer】 全局的秒级定时器，每秒回调一次。 回调在子线程。
 */
@interface ZBWGlobalTimer : NSObject

// 默认使用秒级定时器
+ (void)addTarget:(id)target selector:(SEL)selector;
+ (void)addTarget:(id)target selector:(SEL)selector callbackToMainThread:(BOOL)mainThread;

#pragma mark- 指定定时器类型
+ (void)addTarget:(id)target selector:(SEL)selector type:(float)type;
+ (void)addTarget:(id)target selector:(SEL)selector type:(float)type callbackToMainThread:(BOOL)mainThread;


/*
    手动移除定时器监听。(可以不移除，会自动移除)
    **注意** 千万不要在target对象的dealloc中调用移除方法！！！
    **注意** 千万不要在target对象的dealloc中调用移除方法！！！
    **注意** 千万不要在target对象的dealloc中调用移除方法！！！
 */
+ (void)removeTarget:(id)target;
+ (void)removeTarget:(id)target type:(float)type;

@end
