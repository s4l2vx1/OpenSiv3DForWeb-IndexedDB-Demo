# pragma once

# include "IndexedDB.hpp"

namespace s3d::Platform::Web::IndexedDB
{
	namespace detail
	{
		AsyncTask<bool> SyncFSAsync(bool populate);
	}

	[[nodiscard]]
	inline AsyncTask<bool> LoadAsync()
	{
		return detail::SyncFSAsync(true);
	}

	[[nodiscard]]
	inline AsyncTask<bool> SaveAsync()
	{
		return detail::SyncFSAsync(false);
	}
}

