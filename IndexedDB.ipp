# pragma once

# include "IndexedDB.hpp"

namespace s3d::Platform::Web::IndexedDB
{
	inline void InitAsync(FilePathView path)
	{
		IndexedDB::InitAsync({ path });
	}
}
