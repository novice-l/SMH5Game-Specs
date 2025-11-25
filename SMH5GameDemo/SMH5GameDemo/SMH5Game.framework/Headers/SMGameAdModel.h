//
//  SMGameAdModel.h
//  SMH5Game
//
//  Created by Anting Li on 2024/3/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SMGameInfo, SMGameListModel, SMGameIconListModel;

@interface SMGameAdModel : NSObject

/// 广告跳转id
@property (nonatomic, assign) NSInteger redirectId;

/// 广告跳转类型（1.游戏，2.游戏列表，3.icon，4.H5）
@property (nonatomic, assign) NSInteger redirectType;

/// 广告跳转H5链接地址
@property (nonatomic, copy) NSString *redirectUrl;

/// 广告ID
@property (nonatomic, assign) NSInteger adId;

/// 广告图片
@property (nonatomic, copy) NSString *adUrl;

/// 广告标题
@property (nonatomic, copy) NSString *adName;

/// 广告跳转游戏时对应的游戏详情
@property (nonatomic, strong) SMGameInfo *game;

/// 广告跳转icon时对应的icon详情
@property (nonatomic, strong) SMGameIconListModel *icon;

/// 广告跳转游戏列表时对应的游戏列表详情
@property (nonatomic, strong) SMGameListModel *tag;

@end

NS_ASSUME_NONNULL_END
