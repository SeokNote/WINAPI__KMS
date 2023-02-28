#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class IntroBack : public GameEngineActor
{
public:
	// constrcuter destructer
	IntroBack();
	~IntroBack();

	// delete Function
	IntroBack(const IntroBack& _Other) = delete;
	IntroBack(IntroBack&& _Other) noexcept = delete;
	IntroBack& operator=(const IntroBack& _Other) = delete;
	IntroBack& operator=(IntroBack&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
};

