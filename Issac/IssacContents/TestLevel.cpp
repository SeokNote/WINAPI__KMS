#include "TestLevel.h"
#include "Issac.h"
#include "MonsterOne.h"
#include "Door.h"
#include "Poop.h"
#include "Rock.h"
#include "BombRock.h"
#include "Spike.h"

#include "ItemBomb.h"
#include "ItemCoin.h"
#include "ItemKey.h"
#include "ItemHeart.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/Button.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "MapOne.h"
#include "MouseObject.h"
#include "ContentsValue.h"

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
		GameEngineImage* Image1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StartOne.BMP")); 
		GameEngineImage* ColImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ColMap.BMP"));//맵

		GameEngineImage* Image3 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Door_Down.BMP"));

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Issac.BMP"));
			Image->Cut(8, 4);
		}
		{
			GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Issac.BMP"));
			Image2->Cut(8, 4);
		}
		{
			GameEngineImage* T_Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear.BMP"));
			T_Image->Cut(8, 4);
			GameEngineImage* T_ImagePop = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear_Pop.BMP"));
			T_ImagePop->Cut(4, 4);
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
void TestLevel::Loading()
{
	if (true == LoadImageBool) {
		ImageLoad();
		LoadImageBool = false;
	}


	Issac* NewIssac = CreateActor<Issac>();
	NewIssac->SetPos({ 500,500 });

	/*MonsterOne* NewMonster1 = CreateActor<MonsterOne>();
	NewMonster1->SetPos({ 200,200 });*/

	Poop* NewPoop = CreateActor<Poop>();
	NewPoop->SetPos({ 200,150 });


	Rock* NewRock = CreateActor<Rock>();
	NewRock->SetPos({ 200,250 });


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

	CreateActor<MapOne>();
	CreateActor<Door>();

	Start = float4::Zero;
	End = float4(0.0f, GameEngineWindow::GetScreenSize().half().y);

}


void TestLevel::Update(float _DeltaTime)
{



}


void TestLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	ContentsValue::CameraScale = { 2000, 3000 };
}
