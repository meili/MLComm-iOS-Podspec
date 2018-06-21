//
//  MGJConcurrentMutableSet.h
//  Pods
//
//  Created by Blank on 2016/12/29.
//
//

#import <Foundation/Foundation.h>

@interface MGJConcurrentMutableSet<__covariant ObjectType> : NSObject

- (instancetype)init;
- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (NSSet<ObjectType> *)toNSSet;
- (NSMutableSet<ObjectType> *)toNSMutableSet;

@end

@interface MGJConcurrentMutableSet<__covariant ObjectType> (NSSet)

@property (readonly) NSUInteger count;

@end

@interface MGJConcurrentMutableSet<__covariant ObjectType> (NSExtendedSet)

@property (readonly, copy) NSArray<ObjectType> *allObjects;
- (BOOL)containsObject:(ObjectType)anObject;
- (void)enumerateObjectsUsingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, BOOL *stop))block;

@end

@interface MGJConcurrentMutableSet<__covariant ObjectType> (NSSetCreation)

+ (instancetype)concurrentSet;
+ (instancetype)concurrentSetWithNSSet:(NSSet<ObjectType> *)set;
+ (instancetype)concurrentSetWithNSArray:(NSArray<ObjectType> *)array;

- (instancetype)initWithNSSet:(NSSet<ObjectType> *)set;
- (instancetype)initWithNSArray:(NSArray<ObjectType> *)array;

@end


@interface MGJConcurrentMutableSet<__covariant ObjectType> (NSMutableSet)

- (void)addObject:(ObjectType)object;
- (void)removeObject:(ObjectType)object;

@end

@interface MGJConcurrentMutableSet<__covariant ObjectType> (NSExtendedMutableSet)

- (void)addObjectsFromNSArray:(NSArray<ObjectType> *)array;
- (void)removeAllObjects;

@end

