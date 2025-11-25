//
//  SMH5VipGameTagListView.h
//  SMH5Game
//
//  Created by Anting Li on 2024/3/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SMGameIconListModel, SMGameInfo;

@interface SMH5VipGameTagListView : UIView

/// 通过icon标签或者广告标签点击回调获取到获取到跳转到vip，设置该属性
@property (nonatomic, strong) SMGameIconListModel *vipModel;

/// 点击游戏的回调
@property (nonatomic, copy) void(^didSelectGameBlock)(SMGameInfo *game);

/// 点击开通vip的回调
@property (nonatomic, copy) void(^didSelectVipBlock)(void);

@end

NS_ASSUME_NONNULL_END
