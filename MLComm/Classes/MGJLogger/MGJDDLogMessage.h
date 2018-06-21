//
//  MGJDDLogMessage.h
//  MLComm
//
//  Created by gairui on 2018/5/22.
//

#import <Foundation/Foundation.h>


@interface MGJDDLogMessage : NSObject <NSCopying>
{
    // Direct accessors to be used only for performance
@public
    NSString *_message;
    NSInteger _level;
    NSInteger _flag;
    NSInteger _context;
    NSString *_file;
    NSString *_fileName;
    NSString *_function;
    NSUInteger _line;
    id _tag;
    NSInteger _options;
    NSDate *_timestamp;
    NSString *_threadID;
    NSString *_threadName;
    NSString *_queueLabel;
}

/**
 *  Default `init` for empty messages.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Standard init method for a log message object.
 * Used by the logging primitives. (And the macros use the logging primitives.)
 *
 * If you find need to manually create logMessage objects, there is one thing you should be aware of:
 *
 * If no flags are passed, the method expects the file and function parameters to be string literals.
 * That is, it expects the given strings to exist for the duration of the object's lifetime,
 * and it expects the given strings to be immutable.
 * In other words, it does not copy these strings, it simply points to them.
 * This is due to the fact that __FILE__ and __FUNCTION__ are usually used to specify these parameters,
 * so it makes sense to optimize and skip the unnecessary allocations.
 * However, if you need them to be copied you may use the options parameter to specify this.
 *
 *  @param message   the message
 *  @param level     the log level
 *  @param flag      the log flag
 *  @param context   the context (if any is defined)
 *  @param file      the current file
 *  @param function  the current function
 *  @param line      the current code line
 *  @param tag       potential tag
 *  @param options   a bitmask which supports DDLogMessageCopyFile and DDLogMessageCopyFunction.
 *  @param timestamp the log timestamp
 *
 *  @return a new instance of a log message model object
 */
- (instancetype)initWithMessage:(NSString *)message
                          level:(NSInteger)level
                           flag:(NSInteger)flag
                        context:(NSInteger)context
                           file:(NSString *)file
                       function:(NSString * __nullable)function
                           line:(NSUInteger)line
                            tag:(id __nullable)tag
                        options:(NSInteger)options
                      timestamp:(NSDate * __nullable)timestamp NS_DESIGNATED_INITIALIZER;

/**
 * Read-only properties
 **/

/**
 *  The log message
 */
@property (readonly, nonatomic) NSString *message;
@property (readonly, nonatomic) NSInteger level;
@property (readonly, nonatomic) NSInteger flag;
@property (readonly, nonatomic) NSInteger context;
@property (readonly, nonatomic) NSString *file;
@property (readonly, nonatomic) NSString *fileName;
@property (readonly, nonatomic) NSString * __nullable function;
@property (readonly, nonatomic) NSUInteger line;
@property (readonly, nonatomic) id __nullable tag;
@property (readonly, nonatomic) NSInteger options;
@property (readonly, nonatomic) NSDate *timestamp;
@property (readonly, nonatomic) NSString *threadID; // ID as it appears in NSLog calculated from the machThreadID
@property (readonly, nonatomic) NSString *threadName;
@property (readonly, nonatomic) NSString *queueLabel;

@end

