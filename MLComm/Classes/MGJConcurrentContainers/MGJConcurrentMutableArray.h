//
//  MGJConcurrentMutableArray.h
//  Pods
//
//  Created by Blank on 2016/12/27.
//
//

#import <Foundation/Foundation.h>

@interface MGJConcurrentMutableArray<__covariant ObjectType> : NSObject

- (instancetype)init;
- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (NSArray<ObjectType> *)toNSArray;
- (NSMutableArray<ObjectType> *)toNSMutableArray;

@end

@interface MGJConcurrentMutableArray<__covariant ObjectType>(NSArray)

@property (readonly) NSUInteger count;
- (ObjectType)objectAtIndex:(NSUInteger)index;

@end

@interface MGJConcurrentMutableArray<__covariant ObjectType> (NSExtendedArray)

- (ObjectType)objectAtIndexedSubscript:(NSUInteger)idx;
- (void)enumerateObjectsUsingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);
@end

@interface MGJConcurrentMutableArray<__covariant ObjectType> (NSArrayCreation)

+ (instancetype)concurrentArray;
+ (instancetype)concurrentArrayWithNSArray:(NSArray<ObjectType> *)array;
- (instancetype)initWithNSArray:(NSArray<ObjectType> *)array;

@end

@interface MGJConcurrentMutableArray<__covariant ObjectType> (NSMutableArray)

- (void)addObject:(ObjectType)anObject;
- (void)insertObject:(ObjectType)anObject atIndex:(NSUInteger)index;
- (void)removeLastObject;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(ObjectType)anObject;

@end

@interface MGJConcurrentMutableArray<__covariant ObjectType> (NSExtendedMutableArray)

- (void)setObject:(ObjectType)obj atIndexedSubscript:(NSUInteger)idx;

@end
