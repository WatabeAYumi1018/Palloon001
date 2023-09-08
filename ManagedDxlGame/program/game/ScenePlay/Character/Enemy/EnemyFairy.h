#pragma once
#include "../../../../engine/GameEngine.h"
#include "Enemy.h"

//スライムクラス

class EnemyFairy :public Enemy
{
public:
	
	EnemyFairy(const sEnemyData& data, const sEnemyInfo& info, Player* player, Map* map, Collision* collision);
	~EnemyFairy();

private:

	TNL_CO_SEQUENCE(EnemyFairy, &EnemyFairy::SeqIdle);						//コルーチンシーケンス

public:
	
	void Update(const float delta_time) override;	//更新処理
	void Draw(const float delta_time, const Camera* camera) override;		//描画処理

private:

	bool SeqIdle(const float delta_time) override;
	bool SeqMove(const float delta_time) override;	
	bool SeqAttack(const float delta_time) override;
};
