//
//  Created by Cary_Xu.
//  Copyright © 2019 CaryXu. All rights reserved.
//

#import <Foundation/Foundation.h>


/*
 ******NSLOG******
 */
//NSLog
#ifdef DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"%s:%s\nLine:%d\n%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],__func__,__LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif
//Log for print Rect, Size, Point
#define kShowRect(rect)     NSLog(@" rect.x = %f\n rect.y = %f\n rect.w = %f\n rect.h = %f", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height)
#define kShowSize(size)     NSLog(@" size.w = %f\n size.h = %f", size.width, size.height)
#define kShowPoint(point)   NSLog(@" point.x = %f\n point.y = %f", point.x, point.y)

/*
 ******SCREEN******
 */
//Screen_Size
#define kScreenSize \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] \
? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) \
: [UIScreen mainScreen].bounds.size)
//Screen_Width
#define kScreenWidth    kScreenSize.width
//Screen_Height
#define kScreenHeight   kScreenSize.height
//Screen_Size_Current
#define kScreenCurrent  [[UIScreen mainScreen] currentMode].size

/*
 ******SYSTEM******
 */
//Version_System
#define kSystemVersion          [[UIDevice currentDevice] systemVersion]
#define kSystemVersionDouble    [[[UIDevice currentDevice] systemVersion] doubleValue]
//APP版本号
#define kAppVersion             [[[NSBundle mainBundle] infoDictionary] valueForKey:@"CFBundleShortVersionString"]
//当前版本 = 版本v
#define K_IS_SYSTEM_VERSION_EQUAL_TO(v)     ([[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
//当前版本 > 版本v
#define K_IS_SYSTEM_VERSION_MORE_THAN(v)    ([[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
//当前版本 < 版本v
#define K_IS_SYSTEM_VERSION_LESS_THAN(v)    ([[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)


//APP对象 （单例对象）
#define kApplication        [UIApplication sharedApplication]
//主窗口   （keyWindow）
#define kKeyWindow          [UIApplication sharedApplication].keyWindow
//APP对象的delegate
#define kAppDelegate        [UIApplication sharedApplication].delegate
//NSUserDefaults实例化
#define kUserDefaults       [NSUserDefaults standardUserDefaults]

//通知中心  （单例对象）
#define kNotificationCenter [NSNotificationCenter defaultCenter]
//发送通知
#define kPostNotification(name,obj,info) [[NSNotificationCenter defaultCenter] postNotificationName:name object:obj userInfo:info]
//移除通知
#define kRemoveNotification(_self,name)  ([[NSNotificationCenter defaultCenter] removeObserver:_self name:name object:nil])
//移除所有通知
#define kRemoveAllNotification(_self)    ([[NSNotificationCenter defaultCenter] removeObserver:_self])

//获取沙盒 temp
#define kPathTemp       NSTemporaryDirectory()
//获取沙盒 Document
#define kPathDocument   [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Cache
#define kPathCache      [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]
//Library/Caches 文件路径
#define kFilePath       ([[NSFileManager defaultManager] URLForDirectory:NSCachesDirectory inDomain:NSUserDomainMask appropriateForURL:nil create:YES error:nil])

//获得当前的年份
#define kCurrentYear    [[NSCalendar currentCalendar] component:NSCalendarUnitYear      fromDate:[NSDate date]]
//获得当前的月份
#define kCurrentMonth   [[NSCalendar currentCalendar] component:NSCalendarUnitMonth     fromDate:[NSDate date]]
//获得当前的日期
#define kCurrentDay     [[NSCalendar currentCalendar] component:NSCalendarUnitDay       fromDate:[NSDate date]]
//获得当前的小时
#define kCurrentHour    [[NSCalendar currentCalendar] component:NSCalendarUnitHour      fromDate:[NSDate date]]
//获得当前的分
#define kCurrentMin     [[NSCalendar currentCalendar] component:NSCalendarUnitMinute    fromDate:[NSDate date]]
//获得当前的秒
#define kCurrentSec     [[NSCalendar currentCalendar] component:NSCalendarUnitSecond    fromDate:[NSDate date]]

