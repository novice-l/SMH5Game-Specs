//
//  SMH5GameTagListView.h
//  SMH5Game
//
//  Created by Anting Li on 2023/11/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SMGameInfo, SMGameListModel;

@interface SMH5GameTagListView : UIView

/// 通过游戏列表的标签点击回调获取到对应的标签游戏列表数据，然后设置该属性
@property (nonatomic, strong) SMGameListModel *listModel;

/// 点击游戏的回调
@property (nonatomic, copy) void(^didSelectGameBlock)(SMGameInfo *game);

@end

NS_ASSUME_NONNULL_END
