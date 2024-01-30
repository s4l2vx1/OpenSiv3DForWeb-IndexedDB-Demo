# include <Siv3D.hpp>

# include "IndexedDB.hpp"

// マウントするディレクトリ
constexpr FilePathView SaveDirectory = U"save/";

// セーブファイルのパス
constexpr FilePathView SaveFilePath = U"1.dat";

// セーブファイルからスコアをロードする
static int32 LoadScore(const FilePathView path)
{
	int32 score = 0;
	
	if (Deserializer<BinaryReader> reader{ path })
	{
		Print << U"セーブファイルが見つかりました。";

		// スコアを読み込む
		reader(score);
	}
	else
	{
		Print << U"セーブファイルが見つかりません。";
	}
		
	return score;
}

// セーブファイルにスコアを書き込む
static void SaveScore(const FilePathView path, const int32 score)
{
	if (Serializer<BinaryWriter> writer{ path })
	{
		// スコアを書き込む
		writer(score);
	}
	else
	{
		Print << U"セーブファイルの書き込みに失敗しました。";
	}
}

void Main()
{
	const Font font{ 30 };

	// IndexedDB を常に最新の状態にする非同期タスク
	AsyncTask<bool> syncTask;

	// SaveDirectory内のデータをIndexedDBから非同期で読み込む
	syncTask = Platform::Web::IndexedDB::InitAsync(SaveDirectory);

	// 読み込みが完了するまで待つ
	Platform::Web::System::AwaitAsyncTask(syncTask);

	// スコア
	int32 score = LoadScore((SaveDirectory + SaveFilePath));

	while (System::Update())
	{
		font(score).drawAt(Scene::Center());

		// 毎フレーム 1 点ずつスコアが増える
		++score;

		if ((not syncTask.isValid()) // タスクが空いているか
			|| syncTask.isReady()) // タスクが完了していれば
		{
			SaveScore((SaveDirectory + SaveFilePath), score);

			syncTask = Platform::Web::IndexedDB::SaveAsync();
		}
	}
}