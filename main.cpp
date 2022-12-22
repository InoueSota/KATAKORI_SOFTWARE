#include "main.h"

const char kWindowTitle[] = "LC1A_03_";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, Screen::kWindowWidth, Screen::kWindowHeight);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		Key::Update();

		//コントローラー
		Controller::SetState();

		///
		/// ↓更新処理ここから
		///

		switch (scene)
		{
		case TITLE:
			break;
		case INGAME:

			player.Update();

			//スクロール値をアップデートする
			screen.SetScroll(player);

			//線の位置を画面内に固定する
			ingame.DebagUpdate(player);

			break;
		case OUTGAME:
			break;
		}

		//BGM
		switch (scene)
		{
		case TITLE:
			break;
		case INGAME:
			break;
		case OUTGAME:
			break;
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene)
		{
		case TITLE:
			break;
		case INGAME:

			ingame.BackGroundDraw();
			ingame.DebagDraw(screen);

			player.Draw(screen);

			break;
		case OUTGAME:
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Key::IsTrigger(DIK_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
