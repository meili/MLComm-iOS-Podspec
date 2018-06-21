//
//  MGJConcurrentMutableDictionary.h
//  Pods
//
//  Created by Blank on 2016/12/28.
//
//

#import <Foundation/Foundation.h>

@interface MGJConcurrentMutableDictionary<__covariant KeyType, __covariant ObjectType> : NSObject

- (instancetype)init;
- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (NSDictionary<KeyType, ObjectType> *)toNSDictionary;
- (NSMutableDictionary<KeyType, ObjectType> *)toNSMutableDictionary;

@end

@interface MGJConcurrentMutableDictionary<__covariant KeyType, __covariant ObjectType> (NSDictionary)

@property (readonly) NSUInteger count;

- (nullable ObjectType)objectForKey:(KeyType)aKey;

@end


@interface MGJConcurrentMutableDictionary<__covariant KeyType, __covariant ObjectType> (NSExtendedDictionary)

@property (readonly, copy) NSArray<KeyType> *allKeys;
@property (readonly, copy) NSArray<ObjectType> *allValues;
- (nullable ObjectType)objectForKeyedSubscript:(KeyType)key NS_AVAILABLE(10_8, 6_0);
- (void)enumerateKeysAndObjectsUsingBlock:(void (NS_NOESCAPE ^)(KeyType key, ObjectType obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(KeyType key, ObjectType obj, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);
@end


@interface MGJConcurrentMutableDictionary<__covariant KeyType, __covariant ObjectType> (NSDictionaryCreation)

+ (instancetype)concurrentDictionary;
+ (instancetype)concurrentDictionaryWithNSDictionary:(NSDictionary<KeyType, ObjectType> *)dict;
- (instancetype)initWithNSDictionary:(NSDictionary<KeyType, ObjectType> *)otherDictionary;

@end

@interface MGJConcurrentMutableDictionary<__covariant KeyType, __covariant ObjectType> (NSMutableDictionary)

- (void)removeObjectForKey:(KeyType)aKey;
- (void)setObject:(ObjectType)anObject forKey:(KeyType <NSCopying>)aKey;

@end

@interface MGJConcurrentMutableDictionary<__covariant KeyType, __covariant ObjectType> (NSExtendedMutableDictionary)

- (void)addEntriesFromDictionary:(NSDictionary<KeyType, ObjectType> *)otherDictionary;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray<KeyType> *)keyArray;
- (void)setObject:(nullable ObjectType)obj forKeyedSubscript:(KeyType <NSCopying>)key NS_AVAILABLE(10_8, 6_0);

@end
