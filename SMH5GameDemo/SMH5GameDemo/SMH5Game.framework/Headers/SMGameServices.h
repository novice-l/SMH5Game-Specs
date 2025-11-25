//
//  SMGameServices.h
//  SMH5Game
//
//  Created by Developer on 2022/8/2.
//

#import <UIKit/UIKit.h>

@protocol SMGameServicesDelegate <NSObject>

@required

/// 开启陀螺仪数据采集
- (void)needOpenGSensor;

/// 关闭陀螺仪数据采集
- (void)needCloseGSensor;

@optional

/// 点击了vip按钮
/// 当使用SDK的游戏列表界面时，忽略该回调，使用列表界面的回调
/// 当未使用SDK的游戏列表界面时，通过这个回调可以获取到用户点击了vip按钮
- (void)didSelectVipButton;

/// 游戏界面打开
- (void)willOpenGame;

/// 游戏界面关闭
- (void)willCloseGame;

/// 游戏界面关闭
/// @param inside SDK内部退出游戏时为YES，调用closeGame关闭游戏时为NO
- (void)willCloseGame:(BOOL)inside;

@end



typedef NS_ENUM(NSUInteger, SMGameLanguage) {
    SMGameLanguageZH,  // 中文
    SMGameLanguageEN,  // 英文
};

typedef NS_OPTIONS(NSUInteger, HeartRatePanelAllowedGameType) {
    HeartRatePanelAllowedGameTypeNone      = 0,        // 所有都不显示
    HeartRatePanelAllowedGameTypeFitness   = 1 << 0,   // 健身游戏显示
    HeartRatePanelAllowedGameTypeDance     = 1 << 1,   // 舞蹈舞蹈显示
    HeartRatePanelAllowedGameTypeOther     = 1 << 2,   // 其它游戏显示
    HeartRatePanelAllowedGameTypeAll       = (HeartRatePanelAllowedGameTypeFitness |
                                              HeartRatePanelAllowedGameTypeDance   |
                                              HeartRatePanelAllowedGameTypeOther), // 所有游戏都显示
};

@class SMBannerGameInfo, SMGameListModel, SMGameIconListModel, SMGameAdModel, SMGameTopicListModel, SMGameInfo, SMGameUser, SMGameChannelUserInfo;

@interface SMGameServices : NSObject

+ (NSString *)version;

+ (instancetype)sharedServices;

/// 注册服务
/// @param apikey 授权密钥
/// @param name 名称
+ (void)registerApiKey:(NSString *)apikey
                  name:(NSString *)name;

/// 服务授权密钥
@property (nonatomic, copy) NSString *apikey;

/// 服务授权名
@property (nonatomic, copy) NSString *name;

/// 游戏环境（0为开发环境，1为生产环境）
@property (nonatomic) int serverEnv;

/// 游戏服务端地址
@property (nonatomic, copy) NSString *serverUrl;

/// 设置用户信息
@property (nonatomic, strong) SMGameChannelUserInfo *channelUserInfo;

/// 设置语言（默认中文）
@property (nonatomic, assign) SMGameLanguage currentLanguage;

/// 是否显示陀螺仪数据（调试用，默认关闭）
@property (nonatomic, assign) BOOL sensorLogEnabled;

/// 游戏方法回调委托
@property (nonatomic, weak) id<SMGameServicesDelegate> delegate;

/// 是否解锁超级体感中心，设置为true可以无限制进入体感中心
@property (nonatomic, assign) BOOL isUnlockMotionCenter;

/// 是否是会员
@property (nonatomic, assign) BOOL isMember;

/// 是否已连接设备
@property (nonatomic, assign) BOOL isWatchConnected;

/// 上报付费页面事件
/// @param paymentPage 付费页面（1. 游戏详情付费页，2. 会员开通付费页）
/// 用户在进入付费页面时调用上报
- (void)reportPaymentPageEvent:(NSInteger)paymentPage;

/// 上报付费页面的点击事件
/// @param paymentPage 付费页面（1. 游戏详情付费页，2. 会员开通付费页）
/// @param buttonName 按钮名称（"单独购买"、"包月畅玩"、"充值"或"关闭"）
/// 用户在付费页面点击购买或者退出按钮时调用上报
- (void)reportPaymentPageClickEvent:(NSInteger)paymentPage
                             button:(NSString *)buttonName;

/// 上报付费成功事件
/// @param paymentPage 付费页面（1. 游戏详情付费页，2. 会员开通付费页）
/// @param paymentType 付费类型（"单独购买"、"包月畅玩"、"充值"）
/// @param amount 付费金额（以分为单位）
/// 用户在付费页面点击购买成功后上报
- (void)reportPaymentSuccessEvent:(NSInteger)paymentPage
                      paymentType:(NSString *)paymentType
                           amount:(NSInteger)amount;

/// 配置心率面板在哪些游戏显示
@property (nonatomic, assign) HeartRatePanelAllowedGameType heartRatePanelAllowedGameType;

@end



@interface SMGameServices (SMGameData)

/// 获取游戏用户信息
/// @param completion 游戏用户信息返回
- (void)getGameUserWithCompletion:(void (^)(SMGameUser *user, NSError *error))completion;

