#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class MonsterOne : public GameEngineActor
{
public:
	MonsterOne();
	~MonsterOne();


	MonsterOne(const MonsterOne& _Other) = delete;
	MonsterOne(MonsterOne&& _Other) noexcept = delete;
	MonsterOne& operator=(const MonsterOne& _Other) = delete;
	MonsterOne& operator=(MonsterOne&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);

private:
	GameEngineRender* MonsterOneRender = nullptr;
	GameEngineCollision* MonsterOneCol = nullptr;
	GameEngineCollision* MonsterOneSet = nullptr;

	float MonsterOneAttTime = 0.0f;
	float NowTime = 0.0f;
	int PooterHp = 3;
	int RESET = 1;
	bool PooterDeathcheck = false;
	bool Countbool = true;
};

