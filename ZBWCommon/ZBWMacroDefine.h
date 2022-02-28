//
//  ZBWMacroDefine.h
//  ZBWMacroDefine
//
//  Created by 朱博文 on 2019/1/11.
//  Copyright © 2019年 朱博文. All rights reserved.
//

#ifndef ZBWMacroDefine_h
#define ZBWMacroDefine_h

/************************************************************************************
 屏幕宽高
 ************************************************************************************/
#define kZBW_SCREEN_WIDTH                ((float)[[UIScreen mainScreen] bounds].size.width)
#define kZBW_SCREEN_HEIGHT               ((float)[[UIScreen mainScreen] bounds].size.height)

/************************************************************************************
 // 手机型号
 ************************************************************************************/
#define kZBW_IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define kZBW_IS_PAD (UI_USER_INTERFACE_IDIOM()== UIUserInterfaceIdiomPad)

#define kZBW_IS_IPHONE_4                 (kZBW_SCREEN_HEIGHT == 480)
#define kZBW_IS_IPHONE_5                 (kZBW_SCREEN_HEIGHT == 568)
#define kZBW_IS_IPHONE_6                 (kZBW_SCREEN_HEIGHT == 667)
#define kZBW_IS_IPHONE_6P                (kZBW_SCREEN_HEIGHT == 736)

#define kZBW_IS_IPHONE_X                 (kZBW_IS_IPHONE && (kZBW_SCREEN_HEIGHT >= 812))

/************************************************************************************
 // 型号适配
 ************************************************************************************/
#define kZBW_PHONE_ADAPTER(iphone4Val,iphone5Val,iphone6Val,iphone6PVal) (kZBW_IS_IPHONE_4 ? iphone4Val :\
(kZBW_IS_IPHONE_5 ? iphone5Val :\
(kZBW_IS_IPHONE_6 ? iphone6Val :\
(kZBW_IS_IPHONE_6P ? iphone6PVal : iphone6PVal))))

#define kZBW_Y(_y_)    (_y_ * kZBW_SCREEN_HEIGHT / 667.0)
#define kZBW_X(_x_)      (_x_ * kZBW_SCREEN_WIDTH / 375.0)

/************************************************************************************
 // 系统
 ************************************************************************************/
#define kZBW_SYSTEM_IS_GreaterThan(_version)    ([[UIDevice currentDevice] systemVersion].floatValue > _version)
#define kZBW_SYSTEM_IS_LessThan(_version)    ([[UIDevice currentDevice] systemVersion].floatValue < _version)

/************************************************************************************
 // 颜色
 ************************************************************************************/
#define kZBW_ColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define kZBW_Color_Gray                       kZBW_ColorFromRGB(0xededed)  // 230 230 230
#define kZBW_Color_Gray1                      kZBW_ColorFromRGB(0x9b9b9b)
#define kZBW_Color_Gray2                      kZBW_ColorFromRGB(0x5e5e5e)


#define kZBW_Color_Gray245                    kZBW_ColorFromRGB(0xF5F5F5)
#define kZBW_Color_Gray236                    kZBW_ColorFromRGB(0xECECEC)

#define kZBW_Color_GrayWith(value)                [UIColor colorWithRed:value/255.0 green:value/255.0 blue:value/255.0 alpha:1.0]