/// 获取完整游戏列表
/// @param completion 游戏列表结果返回
- (void)getGameListWithCompletion:(void (^)(NSArray<SMGameInfo *> *result, NSError *error))completion;

/// 获取指定游戏列表
/// @param includeGameIds 包含指定的游戏列表id，用英文逗号拼接
/// @param completion 游戏列表结果返回
- (void)getGameListByIncludeGameIds:(NSString *)includeGameIds
                     withCompletion:(void (^)(NSArray<SMGameInfo *> *result, NSError *error))completion;

/// 获取游戏分类列表
/// @param completion 游戏分类列表结果返回
- (void)getTagGameListWithCompletion:(void (^)(NSArray<SMGameListModel *> *result, NSError *error))completion;

/// 获取指定游戏的分类列表
/// @param includeGameIds 包含指定的游戏列表id，用英文逗号拼接
/// @param completion 游戏分类列表结果返回
- (void)getTagGameListByIncludeGameIds:(NSString *)includeGameIds
                        withCompletion:(void (^)(NSArray<SMGameListModel *> *result, NSError *error))completion;

/// 获取游戏Banner列表
/// @param completion 游戏Banner列表结果返回
- (void)getGameBannerListWithCompletion:(void (^)(NSArray<SMBannerGameInfo *> *result, NSError *error))completion;

/// 获取游戏icon列表
/// @param completion 游戏icon列表结果返回
- (void)getIconListWithCompletion:(void (^)(NSArray<SMGameIconListModel *> *result, NSError *error))completion;

/// 获取游戏item列表
/// @param completion 游戏item列表结果返回
- (void)getItemListWithCompletion:(void (^)(NSArray<SMGameIconListModel *> *result, NSError *error))completion;

/// 获取游戏广告列表
/// @param completion 游戏广告列表结果返回
- (void)getAdListWithCompletion:(void (^)(NSArray<SMGameAdModel *> *result, NSError *error))completion;

/// 获取游戏专题列表
/// @param completion 游戏专题列表结果返回
- (void)getTopicGameListWithCompletion:(void (^)(NSArray<SMGameTopicListModel *> *result, NSError *error))completion;

/// 获取推荐游戏列表
/// @param completion 游戏列表结果返回
- (void)getRecommendedGameListWithCompletion:(void (^)(NSArray<SMGameListModel *> *result, NSError *error))completion;

/// 游戏曝光上报，展示游戏列表的入口时上报（比如App内有一个view点击进入十米游戏，那在展示这个view时调用）
- (void)exposureReport;

@end



@interface SMGameServices (SMGameControl)

/// 启动游戏
/// @param game 通过回调获取的游戏信息
- (void)startGame:(SMGameInfo *)game;

/// 自定义UI时启动游戏
/// @param game 获取的游戏数据信息
/// @param fromItem 表示游戏数据是从哪个model对象获取的
/// fromItem类型：SMGameListModel，SMBannerGameInfo，SMGameIconListModel，SMGameAdModel，SMGameTopicListModel
- (void)startGame:(SMGameInfo *)game from:(id)fromItem;

/// 自定义UI打开体感中心游戏
/// @param baseUrl 体感中心的url
- (void)startMotionCenter:(NSString *)baseUrl;

/// 自定义UI打开专题游戏
/// @param game 对应的专题游戏
- (void)startTopicGame:(SMGameInfo *)game;

/// 自定义UI打开Web
/// @param url web url
- (void)startWeb:(NSString *)url;

/// 三轴传感器设备使用该方法发送数据
/// @param p 对应发送sensor数据的设备（固定传1）
/// @param xGravity 对应sensor数据中的X轴加速度
/// @param yGravity 对应sensor数据中的Y轴加速度
/// @param zGravity 对应sensor数据中的Z轴加速度
- (void)movePlayer:(int)p
          xGravity:(int)xGravity
          yGravity:(int)yGravity
          zGravity:(int)zGravity;

/// 六轴传感器设备使用该方法发送数据
/// @param p  对应发送sensor数据的设备（固定传1）
/// @param x 对应sensor数据中的X陀螺仪
/// @param y 对应sensor数据中的Y陀螺仪
/// @param speed 对应sensor数据中的实时速度
/// @param xThrow 对应sensor数据中的瞬间转向
/// @param yThrow 对应sensor数据中的瞬间俯仰
/// @param countThrow 对应sensor数据中的投掷计数
/// @param xGravity 对应sensor数据中的X轴加速度
/// @param yGravity 对应sensor数据中的Y轴加速度
/// @param zGravity 对应sensor数据中的Z轴加速度
- (void)movePlayer:(int)p
                 x:(int)x
                 y:(int)y
             speed:(int)speed
            xThrow:(int)xThrow
            yThrow:(int)yThrow
        countThrow:(int)countThrow
          xGravity:(int)xGravity
          yGravity:(int)yGravity
          zGravity:(int)zGravity;

/// 发送心率
/// @param bpm  心率
- (void)sentHeartRate:(NSInteger)bpm;

/// App主动关闭游戏
- (void)closeGame;

@end
