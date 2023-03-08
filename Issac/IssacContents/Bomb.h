#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Bomb : public GameEngineActor
{
public:
	Bomb();
	~Bomb();


	Bomb(const Bomb& _Other) = delete;
	Bomb(Bomb&& _Other) noexcept = delete;
	Bomb& operator=(const Bomb& _Other) = delete;
	Bomb& operator=(Bomb&& _Other) noexcept = delete;
	void ImageLoad();

	void BlinkSet(float _DeltaTime);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);


private:
	GameEngineRender* BombRender = nullptr;
	GameEngineCollision* BombCol = nullptr;

	float NowTime = 0.0f;

	float BlinkTime = 0.0f;

};

