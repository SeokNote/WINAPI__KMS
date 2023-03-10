#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

enum class IssacState
{
	IDLE,
	MOVE,
	GET,
	Attack,
};
//enum class IssacDir
//{
//	Left,
//	Right,
//	Up,
//	Down,
//};
// ???? :
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

	void Movecalculation(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);
	void BombCheck(float _DeltaTime);

	GameEngineCollision* GetIssacCollision()
	{
		return IssacColltion;
	}
	//-----------------
	int GetKeyCount()
	{
		return KeyCount;
	}
	int GetBombCount()
	{
		return BombCount;
	}
	int GetCoinCount()
	{
		return CoinCount;
	}
	//-----------------
	int GetTearDamage()
	{
		return TearDamage;
	}

	float GetTearSpeed()
	{
		return TearSpeed;
	}
	float GetTearAttSpeed()
	{
		return TearAttSpeed;
	}
	int GetPlayerHP()
	{
		return HP;
	}
	int SetPlayerHP(int _HP)
	{
		return HP = _HP;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;


private:


	float TearSpeed = 400.0f;
	int TearDamage = 1;
	float TearAttSpeed = 0.4f;

	float AccTime = 0.0f;
	int StartFrame = 0;
	float MoveSpeed = 250.0f;
	float ResetTimeTears = 0.0f;
	float ResetTimeBombs = 0.0f;
	float GetTime = 0.0f;

	float BlinkTime = 0.0f;
	float DeadTime = 0.0f;
	float CollTime = 0.0f;

	int BombCount = 5;
	int KeyCount = 0;
	int CoinCount = 0;


	bool HitIssac = false;
	int HP = 6;
	int MaxHP = 6;


	float4 MoveDir = float4::Zero;
	float4 Dir = float4::Zero;
	std::string DirString = "Right_";
	std::string BDirString = "Right_";

	IssacState StateValue = IssacState::IDLE;

	GameEngineRender* IssacHeadRender = nullptr;
	GameEngineRender* IssacBodyRender = nullptr;
	//GameEngineRender* GetRender = nullptr;

	GameEngineCollision* IssacColltion = nullptr;
	
	//void DirCheck(const std::string_view& _AnimationName);
	void DirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1);
	void ChangeState(IssacState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();


	void GETStart();
	void GETUpdate(float _Time);
	void GETEnd();

	/*void AttackStart();
	void AttackUpdate(float _Time);
	void AttackEnd();*/

	void TearsAttack(float _DeltaTime);

};

