#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class MonsterState
{
	IDLE,
	MOVE,
};
//enum class IssacDir
//{
//	Left,
//	Right,
//	Up,
//	Down,
//};
// Ό³Έν :
class MonsterOne : public GameEngineActor
{
public:
	static MonsterOne* Monster1;

	// constrcuter destructer
	MonsterOne();
	~MonsterOne();

	// delete Function
	MonsterOne(const MonsterOne& _Other) = delete;
	MonsterOne(MonsterOne&& _Other) noexcept = delete;
	MonsterOne& operator=(const MonsterOne& _Other) = delete;
	MonsterOne& operator=(MonsterOne&& _Other) noexcept = delete;

	//	void Movecalculation(float _DeltaTime);


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;


private:
	float AccTime = 0.0f;
	int StartFrame = 0;
	float MoveSpeed = 150.0f;
	float4 MoveDir = float4::Zero;
	float4 Dir = float4::Zero;
	std::string DirString = "Right_";
	MonsterState StateValue = MonsterState::IDLE;

	GameEngineRender* MonsterOneRender = nullptr;
	

	void DirCheck();

	void ChangeState(MonsterState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

};

