#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

enum class IsaacState
{
	IDLE,
	MOVE,
	GET,
	Attack,
};
//enum class IsaacDir
//{
//	Left,
//	Right,
//	Up,
//	Down,
//};
// Ό³Έν :
class Isaac : public GameEngineActor
{
public:
	static Isaac* MainPlayer;

	// constrcuter destructer
	Isaac();
	~Isaac();

	// delete Function
	Isaac(const Isaac& _Other) = delete;
	Isaac(Isaac&& _Other) noexcept = delete;
	Isaac& operator=(const Isaac& _Other) = delete;
	Isaac& operator=(Isaac&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);
	void BombCheck(float _DeltaTime);

	GameEngineCollision* GetIsaacCollision()
	{
		return IsaacColltion;
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


	bool HitIsaac = false;
	int HP = 6;
	int MaxHP = 6;


	float4 MoveDir = float4::Zero;
	float4 Dir = float4::Zero;
	std::string DirString = "Right_";
	std::string BDirString = "Right_";

	IsaacState StateValue = IsaacState::IDLE;

	GameEngineRender* IsaacHeadRender = nullptr;
	GameEngineRender* IsaacBodyRender = nullptr;
	//GameEngineRender* GetRender = nullptr;

	GameEngineCollision* IsaacColltion = nullptr;
	
	//void DirCheck(const std::string_view& _AnimationName);
	void DirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1);
	void ChangeState(IsaacState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void TearsAttack(float _DeltaTime);

};

