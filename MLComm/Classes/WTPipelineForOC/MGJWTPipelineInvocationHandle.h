//
// Created by wentong on 15/11/25.
//

#import <Foundation/Foundation.h>
#import "MGJWTPipelineStates.h"
#import "MGJWTCancelable.h"

@protocol MGJWTPipelineInvocationHandle <MGJWTPipelineStates, MGJWTCancelable>

- (void)invoke;

//异步的的一些await
- (void)wait;

- (BOOL)waitUntilDate:(NSDate *)limit;
@end