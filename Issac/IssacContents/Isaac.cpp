#include "Isaac.h"
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

Isaac* Isaac::MainPlayer;

Isaac::Isaac()
{
}

Isaac::~Isaac()
{
}

void Isaac::Start()
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
		IsaacBodyRender = CreateRender(IsaacRenderOrder::Player);
		IsaacBodyRender->SetScale({ 55, 55 });
		IsaacBodyRender->SetPosition({ 0,29 });
		//Idle
		IsaacBodyRender->CreateAnimation({ .AnimationName = "Down_BIdle",  .ImageName = "Right_Isaac.bmp",.Start = 8, .End = 8 });
		IsaacBodyRender->CreateAnimation({ .AnimationName = "Left_BIdle",  .ImageName = "Left_Isaac.bmp",.Start = 8, .End = 8 });
		IsaacBodyRender->CreateAnimation({ .AnimationName = "Up_BIdle",  .ImageName = "Right_Isaac.bmp",.Start = 8, .End = 8 });
		IsaacBodyRender->CreateAnimation({ .AnimationName = "Right_BIdle",  .ImageName = "Right_Isaac.bmp",.Start = 8, .End = 8 });
		//Move
		IsaacBodyRender->CreateAnimation({ .AnimationName = "Right_BMove",  .ImageName = "Right_Isaac.bmp",.Start = 16, .End = 22, .InterTime = 0.1f });
		IsaacBodyRender->CreateAnimation({ .AnimationName = "Left_BMove", .ImageName = "Left_Isaac.bmp", .Start = 16, .End = 22, .InterTime = 0.1f });
		IsaacBodyRender->CreateAnimation({ .AnimationName = "Down_BMove", .ImageName = "Left_Isaac.bmp", .Start = 6, .End = 13, .InterTime = 0.1f });
		IsaacBodyRender->CreateAnimation({ .AnimationName = "Up_BMove", .ImageName = "Left_Isaac.bmp", .Start = 6, .End = 13, .InterTime = 0.1f });


		//Idle
		IsaacHeadRender = CreateRender(IsaacRenderOrder::Player);
		IsaacHeadRender->SetScale({ 70, 70 });
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Down_HIdle",  .ImageName = "Right_Isaac.bmp",.Start = 0, .End = 0, });//기본상태
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Up_HIdle",  .ImageName = "Right_Isaac.bmp",.Start = 0, .End = 0, });
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Left_HIdle",  .ImageName = "Left_Isaac.bmp",.Start = 0, .End = 0, });
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Right_HIdle",  .ImageName = "Right_Isaac.bmp",.Start = 0, .End = 0, });
		//Move
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Right_HMove",  .ImageName = "Right_Isaac.bmp",.Start = 2, .End = 2});
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Left_HMove", .ImageName = "Left_Isaac.bmp", .Start = 2, .End = 2 });
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Up_HMove", .ImageName = "Left_Isaac.bmp", .Start = 4, .End = 5,.InterTime = 0.2f });
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Down_HMove", .ImageName = "Left_Isaac.bmp", .Start = 0, .End = 0,.InterTime = 0.2f });
		//Attack
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Down_Attack",  .ImageName = "Right_Isaac.bmp",.Start = 1, .End = 1,.InterTime = 0.2f });//기본상태
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Up_Attack",  .ImageName = "Right_Isaac.bmp",.Start = 5, .End = 5,.InterTime = 0.2f });
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Left_Attack",  .ImageName = "Left_Isaac.bmp",.Start = 3, .End = 3,.InterTime = 0.2f });
		IsaacHeadRender->CreateAnimation({ .AnimationName = "Right_Attack",  .ImageName = "Right_Isaac.bmp",.Start = 3, .End = 3, .InterTime = 0.2f });



		/*GetRender = CreateRender(IsaacRenderOrder::Player);
		GetRender->SetScale({ 125, 125 });
		GetRender->CreateAnimation({ .AnimationName = "GetItem",  .ImageName = "Isaac_Anim.bmp",.Start = 5, .End = 5, });*/

	}
	{
		IsaacColltion = CreateCollision(IsaacCollisionOrder::Player);
		IsaacColltion->SetScale({ 50,50 });
		IsaacColltion->On();
		IsaacColltion->SetDebugRenderType(CollisionType::CT_Rect);
	}
	ChangeState(IsaacState::IDLE);

}


 

