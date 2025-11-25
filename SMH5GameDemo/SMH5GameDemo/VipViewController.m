//
//  VipViewController.m
//  SMH5GameDemo
//
//  Created by Anting Li on 2025/11/19.
//

#import "VipViewController.h"
#import <SMH5Game/SMH5Game.h>

@interface VipViewController ()

@end

@implementation VipViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"返回" style:UIBarButtonItemStylePlain target:self action:@selector(leftItemAction)];

    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    button.backgroundColor = [UIColor systemBlueColor];
    [button setTitle:@"模拟开通会员 30￥" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(paymentForVip) forControlEvents:UIControlEventTouchUpInside];
    button.frame = CGRectMake((self.view.frame.size.width - 200) / 2, 200, 200, 44);
    button.layer.cornerRadius = 22;
    [self.view addSubview:button];
    
    [SMGameServices.sharedServices reportPaymentPageEvent:2];
}

- (void)paymentForVip {
    [SMGameServices.sharedServices reportPaymentPageClickEvent:2 button:@"充值"];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        // 模拟购买成功

        [SMGameServices.sharedServices reportPaymentSuccessEvent:2 paymentType:@"充值" amount:3000];
        SMGameServices.sharedServices.isMember = YES;
    });
}

- (void)leftItemAction {
    [SMGameServices.sharedServices reportPaymentPageClickEvent:2 button:@"关闭"];
    
    [self.navigationController popViewControllerAnimated:YES];
}

@end
