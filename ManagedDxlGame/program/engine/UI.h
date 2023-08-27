#pragma once
#include "GameEngine.h"
#include "GameObject.h"

//今、だいぶ荒れてます

class UI:public GameObject{

public:
	UI();
	virtual ~UI();
	
	//-----メッシュ-----//
	dxe::Mesh* m_mesh_hp = nullptr;				//体力バー
	dxe::Mesh* m_mesh_face = nullptr;			//フェイスバー
	
	//能力バー
	dxe::Mesh* m_mesh_ability_normal = nullptr;	//�@ノーマル
	dxe::Mesh* m_mesh_ability_fire = nullptr;		//�A炎
	dxe::Mesh* m_mesh_ability_beam = nullptr;		//�Bビーム
	//-----カメラ-----//
	dxe::Camera* m_camera = nullptr;

public:
	//-----メンバ関数-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;
};

//UIの処理一括を行うクラス