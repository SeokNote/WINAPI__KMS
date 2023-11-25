#pragma once
#include <GameEngineCore/GameEngineActor.h>
class MonsterBase : public GameEngineActor
{
public:
	MonsterBase();
	~MonsterBase();


	MonsterBase(const MonsterBase& _Other) = delete;
	MonsterBase(MonsterBase&& _Other) noexcept = delete;
	MonsterBase& operator=(const MonsterBase& _Other) = delete;
	MonsterBase& operator=(MonsterBase&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime,bool _IsValue);
private:

};

