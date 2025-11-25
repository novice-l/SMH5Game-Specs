//
//  GameListViewController.m
//  SMH5GameDemo
//
//  Created by Anting Li on 2025/11/19.
//

#import "GameListViewController.h"
#import "VipViewController.h"
#import "GameInfoViewController.h"

@interface GameListViewController ()

@end

@implementation GameListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self setupCallback];
}

- (void)setupCallback {
    typeof(self) __weak weakSelf = self;
    self.didSelectGameBlock = ^(SMGameInfo * _Nonnull game) {
        __strong typeof(weakSelf) strongSelf = weakSelf;
        [strongSelf openGameInfo:game];
    };
    self.didSelectVipBlock = ^{
        __strong typeof(weakSelf) strongSelf = weakSelf;
        [strongSelf openVip];
    };
}

- (void)openGameInfo:(SMGameInfo *)game {
    GameInfoViewController *vc = [[GameInfoViewController alloc] init];
    vc.game = game;
    vc.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)openVip {
    VipViewController *vc = [[VipViewController alloc] init];
    vc.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:vc animated:YES];
}

@end
