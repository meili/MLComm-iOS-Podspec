//
// Created by wentong on 15/11/25.
//

#import <Foundation/Foundation.h>
#import "MGJWTLabelable.h"
#import "MGJWTBasicPipelineContext.h"

@protocol MGJWTBasicValve <MGJWTLabelable>

@required
- (void)invoke:(id <MGJWTBasicPipelineContext>)pipelineContext;
@end