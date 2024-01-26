#include <objc/runtime.h>


        __attribute((naked, used)) void a()      
      { /* I'm inlining asm to prevent nasty
      compilers adding useless nops :3... */     
     #ifdef __arm__ /***********************/
     asm ("bx lr;"); /**********************/    
     #else/**********:..:*******************/     
     asm("ret;");/***:    .:+***************/     
     #endif/*********:       .=*************/     
     }/**************:    .-+****************     
     ****************: .-********************     
     ****************************************     
     ****************************************    
      **************************************      
      **************************************      
         *********************************        

*/

 /*
  * We don't care if the method will ever be implemented in a subclass
  * because we don't have to worry about YouTube updating their app.
  * Hence, why IMO using method_setImplementation is fine.
 */

          /*************************************/          
        #define cnstr __attribute__((constructor))
       cnstr static void init(){Class cls; SEL name;
       /****/cls = objc_getClass("YTUpgradeWorker");
      /*****************************/name=sel_getUid(
      "startWorkWithCompletionBlock:errorBlock:");/** 
      */Method me=class_getInstanceMethod(cls, name);      
      /**/IMP imp;/*****+:..:+***********************      
      */imp = (IMP)&a;/*+:    .:=********************     
      ******************+:       .:=*****************    
      ******************+:       .-=*****************     
      ******************+:   ..-+******************** 
      ******************+:..-+***********************      
      *******************+**************************/      
      /****/method_setImplementation(me,imp);/******/
       }/*******************************************      
       *********************************************       
        *******************************************        
          ***************************************          

*/
