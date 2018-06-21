//
// Created by <a href="mailto:wentong@mogujie.com">文通</a> on 12-8-27 下午12:20.
//


#import <Foundation/Foundation.h>
#import <objc/runtime.h>


#ifndef DEFAULT_CACHE_CLASS_SIZE
#define DEFAULT_CACHE_CLASS_SIZE 10
#endif


typedef enum {
    TBIU_CHAR, TBIU_UNSIGNED_CHAR, TBIU_SHORT, TBIU_UNSIGNED_SHORT, TBIU_INT, TBIU_UNSIGNED, TBIU_LONG, TBIU_UNSIGNED_LONG,
    TBIU_LONG_LONG, TBIU_UNSIGNED_LONG_LONG, TBIU_DOUBLE, TBIU_FLOAT, TBIU_C_BOOL,
    TBIU_ID, TBIU_STRUCT, TBIU_FUNC, TBIU_BLOCK, TBIU_INT_P, TBIU_VOID_P, TBIU_CHAR_P, TBIU_NIL
} TBIU_TypeOfProperty;

@protocol TBIUTransient
@end

@interface PropertyAttributeInfo : NSObject
@property BOOL transient;
@property BOOL readOnly;
@property TBIU_TypeOfProperty type;
@property Class clazz;
@property Class arrayClass;
@property(nonatomic, copy) NSString *dicPropertyName;
@property(nonatomic, copy) NSString *oriPropertyName;

@property SEL getter;
@property SEL setter;

@property(nonatomic, strong) NSArray *protocols;


+ (PropertyAttributeInfo *)analyseProperty:(objc_property_t)pProperty
                                 WithClass:(Class)aClass
                       AndWithCurrentClass:(Class)currentClass;

+ (void)enumerateClassProperties:(Class)aClass
                   withInfoBlock:(void (^)(Class oriClass, Class currentClass, PropertyAttributeInfo *info))infoBlock;

+ (id)getValue:(id)obj with:(PropertyAttributeInfo *)info;

+ (NSArray *)getProtocolsFromClass:(Class)clazz;

@end

@interface PropertyAttributeInfoCache : NSObject

+ (PropertyAttributeInfoCache *)instance;

- (PropertyAttributeInfo *)getFromCacheWithClass:(Class)class AndPropertyName:(NSString *)name;

- (void)putToCacheWithClass:(Class)class AndPropertyName:(NSString *)name WithInfo:(PropertyAttributeInfo *)info;

@end