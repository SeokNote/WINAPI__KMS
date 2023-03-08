#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

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

	void Movecalculation(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);
	void BombCheck(float _DeltaTime);

	GameEngineCollision* GetIsaacCollision()
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

	float AccTime = 0.0f;
	int StartFrame = 0;
	float MoveSpeed = 200.0f;
	float ResetTimeTears = 0.0f;
	float ResetTimeBombs = 0.0f;

	float BlinkTime = 0.0f;
	float DeadTime = 0.0f;
	float CollTime = 0.0f;

	int BombCount = 5;
	int KeyCount = 0;
	int CoinCount = 0;

	int TearDamage = 1;

	bool HitIssac = false;
	int HP = 6;
	int MaxHP = 6;


	float4 MoveDir = float4::Zero;
	float4 Dir = float4::Zero;
	std::string DirString = "Right_";
	IssacState StateValue = IssacState::IDLE;

	GameEngineRender* IssacHeadRender = nullptr;
	GameEngineRender* IssacBodyRender = nullptr;

	GameEngineCollision* IssacColltion = nullptr;
	
	void DirCheck();

	void ChangeState(IssacState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void TearsAttack(float _DeltaTime);

};

