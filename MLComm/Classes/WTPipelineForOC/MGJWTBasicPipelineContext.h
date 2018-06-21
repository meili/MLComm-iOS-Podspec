//
// Created by wentong on 15/11/25.
//

#import <Foundation/Foundation.h>

#import "MGJWTPipelineStates.h"

@protocol MGJWTCancelable;

@protocol MGJWTBasicPipelineContext <MGJWTPipelineStates>

- (void)invokeNext;

//增加一个可被取消的行为,在自己被终止的时候也能去终止下面的行为
- (void)addCancelable:(id <MGJWTCancelable>)cancelable;

//不需要被cancel的时候 移除
- (void)removeCancelable:(id <MGJWTCancelable>)cancelable;
@end