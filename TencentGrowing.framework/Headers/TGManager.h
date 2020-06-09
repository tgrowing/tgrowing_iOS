//
//  TGManager.h
//  TencentGrowing
//
//  Created by yiqiwang(王一棋) on 2019/11/29.
//  Copyright © 2019 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TGManager : NSObject

/// SDK 版本号
+ (NSString *)sdkVersion;

/// Device Id
+ (NSString *)deviceId;

/// 开启log，需要在startWithAppId之前设置
+ (void)enableLog;

/// 开启Debug，需要在startWithAppId之前设置
+ (void)enableDebugMode;

/// 开启实时联调模式，上线前必须关闭， 需要在startWithAppId之前设置
+ (void)enableAccessTest;

/// 开启全埋点上报
///
/// - Note: 在applicationDidFinishLaunching中初始化
///
/// - Parameter appId: 应用id
+ (void)startWithAppId:(NSString *)appId;

// todo yiqi comment需要优化
// 如果您的AppDelegate中 实现了其中一个或者多个方法 请以在已实现的函数中 调用handleUrl
//- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation
//- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
//- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options
// 如果以上所有函数都未实现 则请实现 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation 方法并调用handleUrl
+ (BOOL)canHandleUrl:(NSURL*)url;

/// 判断类型是否开启自动上报
///
/// - Parameter aClass: 对应类型
///
/// - Returns: YES:开启； NO：关闭；
+ (BOOL)isEnableAutoReportWith:(Class)aClass;

/// 上报事件
///
/// - Parameter event: 事件名称
+ (void)report:(nonnull NSString *)event;

+ (void)reportSender:(nonnull id)sender event:(nonnull NSString *)event;

@end

NS_ASSUME_NONNULL_END
