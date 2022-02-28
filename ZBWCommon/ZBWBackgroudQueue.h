//
//  ZBWBackgroudQueue.h
//  Common-iOS
//
//  Created by 朱博文 on 2019/1/14.
//  Copyright © 2019年 朱博文. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef ZBWCOMMON_BACKGROUDQUEUE_H_
#define ZBWCOMMON_BACKGROUDQUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif
// --------------------------- 后台线程 ---------------------
dispatch_queue_t zbw_backgroundSycQueue(void);
dispatch_queue_t zbw_IOSycQueue(void);

#ifdef __cplusplus
}
#endif

#endif

