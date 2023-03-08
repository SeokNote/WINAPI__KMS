
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Issac.h"
#include "ContentsEnums.h"
#include "Spike.h"




Spike::Spike()
{

}

Spike::~Spike()
{
}


void Spike::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Spikes = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Spikes.bmp"));
	Spikes->Cut(4, 5);

}

bool LoadSpike = true;
void Spike::Start()
{
	if (true == LoadSpike)
	{
		ImageLoad();
		LoadSpike = false;
	}
	SpikeRender = CreateRender(IssacRenderOrder::Object);
	SpikeRender->SetScale({ 70, 70 });



	SpikeRender->CreateAnimation({ .AnimationName = "Spike",  .ImageName = "Spikes.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	SpikeRender->ChangeAnimation("Spike");

	{

		SpikeCol = CreateCollision(IssacCollisionOrder::Spike);
		SpikeCol->SetScale({ 50, 50 });
		SpikeCol->On();
		SpikeCol->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Spike::Update(float _DeltaTime)
{
	//CollisionCheck(_DeltaTime);
}


void Spike::Render(float _DeltaTime)
{
	//Spike_Coll->DebugRender();
}