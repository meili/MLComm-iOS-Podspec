//
// Created by wentong on 15/11/25.
//

#import <Foundation/Foundation.h>
#import "MGJWTBasicPipelineContext.h"

@protocol MGJWTPipelineContext <MGJWTBasicPipelineContext>

//如果返回NO 表示没有找到对应的label
- (BOOL)gotoLabelAndInvoke:(NSString *)label;

- (void)breakPipeline;
@end