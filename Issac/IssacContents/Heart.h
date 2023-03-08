#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>


class Heart : public GameEngineActor
{
public:
	Heart();
	~Heart();

	Heart(const Heart& _Other) = delete;
	Heart(Heart&& _Other) noexcept = delete;
	Heart& operator=(const Heart& _Other) = delete;
	Heart& operator=(Heart&& _Other) noexcept = delete;

	void ImageLoad();
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	GameEngineRender* HeartRender = nullptr;
	GameEngineCollision* HeartCol = nullptr;

};
