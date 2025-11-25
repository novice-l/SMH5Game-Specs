//
//  GameInfoViewController.m
//  SMH5GameDemo
//
//  Created by Anting Li on 2025/11/19.
//

#import "GameInfoViewController.h"

@interface GameInfoViewController ()

@property (nonatomic, strong) UILabel *label;
@property (nonatomic, strong) UILabel *descLabel;
@property (nonatomic, strong) UIButton *playButton;
@property (nonatomic, strong) UIButton *buyButton;
@property (nonatomic, strong) UIButton *monthButton;

@end

@implementation GameInfoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"返回" style:UIBarButtonItemStylePlain target:self action:@selector(leftItemAction)];
    
    UILabel *label = [[UILabel alloc] init];
    label.text = self.game.gname;
    label.textAlignment = NSTextAlignmentCenter;
    label.font = [UIFont systemFontOfSize:18];
    [label sizeToFit];
    [self.view addSubview:label];
    self.label = label;
    
    UILabel *descLabel = [[UILabel alloc] init];
    descLabel.text = self.game.details;
    descLabel.font = [UIFont systemFontOfSize:14];
    descLabel.numberOfLines = 0;
    [self.view addSubview:descLabel];
    self.descLabel = descLabel;
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:@"点击打开游戏" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    button.titleLabel.font = [UIFont systemFontOfSize:18];
    [self.view addSubview:button];
    [button addTarget:self action:@selector(playButtonAction:) forControlEvents:UIControlEventTouchUpInside];
    button.layer.cornerRadius = 22;
    button.backgroundColor = [UIColor systemBlueColor];
    self.playButton = button;
    
    UIButton *buyButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [buyButton setTitle:@"购买游戏 2￥" forState:UIControlStateNormal];
    [buyButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    buyButton.titleLabel.font = [UIFont systemFontOfSize:18];
    [self.view addSubview:buyButton];
    [buyButton addTarget:self action:@selector(buyButtonAction:) forControlEvents:UIControlEventTouchUpInside];
    buyButton.layer.cornerRadius = 22;
    buyButton.backgroundColor = [UIColor systemBlueColor];
    self.buyButton = buyButton;
    
    UIButton *monthButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [monthButton setTitle:@"包月畅玩 12￥" forState:UIControlStateNormal];
    [monthButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    monthButton.titleLabel.font = [UIFont systemFontOfSize:18];
    [self.view addSubview:monthButton];
    [monthButton addTarget:self action:@selector(monthButtonAction:) forControlEvents:UIControlEventTouchUpInside];
    monthButton.layer.cornerRadius = 22;
    monthButton.backgroundColor = [UIColor systemBlueColor];
    self.monthButton = monthButton;
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    
    self.label.center = CGPointMake(self.view.frame.size.width / 2, 100);
    CGSize size = [self.descLabel sizeThatFits:CGSizeMake(self.view.frame.size.width - 64, CGFLOAT_MAX)];
    self.descLabel.frame = CGRectMake(32, CGRectGetMaxY(self.label.frame) + 22, self.view.frame.size.width - 64, size.height);
    self.buyButton.frame = CGRectMake((self.view.frame.size.width - 200) / 2, 400, 200, 44);
    self.monthButton.frame = CGRectMake((self.view.frame.size.width - 200) / 2, 470, 200, 44);
    self.playButton.frame = CGRectMake((self.view.frame.size.width - 200) / 2, 540, 200, 44);
}

- (void)leftItemAction {
    [SMGameServices.sharedServices reportPaymentPageClickEvent:1 button:@"关闭"];
    
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)playButtonAction:(UIButton *)button {
    [SMGameServices.sharedServices startGame:self.game];
}

- (void)buyButtonAction:(UIButton *)button {
    [SMGameServices.sharedServices reportPaymentPageClickEvent:1 button:@"单独购买"];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        // 模拟购买成功
        [SMGameServices.sharedServices reportPaymentSuccessEvent:1 paymentType:@"单独购买" amount:200];
    });
}

- (void)monthButtonAction:(UIButton *)button {
    [SMGameServices.sharedServices reportPaymentPageClickEvent:1 button:@"包月畅玩"];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        // 模拟购买成功
        SMGameServices.sharedServices.isMember = YES;
        [SMGameServices.sharedServices reportPaymentSuccessEvent:1 paymentType:@"包月畅玩" amount:1200];
    });
}

@end
