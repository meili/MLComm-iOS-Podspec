//
// Created by wentong on 15/11/25.
//

#import <Foundation/Foundation.h>
#import "MGJWTLabelable.h"
#import "MGJWTPipelineContext.h"

@protocol MGJWTValve <MGJWTLabelable>

@required
- (void)invoke:(id <MGJWTPipelineContext>)pipelineContext;

@end