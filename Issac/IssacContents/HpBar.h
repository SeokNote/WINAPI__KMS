#pragma once

#include <GameEngineCore/GameEngineActor.h>


class HpBar : public GameEngineActor
{
public:
	// constrcuter destructer
	HpBar();
	~HpBar();

	// delete Function
	HpBar(const HpBar& _Other) = delete;
	HpBar(HpBar&& _Other) noexcept = delete;
	HpBar& operator=(const HpBar& _Other) = delete;
	HpBar& operator=(HpBar&& _Other) noexcept = delete;


	void Renders(int _Hp);
	void SetLokiHP();
	void ImageLoad();
protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* HpbarRender = nullptr;
	GameEngineRender* HpbarBackRender = nullptr;

	int LokiHp = 0;

};

