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
//�Bカメラ移動の実装　ひとまず置いとく
//�C攻撃の当たり判定
//�D敵キャラのAI
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

//MapManager* mapChip = nullptr;
//UI* ui=nullptr;
//Character *player=nullptr;
//PlayCamera* camera=nullptr;
//backGround* back=nullptr;
//CollisionCalc* m_collision = nullptr;	//当たり判定


//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	SetWindowText("Title");
	//コンストラクタ作成(後に多態性でまとめて管理)
	//back = new backGround();
	//ui = new UI({10,0,50});
	//player = new Player();
	//camera = new PlayCamera(player);
	//m_collision = new CollisionCalc();
	//mapChip = new MapManager();
	SceneManager::GetInstance( new SceneTitle() );
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {

	////生成したコンストラクタでUpdate回す
	//back->Update(delta_time);
	//ui->Update(delta_time);
	//camera->Update(delta_time);
	//player->Update(delta_time);
	//mapChip->Update(delta_time);//, camera);
	//m_collision->CollisionCalculate(player, mapChip, 2);
	//m_collision->CheckBoxCollision(player, mapChip, mapChip->GetCollisionInfo());

	//使用方法
	SceneManager::GetInstance()->Update(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
	//delete camera;
	//camera = nullptr;
	//delete m_collision;
	//m_collision = nullptr;
}
