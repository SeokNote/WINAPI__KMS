#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// 설명 :
class Stage2Level : public GameEngineLevel
{
public:
	// constrcuter destructer
	Stage2Level();
	~Stage2Level();

	// delete Function
	Stage2Level(const Stage2Level& _Other) = delete;
	Stage2Level(Stage2Level&& _Other) noexcept = delete;
	Stage2Level& operator=(const Stage2Level& _Other) = delete;
	Stage2Level& operator=(Stage2Level&& _Other) noexcept = delete;

protected:
	// 문법은 지나침 없이 fm대로 적어야 합니다.
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

private:
	// float4 MoveY;
	void ImageLoad();
	float Time = 0.0f;
	float4 Start = float4::Zero;
	float4 End = float4::Zero;
};

