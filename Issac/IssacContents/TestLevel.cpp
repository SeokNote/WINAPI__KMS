#include "TestLevel.h"
#include "Isaac.h"
#include "Door.h"
#include "Poop.h"
#include "Rock.h"
#include "Stone.h"
#include "BombRock.h"
#include "Spike.h"

#include "MonsterSet.h"
#include "BossSet.h"
#include "HpBar.h"
#include "HP.h"


#include "ItemBomb.h"
#include "ItemCoin.h"
#include "ItemKey.h"
#include "ItemHeart.h"
#include "Glasses.h"
#include "Leo.h"
#include "Heart.h"
#include "BoomCount.h"
#include "CoinCount.h"
#include "KeyCount.h"

#include "Pooter.h"
#include "Fly.h"
#include "Loki.h"

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/Button.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "MapOne.h"
#include "MouseObject.h"
#include "ContentsValue.h"
#include "ContentsEnums.h"


TestLevel::TestLevel()
{
}

TestLevel::~TestLevel()
{
}

void TestLevel::ImageLoad() {


	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// 이미지 로드
	{
		GameEngineImage* Image1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BaseMap.BMP")); 
		GameEngineImage* ColImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BaseColMap.BMP"));//맵

		GameEngineImage* Image3 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Door_Down.BMP"));

		GameEngineImage* ItemUI = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ItemsUI.BMP"));
		ItemUI->Cut(3, 2);
		GameEngineImage* Number = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Number.BMP"));
		Number->Cut(10, 1);
		GameEngineImage* FlyDead = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Monster02_Dead.BMP"));
		FlyDead->Cut(5, 3);

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Isaac.BMP"));
			Image->Cut(8, 4);
		}
		{
			GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Isaac.BMP"));
			Image2->Cut(8, 4);
		}
		
			
		{
			GameEngineImage* GetImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac_Anim.BMP"));
			GetImage->Cut(4, 3);
			GameEngineImage* TearImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear.BMP"));
			TearImage->Cut(8, 4);
			GameEngineImage* TearImagePop = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear_Pop.BMP"));
			TearImagePop->Cut(4, 4);
		}
		{
			GameEngineImage* Hp = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("HP.BMP"));
			Hp->Cut(5, 2);
	
			//GameEngineImage* Hp1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP1.BMP"));
			//GameEngineImage* Hp2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP2.BMP"));
			//GameEngineImage* Hp3 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP3.BMP"));
			//GameEngineImage* Hp4 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP4.BMP"));
			//GameEngineImage* Hp5 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP5.BMP"));
			//GameEngineImage* Hp6 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP6.BMP"));

		}
		
	}

}
bool LoadImageBool = true;