//Time
#define kTimeMinute      60
#define kTimeHour       (kTimeMinute    * 60)
#define kTimeDay        (kTimeHour      * 24)
#define kTimeFiveDay    (kTimeDay       * 5)
#define kTimeWeek       (kTimeDay       * 7)
#define kTimeMonth      (kTimeDay       * 30.5)
#define kTimeYear       (kTimeDay       * 365)

/*
 ******DEVICE******
 */
//Version_Idiom
#define K_IS_PAD            ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define K_IS_PHONE          ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
#define kSystemIdiom        (([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) ? @"ipad": @"iphone")
//iPhone_type
#define K_IS_RETINA         ([[UIScreen mainScreen] scale] == 2.0f)
#define K_IS_INSTANCES      [UIScreen instancesRespondToSelector:@selector(currentMode)]
#define K_IS_iPhone4        (K_IS_INSTANCES ? K_IS_PHONE && CGSizeEqualToSize(kScreenCurrent,CGSizeMake(640, 960))   : NO)
#define K_IS_iPhone5        (K_IS_INSTANCES ? K_IS_PHONE && CGSizeEqualToSize(kScreenCurrent,CGSizeMake(640, 1136))  : NO)
#define K_IS_iPhone6        (K_IS_INSTANCES ? K_IS_PHONE && CGSizeEqualToSize(kScreenCurrent,CGSizeMake(750, 1334))  : NO)
#define K_IS_iPhone6Plus    (K_IS_INSTANCES ? K_IS_PHONE && CGSizeEqualToSize(kScreenCurrent,CGSizeMake(1242, 2208)) : NO)
#define K_IS_iPhone_X       (K_IS_INSTANCES ? K_IS_PHONE && CGSizeEqualToSize(kScreenCurrent,CGSizeMake(1125, 2436)) : NO)
#define K_IS_iPhone_Xr      (K_IS_INSTANCES ? K_IS_PHONE && CGSizeEqualToSize(kScreenCurrent,CGSizeMake(828, 1792))  : NO)
#define K_IS_iPhone_Xs      (K_IS_INSTANCES ? K_IS_PHONE && CGSizeEqualToSize(kScreenCurrent,CGSizeMake(1125, 2436)) : NO)
#define K_IS_iPhone_Xs_Max  (K_IS_INSTANCES ? K_IS_PHONE && CGSizeEqualToSize(kScreenCurrent,CGSizeMake(1242, 2688)) : NO)
#define K_IS_iPhoneXXX      (K_IS_iPhone_X || K_IS_iPhone_Xr || K_IS_iPhone_Xs || K_IS_iPhone_Xs_Max)


/*
 ******CONSTANT******
 */
//在 iPhoneX 系列上Bottom Bar的安全增量
#define kHeightSafeBottom       (K_IS_iPhoneXXX ? 34.0 : 0)
//在 iPhoneX 系列上Status Bar的安全增量
#define kHeightSafeStatus       (K_IS_iPhoneXXX ? 24.0 : 0)
//系统手势增量
#define kHeightGestureSystem    (K_IS_iPhoneXXX ? 13.0 : 0)
//状态栏高度
#define kHeightStatusBar        (20.0 + kHeightSafeStatus)
//导航栏高度
#define kHeightNavBar           44.0
//顶部高度
#define kHeightTop              (kHeightStatusBar + kHeightNavBar)
//底部tabBar高度
#define kHeightTabBar           (49 + kHeightSafeBottom)

//View 坐标(x,y)、宽高(width,height)、左上角坐标(minX,minY)、中心坐标(midX,midY)、右下角坐标(maxX,maxY)
#define kFrameX(v)              (v).frame.origin.x
#define kFrameY(v)              (v).frame.origin.y
#define kFrameWidth(v)          (v).frame.size.width
#define kFrameHeight(v)         (v).frame.size.height
#define kFrameMinX(v)           CGRectGetMinX((v).frame)
#define kFrameMinY(v)           CGRectGetMinY((v).frame)
#define kFrameMidX(v)           CGRectGetMidX((v).frame)
#define kFrameMidY(v)           CGRectGetMidY((v).frame)
#define kFrameMaxX(v)           CGRectGetMaxX((v).frame)
#define kFrameMaxY(v)           CGRectGetMaxY((v).frame)