//正文黑色：#252525
#define kZBW_Color_Black                      kZBW_ColorFromRGB(0x252525)
//二级标题灰色：#666666
#define kZBW_Color_Gray4TitleLv2                   kZBW_ColorFromRGB(0x666666)
//注释灰：#999999
#define kZBW_Color_Gray4Notes                   kZBW_ColorFromRGB(0x999999)
//背景灰：#f3f3f3
#define kZBW_Color_Gray4Bg                    kZBW_ColorFromRGB(0xf3f3f3)
//分隔线灰（浅点）：#f6f6f6
#define kZBW_Color_Gray4Separate_Light                    kZBW_ColorFromRGB(0xf6f6f6)
//分隔线灰（深点）：#e5e5e5
#define kZBW_Color_Gray4Separate_Dark                    kZBW_ColorFromRGB(0xe5e5e5)
//橙色(主色）：#ff9900
#define kZBW_Color_Orange                    kZBW_ColorFromRGB(0xff9900)
//橙色2（文科色标）：#fcac4e
//#define kZBW_Color_Orange                    kZBW_ColorFromRGB(0xff9900)
//橙色（掌握程度）：#fcac4e
#define kZBW_Color_Orange1                    kZBW_ColorFromRGB(0xfcac4e)
//黄色：#f7ff29
#define kZBW_Color_Yellow                    kZBW_ColorFromRGB(0xf7ff29)
//红色（强调）：#ff1f1f
#define kZBW_Color_Red                        kZBW_ColorFromRGB(0xff1f1f)
//红色（掌握程度）：#fc4e4e
#define kZBW_Color_Red1                        kZBW_ColorFromRGB(0xfc4e4e)
//蓝色（理科色标）：#3fa6f5
#define kZBW_Color_Blue                      kZBW_ColorFromRGB(0x3fa6f5)
//蓝色（掌握程度）：#5aceff
#define kZBW_Color_Blue1                      kZBW_ColorFromRGB(0x5aceff)
//绿色（掌握程度）：#47d738
#define kZBW_Color_Green                      kZBW_ColorFromRGB(0x47d738)

#define kZBW_Color_Purple                     [UIColor colorWithRed:119.0/255 green:95.0/255 blue:190.0/255 alpha:1.0]

//#define kZBW_Color_Orange                    kZBW_ColorFromRGB(0xF9B54D)

#define kZBW_Color_White                     [UIColor whiteColor]
#define kZBW_Color_Clear                     [UIColor clearColor]

#define kZBW_Color_Background                kZBW_Color_Gray
#define kZBW_Color_TipBackground             [[UIColor blackColor] colorWithAlphaComponent:.6]


/************************************************************************************
 // 字体大小
 ************************************************************************************/

#define kZBW_FontSize_Big                kZBW_PHONE_ADAPTER(18, 18, 20, 22)
#define kZBW_FontSize_Mid_2              kZBW_PHONE_ADAPTER(16, 16, 18, 18)
#define kZBW_FontSize_Mid                kZBW_PHONE_ADAPTER(14, 14, 16, 16)
#define kZBW_FontSize_Small              kZBW_PHONE_ADAPTER(12, 12, 14, 14)
#define kZBW_FontSize_Mirco              kZBW_PHONE_ADAPTER(10, 11, 12, 13)

// 系统字体

#define kZBW_Font(fontSize)              ([UIFont systemFontOfSize:fontSize])

#define kZBW_Font_Big                    kZBW_Font(kZBW_FontSize_Big)  // 宝贝title
#define kZBW_Font_Mid_2                  kZBW_Font(kZBW_FontSize_Mid_2)
#define kZBW_Font_Mid                    kZBW_Font(kZBW_FontSize_Mid)  // segmentTitle 、 @“不变更”
#define kZBW_Font_Small                  kZBW_Font(kZBW_FontSize_Small)
#define kZBW_Font_Micro                  kZBW_Font(kZBW_FontSize_Mirco)

// 细字体
#define kZBW_Font_Light(fontSize)        ([UIFont fontWithName:@"Helvetica-Light" size:fontSize] ?: kZBW_Font(fontSize))

#define kZBW_Font_Light_Big              kZBW_Font_Light(kZBW_FontSize_Big)
#define kZBW_Font_Light_Mid_2            kZBW_Font_Light(kZBW_FontSize_Mid_2)
#define kZBW_Font_Light_Mid              kZBW_Font_Light(kZBW_FontSize_Mid)
#define kZBW_Font_Light_Small            kZBW_Font_Light(kZBW_FontSize_Small)
#define kZBW_Font_Light_Micro            kZBW_Font_Light(kZBW_FontSize_Mirco)

// 粗体
#define kZBW_Font_Bold(fontSize)         ([UIFont boldSystemFontOfSize:fontSize])
#define kZBW_Font_Bold_Big               kZBW_Font_Bold(kZBW_FontSize_Big)
#define kZBW_Font_Bold_Mid_2             kZBW_Font_Bold(kZBW_FontSize_Mid_2)
#define kZBW_Font_Bold_Mid               kZBW_Font_Bold(kZBW_FontSize_Mid)
#define kZBW_Font_Bold_Small             kZBW_Font_Bold(kZBW_FontSize_Small)
#define kZBW_Font_Bold_Micro             kZBW_Font_Bold(kZBW_FontSize_Mirco)

