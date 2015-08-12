//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Jun  3 2014 10:55:11).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DOCKFolder.h"

#import "DOCKStackCollapsedDataSource.h"

@class NSMutableArray, NSMutableDictionary, NSString;

@interface DOCKDynamicFolder : DOCKFolder <DOCKStackCollapsedDataSource>
{
    NSMutableDictionary *_collapsedCache;
    BOOL _needsToInvalidateDataSource;
    NSMutableArray *_menuListCleanup;
}

- (void).cxx_destruct;
- (id)collapsedStackValueForKey:(id)arg1 atIndex:(unsigned long long)arg2;
- (unsigned long long)numberOfCollapsedStackItems;
- (void)showStackAsMenu:(BOOL)arg1;
- (void)stackDidClose;
- (void)_updateFile:(id)arg1;
- (void)invalidate;
- (void)invalidateCollapseCache;
- (void)arrangementChanged;
- (void)_removeDirectoryObservers;
- (void)_fetchIconForFile:(id)arg1 atIndex:(unsigned long long)arg2 withSize:(unsigned long long)arg3 andScaleFactor:(float)arg4;
- (void)_addsubmenu:(struct OpaqueMenuRef *)arg1 forFile:(id)arg2;
- (void)_addFiles:(id)arg1 toMenu:(struct OpaqueMenuRef *)arg2 withArrangement:(int)arg3;
- (void)_filesRemoved:(id)arg1;
- (void)_filesAdded:(id)arg1;
- (void)_filesChanged:(id)arg1;
- (void)_setNeedsToInvalidateDataSource;
- (void)_sortFilesAndInvalidateDataSource;
- (void)_setCollapsedPreviewImage:(id)arg1 atIndex:(unsigned long long)arg2 withIconSize:(unsigned long long)arg3 forFile:(id)arg4 cache:(BOOL)arg5;
- (void)_iconChanged:(id)arg1;
- (void)_directoryNameChanged:(id)arg1;
- (void)_directoryDeleted:(id)arg1;
- (id)_folderTile;
- (void)dealloc;
- (id)initWithDirectory:(id)arg1 folderTile:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
