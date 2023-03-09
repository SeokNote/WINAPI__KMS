#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossSet : public GameEngineActor
{

public:
	// constrcuter destructer
	BossSet();
	~BossSet();

	// delete Function
	BossSet(const BossSet& _Other) = delete;
	BossSet(BossSet&& _Other) noexcept = delete;
	BossSet& operator=(const BossSet& _Other) = delete;
	BossSet& operator=(BossSet&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void Render(float _DeltaTime);
	GameEngineCollision* BossSetCol = nullptr;
private:
};

