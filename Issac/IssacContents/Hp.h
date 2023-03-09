#pragma once

#include <GameEngineCore/GameEngineActor.h>


class HP : public GameEngineActor
{
public:
	// constrcuter destructer
	HP();
	~HP();

	// delete Function
	HP(const HP& _Other) = delete;
	HP(HP&& _Other) noexcept = delete;
	HP& operator=(const HP& _Other) = delete;
	HP& operator=(HP&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* HpRender0 = nullptr;
	GameEngineRender* HpRender1 = nullptr;
	GameEngineRender* HpRender2 = nullptr;
	GameEngineRender* HpRender3 = nullptr;
	GameEngineRender* HpRender4 = nullptr;
	GameEngineRender* HpRender5 = nullptr;
	GameEngineRender* HpRender6 = nullptr;

	int IsaacHP = 0;

	void GetandSetIsaacHP();
	void HpSet(int _PlayerHP);
};

