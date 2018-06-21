//
// Created by Zephyrleaves on 15/11/25.
//

#import <Foundation/Foundation.h>
#import "MGJWTPipelineContext.h"
#import "MGJWTPipelineInvocationHandle.h"
#import "MGJWTBasicValve.h"


@interface MGJWTDefaultPipelineContext : NSObject <MGJWTPipelineContext, MGJWTBasicPipelineContext,
        MGJWTPipelineInvocationHandle>
- (instancetype)initWithValves:(NSArray *)valves
                    valveIndex:(NSDictionary *)valveIndex
                    basicValve:(id <MGJWTBasicValve>)basicValve;

+ (instancetype)contextWithValves:(NSArray *)valves
                       valveIndex:(NSDictionary *)valveIndex
                       basicValve:(id <MGJWTBasicValve>)basicValve;

@end