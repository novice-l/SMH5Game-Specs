//
//  SMGameTopicListModel.h
//  SMH5Game
//
//  Created by Anting Li on 2025/8/13.
//

#import <Foundation/Foundation.h>

@class SMGameInfo;

@interface SMGameTopicListModel : NSObject

@property (nonatomic, copy) NSArray<SMGameInfo *> *games;

@property (nonatomic, assign) NSInteger tagId;

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *nameEn;

@property (nonatomic, assign) NSInteger sequence;

@end
