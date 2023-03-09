#include "Issac.h"
#include "Tears.h"
#include "Bomb.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentsEnums.h"

Issac* Issac::MainPlayer;

Issac::Issac()
{
}

Issac::~Issac()
{
}

void Issac::Start()
{
	MainPlayer = this;


	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');
		GameEngineInput::CreateKey("LeftTears", VK_LEFT);
		GameEngineInput::CreateKey("RightTears", VK_RIGHT);
		GameEngineInput::CreateKey("UpTears", VK_UP);
		GameEngineInput::CreateKey("DownTears", VK_DOWN);
		GameEngineInput::CreateKey("Bomb", 'E');


	}

	{
		IssacBodyRender = CreateRender(IssacRenderOrder::Player);
		IssacBodyRender->SetScale({ 55, 55 });
		IssacBodyRender->SetPosition({ 0,29 });
		//Idle
		IssacBodyRender->CreateAnimation({ .AnimationName = "Down_BIdle",  .ImageName = "Right_Issac.bmp",.Start = 8, .End = 8 });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Left_BIdle",  .ImageName = "Left_Issac.bmp",.Start = 8, .End = 8 });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Up_BIdle",  .ImageName = "Right_Issac.bmp",.Start = 8, .End = 8 });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Right_BIdle",  .ImageName = "Right_Issac.bmp",.Start = 8, .End = 8 });
		//Move
		IssacBodyRender->CreateAnimation({ .AnimationName = "Right_BMove",  .ImageName = "Right_Issac.bmp",.Start = 16, .End = 22, .InterTime = 0.1f });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Left_BMove", .ImageName = "Left_Issac.bmp", .Start = 16, .End = 22, .InterTime = 0.1f });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Down_BMove", .ImageName = "Left_Issac.bmp", .Start = 6, .End = 13, .InterTime = 0.1f });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Up_BMove", .ImageName = "Left_Issac.bmp", .Start = 6, .End = 13, .InterTime = 0.1f });


		//Idle
		IssacHeadRender = CreateRender(IssacRenderOrder::Player);
		IssacHeadRender->SetScale({ 70, 70 });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Down_HIdle",  .ImageName = "Right_Issac.bmp",.Start = 0, .End = 0, });//기본상태
		IssacHeadRender->CreateAnimation({ .AnimationName = "Up_HIdle",  .ImageName = "Right_Issac.bmp",.Start = 0, .End = 0, });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Left_HIdle",  .ImageName = "Left_Issac.bmp",.Start = 0, .End = 0, });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Right_HIdle",  .ImageName = "Right_Issac.bmp",.Start = 0, .End = 0, });
		//Move
		IssacHeadRender->CreateAnimation({ .AnimationName = "Right_HMove",  .ImageName = "Right_Issac.bmp",.Start = 2, .End = 2});
		IssacHeadRender->CreateAnimation({ .AnimationName = "Left_HMove", .ImageName = "Left_Issac.bmp", .Start = 2, .End = 2 });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Up_HMove", .ImageName = "Left_Issac.bmp", .Start = 4, .End = 5,.InterTime = 0.2f });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Down_HMove", .ImageName = "Left_Issac.bmp", .Start = 0, .End = 0,.InterTime = 0.2f });
		//Attack
		IssacHeadRender->CreateAnimation({ .AnimationName = "Down_Attack",  .ImageName = "Right_Issac.bmp",.Start = 1, .End = 1,.InterTime = 0.2f });//기본상태
		IssacHeadRender->CreateAnimation({ .AnimationName = "Up_Attack",  .ImageName = "Right_Issac.bmp",.Start = 5, .End = 5,.InterTime = 0.2f });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Left_Attack",  .ImageName = "Left_Issac.bmp",.Start = 3, .End = 3,.InterTime = 0.2f });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Right_Attack",  .ImageName = "Right_Issac.bmp",.Start = 3, .End = 3, .InterTime = 0.2f });



		/*GetRender = CreateRender(IssacRenderOrder::Player);
		GetRender->SetScale({ 125, 125 });
		GetRender->CreateAnimation({ .AnimationName = "GetItem",  .ImageName = "Isaac_Anim.bmp",.Start = 5, .End = 5, });*/

	}
	{
		IssacColltion = CreateCollision(IssacCollisionOrder::Player);
		IssacColltion->SetScale({ 50,50 });
		IssacColltion->On();
		IssacColltion->SetDebugRenderType(CollisionType::CT_Rect);
	}
	ChangeState(IssacState::IDLE);

}


 

