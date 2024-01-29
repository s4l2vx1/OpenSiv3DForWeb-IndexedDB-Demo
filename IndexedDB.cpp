# include <emscripten.h>

# include <Siv3D.hpp>

# include "IndexedDB.hpp"

namespace s3d::Platform::Web::IndexedDB
{
	namespace detail
	{
		namespace
		{
			enum SyncFSState
			{
				Uninitialized,
				Initializing,
				Ready,
				Saving,
				SaveSucceeded,
				SaveFailed,
			};

			SyncFSState state = Uninitialized;
			bool hasPendingSaveTask = false;
		}

		
		__attribute__((import_name("siv3dMountIDBFS")))
		void siv3dMountIDBFS(const char32* path);
		
		__attribute__((import_name("__asyncjs__siv3dSyncFSAsync")))
		void siv3dSyncFSAsync(bool populate);
		

		/*
		EM_JS(void, siv3dMountIDBFS, (const char32* path), {
			const pathStr = UTF32ToString(path);
        	FS.mount(IDBFS, {}, pathStr);
		});

		EM_ASYNC_JS(void, siv3dSyncFSAsync, (bool populate), {
			FS.syncfs
			(
				populate,
				function(err)
				{
					_siv3dSyncFSCallback(!err);
					_siv3dMaybeAwake();
				}
			);
		});
		*/

		__attribute__((used, export_name("siv3dSyncFSCallback")))
		void siv3dSyncFSCallback(bool result)
		{
			state = (state == Initializing) ? Ready : (result ? SaveSucceeded : SaveFailed);
		}

		void Mount(FilePathView path)
		{
			FileSystem::CreateDirectories(path);
			siv3dMountIDBFS(path.data());
		}
	}

	namespace
	{
		using namespace detail;
	}
	
	void InitAsync(std::initializer_list<FilePathView> paths)
	{
		if (state != Uninitialized) throw Error(U"IndexedDB::InitAsync() can be called only once.");
		for(const FilePathView path : paths) Mount(path);
		state = Initializing;
		siv3dSyncFSAsync(true);
	}

	void SaveAsync()
	{
		if (not IsReady()) AwaitSyncResult();
		state = Saving;
		siv3dSyncFSAsync(false);
	}

	bool IsReady()
	{
		return state == Ready or state == SaveSucceeded or state == SaveFailed;
	}

	bool AwaitSyncResult()
	{
		while (state == Initializing or state == Saving)
		{
			if (s3d::Platform::Web::System::detail::siv3dSleepUntilWaked() != 0)
			{
				return false;
			}
		}
		return state == SaveSucceeded;
	}

	void RequestSave()
	{
		hasPendingSaveTask = true;
	}

	void ProceedSaveAsync()
	{
		if (IsReady() and hasPendingSaveTask)
		{
			hasPendingSaveTask = false;
			state = Saving;
			siv3dSyncFSAsync(false);
		}
	}

	bool HasPendingSaveTask()
	{
		return hasPendingSaveTask;
	}

	int WatchState()
	{
		return state;
	}
}
