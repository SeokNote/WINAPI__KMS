#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class MonsterSet : public GameEngineActor
{

public:
	// constrcuter destructer
	MonsterSet();
	~MonsterSet();

	// delete Function
	MonsterSet(const MonsterSet& _Other) = delete;
	MonsterSet(MonsterSet&& _Other) noexcept = delete;
	MonsterSet& operator=(const MonsterSet& _Other) = delete;
	MonsterSet& operator=(MonsterSet&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void Render(float _DeltaTime);
	GameEngineCollision* MonsterSetCol = nullptr;
private:
};