/*
 ******TOOLS******
 */
//Color_RGBA
#define kColorRGBA(r, g, b, a)  [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
//Color_RGB
#define kColorRGB(r, g, b)      kColorRGBA(r, g, b, 1.0)
//Color_Random
#define kColorRandom            kColorRGB(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))
//Color_Value
#define kColorValue(rgbValue)   [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 16))/255.0 blue:((float)((rgbValue & 0xFF) >> 16))/255.0 alpha:1.0];
//Fount
#define kFont(x)                [UIFont systemFontOfSize:x]
//加载图片
#define kGetImage(imageName)    [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
//加载本地图片
#define kGetImageWithFile(name,ext)\
                                [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(name) ofType:(ext)]]
//加载xib
#define kLoadNib(nibName)       [UINib nibWithNibName:nibName bundle:[NSBundle mainBundle]]
//字符串拼接
#define kStringFormat(FORMAT,...) \
                                [NSString stringWithFormat:FORMAT,##__VA_ARGS__]
//由角度转换为弧度
#define kDegreesToRadian(d)     (M_PI * (d) / 180.0)
//由弧度转换为角度
#define kRadianToDegrees(r)     (r * 180.0) / (M_PI)
//UIAlertView
#define kUIAlertView(FORMAT, ...) \
[[[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] delegate:nil cancelButtonTitle:@"知道了" otherButtonTitles:nil] show]

//字符串是否为空
#define K_IS_NULL_String(str)   (str == nil || [str isKindOfClass:[NSNull class]] || [str length] < 1)
//数组是否为空
#define K_IS_NULL_Array(array)  (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0 || [array isEqual:[NSNull null]])
//字典是否为空
#define K_IS_NULL_Dict(dic)     (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0 || [dic isEqual:[NSNull null]])
//是否是空对象
#define K_IS_NULL_Object(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))
//判断对象是否为空,为空则返回默认值
#define kGetDefaultWhenNullObject(_value,_default) ((_value == nil  \
|| !_value \
|| [_value isKindOfClass:[NSNull class]] \
|| [_value isEqualToString:@"(null)"] \
|| [_value isEqualToString:@"<null>"] \
|| [_value isEqualToString:@""] \
|| [_value length] == 0) ? _default : _value)



//带自动提示的keypath宏(https://www.jianshu.com/p/6da4155e09ec)
#define keypath2(OBJ, PATH) \
(((void)(NO && ((void)OBJ.PATH, NO)), # PATH))

//根据当前 view 找所在tableview 里的 indexpath
#define kIndexpathSubviewTable(subview,tableview)\
({\
CGRect subviewFrame         = [subview convertRect:subview.bounds toView:tableview];\
NSIndexPath *tabIndexPath   = [tableview indexPathForRowAtPoint:subviewFrame.origin];\
tabIndexPath;\
})\

//根据当前view 找所在collectionview 里的 indexpath
#define kIndexpathSubviewCollection(subview,collectionview)\
({\
CGRect subviewFrame         = [subview convertRect:subview.bounds toView:collectionview];\
NSIndexPath *tabIndexPath   = [collectionview indexPathForItemAtPoint:subviewFrame.origin];\
tabIndexPath;\
})\

//根据当前view 找所在tableview 里的 tableviewcell
#define kCellSubviewTable(subview,tableview)\
({\
CGRect subviewFrame         = [subview convertRect:subview.bounds toView:tableview];\
NSIndexPath *indexPath      = [tableview indexPathForRowAtPoint:subviewFrame.origin];\
UITableViewCell *tabCell    = [tableview cellForRowAtIndexPath:indexPath];\
tabCell;\
})\




NS_ASSUME_NONNULL_BEGIN

@interface CYMacrosHeader : NSObject

@end

NS_ASSUME_NONNULL_END
