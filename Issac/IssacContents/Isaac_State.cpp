#include "Isaac.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "ContentsEnums.h"


void Isaac::ChangeState(IsaacState _State)
{


	IsaacState NextState = _State;
	IsaacState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case IsaacState::IDLE:
		IdleStart();
		break;
	case IsaacState::MOVE:
		MoveStart();
		break;
	//case IsaacState::GET:
	//	GETStart();
	//	break;
	case IsaacState::Attack:
		//AttackStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case IsaacState::IDLE:
		IdleEnd();
		break;
	case IsaacState::MOVE:
		MoveEnd();
	//case IsaacState::GET:
	//	GETEnd();
	//	break;
	case IsaacState::Attack:
	//	AttackEnd();
		break;
	default:
		break;
	}
}


void Isaac::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case IsaacState::IDLE:
		IdleUpdate(_Time);
		break;
	case IsaacState::MOVE:
		MoveUpdate(_Time);
		break;
	/*case IsaacState::GET:
		GETUpdate(_Time);
		break;*/
	case IsaacState::Attack:
		//AttackUpdate(_Time);
		break;
	default:
		break;
	}


}





void Isaac::IdleStart() {


//	IsaacHeadRender->ChangeAnimation(DirString + "HIdle");
//	IsaacBodyRender->ChangeAnimation(DirString + "BIdle");
//	GetRender->ChangeAnimation("GetItem");

	DirCheck("HIdle", "BIdle");
	//DirCheck("BIdle");

}
void Isaac::IdleUpdate(float _Time) //가만히 있을때 뭘해야할까
{
	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove")|| GameEngineInput::IsPress("DownMove")|| GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(IsaacState::MOVE);
	}

}
void Isaac::IdleEnd() {


}

void Isaac::MoveStart() {

	//DirCheck("HMove");
	//DirCheck("BMove");
	DirCheck("HMove", "BMove");

//	IsaacHeadRender->ChangeAnimation(DirString +"HMove");
//	IsaacBodyRender->ChangeAnimation(DirString +"BMove");
//	GetRender->ChangeAnimation("GetItem");

}
void Isaac::MoveUpdate(float _Time) {


	if (false == GameEngineInput::IsPress("LeftMove") && false == GameEngineInput::IsPress("RightMove") && false == GameEngineInput::IsPress("DownMove") && false == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(IsaacState::IDLE);
		return; //최종 결정후 무조건 리턴
	}
	float4 Dir;
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		Dir += float4::Left;
	}
	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		Dir += float4::Right;
	}
	if (true == GameEngineInput::IsPress("DownMove"))
	{
		Dir += float4::Down;
	}
	if (true == GameEngineInput::IsPress("UpMove"))
	{
		Dir += float4::Up;
	}
	Dir.Normalize();
	MoveDir = Dir * MoveSpeed;

	DirCheck("HMove","BMove");

/*if (
		false == GameEngineInput::IsPress("LeftMove") && 
		false == GameEngineInput::IsPress("RightMove")
		)
	{
		// 
		ChangeState(PlayerState::IDLE);
		return;
	}

	// float4 MoveDir = float4::Zero;

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir += float4::Left * MoveSpeed;
	} else if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir += float4::Right * MoveSpeed;
	}


	DirCheck("Move");*/
}



void Isaac::MoveEnd() {


}


//void Isaac::GETStart() {
//
//
//	DirCheck("GetItem");
//
//}
//
//void Isaac::GETUpdate(float _Time) //가만히 있을때 뭘해야할까
//{
//	GetTime += _Time;
//	
//	
//		if (1.0f < GetTime) {
//			ChangeState(IsaacState::IDLE);
//		}
//
//
//}
//void Isaac::GETEnd() {
//
//	GetTime = 0.0f;
//}

//void Isaac::AttackStart()
//{
//	DirCheck("Attack", "BMove");
//
//}
//
//void Isaac::AttackUpdate(float _Time)
//{
//	if (false == GameEngineInput::IsPress("LeftTears") && false == GameEngineInput::IsPress("RightTears") && false == GameEngineInput::IsPress("DownTears") && false == GameEngineInput::IsPress("UpTears"))
//	{
//		ChangeState(IsaacState::MOVE);
//		return; //최종 결정후 무조건 리턴
//	}
//	//float4 Dir;
//	//if (true == GameEngineInput::IsPress("LeftTears"))
//	//{
//	//	Dir += float4::Left;
//	//}
//	//else if (true == GameEngineInput::IsPress("RightTears"))
//	//{
//	//	Dir += float4::Right;
//	//}
//	//if (true == GameEngineInput::IsPress("DownTears"))
//	//{
//	//	Dir += float4::Down;
//	//}
//	//if (true == GameEngineInput::IsPress("UpTears"))
//	//{
//	//	Dir += float4::Up;
//	//}
//
//	DirCheck("Attack", "BMove");
//}
//
//void Isaac::AttackEnd()
//{
//}
