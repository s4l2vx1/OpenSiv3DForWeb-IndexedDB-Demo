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

		Print << U"スコア: {} 点"_fmt(score);
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

	// ディレクトリをマウントし、SaveDirectory内のデータを非同期でロードする
	Platform::Web::IndexedDB::InitAsync(SaveDirectory);

	// ロードが完了するまで待機する
	Platform::Web::IndexedDB::AwaitSyncResult();

	// スコア
	int32 score = LoadScore((SaveDirectory + SaveFilePath));

	bool saveAlways = false;

	int32 scoreAtLastSave = score;

	while (System::Update())
	{
		font(score).drawAt(Scene::Center());

		SimpleGUI::CheckBoxAt(saveAlways, U"Save always", Scene::Center() + Vec2(0, 80));

		// 毎フレーム 1 点ずつスコアが増える
		++score;

		if(saveAlways) // 常にセーブする
		{
			// 進行中のセーブが無く、セーブが可能な状態ならば
			if (Platform::Web::IndexedDB::IsReady())
			{
				SaveScore((SaveDirectory + SaveFilePath), score);
				
				Platform::Web::IndexedDB::SaveAsync();

				scoreAtLastSave = score;
			}
		}
		else // 300 点ごとにセーブする
		{
			if (score > scoreAtLastSave + 300)
			{
				SaveScore((SaveDirectory + SaveFilePath), score);
				
				Platform::Web::IndexedDB::RequestSave();

				Print << U"{} 点でセーブを要求しました"_fmt(score);

				scoreAtLastSave = score;
			}
		}

		// RequestSaveで要求されたセーブがあれば実行する
		Platform::Web::IndexedDB::ProceedSaveAsync();
	}
}
