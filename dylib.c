#include <objc/runtime.h>


          /*************************************/          
        #define zd __attribute__((constructor)) //
       __attribute((naked, used)) static void/**/a()
       { /* in-lining asm to prevent nasty compilers
      from adding useless NOP's and other junk :3c */
      #ifdef __arm__ /*sadly i cant add more code  */
      asm ("bx lr;");/*on separate lines after #'s */   
      #else/*********+:..:+*************************/    
      asm ("ret;");/****+:    .:=*******************/    
      #endif/***********+:       .:=****************/  
      }/****************+:       .-=****************/     
      zd static void /**+:   ..-+*/ init(){Class cls;
      SEL name; /*******+:..-+**/ Method me; IMP imp;      
      /***/cls=objc_getClass("YTUpgradeWorker");/***/
      /****************************/name=sel_getUid(
       "startWorkWithCompletionBlock:errorBlock:" );      
       me=class_getInstanceMethod(cls, name);imp=&a;       
        method_setImplementation(me,imp);/********/     
          /************************************/}          
