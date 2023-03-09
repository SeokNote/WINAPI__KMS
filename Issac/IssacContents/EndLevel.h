#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// 설명 :
class EndLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	EndLevel();
	~EndLevel();

	// delete Function
	EndLevel(const EndLevel& _Other) = delete;
	EndLevel(EndLevel&& _Other) noexcept = delete;
	EndLevel& operator=(const EndLevel& _Other) = delete;
	EndLevel& operator=(EndLevel&& _Other) noexcept = delete;

protected:
	// 문법은 지나침 없이 fm대로 적어야 합니다.
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;


private:

};
