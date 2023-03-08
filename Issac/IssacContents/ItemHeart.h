#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class ItemHeart : public GameEngineActor
{
public:
	ItemHeart();
	~ItemHeart();


	ItemHeart(const ItemHeart& _Other) = delete;
	ItemHeart(ItemHeart&& _Other) noexcept = delete;
	ItemHeart& operator=(const ItemHeart& _Other) = delete;
	ItemHeart& operator=(ItemHeart&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* HeartRender = nullptr;
	GameEngineCollision* HeartCol = nullptr;
};