void Isaac::Update(float _DeltaTime)
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
void Isaac::Movecalculation(float _DeltaTime)
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

void Isaac::CollisionCheck(float _DeltaTime)
{
	CollTime += _DeltaTime;
	if (CollTime >= 2.0f)
	{
		CollTime = 0.0f;
		IsaacColltion->On();
	


	}
	if (nullptr != IsaacColltion)
	{
		if (true == IsaacColltion->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{

			CollTime += _DeltaTime;
			HP -= 2;
			IsaacColltion->Off();
		}

		if (true == IsaacColltion->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Spike), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{

			CollTime += _DeltaTime;
			HP -= 1;
			IsaacColltion->Off();
		}
		if (true == IsaacColltion->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{

			CollTime += _DeltaTime;
			HP -= 1;
			IsaacColltion->Off();
		}
		
		std::vector<GameEngineCollision*> ICollisions;
		CollisionCheckParameter CheckHp = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::ItemHeart), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckKey = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::ItemKey), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckBomb = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::ItemBomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckCoin = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::ItemCoin), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckGlasses = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::ItemGlasses), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckLeo = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::ItemLeo), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckHeart = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::Heart), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckMonsterA = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::MonsterAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		//Heart
		if (true == IsaacColltion->Collision(CheckHp, ICollisions) && 6 != HP)
		{
			ICollisions[0]->GetActor()->Death();
			HP += 2;
			if (HP > MaxHP)
			{
				HP = MaxHP;
			}
		}
		//Key
		if (true == IsaacColltion->Collision(CheckKey, ICollisions))
		{
	
			ICollisions[0]->GetActor()->Death();
			KeyCount += 1;
		}
		//Bomb
		if (true == IsaacColltion->Collision(CheckBomb, ICollisions))
		{
			ICollisions[0]->GetActor()->Death();
			BombCount += 1;
		}
		//Coin
		if (true == IsaacColltion->Collision(CheckCoin, ICollisions))
		{
			
			ICollisions[0]->GetActor()->Death();
			CoinCount += 1;
		}
		if (true == IsaacColltion->Collision(CheckGlasses, ICollisions))
		{
			//ChangeState(IsaacState::GET);
			TearAttSpeed -= 0.1f;
			ICollisions[0]->GetActor()->Death();

		}
		if (true == IsaacColltion->Collision(CheckLeo, ICollisions))
		{
			//ChangeState(IsaacState::GET);
			TearDamage += 2;
			ICollisions[0]->GetActor()->Death();

		}
		if (true == IsaacColltion->Collision(CheckHeart, ICollisions))
		{
			//ChangeState(IsaacState::GET);
			TearSpeed += 100;
			ICollisions[0]->GetActor()->Death();

		}
		if (true == IsaacColltion->Collision(CheckMonsterA, ICollisions))
		{

			ICollisions[0]->GetActor()->Death();
			HP -= 1;
			IsaacColltion->Off();

		}
		
	}
	
}

void Isaac::BombCheck(float _DeltaTime)
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
			Bomb* NewBomb = GetLevel()->CreateActor<Bomb>(IsaacRenderOrder::Player);
			BombCount -= 1;
		}
	}
}

void Isaac::DirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1)
{
	std::string PrevDirString = DirString;
	IsaacHeadRender->ChangeAnimation(DirString + _AnimationName.data());

	std::string PrevDirStringB = BDirString;
	IsaacBodyRender->ChangeAnimation(BDirString + _AnimationName1.data());

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
		IsaacHeadRender->ChangeAnimation(DirString + _AnimationName.data());
		IsaacBodyRender->ChangeAnimation(DirString + _AnimationName1.data());
	}
}

void Isaac::TearsAttack(float _DeltaTime)
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

	Tears* NewTears = GetLevel()->CreateActor<Tears>(IsaacRenderOrder::Player);

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
void Isaac::Render(float _DeltaTime)
{
//	IsaacColltion->DebugRender();

}