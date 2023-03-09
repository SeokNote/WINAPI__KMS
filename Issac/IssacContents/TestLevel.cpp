#include "TestLevel.h"
#include "Issac.h"
#include "MonsterOne.h"
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

#include "MonsterOne.h"
#include "MonsterTwo.h"
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

		GameEngineImage* MonsterTwoDead = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Monster02_Dead.BMP"));
		MonsterTwoDead->Cut(5, 3);

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Issac.BMP"));
			Image->Cut(8, 4);
		}
		{
			GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Issac.BMP"));
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
			GameEngineImage* Hp = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP0.BMP"));
			GameEngineImage* Hp1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP1.BMP"));
			GameEngineImage* Hp2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP2.BMP"));
			GameEngineImage* Hp3 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP3.BMP"));
			GameEngineImage* Hp4 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP4.BMP"));
			GameEngineImage* Hp5 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP5.BMP"));
			GameEngineImage* Hp6 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerHP6.BMP"));

		}
		/*{
			GameEngineImage* MonsterImage1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Monster1.BMP"));
			MonsterImage1->Cut(4, 4);
		}
		{
			GameEngineImage* MonsterImage1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Monster1.BMP"));
			MonsterImage1->Cut(4, 4);
		}*/
	}

}
bool LoadImageBool = true;

void TestLevel::Loading()
{

	

	if (true == LoadImageBool) {
		ImageLoad();
		LoadImageBool = false;
	}


	Issac* NewIssac = CreateActor<Issac>();
	NewIssac->SetPos({ 300,300 });

	/*MonsterOne* NewMonster1 = CreateActor<MonsterOne>();
	NewMonster1->SetPos({ 200,200 });*/

	Poop* NewPoop = CreateActor<Poop>();
	NewPoop->SetPos({ 200,140 });


	Rock* NewRock = CreateActor<Rock>();
	NewRock->SetPos({ 200,260 });




	STone* NewSTone = CreateActor<STone>();
	NewSTone->SetPos({ 200,200 });

	BombRock* NewBombRock = CreateActor<BombRock>();
	NewBombRock->SetPos({ 200,450 });


	Spike* NewSpike = CreateActor<Spike>();
	NewSpike->SetPos({ 600,450 });

	ItemBomb* NewItemBomb = CreateActor<ItemBomb>();
	NewItemBomb->SetPos({ 200,500 });


	ItemCoin* NewItemCoin = CreateActor<ItemCoin>();
	NewItemCoin->SetPos({ 200,550 });

	ItemKey* NewItemKey = CreateActor<ItemKey>();
	NewItemKey->SetPos({ 300,500 });


	ItemHeart* NewItemHeart = CreateActor<ItemHeart>();
	NewItemHeart->SetPos({ 400,500 });


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

	Rock* NewRock1 = CreateActor<Rock>();
	NewRock1->SetPos({315+ 370,1100 });
	Rock* NewRock2 = CreateActor<Rock>();
	NewRock2->SetPos({ 315 + 315,1150 });
	Rock* NewRock3 = CreateActor<Rock>();
	NewRock3->SetPos({ 315 + 260,1100 });
	Rock* NewRock4 = CreateActor<Rock>();
	NewRock4->SetPos({ 315 + 315,1050 });

	
	
	Heart* NewHeart = CreateActor<Heart>();
	NewHeart->SetPos({ 930,1100 });
	
	STone* NewSTone5 = CreateActor<STone>();
	NewSTone5->SetPos({ 615+370,1100 });
	STone* NewSTone6 = CreateActor<STone>();
	NewSTone6->SetPos({ 615 + 315,1150 });
	STone* NewSTone7 = CreateActor<STone>();
	NewSTone7->SetPos({ 615 + 260,1100 });
	STone* NewSTone8 = CreateActor<STone>();
	NewSTone8->SetPos({ 615 + 315,1050 });

// Stage 2


	//MonsterOne* NewMonsterOne = CreateActor<MonsterOne>();
	//NewMonsterOne->SetPos({ 600,500 });
	
	//MonsterTwo* NewMonsterTwo = CreateActor<MonsterTwo>();
	//NewMonsterTwo->SetPos({ 1000,500 });


	//Loki* NewLoki = CreateActor<Loki>();
	//NewLoki->SetPos({ 1000,500 });

	
	CreateActor<MapOne>();
	CreateActor<MonsterSet>();
	CreateActor<BossSet>();
	CreateActor<HP>();

	

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

	if (true== SetMonster && true == Issac::MainPlayer->GetIssacCollision()->Collision({ .TargetGroup = static_cast<int>(IssacCollisionOrder::MonsterSetting),
	  .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		SetMonster = false;
		MonsterOne* NewMonster1 =CreateActor<MonsterOne>();
		NewMonster1->SetPos({ 230,1690 });
		MonsterOne* NewMonster2 = CreateActor<MonsterOne>();
		NewMonster2->SetPos({ 230,1790 });
		MonsterOne* NewMonster3 = CreateActor<MonsterOne>();
		NewMonster3->SetPos({ 230,1890 });

		MonsterTwo* NewMonster4 = CreateActor<MonsterTwo>();
		NewMonster4->SetPos({ 830,1690 });
		MonsterTwo* NewMonster5 = CreateActor<MonsterTwo>();
		NewMonster5->SetPos({ 830,1790 });
		MonsterTwo* NewMonster6 = CreateActor<MonsterTwo>();
		NewMonster6->SetPos({ 830,1890 });

	}

	if (true == SetBoss && true == Issac::MainPlayer->GetIssacCollision()->Collision({ .TargetGroup = static_cast<int>(IssacCollisionOrder::BossSetting),
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
	float IssacY = Issac::MainPlayer->GetPos().y;
	float YSize= GameEngineWindow::GetScreenSize().y;
	if (IssacY > YSize)
	{
		IssacY = IssacY - (YSize * MoveY);
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
		if (IssacY > 570.0f)
		{
			End = Start + float4(0, YSize);
			MoveMap = false;
			MoveY = MoveY + 1;
			Issac::MainPlayer->SetPos({640,120+(YSize*(float)MoveY)});
			int a = 0;
		}
	}
}
