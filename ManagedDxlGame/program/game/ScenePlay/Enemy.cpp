#include "Enemy.h"
#include <random>	

Enemy::Enemy() : Character(m_pos,m_size,m_hp,m_velocity){

}

Enemy::~Enemy(){}

void Enemy::Initialize() {

}

void Enemy::Update(float delta_time) {

}

void Enemy::Draw(float delta_time, const PlayCamera* camera) {
    DrawCircle(m_pos.x,m_pos.y,m_size,-1);
}

void Enemy::Finalize() {

}

bool Enemy::SeqBaseAction(const float delta_time) { 
	
    float chance = distribution(generator);

    //move→idleの確率
    if (chance < 0.001f) {
        tnl_sequence_.change(&Enemy::SeqNextAction);
        return true;
    }

    //プレイヤーとの距離計算
    if (std::abs(m_pos.x - m_player->GetPos().x) < 2.0f) {
        tnl_sequence_.change(&Enemy::SeqAttack);
        return true;
    }
    DrawStringEx(0, 0, -1, "move");

    //経過時間をカウント
    m_moveTimeCounter += delta_time;

    if (m_moveTimeCounter <= 2.0f) {

        TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]() {
            DrawStringEx(0, 50, -1, "right");
            m_pos.x += m_velocity.x * delta_time;
        });
    }
    else if (m_moveTimeCounter > 2.0f && m_moveTimeCounter <= 4.0f) {

        TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]() {
            DrawStringEx(0, 50, -1, "left");
            m_pos.x -= m_velocity.x * delta_time;
        });
    }
    else if (m_moveTimeCounter > 4.0f) {m_moveTimeCounter = 0.0f;}

    tnl_sequence_.change(&Enemy::SeqBaseAction);
    TNL_SEQ_CO_END;
}

bool Enemy::SeqNextAction(const float delta_time) { 

	DrawStringEx(0, 0, -1, "idle");

    TNL_SEQ_CO_TIM_YIELD_RETURN(2, delta_time, [&]() {
        //アニメーション画像再生表示とか
    });
    
    tnl_sequence_.change(&Enemy::SeqBaseAction);
    TNL_SEQ_CO_END;
}

bool Enemy::SeqAttack(const float delta_time) { 

    DrawStringEx(0, 0, -1, "attack");

    TNL_SEQ_CO_TIM_YIELD_RETURN(1, delta_time, [&]() {
        //攻撃アニメーション再生
    });

    tnl_sequence_.change(&Enemy::SeqBaseAction);
    TNL_SEQ_CO_END;
}
