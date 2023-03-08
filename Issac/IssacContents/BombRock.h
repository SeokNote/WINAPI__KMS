#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class BombRock : public GameEngineActor
{
public:
	BombRock();
	~BombRock();


	BombRock(const BombRock& _Other) = delete;
	BombRock(BombRock&& _Other) noexcept = delete;
	BombRock& operator=(const BombRock& _Other) = delete;
	BombRock& operator=(BombRock&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* BombRockRender = nullptr;
	GameEngineCollision* BombRockCol = nullptr;


};


