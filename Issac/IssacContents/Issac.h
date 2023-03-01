#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class IssacState
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
class Issac : public GameEngineActor
{
public:
	static Issac* MainPlayer;

	// constrcuter destructer
	Issac();
	~Issac();

	// delete Function
	Issac(const Issac& _Other) = delete;
	Issac(Issac&& _Other) noexcept = delete;
	Issac& operator=(const Issac& _Other) = delete;
	Issac& operator=(Issac&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;


private:
	float AccTime = 0.0f;
	int StartFrame = 0;
	float MoveSpeed = 150.0f;

	std::string DirString = "Right_";
	IssacState StateValue = IssacState::IDLE;

	GameEngineRender* IssacHeadRender = nullptr;
	GameEngineRender* IssacBodyRender = nullptr;

	void DirCheck(const std::string& _AnimationName);

	void ChangeState(IssacState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

};

