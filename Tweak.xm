#import <UIKit/UIKit.h>
#include <objc/runtime.h>

@interface YTAlertView : UIView
@end

@interface GOODialogView : UIView
-(UILabel *)titleLabel;
-(UILabel *)subtitleLabel;
@end

void let_me_pass(UIView *view) {
 id currentView = view;
 while (![currentView isMemberOfClass:objc_getClass("UIWindow")]) {
  currentView = [currentView superview];
 }
 UIWindow *window = currentView;
 [window setHidden:YES];
}

/* This could be improved prob but it works, I'll improve it later */
%hook YTAlertView
-(void)didMoveToWindow {
 %orig;
 if (self) {
  NSArray *alertViewSubviews = [self subviews];
  for (id subview in alertViewSubviews) {
   if ([subview isMemberOfClass:objc_getClass("GOODialogView")]) {
    /* subview is GOODialogView, check titleLabel / subtitleLabel */
    GOODialogView *alertDialog = subview;
    UILabel *titleLabel = [alertDialog titleLabel];
    if (titleLabel) {
     NSString *title = [titleLabel text];
     if (title) {
      if ([title isEqualToString:@"Update Required"]) {
       UILabel *subtitleLabel = [alertDialog subtitleLabel];
       if (subtitleLabel) {
        NSString *subtitle = [subtitleLabel text];
        if (subtitle) {
         if ([subtitle isEqualToString:@"You must update to continue."]) {
          /* This is the update required alert, hide its window!! */
          let_me_pass(self);
         }
        }
       }
      }
     }
    }
   }
  }
 }
}
%end