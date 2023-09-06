#pragma once
#include "../../SceneAll/GameObject.h"
#include "../../../wta_library/wta_DrawAnim.h"


//Player,Enemy�̊��N���X

class Character :public GameObject
{

public:
	Character(const tnl::Vector3 pos, int size, int hp, const tnl::Vector3 velocity) :
		GameObject(pos), m_size(size), m_hp(hp), m_velocity(velocity) 
	{
		// CSV����A�j���[�V�����f�[�^�����[�h
		animLoader = new wta::DrawAnim("csv/AnimLoad.csv", "graphics/animation");
	}
	virtual ~Character() 
	{
		delete animLoader;
		animLoader = nullptr;
	}

	//-----�����o�ϐ�-----//
protected:
	int m_size;										/*�����蔻��p�T�C�Y*/
	int m_hp;										/*HP*/

	tnl::Vector3 m_velocity = { 100,0,0 };			/*���x*/
	tnl::Vector3 m_gravity = { 0,100,0 };			/*�d��*/

	bool m_is_ground = true;						/*�ڒn��*/
	bool m_is_jump = false;							/*�W�����v��*/
	bool m_is_attack = false;						/*�U����*/
	bool m_is_dead = false;							/*���S*/
	bool m_is_dirction_right = true;				/*�E����*/

	wta::DrawAnim* animLoader = nullptr;		//�A�j���[�V�����f�[�^�����[�h

public:
	//-----Setter,Getter-----//
	int GetSize() const { return m_size; }
	int GetHp() const { return m_hp; }

	int GetIsDead() const { return m_is_dead; }
	void SetIsDead(bool is_dead) { m_is_dead = is_dead; }

	tnl::Vector3 GetVelocity() const { return m_velocity; }
	void SetVelocity(tnl::Vector3 velocity) { m_velocity = velocity; }
};


//Character�N���X�̃f�X�g���N�^�����ʂȌ㏈����K�v�Ƃ��Ȃ��ꍇ�A
//virtual ~Character() = default;�̂悤�ɖ����I��= default���g�p���邱�Ƃ́A
//���̈Ӑ}�𖾊m�ɓ`���邽�߂ɗL���ł��B