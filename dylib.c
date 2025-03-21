#include <objc/runtime.h>
#include <objc/message.h>

__attribute((used)) static id hook_YTVersionUtils_appVersionLong(void) {
    Class NSStringClass = objc_getClass("NSString");

    SEL allocSelector = sel_getUid("alloc");
    SEL initSelector = sel_getUid("initWithUTF8String:");

    id stringObject = ((id (*)(Class, SEL))objc_msgSend)(NSStringClass, allocSelector);
    
    stringObject = ((id (*)(id, SEL, const char *))objc_msgSend)(stringObject, initSelector, "19.01.1");

    return stringObject;
}

__attribute((naked, used)) static void hook_YTUpgradeWorker_updateCheck(void) {
    /* inlining asm to prevent nasty compilers adding useless nops... */
    #ifdef __arm__
    asm ("bx lr;");
    #else
    asm ("ret;");
    #endif
}

__attribute__((constructor)) static void init() {
    /*
     * We don't care if the method will ever be implemented in a subclass
     * because we don't have to worry about YouTube updating their app.
     * Hence, why IMO using method_setImplementation is fine.
    */
    Class cls = objc_getClass("YTUpgradeWorker"); /* wrapper around look_up_class */
    SEL name = sel_getUid("startWorkWithCompletionBlock:errorBlock:"); /* perhaps this can be done via dyld_get_objc_selector ? */
    Method meth = class_getInstanceMethod(cls, name);
    IMP imp = (IMP)&hook_YTUpgradeWorker_updateCheck;
    method_setImplementation(meth, imp); /* this function already checks meth for nil so this is safe */

    Class versionUtilsClass = objc_getClass("YTVersionUtils");
    SEL versionSel = sel_getUid("appVersionLong");

    Method versionMethod = class_getClassMethod(versionUtilsClass, versionSel);

    IMP versionImp = (IMP)&hook_YTVersionUtils_appVersionLong;
    method_setImplementation(versionMethod, versionImp);
}