#pragma once

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>


class KeyCount : public GameEngineActor
{
public:
	static KeyCount* KeyNumberPtr;
	// constrcuter destructer
	KeyCount();
	~KeyCount();

	// delete Function
	KeyCount(const KeyCount& _Other) = delete;
	KeyCount(KeyCount&& _Other) noexcept = delete;
	KeyCount& operator=(const KeyCount& _Other) = delete;
	KeyCount operator=(KeyCount&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* KeyRender = nullptr;

	NumberRenderObject N_KeyRender;


	int KeyNumbers = 0;

	void GetKeyNumberSet();
	void NumberSet();
};

