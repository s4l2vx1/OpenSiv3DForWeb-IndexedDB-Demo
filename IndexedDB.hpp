# pragma once

# include <Siv3D/AsyncTask.hpp>
# include <Siv3D/FileSystem.hpp>

namespace s3d::Platform::Web
{
	/// @brief ファイルシステム内のデータをIndexedDB上に保存するための関数群を提供します。
	/// @remark マルチスレッドには対応していません。
	namespace IndexedDB
	{
		/// @brief 指定されたパス以下をIndexedDBの同期対象に設定し、既にデータが存在する場合には非同期でロードします。
		/// @note この関数はIndexedDBの他の関数の呼び出し前に必ず一度だけ呼び出してください。
		/// @note 他の非同期処理が既に実行中の場合、この関数の呼び出しはエラーになります。
		inline void InitAsync(FilePathView path);

		/// @brief 指定されたパス以下をIndexedDBの同期対象に設定し、既にデータが存在する場合にはロードします。
		/// @note この関数はIndexedDBの他の関数の呼び出し前に必ず一度だけ呼び出してください。
		/// @note 他の非同期処理が既に実行中の場合、この関数の呼び出しはエラーになります。
		void InitAsync(std::initializer_list<FilePathView> paths);

		/// @brief 現在のファイルの内容をIndexedDBに非同期で保存します。
		/// @note セーブ/ロードを除く他の非同期処理が既に実行中の場合、この関数の呼び出しはエラーになります。
		/// @note 進行中のセーブ/ロードがある場合、この関数はその完了まで待機します。
		void SaveAsync();

		/// @return 現在進行中のセーブ/ロードが無い場合にはtrue、それ以外の場合はfalse。
		[[nodiscard]]
		bool IsReady();

		/// @brief 最後に行われた非同期のセーブ/ロードが未完了の場合は待機し、その結果を返します。
		/// @return セーブ/ロードが成功した場合にはtrue、それ以外の場合はfalse。
		bool AwaitSyncResult();
		
		/// @brief 次のProceedSaveAsyncの呼び出し時に、セーブを行うように要求します。
		void RequestSave();

		/// @brief RequestSaveで要求されたセーブの実行を試みます。
		/// @note 既に進行中のセーブがある場合、この関数は次回以降の呼び出しまでセーブを延期します。
		void ProceedSaveAsync();

		/// @return RequestSaveによって要求されたがまだ実行されてないセーブがある場合にはtrue、それ以外の場合はfalse。
		[[nodiscard]]
		bool HasPendingSaveTask();
	}
}

# include "IndexedDB.ipp"
