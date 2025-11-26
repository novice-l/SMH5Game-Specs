//
//  SMH5GameManager.m
//  SMH5GameDemo
//
//  Created by Anting Li on 2025/11/19.
//

#import "SMH5GameManager.h"
#import <SMH5Game/SMH5Game.h>

@interface SMH5GameManager () <SMGameServicesDelegate>

@end

@implementation SMH5GameManager

+ (instancetype)sharedManager {
    static SMH5GameManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager = [[SMH5GameManager alloc] init];
    });
    
    return manager;
}

- (void)start {
    // 注册服务并设置游戏监听
    // 在此替换为自己的key和name
    [SMGameServices registerApiKey:@"dGhpcyBpcyBhIGV4YW1wbGVVeko0VTFFeGJGZFVXR3hWVjBkb2NWVnNaRk5oUmxaeFUycFNhVTkWFdIQlRZa1pLYzJ" name:@"超级app"];
    SMGameServices.sharedServices.delegate = self;
    
    // 设置用户信息，不设置默认临时用户
    NSString *userId   = @"12345678";
    NSString *userName = @"测试";
    NSString *portrait = @"https://avatar.iran.liara.run/public";
    SMGameChannelUserInfo *userInfo = [SMGameChannelUserInfo userWithUserId:userId userName:userName portrait:portrait];
    userInfo.age = 30; // 年龄可以不用设置
    SMGameServices.sharedServices.channelUserInfo = userInfo;
    
    // 设置语言（默认中文）
    SMGameServices.sharedServices.currentLanguage = SMGameLanguageZH;
}

- (void)sendGSensorX:(int)x y:(int)y z:(int)z {
    [SMGameServices.sharedServices movePlayer:1 xGravity:x yGravity:y zGravity:z];
}

#pragma mark - SMGameServicesDelegate

- (void)needOpenGSensor {
    // 在这里开启硬件的陀螺仪
}

- (void)needCloseGSensor {
    // 在这里关闭硬件的陀螺仪
}

@end
