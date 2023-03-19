#pragma once

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>


class BoomCount : public GameEngineActor
{
public:
	static BoomCount* BombNumberPtr;
	// constrcuter destructer
	BoomCount();
	~BoomCount();

	// delete Function
	BoomCount(const BoomCount& _Other) = delete;
	BoomCount(BoomCount&& _Other) noexcept = delete;
	BoomCount& operator=(const BoomCount& _Other) = delete;
	BoomCount operator=(BoomCount&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* BombRender = nullptr;

	NumberRenderObject N_BombNumber;


	int BombNumbers = 0;

	void GetBombNumberSet();
	void NumberSet();
};

