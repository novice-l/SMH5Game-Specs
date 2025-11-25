//
//  SMBannerGameInfo.h
//  SMH5Game
//
//  Created by Anting Li on 2023/8/26.
//

#import <Foundation/Foundation.h>

@class SMGameInfo;

@interface SMBannerGameInfo : NSObject

/// 游戏id
@property (nonatomic, assign) NSInteger gameId;

/// 游戏名
@property (nonatomic, copy)   NSString *gameName;

/// 根据tagId来区分游戏类型，1：健身游戏，2：休闲游戏，3：舞蹈游戏，4：热门游戏，5:3d游戏
@property (nonatomic, assign) NSInteger tagId;

/// banner图片
@property (nonatomic, copy)   NSString *bannerImage;

/// banner视频url地址
@property (nonatomic, copy)   NSString *video;

/// banner ID
@property (nonatomic, assign) NSInteger bannerId;

/// banner名称
@property (nonatomic, copy)   NSString *bannerName;

/// banner类型，1：普通banner，3：体感中心
@property (nonatomic, assign) NSInteger bannerType;

/// banner标题
@property (nonatomic, copy)   NSString *bannerTitle;

/// 游戏数据
@property (nonatomic, strong) SMGameInfo *game;

/// 跳转H5的链接地址
@property (nonatomic, copy) NSString *redirectUrl;

/// 是否显示体感中心新手引导
@property (nonatomic, assign) BOOL showNewUserGuide;

@end
