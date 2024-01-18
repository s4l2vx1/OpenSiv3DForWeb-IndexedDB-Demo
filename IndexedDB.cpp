# include <emscripten.h>

# include <Siv3D/FileSystem.hpp>

# include "IndexedDB.hpp"

namespace s3d::Platform::Web::IndexedDB
{
	namespace detail {
		EM_JS
		(
			void, siv3dMountIDBFS, (const char32_t* path),
			{
				const pathStr = UTF32ToString(path);
				FS.mount(IDBFS, {}, pathStr);
			}
		);
	}
	
	void Mount(FilePathView path)
	{
		FileSystem::CreateDirectories(path);
		detail::siv3dMountIDBFS(path.data());
	}

	namespace detail {
		EM_ASYNC_JS
		(
			void, siv3dSyncFSAsync, (bool populate, std::promise<bool>* promise),
			{
				FS.syncfs
				(
					populate,
					function(err)
					{
						Module["_siv3dSyncFSCallback"](promise, !err);
						_siv3dMaybeAwake();
					}
				);
			}
		);

		__attribute__((used, export_name("siv3dSyncFSCallback")))
		void siv3dSyncFSCallback(std::promise<bool>* promise, bool result)
		{
			promise->set_value(result);
			delete promise;
		}
		
		AsyncTask<bool> SyncFSAsync(bool populate)
		{
			auto* promisePtr = new std::promise<bool>();
			siv3dSyncFSAsync(populate, promisePtr);
			return promisePtr->get_future();
		}
	}
}
