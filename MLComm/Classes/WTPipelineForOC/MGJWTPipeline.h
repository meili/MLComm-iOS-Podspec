//
// Created by wentong on 15/11/25.
//

#import <Foundation/Foundation.h>

#import "MGJWTPipelineInvocationHandle.h"

@protocol MGJWTPipeline <NSObject>

- (id <MGJWTPipelineInvocationHandle>)newInvocation;

@end