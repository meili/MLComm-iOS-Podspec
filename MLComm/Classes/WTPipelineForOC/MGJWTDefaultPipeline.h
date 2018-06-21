//
// Created by wentong on 15/11/25.
//

#import <Foundation/Foundation.h>
#import "MGJWTPipeline.h"
#import "MGJWTValve.h"
#import "MGJWTBasicValve.h"

@interface MGJWTDefaultPipeline : NSObject <MGJWTPipeline>
- (instancetype)initWithValves:(NSArray<id <MGJWTValve>> *)valves basicValve:(id <MGJWTBasicValve>)basicValve;

+ (instancetype)pipelineWithValves:(NSArray<id <MGJWTValve>> *)valves basicValve:(id <MGJWTBasicValve>)basicValve;

@end