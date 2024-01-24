#import <UIKit/UIKit.h>
#include <objc/runtime.h>

@interface YTAlertView : UIView
@end

@interface GOODialogView : UIView
-(UILabel *)titleLabel;
-(UILabel *)subtitleLabel;
@end

/* translate string */
NSString *trans(NSString *orig) {
 return [NSBundle.mainBundle localizedStringForKey:orig value:nil table:0x0];
}

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
 NSString *updateRequiredString = trans(@"update.title.force");
 if ([@"update.title.force" isEqualToString:updateRequiredString]) {updateRequiredString = @"Update Required";};
 NSString *dialogRequiredString = trans(@"update.dialog.force");
 if ([@"update.dialog.force" isEqualToString:dialogRequiredString]) {dialogRequiredString = @"You must update to continue.";};
 Class GOODialogViewClass = objc_getClass("GOODialogView");
 NSArray *alertViewSubviews = [self subviews];
 for (id subview in alertViewSubviews) {
  if ([subview isMemberOfClass:GOODialogViewClass]) {
   /* subview is GOODialogView, check titleLabel / subtitleLabel */
   GOODialogView *alertDialog = subview;
   UILabel *titleLabel = [alertDialog titleLabel];
   if (titleLabel) {
    NSString *title = [titleLabel text];
    if ([updateRequiredString isEqualToString:title]) {
     UILabel *subtitleLabel = [alertDialog subtitleLabel];
     if (subtitleLabel) {
      NSString *subtitle = [subtitleLabel text];
      if ([dialogRequiredString isEqualToString:subtitle]) {
       /* This is the update required alert, hide its window!! */
       let_me_pass(self);
      }
     }
    }
   }
  }
 }
}
%end