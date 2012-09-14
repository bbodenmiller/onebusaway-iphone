/**
 * Copyright (C) 2009 bdferris <bdferris@onebusaway.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "OBAModelDAO.h"
#import "OBAModelFactory.h"
#import "OBAModelService.h"
#import "OBADataSourceConfig.h"
#import "OBALocationManager.h"
#import "OBAActivityListeners.h"
#import "OBANavigationTarget.h"
#import "OBAReferencesV2.h"
#import "IASKAppSettingsViewController.h"

@class OBASearchResultsMapViewController;
@class OBABookmarksViewController;
@class OBARecentStopsViewController;
@class OBASearchViewController;
@class OBAContactUsViewController;
@class OBAAgenciesListViewController;

@class OBANearbyTripsController;
@class OBAStopIconFactory;

@interface OBAApplicationContext : NSObject <UIApplicationDelegate,UITabBarControllerDelegate,IASKSettingsDelegate> {
	
	BOOL _setup;
	BOOL _active;
	
	OBAReferencesV2 * _references;
	OBAModelDAO * _modelDao;
	OBAModelService * _modelService;
	
	OBALocationManager * _locationManager;
	OBAActivityListeners * _activityListeners;

	OBAStopIconFactory * _stopIconFactory;
	
	UIWindow * _window;
	UITabBarController * _tabBarController;
	
}

@property(nonatomic, strong) UIWindow *window;
@property(strong) UITabBarController * tabBarController;

// view controller tabs
@property(strong) OBASearchResultsMapViewController *mapViewController;
@property(strong) OBABookmarksViewController *bookmarksViewController;
@property(strong) OBARecentStopsViewController *recentViewController;
@property(strong) OBASearchViewController *searchViewController;
@property(strong) OBAContactUsViewController *contactViewController;
@property(strong) IASKAppSettingsViewController *settingsViewController;
@property(strong) OBAAgenciesListViewController *agenciesViewController;

@property (nonatomic,readonly) OBAReferencesV2 * references;
@property (nonatomic,readonly) OBAModelDAO * modelDao;
@property (nonatomic,readonly) OBAModelService * modelService;

@property (nonatomic,readonly) OBAStopIconFactory * stopIconFactory;

@property (nonatomic,readonly) OBALocationManager * locationManager;
@property (nonatomic,readonly) OBAActivityListeners * activityListeners;

@property (nonatomic,readonly) BOOL active;

- (void) navigateToTarget:(OBANavigationTarget*)navigationTarget;
- (void) refreshSettings;

@end
