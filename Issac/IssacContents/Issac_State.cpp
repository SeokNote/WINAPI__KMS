#include "Issac.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "ContentsEnums.h"


void Issac::ChangeState(IssacState _State)
{


	IssacState NextState = _State;
	IssacState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case IssacState::IDLE:
		IdleStart();
		break;
	case IssacState::MOVE:
		MoveStart();
		break;
	//case IssacState::GET:
	//	GETStart();
	//	break;
	case IssacState::Attack:
		//AttackStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case IssacState::IDLE:
		IdleEnd();
		break;
	case IssacState::MOVE:
		MoveEnd();
	//case IssacState::GET:
	//	GETEnd();
	//	break;
	case IssacState::Attack:
	//	AttackEnd();
		break;
	default:
		break;
	}
}


void Issac::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case IssacState::IDLE:
		IdleUpdate(_Time);
		break;
	case IssacState::MOVE:
		MoveUpdate(_Time);
		break;
	/*case IssacState::GET:
		GETUpdate(_Time);
		break;*/
	case IssacState::Attack:
		//AttackUpdate(_Time);
		break;
	default:
		break;
	}


}





void Issac::IdleStart() {


//	IssacHeadRender->ChangeAnimation(DirString + "HIdle");
//	IssacBodyRender->ChangeAnimation(DirString + "BIdle");
//	GetRender->ChangeAnimation("GetItem");

	DirCheck("HIdle", "BIdle");
	//DirCheck("BIdle");

}
void Issac::IdleUpdate(float _Time) //가만히 있을때 뭘해야할까
{
	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove")|| GameEngineInput::IsPress("DownMove")|| GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(IssacState::MOVE);
	}

}
void Issac::IdleEnd() {


}

void Issac::MoveStart() {

	//DirCheck("HMove");
	//DirCheck("BMove");
	DirCheck("HMove", "BMove");

//	IssacHeadRender->ChangeAnimation(DirString +"HMove");
//	IssacBodyRender->ChangeAnimation(DirString +"BMove");
//	GetRender->ChangeAnimation("GetItem");

}
void Issac::MoveUpdate(float _Time) {


	if (false == GameEngineInput::IsPress("LeftMove") && false == GameEngineInput::IsPress("RightMove") && false == GameEngineInput::IsPress("DownMove") && false == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(IssacState::IDLE);
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



void Issac::MoveEnd() {


}


//void Issac::GETStart() {
//
//
//	DirCheck("GetItem");
//
//}
//
//void Issac::GETUpdate(float _Time) //가만히 있을때 뭘해야할까
//{
//	GetTime += _Time;
//	
//	
//		if (1.0f < GetTime) {
//			ChangeState(IssacState::IDLE);
//		}
//
//
//}
//void Issac::GETEnd() {
//
//	GetTime = 0.0f;
//}

//void Issac::AttackStart()
//{
//	DirCheck("Attack", "BMove");
//
//}
//
//void Issac::AttackUpdate(float _Time)
//{
//	if (false == GameEngineInput::IsPress("LeftTears") && false == GameEngineInput::IsPress("RightTears") && false == GameEngineInput::IsPress("DownTears") && false == GameEngineInput::IsPress("UpTears"))
//	{
//		ChangeState(IssacState::MOVE);
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
//void Issac::AttackEnd()
//{
//}
