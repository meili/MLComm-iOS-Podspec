//
// Created by <a href="mailto:wentong@mogujie.com">文通</a> on 12-8-27 上午11:38.
//


#import <Foundation/Foundation.h>

@interface NSString (TBIU_JSONToObject)

- (id)jsonToObjectWithClass:(Class)class;

- (id)jsonToObjectWithClass:(Class)class withDepth:(NSUInteger)depth;

@end