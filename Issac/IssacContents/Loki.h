#pragma once
#include "MonsterBase.h"
#include <GameEnginePlatform/GameEngineImage.h>


class Loki : public MonsterBase
{
public:
	static Loki* MainBoss;

	Loki();
	~Loki();

	Loki(const Loki& _Other) = delete;
	Loki(Loki&& _Other) noexcept = delete;
	Loki& operator=(const Loki& _Other) = delete;
	Loki& operator=(Loki&& _Other) noexcept = delete;

	int GetLokiHp()
	{
		return LokiHp;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* LokiRender = nullptr;
	GameEngineCollision* LokiCol = nullptr;
	void CollisionCheck(float _DeltaTime);
	void ImageLoad();

	float LokiAttTime = 0.0f;
	float LokiAttTime2 = 0.0f;
	float EndingTime = 0.0f;

	float NowTime = 0.0f;
	int LokiHp = 33;
	int RESET = 1;
	bool LokiDeathcheck = false;
	bool Countbool = true;
	float CollTime = 0.0f;
	float LokiSpeed = 20.0f;

};

