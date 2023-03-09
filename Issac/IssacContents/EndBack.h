#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class EndBack : public GameEngineActor
{
public:
	// constrcuter destructer
	EndBack();
	~EndBack();

	// delete Function
	EndBack(const EndBack& _Other) = delete;
	EndBack(EndBack&& _Other) noexcept = delete;
	EndBack& operator=(const EndBack& _Other) = delete;
	EndBack& operator=(EndBack&& _Other) noexcept = delete;

protected:
	void Start() override;

	GameEngineRender* EndRender =nullptr;
	GameEngineRender* EndBackImage = nullptr;

private:
};

