//
//  RNVCNavbarViewController.h
//  Resplendent
//
//  Created by Benjamin Maer on 10/2/12.
//  Copyright (c) 2012 Resplendent G.P. All rights reserved.
//

#import <UIKit/UIKit.h>





typedef enum {
    RNVCNavbarViewControllerTransitionFromStyleNone,
    RNVCNavbarViewControllerTransitionFromStyleFromRight,
    RNVCNavbarViewControllerTransitionFromStyleFromLeft,
    RNVCNavbarViewControllerTransitionFromStyleFromLeftQuarterDistance,
}RNVCNavbarViewControllerTransitionFromStyle;

typedef enum {
    RNVCNavbarViewControllerTransitionToStyleNone,
    RNVCNavbarViewControllerTransitionToStyleToRight,
    RNVCNavbarViewControllerTransitionToStyleToLeft,
    RNVCNavbarViewControllerTransitionToStyleToLeftQuarterDistance,
    RNVCNavbarViewControllerTransitionToStyleToBottom,
}RNVCNavbarViewControllerTransitionToStyle;





extern NSString* const kRNVCNavbarViewControllerNotificationCenterWillPop;
extern NSString* const kRNVCNavbarViewControllerNotificationCenterDidPop;
extern NSString* const kRNVCNavbarViewControllerNotificationCenterWillPush;
extern NSString* const kRNVCNavbarViewControllerNotificationCenterDidPush;





@class RNVCNavbar;





@interface RNVCNavbarViewController : UIViewController

@property (nonatomic, assign) BOOL ignoreNavbarSetFrameOnLayout;

@property (nonatomic, strong) RNVCNavbar* navbar;
@property (nonatomic, readonly) CGRect navbarFrame;
@property (nonatomic, readonly) CGRect contentFrame;

@property (nonatomic, assign) RNVCNavbarViewController* parentNBViewController;
@property (nonatomic, strong) RNVCNavbarViewController* childNBViewController;

@property (nonatomic, readonly) RNVCNavbarViewController* mostDistantChildNBViewController;

//User by parent on push, child on pop
@property (nonatomic, assign) RNVCNavbarViewControllerTransitionFromStyle pushChildTransitionStyle;
@property (nonatomic, assign) RNVCNavbarViewControllerTransitionToStyle pushTransitionStyle;
@property (nonatomic, assign) RNVCNavbarViewControllerTransitionFromStyle popParentTransitionStyle;
@property (nonatomic, assign) RNVCNavbarViewControllerTransitionToStyle popTransitionStyle;

@property (nonatomic, readonly) Class navbarClass;

//-(void)setTransitionStyleIncludeChildren:(RNVCNavbarViewControllerTransitionFromStyle)transitionStyle;
-(BOOL)isNavbarViewControllerAChild:(RNVCNavbarViewController*)navbarViewController;

-(void)setDefaultLeftToRightTransitionProperties;

-(void)popChildrenViewControllers:(BOOL)animated completion:(void (^)())completion;

-(void)pushViewController:(RNVCNavbarViewController*)navbarViewController animated:(BOOL)animated completion:(void (^)())completion;
-(void)popViewControllerAnimated:(BOOL)animated completion:(void (^)())completion;

-(void)navbarViewWillAppear:(BOOL)animated;
-(void)navbarViewDidAppear:(BOOL)animated;

-(void)navbarViewWillDisappear:(BOOL)animated;
-(void)navbarViewDidDisappear:(BOOL)animated;

-(void)navbarChildWillPerformPopAnimationToOrigin:(CGPoint)startParentOrigin;
-(void)navbarChildIsPerformingAnimationToOrigin:(CGPoint)animateToParentOrigin;

-(void)prepareForNavbarPushTransitionToViewController:(RNVCNavbarViewController*)navbarViewController withStartChildOrigin:(CGPoint)startChildOrigin;
-(void)performPushTransitionAnimationsWithChildOrigin:(CGPoint)animateToChildOrigin parentOrigin:(CGPoint)animateToParentOrigin;
-(void)performNavbarPushTransitionCompletionToViewController:(RNVCNavbarViewController*)navbarViewController;

-(void)performPopTransitionAnimationsWithChildOrigin:(CGPoint)animateToChildOrigin parentOrigin:(CGPoint)animateToParentOrigin;


+(void)setPushPopTransitionDuration:(NSTimeInterval)duration;

@end
