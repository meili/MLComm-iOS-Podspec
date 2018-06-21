//
// Created by wentong on 15/11/25.
//

#import <Foundation/Foundation.h>

@protocol MGJWTPipelineStates <NSObject>

@property(readonly) BOOL isFinished;

@property(readonly) BOOL isBroken;

@property(readonly) BOOL isCanceled;

@property(readonly) NSMutableDictionary<NSString *, id> *userInfo;

@property(readonly) NSMutableDictionary<NSString *, id> *userInfoForCurrentValve;

//理论上应该是外部的Context来持有Pipeline的上下文
@property(nonatomic, strong) id outerContext;

- (void)setWeakOutContext:(id)outContext;


/**
 *  @author kongkong
 *
 *  @brief 获取当前阀门
 */
-(id)currentValve;
@end