void Issac::Update(float _DeltaTime)
{
	if (false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove") &&
		false == GameEngineInput::IsPress("DownMove") &&
		false == GameEngineInput::IsPress("UpMove"))
	{
		MoveDir = float4::Zero;
	}

//	DirCheck();
	UpdateState(_DeltaTime);
	TearsAttack(_DeltaTime);
	BombCheck(_DeltaTime);
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
	SetMove(MoveDir * _DeltaTime);

}
void Issac::Movecalculation(float _DeltaTime)
{
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BaseColMap.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}
	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		Check = false;
	}
	if (false == Check)
	{
		MoveDir = float4::Zero;
	}

}

void Issac::CollisionCheck(float _DeltaTime)
{
	CollTime += _DeltaTime;
	if (CollTime >= 2.0f)
	{
		CollTime = 0.0f;
		IssacColltion->On();
	


	}
	if (nullptr != IssacColltion)
	{
		if (true == IssacColltion->Collision({ .TargetGroup = static_cast<int>(IssacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{

			CollTime += _DeltaTime;
			HP -= 2;
			IssacColltion->Off();
		}

		if (true == IssacColltion->Collision({ .TargetGroup = static_cast<int>(IssacCollisionOrder::Spike), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{

			CollTime += _DeltaTime;
			HP -= 1;
			IssacColltion->Off();
		}
		if (true == IssacColltion->Collision({ .TargetGroup = static_cast<int>(IssacCollisionOrder::Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{

			CollTime += _DeltaTime;
			HP -= 1;
			IssacColltion->Off();
		}
		
		std::vector<GameEngineCollision*> ICollisions;
		CollisionCheckParameter CheckHp = { .TargetGroup = static_cast<int>(IssacCollisionOrder::ItemHeart), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckKey = { .TargetGroup = static_cast<int>(IssacCollisionOrder::ItemKey), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckBomb = { .TargetGroup = static_cast<int>(IssacCollisionOrder::ItemBomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckCoin = { .TargetGroup = static_cast<int>(IssacCollisionOrder::ItemCoin), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckGlasses = { .TargetGroup = static_cast<int>(IssacCollisionOrder::ItemGlasses), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckLeo = { .TargetGroup = static_cast<int>(IssacCollisionOrder::ItemLeo), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckHeart = { .TargetGroup = static_cast<int>(IssacCollisionOrder::Heart), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckMonsterA = { .TargetGroup = static_cast<int>(IssacCollisionOrder::MonsterAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		//Heart
		if (true == IssacColltion->Collision(CheckHp, ICollisions) && 6 != HP)
		{
			ICollisions[0]->GetActor()->Death();
			HP += 2;
			if (HP > MaxHP)
			{
				HP = MaxHP;
			}
		}
		//Key
		if (true == IssacColltion->Collision(CheckKey, ICollisions))
		{
	
			ICollisions[0]->GetActor()->Death();
			KeyCount += 1;
		}
		//Bomb
		if (true == IssacColltion->Collision(CheckBomb, ICollisions))
		{
			ICollisions[0]->GetActor()->Death();
			BombCount += 1;
		}
		//Coin
		if (true == IssacColltion->Collision(CheckCoin, ICollisions))
		{
			
			ICollisions[0]->GetActor()->Death();
			CoinCount += 1;
		}
		if (true == IssacColltion->Collision(CheckGlasses, ICollisions))
		{
			//ChangeState(IssacState::GET);
			TearAttSpeed -= 0.1f;
			ICollisions[0]->GetActor()->Death();

		}
		if (true == IssacColltion->Collision(CheckLeo, ICollisions))
		{
			//ChangeState(IssacState::GET);
			TearDamage += 2;
			ICollisions[0]->GetActor()->Death();

		}
		if (true == IssacColltion->Collision(CheckHeart, ICollisions))
		{
			//ChangeState(IssacState::GET);
			TearSpeed += 100;
			ICollisions[0]->GetActor()->Death();

		}
		if (true == IssacColltion->Collision(CheckMonsterA, ICollisions))
		{

			ICollisions[0]->GetActor()->Death();
			HP -= 1;
			IssacColltion->Off();

		}
		
	}
	
}

void Issac::BombCheck(float _DeltaTime)
{
	ResetTimeBombs += _DeltaTime;
	if (false == GameEngineInput::IsDown("Bomb"))
	{
		return;
	}
	if (ResetTimeBombs > 1.0f) 
	{ 
		ResetTimeBombs = 0.0f;
	} 
	else { 
		return; 
	}

	if (true == GameEngineInput::IsDown("Bomb"))
	{
		if (0 != BombCount)
		{
			Bomb* NewBomb = GetLevel()->CreateActor<Bomb>(IssacRenderOrder::Player);
			BombCount -= 1;
		}
	}
}

void Issac::DirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1)
{
	std::string PrevDirString = DirString;
	IssacHeadRender->ChangeAnimation(DirString + _AnimationName.data());

	std::string PrevDirStringB = BDirString;
	IssacBodyRender->ChangeAnimation(BDirString + _AnimationName1.data());

	if (GameEngineInput::IsPress("LeftMove"))
	{
		DirString = "Left_";
		BDirString = "Left_";
	}
	else if (GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
		BDirString = "Right_";

	}
	else if (GameEngineInput::IsPress("UpMove"))
	{
		DirString = "Up_";
		BDirString = "Up_";

	}

	else if (GameEngineInput::IsPress("DownMove"))
	{
		DirString = "Down_";
		BDirString = "Down_";

	}
	if (GameEngineInput::IsPress("LeftTears"))
	{
		DirString = "Left_";
		BDirString = "Right_";
	}
	else if (GameEngineInput::IsPress("RightTears"))
	{
		DirString = "Right_";
		BDirString = "Right_";

	}
	else if (GameEngineInput::IsPress("UpTears"))
	{
		DirString = "Up_";
		BDirString = "Up_";

	}

	else if (GameEngineInput::IsPress("DownTears"))
	{
		DirString = "Down_";
		BDirString = "Down_";

	}
	if (PrevDirString != DirString)
	{
		IssacHeadRender->ChangeAnimation(DirString + _AnimationName.data());
		IssacBodyRender->ChangeAnimation(DirString + _AnimationName1.data());
	}
}

void Issac::TearsAttack(float _DeltaTime)
{
	ResetTimeTears += _DeltaTime;

	if (false == GameEngineInput::IsDown("LeftTears") &&
		false == GameEngineInput::IsDown("RightTears") &&
		false == GameEngineInput::IsDown("UpTears") &&
		false == GameEngineInput::IsDown("DownTears"))
	{
		return;
	}
	if (ResetTimeTears > TearAttSpeed)
	{
		ResetTimeTears = 0.0f;
	}
	else {
		return;
	}

	Tears* NewTears = GetLevel()->CreateActor<Tears>(IssacRenderOrder::Player);

	float4 Dir;
	if (true == GameEngineInput::IsPress("LeftTears"))
	{
		
		Dir += float4::Left;
		NewTears->SetLeftMoveDir(Dir); 
		NewTears->SetPos(GetPos());
	}
	else if (true == GameEngineInput::IsPress("RightTears"))
	{
		Dir += float4::Right;
		NewTears->SetLeftMoveDir(Dir); 
		NewTears->SetPos(GetPos());
	}
	if (true == GameEngineInput::IsPress("UpTears"))
	{
		Dir += float4::Up;
		NewTears->SetLeftMoveDir(Dir); 
		NewTears->SetPos(GetPos());
	}
	if (true == GameEngineInput::IsPress("DownTears"))
	{
		Dir += float4::Down;
		NewTears->SetLeftMoveDir(Dir); 
		NewTears->SetPos(GetPos());
	}

	
}
void Issac::Render(float _DeltaTime)
{
//	IssacColltion->DebugRender();

}