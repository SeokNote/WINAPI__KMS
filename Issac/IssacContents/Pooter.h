#pragma once
#include "MonsterBase.h"
#include <GameEnginePlatform/GameEngineImage.h>


class Pooter : public MonsterBase
{
public:
	Pooter();
	~Pooter();


	Pooter(const Pooter& _Other) = delete;
	Pooter(Pooter&& _Other) noexcept = delete;
	Pooter& operator=(const Pooter& _Other) = delete;
	Pooter& operator=(Pooter&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* PooterRender = nullptr;
	GameEngineCollision* PooterCol = nullptr;
	GameEngineCollision* PooterSet = nullptr;
	void CollisionCheck(float _DeltaTime);
	void ImageLoad();

	float PooterAttTime = 0.0f;
	float NowTime = 0.0f;
	int PooterHp = 5;
	int RESET = 1;
	bool PooterDeathcheck = false;
	bool Countbool = true;
};

