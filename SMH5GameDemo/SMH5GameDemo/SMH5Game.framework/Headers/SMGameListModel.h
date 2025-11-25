//
//  SMGameListModel.h
//  SMH5Game
//
//  Created by Anting Li on 2023/8/26.
//

#import <Foundation/Foundation.h>

@class SMGameInfo;

typedef NS_ENUM(NSUInteger, SMGameTagListViewType) {
    SMGameTagListViewTypeRecommended,
    SMGameTagListViewTypeHot,
    SMGameTagListViewTypeMustPlay,
    SMGameTagListViewTypeRelaxed,
    SMGameTagListViewTypeDanceFitness,
    SMGameTagListViewTypeFree,
    SMGameTagListViewTypeIcon,
};

@interface SMGameListModel : NSObject

@property (nonatomic, copy) NSArray<SMGameInfo *> *gameList;

/// 游戏列表分类
/// 1：健身游戏，2：休闲游戏，3：舞蹈游戏，4：热门游戏，5：3d游戏，6：H5游戏
@property (nonatomic, assign) NSInteger tagId;

@property (nonatomic, copy) NSString *tagName;

/// 游戏列表分组（SDK内部使用）
@property (nonatomic, assign) SMGameTagListViewType viewType;

@end



@interface SMGameIconListModel : SMGameListModel

@property (nonatomic, assign) NSInteger iconId;

@property (nonatomic, copy) NSString *iconName;

/// icon跳转的页面（1.普通游戏列表，2.vip特权页，3.体感中心，4.排行榜，5.新游列表，6.新会员权益，7.游玩历史，8.操作指南）
@property (nonatomic, assign) NSInteger iconPage;

/// 体感中心时对应的base url
@property (nonatomic, copy) NSString *iconRedirectUrl;

/// 是否显示体感中心新手引导
@property (nonatomic, assign) BOOL showNewUserGuide;

@property (nonatomic, copy) NSString *iconPageTitle;

@property (nonatomic, copy) NSString *iconUrl;

@property (nonatomic, copy) NSString *tagDisplayName;

@end
