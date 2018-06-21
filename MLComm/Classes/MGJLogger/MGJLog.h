//
//  MGJLog.h
//  MGJFoundation
//
//  Created by yongtai on 4/16/15.
//  Copyright (c) 2014 juangua. All rights reserved.
//


#define LOG_LEVEL_DEF [MGJLogger logLevel]

#import <Foundation/Foundation.h>

extern NSInteger const MGJLogContextDefault;

typedef NS_OPTIONS(NSUInteger, MGJDDLogFlag){
    /**
     *  0...00001 DDLogFlagError
     */
    MGJDDLogFlagError      = (1 << 0),
    
    /**
     *  0...00010 DDLogFlagWarning
     */
    MGJDDLogFlagWarning    = (1 << 1),
    
    /**
     *  0...00100 DDLogFlagInfo
     */
    MGJDDLogFlagInfo       = (1 << 2),
    
    /**
     *  0...01000 DDLogFlagDebug
     */
    MGJDDLogFlagDebug      = (1 << 3),
    
    /**
     *  0...10000 DDLogFlagVerbose
     */
    MGJDDLogFlagVerbose    = (1 << 4)
};

/**
 *  Log levels are used to filter out logs. Used together with flags.
 */
typedef NS_ENUM(NSUInteger, MGJDDLogLevel){
    /**
     *  No logs
     */
    MGJDDLogLevelOff       = 0,
    
    /**
     *  Error logs only
     */
    MGJDDLogLevelError     = (MGJDDLogFlagError),
    
    /**
     *  Error and warning logs
     */
    MGJDDLogLevelWarning   = (MGJDDLogLevelError   | MGJDDLogFlagWarning),
    
    /**
     *  Error, warning and info logs
     */
    MGJDDLogLevelInfo      = (MGJDDLogLevelWarning | MGJDDLogFlagInfo),
    
    /**
     *  Error, warning, info and debug logs
     */
    MGJDDLogLevelDebug     = (MGJDDLogLevelInfo    | MGJDDLogFlagDebug),
    
    /**
     *  Error, warning, info, debug and verbose logs
     */
    MGJDDLogLevelVerbose   = (MGJDDLogLevelDebug   | MGJDDLogFlagVerbose),
    
    /**
     *  All logs (1...11111)
     */
    MGJDDLogLevelAll       = NSUIntegerMax
};


@interface MGJLogger : NSObject
+ (void)log:(BOOL)asynchronous
       flag:(MGJDDLogFlag)flag
    context:(NSInteger)context
       file:(const char *)file
   function:(const char *)function
       line:(NSUInteger)line
        tag:(id)tag
     format:(NSString *)format, ... NS_FORMAT_FUNCTION(8,9);

+ (instancetype)sharedInstance;

- (MGJDDLogLevel)logLevel;
- (void)setLogLevel:(MGJDDLogLevel)level;
@end



#define MGJ_LOG_MACRO(isAsynchronous, flg, ctx, atag, fnct, frmt, ...) \
        [MGJLogger log : isAsynchronous                                     \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]


#define MGJLogCommon(flag, context, tag, frmt, ...) MGJ_LOG_MACRO(YES, flag,  context, tag, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define MGJError(context, frmt, ...)	MGJLogCommon(MGJDDLogFlagError, context, nil, frmt, ##__VA_ARGS__)
#define MGJWarning(context, frmt, ...)	MGJLogCommon(MGJDDLogFlagWarning, context, nil, frmt, ##__VA_ARGS__)
#define MGJInfo(context, frmt, ...)	    MGJLogCommon(MGJDDLogFlagInfo, context, nil, frmt, ##__VA_ARGS__)
#define MGJDebug(context, frmt, ...)	MGJLogCommon(MGJDDLogFlagDebug, context, nil, frmt, ##__VA_ARGS__)
#define MGJVerbose(context, frmt, ...)	MGJLogCommon(MGJDDLogFlagVerbose, context, nil, frmt, ##__VA_ARGS__)

#define MGJLog(frmt, ...) MGJDebug(MGJLogContextDefault, frmt, ##__VA_ARGS__)
#define MGJLogDebug(frmt, ...) MGJDebug(MGJLogContextDefault, frmt, ##__VA_ARGS__)
#define MGJLogInfo(frmt, ...) MGJInfo(MGJLogContextDefault, frmt, ##__VA_ARGS__)
#define MGJLogWarning(frmt, ...) MGJWarning(MGJLogContextDefault, frmt, ##__VA_ARGS__)
#define MGJLogError(frmt, ...) MGJError(MGJLogContextDefault, frmt, ##__VA_ARGS__)
#define MGJLogAlert(frmt, ...) MGJError(MGJLogContextDefault, frmt, ##__VA_ARGS__)
#define MGJLogVerbose(frmt, ...) MGJVerbose(MGJLogContextDefault, frmt, ##__VA_ARGS__)