#define kZBW_Font_TabNormal              kZBW_Font(kZBW_PHONE_ADAPTER(11, 11, 13, 14))
#define kZBW_Font_TabSelected            kZBW_Font(kZBW_PHONE_ADAPTER(13, 13, 15, 16))


/************************************
 *  一个像素大小
 ************************************/
#define kZBW_OnePixel                    (1/[UIScreen mainScreen].scale)


/************************************
 *  数学转换
 ************************************/
#define kZBW_DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * M_PI)


/************************************
 *  Class 安全检查
 ************************************/
#define kZBW_Is_Class(obj,class)         (obj && class && [obj isKindOfClass:class])
#define kZBW_Is_ClassStr(obj,classStr)         (obj && classStr && [obj isKindOfClass:NSClassFromString(classStr)])

/************************************
 *  weak
 ************************************/
#define weaked(p)                   _weak_##p
#define WEAK(obj)                   __weak typeof(obj) weaked(obj) = obj; __weak typeof(obj) weak##obj = obj;

#define __weakSelf                      __weak typeof(self) __weakedSelf = self;

/************************************
 *  KVO 、获取属性名称
 ************************************/
#define kZBW_Field(__obj__, __field__)   (__obj__.__field__ ? @#__field__ : @#__field__)

/************************************
 *  NSString
 ************************************/
#define kZBW_StringNotNULL(_str) (_str ? : @"")

#define kZBW_API_Error_TipStr    (@"请求异常！")

/************************************
 *  Storyboard
 ************************************/
#define kStoryBoard [UIStoryboard zbw_storyboardAdapter:@"Storyboard" bundle:[NSBundle mainBundle]]
#define kViewControllerByStoryBoard(vcIdStr) \
[kStoryBoard instantiateViewControllerWithIdentifier:vcIdStr]

/************************************************************************************
 // 导航栏高度
 ************************************************************************************/
// 状态栏高度
#define kZBW_StatusBar_Height   ([UIApplication sharedApplication].statusBarFrame.size.height)
// 导航栏内容高度
#define kZBW_NavBar_Height  ((kZBW_IS_PAD ? 50 : 44))

// 导航栏总高度 = 状态栏高度 + 导航内容高度
#define kZBW_NAV_HEIGHT (kZBW_StatusBar_Height + kZBW_NavBar_Height)

// iPhoneX 底部安全区域高度
#define kZBW_IPHONEX_BOTTOM_SAFE_HEIGHT (kZBW_IS_IPHONE_X ? 34 : 0)

#define kZBW_Align  15

#define kZBW_Cell_Height        kZBW_PHONE_ADAPTER(44, 44, 50, 60)

/************************************************************************************
 // Toast
 ************************************************************************************/
#define kZBW_ToastInView(msgStr, view) \
do {\
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view animated:YES];\
    hud.bezelView.color = [UIColor blackColor];\
    hud.contentColor = [UIColor whiteColor];\
    hud.detailsLabel.font = kZBW_Font_Mid_2;\
    hud.mode = MBProgressHUDModeText;\
    hud.userInteractionEnabled = NO;\
    hud.label.text = nil;\
    hud.detailsLabel.text = msgStr;\
    hud.minShowTime = 1;\
    hud.removeFromSuperViewOnHide = YES;\
    [hud hideAnimated:YES afterDelay:2];\
} while(0);

#define kZBW_Toast(msgStr) \
kZBW_ToastInView(msgStr, [[UIApplication sharedApplication] zbw_mainWindow]);


#define kZBW_LoadingStyle    0

/************************************************************************************
 // loading
 ************************************************************************************/
#if (kZBW_LoadingStyle)
#define kZBW_LoadingInView(msgStr, view) \
do {\
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view animated:YES];\
    hud.detailsLabel.font = kZBW_Font_Mid_2;\
    hud.mode = MBProgressHUDModeIndeterminate;\
    hud.userInteractionEnabled = NO;\
    hud.label.text = nil;\
    hud.detailsLabel.text = msgStr;\
    hud.minShowTime = 1;\
    hud.removeFromSuperViewOnHide = YES;\
    [hud hideAnimated:YES afterDelay:2];\
} while(0);

