//
//  SMH5GameListView.h
//  SMH5Game
//
//  Created by Anting Li on 2023/11/30.
//

#import <UIKit/UIKit.h>

@class SMGameInfo, SMGameListModel, SMGameIconListModel;

NS_ASSUME_NONNULL_BEGIN

@interface SMH5GameListView : UIView

/// 点击游戏的回调
@property (nonatomic, copy) void(^didSelectGameBlock)(SMGameInfo *game);

/// 点击游戏标签的回调
@property (nonatomic, copy) void(^didSelectGameTagBlock)(SMGameListModel *tagGameList);

/// 点击icon标签的回调
@property (nonatomic, copy) void(^didSelectIconGameBlock)(SMGameIconListModel *iconGameList);

/// 刷新整个游戏列表
- (void)reloadView;

/// 停止视频播放
- (void)stopAllVideos;

- (void)setListViewDidAppear;
- (void)setListViewWillDisappear;

@end

NS_ASSUME_NONNULL_END
