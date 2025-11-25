//
//  ViewController.m
//  SMH5GameDemo
//
//  Created by Anting Li on 2025/11/19.
//

#import "ViewController.h"
#import "GameListViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    // 游戏列表入口曝光上报
    [[SMGameServices sharedServices] exposureReport];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    button.backgroundColor = [UIColor systemBlueColor];
    [button setTitle:@"进入游戏列表" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(buttonAction:) forControlEvents:UIControlEventTouchUpInside];
    button.frame = CGRectMake((self.view.frame.size.width - 200) / 2, 200, 200, 44);
    button.layer.cornerRadius = 22;
    [self.view addSubview:button];
}

- (void)buttonAction:(UIButton *)button {
    GameListViewController *vc = [[GameListViewController alloc] init];
    vc.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:vc animated:YES];
}

@end
