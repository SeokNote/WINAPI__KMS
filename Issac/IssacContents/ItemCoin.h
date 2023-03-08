#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class ItemCoin : public GameEngineActor
{
public:
	ItemCoin();
	~ItemCoin();


	ItemCoin(const ItemCoin& _Other) = delete;
	ItemCoin(ItemCoin&& _Other) noexcept = delete;
	ItemCoin& operator=(const ItemCoin& _Other) = delete;
	ItemCoin& operator=(ItemCoin&& _Other) noexcept = delete;

	void ImageLoad();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* CoinRender = nullptr;
	GameEngineCollision* CoinCol = nullptr;

	float CoinLoadTime = 0.0f;
};

