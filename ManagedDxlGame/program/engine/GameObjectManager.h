#pragma once

class PlayCamera;

class GameObjectManager {

protected:
	//-----メンバ関数-----//
	virtual void Initialize() {}
	virtual void Update(float delta_time) { }
	virtual void Draw(float delta_time, const PlayCamera* camera) {}
	virtual void Finalize() {}
};