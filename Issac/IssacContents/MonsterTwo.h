#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class MonsterTwo : public GameEngineActor
{
public:
	MonsterTwo();
	~MonsterTwo();


	MonsterTwo(const MonsterTwo& _Other) = delete;
	MonsterTwo(MonsterTwo&& _Other) noexcept = delete;
	MonsterTwo& operator=(const MonsterTwo& _Other) = delete;
	MonsterTwo& operator=(MonsterTwo&& _Other) noexcept = delete;
	void ImageLoad();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* MonsterTwoRender = nullptr;
	GameEngineCollision* MonsterTwoCol = nullptr;

	float CollTime = 0.0f;
	int MonsterTwoHp = 4;
	float4 MoveA = float4::Zero;
};