#define kZBW_Loading \
kZBW_LoadingInView(@"加载中...", [[UIApplication sharedApplication] zbw_mainWindow]);

#define kZBW_HideLoadingInView(view) \
[MBProgressHUD hideHUDForView:view animated:YES];

#define kZBW_HideLoading \
kZBW_HideLoadingInView([[UIApplication sharedApplication] zbw_mainWindow])

#else
#define kZBW_LoadingInView(msgStr, view) \
do {\
    if ([NSThread isMainThread]) {\
        UIView *aView = view;\
        if (!aView) {\
            aView = [[UIApplication sharedApplication] zbw_mainWindow];\
        }\
        [aView zbw_loadingWithTipStr:msgStr];\
    }\
    else\
    {\
        dispatch_async(dispatch_get_main_queue(), ^{\
            UIView *aView = view;\
            if (!aView) {\
                aView = [[UIApplication sharedApplication] zbw_mainWindow];\
            }\
            [aView zbw_loadingWithTipStr:msgStr];\
        });\
    }\
} while(0);

#define kZBW_Loading \
kZBW_LoadingInView(nil, [[UIApplication sharedApplication] zbw_mainWindow]);

#define kZBW_LoadingInResponder(msgStr, responder) \
kZBW_LoadingInView(msgStr, ([responder isKindOfClass:[UIView class]] ? (UIView *)responder : [(UIViewController *)responder view]));

#define kZBW_HideLoadingInView(view) \
do{\
    UIView *theView = view;\
    theView = theView ?: [[UIApplication sharedApplication] zbw_mainWindow];\
    if ([NSThread isMainThread]) {\
        [theView zbw_dismssLoading];\
    } else {\
        dispatch_async(dispatch_get_main_queue(), ^{\
            [theView zbw_dismssLoading];\
        });\
    }\
}while(0);

#define kZBW_HideLoadingInResponder(responder) \
kZBW_HideLoadingInView([responder isKindOfClass:[UIView class]] ? (UIView *)responder : [(UIViewController *)responder view])

#define kZBW_HideLoading \
kZBW_HideLoadingInView([[UIApplication sharedApplication] zbw_mainWindow])

#endif


#define kZBW_Default_EmptyViewForTable(__tableView, __callback) \
do {\
    UIView *emptyView = [[UIView alloc] initWithFrame:__tableView.bounds];\
    UIButton *emptyBtn = [[UIButton alloc] initWithFrame:emptyView.bounds];\
    [emptyBtn setTitleColor:kZBW_Color_Orange forState:UIControlStateNormal];\
    emptyBtn.titleLabel.font = kZBW_Font_Mid;\
    [emptyBtn setTitle:@"网络异常，点击重试！" forState:UIControlStateNormal];\
    emptyBtn.zbwClickCallback = __callback;\
    [emptyBtn setTag:99];\
    emptyBtn.hidden = YES;\
    [emptyView addSubview:emptyBtn];\
    __tableView.zbw_emptyView = emptyView;\
} while(0);


#define kZBW_AddBlankView \
do {\
    UIView *__blankView__ = [[UIView alloc] initWithFrame:CGRectZero];\
    [self.view addSubview:__blankView__];\
} while(0);


/**
 在主线程执行
 */
#define kZBW_ExcuteInMainQueue(__exec_block__) \
do {\
    if ([NSThread isMainThread]) {\
        __exec_block__ ? __exec_block__() : NULL;\
    } else {\
        dispatch_async(dispatch_get_main_queue(), __exec_block__);\
    }\
} while(0);

/**
 防止按钮双击
 */
#define kZBW_DoNotDoubleClick \
do {\
    static double lastTime = 0;\
    double __timeInterval__ = 0.5;\
    NSDate *now = [NSDate date];\
    NSTimeInterval timestamp = [now timeIntervalSince1970];\
    if (timestamp - lastTime <= __timeInterval__) {\
        NSLog(@"禁止重复点击");\
        return;\
    }\
    lastTime = timestamp;\
} while (0);

#endif
