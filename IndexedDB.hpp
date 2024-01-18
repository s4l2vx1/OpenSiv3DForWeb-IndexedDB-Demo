# pragma once

# include <Siv3D/AsyncTask.hpp>
# include <Siv3D/FileSystem.hpp>

/// @brief ファイルシステム内のデータをIndexedDB上に保存するための機能を提供します。
/// @remark IndexedDB上のデータは自動では変更されません。
namespace s3d::Platform::Web::IndexedDB
{
	/// @brief 指定されたパス以下をIndexedDB上の同期対象に設定します。
	void Mount(FilePathView path);

	/// @brief Mountされたパス以下をIndexedDB上のデータで上書きします。
	/// @return 読み込みが完了した場合、成功したらtrue、失敗したらfalse
	[[nodiscard]]
	inline AsyncTask<bool> LoadAsync();
	

	/// @brief Mountされたパス以下のデータをIndexedDBに保存します。
	/// @return セーブが完了した場合、成功したらtrue、失敗したらfalse
	[[nodiscard]]
	inline AsyncTask<bool> SaveAsync();
}

# include "IndexedDB.ipp"
