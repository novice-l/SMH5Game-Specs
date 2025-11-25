//
//  SMGameInfo.h
//  SMH5Game
//
//  Created by Developer on 2022/8/2.
//

#import <Foundation/Foundation.h>

/**
 游戏信息类
 */
@interface SMGameInfo : NSObject <NSSecureCoding, NSCopying>

/// 游戏id
@property (nonatomic, assign) NSInteger gid;

/// 游戏类型 3：健身游戏，4: 舞蹈游戏，88: 体感中心游戏，99: cps游戏
@property (nonatomic, assign) NSInteger gameType;

/// 根据tagId来区分游戏分类，1：健身游戏，2：休闲游戏，3：舞蹈游戏，4：热门游戏，5:3d游戏
@property (nonatomic, assign) NSInteger tagId;

/// 游戏版本
@property (nonatomic, assign) NSInteger gameVersion;

/// 游戏名
@property (nonatomic, copy)   NSString *gname;

/// 游戏背景图
@property (nonatomic, copy)   NSString *background;

/// 游戏角标
@property (nonatomic, copy)   NSString *angleMark;

/// 游玩人数
@property (nonatomic, assign) NSInteger playNum;

/// 游戏标题
@property (nonatomic, copy)   NSString *title;

/// 游戏简介
@property (nonatomic, copy)   NSString *details;

/// 游戏标签 "标签1,标签2,标签3"
@property (nonatomic, copy)   NSString *label;

/// 游戏banner图片地址 "地址1,地址2"
@property (nonatomic, copy)   NSString *urls;

/// H5游戏资源下载地址或者网页地址
@property (nonatomic, copy)   NSString *resourceUrl;

/// 体感中心游戏完整url地址
@property (nonatomic, copy)   NSString *fullResourceUrl;

/// 是否横屏游戏，0或1：竖屏，2：横屏
@property (nonatomic, assign) NSInteger vertical;

/// 游戏手表按键模式
@property (nonatomic, assign) NSInteger keyboard;
/// 游戏难度
@property (nonatomic, assign) NSInteger hardLevel;

/// 是否需要vip
@property (nonatomic, assign) BOOL needVip;

@end



@interface SMGameInfo ()

@property (nonatomic, copy)   NSString *tag;
@property (nonatomic, copy)   NSString *modeGifUrl;
@property (nonatomic, copy)   NSString *modeDesc;
@property (nonatomic, assign) NSInteger timestamp;

@end
