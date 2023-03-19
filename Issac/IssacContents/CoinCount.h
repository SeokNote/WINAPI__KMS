#pragma once

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>


class CoinCount : public GameEngineActor
{
public:
	static CoinCount* CoinNumberPtr;
	// constrcuter destructer
	CoinCount();
	~CoinCount();

	// delete Function
	CoinCount(const CoinCount& _Other) = delete;
	CoinCount(CoinCount&& _Other) noexcept = delete;
	CoinCount& operator=(const CoinCount& _Other) = delete;
	CoinCount operator=(CoinCount&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* CoinRender = nullptr;

	NumberRenderObject N_CoinRender;


	int CoinNumbers = 0;

	void GetCoinNumberSet();
	void NumberSet();
};

