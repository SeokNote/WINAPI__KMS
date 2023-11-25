#pragma once
#include "MonsterBase.h"
#include <GameEnginePlatform/GameEngineImage.h>


class Fly : public GameEngineActor
{
public:
	Fly();
	~Fly();


	Fly(const Fly& _Other) = delete;
	Fly(Fly&& _Other) noexcept = delete;
	Fly& operator=(const Fly& _Other) = delete;
	Fly& operator=(Fly&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* FlyRender = nullptr;
	GameEngineCollision* FlyCol = nullptr;
	void ImageLoad();

	float CollTime = 0.0f;
	int FlyHp = 3;
	float4 MoveA = float4::Zero;
};

