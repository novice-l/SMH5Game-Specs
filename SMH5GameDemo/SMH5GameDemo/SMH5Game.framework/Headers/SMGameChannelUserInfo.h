//
//  SMGameChannelUserInfo.h
//  SMH5Game
//
//  Created by Developer on 2022/8/4.
//

#import <Foundation/Foundation.h>

@interface SMGameChannelUserInfo : NSObject

/// 用户id
@property (nonatomic, copy) NSString *userId;

/// 用户昵称
@property (nonatomic, copy) NSString *userName;

/// 用户头像地址
@property (nonatomic, copy) NSString *portrait;

/// 用户年龄
@property (nonatomic, assign) NSInteger age;

/// 初始化用户信息
/// @param userId      用户id
/// @param userName 用户昵称
/// @param portrait 用户头像地址
/// @return 用户信息对象
+ (instancetype)userWithUserId:(NSString *)userId
                      userName:(NSString *)userName
                      portrait:(NSString *)portrait;

@end



@interface SMGameUser : NSObject <NSCopying, NSSecureCoding>

/// 游戏用户id
@property (nonatomic, copy) NSString *userId;

/// 游戏用户名
@property (nonatomic, copy) NSString *userName;

/// 游戏用户头像
@property (nonatomic, copy) NSString *portrait;

/// 游戏用户token
@property (nonatomic, copy) NSString *userToken;

/// 游戏服务校验token
@property (nonatomic, copy) NSString *otpToken;

@end
