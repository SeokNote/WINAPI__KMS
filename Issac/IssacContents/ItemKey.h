#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class ItemKey : public GameEngineActor
{
public:
	ItemKey();
	~ItemKey();


	ItemKey(const ItemKey& _Other) = delete;
	ItemKey(ItemKey&& _Other) noexcept = delete;
	ItemKey& operator=(const ItemKey& _Other) = delete;
	ItemKey& operator=(ItemKey&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* KeyRender = nullptr;
	GameEngineCollision* KeyCol = nullptr;
};

