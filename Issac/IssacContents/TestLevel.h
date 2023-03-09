#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// 설명 :
class TestLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	TestLevel();
	~TestLevel();

	// delete Function
	TestLevel(const TestLevel& _Other) = delete;
	TestLevel(TestLevel&& _Other) noexcept = delete;
	TestLevel& operator=(const TestLevel& _Other) = delete;
	TestLevel& operator=(TestLevel&& _Other) noexcept = delete;
	void MoveMaps();
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
	float _Time = 0.0f;

	bool MoveMap = true;



	
};

