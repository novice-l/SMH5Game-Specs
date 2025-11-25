//
//  SMH5GameManager.h
//  SMH5GameDemo
//
//  Created by Anting Li on 2025/11/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMH5GameManager : NSObject

+ (instancetype)sharedManager;

- (void)start;

- (void)sendGSensorX:(int)x y:(int)y z:(int)z;

@end

NS_ASSUME_NONNULL_END
