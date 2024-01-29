mergeInto(LibraryManager.library, {
    siv3dMountIDBFS: function(path) {
        const pathStr = UTF32ToString(path);
        FS.mount(IDBFS, {}, pathStr);
    },
    siv3dMountIDBFS__sig: "vi",
    siv3dMountIDBFS__deps: [ "$FS" ],

    __asyncjs__siv3dSyncFSAsync: function(populate) {
        FS.syncfs
        (
            populate,
            function(err)
            {
                _siv3dSyncFSCallback(!err);
                _siv3dMaybeAwake();
            }
        );
    },
    __asyncjs__siv3dSyncFSAsync__sig: "vi",
    __asyncjs__siv3dSyncFSAsync__deps: [ "$FS", "siv3dMaybeAwake", "siv3dSyncFSCallback" ],
});