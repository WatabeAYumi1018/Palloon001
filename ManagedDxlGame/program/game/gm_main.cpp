#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "../game/ScenePlay/Character.h"
#include "../game/ScenePlay/Player.h"
#include "../game/ScenePlay/MapManager.h"
#include "../engine/backGround.h"
#include "../game/ScenePlay/CollisionCalc.h"
#include "ScenePlay/PlayCamera.h"
#include "../engine/UI.h"
#include "../game/ScenePlay/Enemy.h"
#include "../game/ScenePlay/ScenePlay.h"
#include "../game/SceneTitle/SceneTitle.h"
#include "../engine/SceneManager.h"


//�@マップ、背景描画 OK
//�Aキャラクターの動向と当たり判定の実装　多分OK
//�Bカメラ移動の実装　ひとまずOK
//�C攻撃の当たり判定
//�D敵キャラのAI		ひとまずOK
//�EUIやパラメータなどとの紐づけ
//�Fアクションの動向とアニメーションなどの確認とひと通りのプレイ実現
//�Gステージセレクト画面作成
//�Hひと通りゲームとして完成
//�Iボス戦
//�Jアイテム実装

//〜9月中旬まで〜
//�Kデバック
//�L画面セレクト作成
//�Mタイトル作成
//�Nエンディング作成

// 〜期限まで〜
//�O最終確認


//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	SetWindowText("Title");
	
	SceneManager::GetInstance(new ScenePlay());
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {


	SceneManager::GetInstance()->Update(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}
