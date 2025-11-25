//
//  SMH5GameListRootViewController.h
//  SMH5Game
//
//  Created by Anting Li on 2024/7/3.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SMGameInfo;

@interface SMH5GameListRootViewController : UIViewController

/// 设置导航栏的返回按钮图片
@property (nonatomic, strong) UIImage *backImage;

/// 设置显示预留的顶部标题和信息流广告空位
@property (nonatomic, strong) UIView *topView;

/// 点击游戏的回调
/// App可以在该回调中跳转到游戏详情页
@property (nonatomic, copy) void(^didSelectGameBlock)(SMGameInfo *game);

/// 打开游戏的回调
/// App可以在该回调中根据是否连接了设备来决定是否打开游戏
@property (nonatomic, copy) void(^didOpenGameBlock)(SMGameInfo *game);

/// 点击开通vip的回调
/// App可以在该回调中跳转到会员开通页
@property (nonatomic, copy) void(^didSelectVipBlock)(void);

@end

NS_ASSUME_NONNULL_END