void TestLevel::Loading()
{

	

	if (true == LoadImageBool) {
		ImageLoad();
		LoadImageBool = false;
	}


	Isaac* NewIsaac = CreateActor<Isaac>();
	NewIsaac->SetPos({ 300,300 });

	Rock* NewRR = CreateActor<Rock>();
	NewRR->SetPos({ 165,145 });

	Rock* NewRR1 = CreateActor<Rock>();
	NewRR1->SetPos({ 1115,145 });

	Rock* NewRR2 = CreateActor<Rock>();
	NewRR2->SetPos({ 165,580 });

	Rock* NewRR3 = CreateActor<Rock>();
	NewRR3->SetPos({ 1115,580 });

	Spike* NewSpike = CreateActor<Spike>();
	NewSpike->SetPos({ 600,450 });

	//

	ItemBomb* NewItemBomb = CreateActor<ItemBomb>();
	NewItemBomb->SetPos({ 300,200 });


	ItemCoin* NewItemCoin = CreateActor<ItemCoin>();
	NewItemCoin->SetPos({ 500,200 });

	ItemKey* NewItemKey = CreateActor<ItemKey>();
	NewItemKey->SetPos({ 700,200 });


	ItemHeart* NewItemHeart = CreateActor<ItemHeart>();
	NewItemHeart->SetPos({ 900,200 });


// Stage 2
	Glasses* NewGlasses = CreateActor<Glasses>();
	NewGlasses->SetPos({ 315,1100 });

	STone* NewSTone1 = CreateActor<STone>();
	NewSTone1->SetPos({ 370,1100 });
	STone* NewSTone2 = CreateActor<STone>();
	NewSTone2->SetPos({ 315,1150 });
	STone* NewSTone3 = CreateActor<STone>();
	NewSTone3->SetPos({ 260,1100 });
	STone* NewSTone4 = CreateActor<STone>();
	NewSTone4->SetPos({ 315,1050 });

	Leo* NewLeo = CreateActor<Leo>();
	NewLeo->SetPos({ 630,1100 });

	Poop* NewRock1 = CreateActor<Poop>();
	NewRock1->SetPos({315+ 370,1100 });
	Poop* NewRock2 = CreateActor<Poop>();
	NewRock2->SetPos({ 315 + 315,1150 });
	Poop* NewRock3 = CreateActor<Poop>();
	NewRock3->SetPos({ 315 + 260,1100 });
	Poop* NewRock4 = CreateActor<Poop>();
	NewRock4->SetPos({ 315 + 315,1050 });

	
	
	Heart* NewHeart = CreateActor<Heart>();
	NewHeart->SetPos({ 930,1100 });
	
	STone* NewSTone5 = CreateActor<STone>();
	NewSTone5->SetPos({ 615+370,1100 });
	STone* NewSTone6 = CreateActor<STone>();
	NewSTone6->SetPos({ 615 + 315,1150 });
	BombRock* NewSTone7 = CreateActor<BombRock>();
	NewSTone7->SetPos({ 615 + 260,1100 });
	STone* NewSTone8 = CreateActor<STone>();
	NewSTone8->SetPos({ 615 + 315,1050 });



	CreateActor<MapOne>();
	CreateActor<MonsterSet>();
	CreateActor<BossSet>();
	CreateActor<HP>();
	CreateActor<BoomCount>();
	CreateActor<CoinCount>();
	CreateActor<KeyCount>();
	
}

bool SetMonster = true;
bool SetBoss = true;

void TestLevel::Update(float _DeltaTime)
{
	MoveMaps();
	
	if (false == MoveMap)
	{
		_Time += _DeltaTime * 3.0f;
	}

	if (true== SetMonster && true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::MonsterSetting),
	  .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		SetMonster = false;
		Pooter* NewMonster1 =CreateActor<Pooter>();
		NewMonster1->SetPos({ 230,1690 });
		Pooter* NewMonster2 = CreateActor<Pooter>();
		NewMonster2->SetPos({ 230,1790 });
		Pooter* NewMonster3 = CreateActor<Pooter>();
		NewMonster3->SetPos({ 230,1890 });

		Fly* NewMonster4 = CreateActor<Fly>();
		NewMonster4->SetPos({ 830,1690 });
		Fly* NewMonster5 = CreateActor<Fly>();
		NewMonster5->SetPos({ 830,1790 });
		Fly* NewMonster6 = CreateActor<Fly>();
		NewMonster6->SetPos({ 830,1890 });

	}

	if (true == SetBoss && true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::BossSetting),
	  .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		SetBoss = false;
		Loki* NewLoki = CreateActor<Loki>();
		NewLoki->SetPos({ 1000,2500 });
		HpBar* NewHpbar = CreateActor<HpBar>();
		NewHpbar->SetPos({ 600,2800 });

	}
}



void TestLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}
int MoveY = 0;
void TestLevel::MoveMaps()
{
	float IsaacY = Isaac::MainPlayer->GetPos().y;
	float YSize= GameEngineWindow::GetScreenSize().y;
	if (IsaacY > YSize)
	{
		IsaacY = IsaacY - (YSize * MoveY);
	}
	float4 Pos = float4::LerpClamp(Start, End, _Time);

	if (_Time >= 1.0f)
	{
		MoveMap = true;
		_Time = 0.0f;
		Start = Pos;
	}

	SetCameraPos(Pos);

	if (true == MoveMap)
	{
		if (IsaacY > 570.0f)
		{
			End = Start + float4(0, YSize);
			MoveMap = false;
			MoveY = MoveY + 1;
			Isaac::MainPlayer->SetPos({640,140+(YSize*(float)MoveY)});
			int a = 0;
		}
	}
}
