#include "IssacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "TitleLevel.h"
#include "IntroLevel.h"
#include "TestLevel.h"
// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// 중간에 절대로 지워지지 않을애를 포인터형으로 만들어서 동적할당해서 사용한다는건
// 제가보기에는 왜??? 그래야하지?
IssacCore IssacCore::Core;

IssacCore::IssacCore()
{
}

IssacCore::~IssacCore()
{
}

void IssacCore::Start()
{
	// GameEngineDebug::LeakPointBreak(557);
	new int();

	// 정수의 연산 결과값은? 무조건 정수만 나옵니다.
	// 실수 1.2 원한다면 
	GameEngineWindow::SettingWindowSize({ 1280, 720 });


	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<TestLevel>("TestLevel");
	CreateLevel<IntroLevel>("IntroLevel");
	CreateLevel<IntroLevel>("Stage2Level");

	ChangeLevel("TitleLevel");
}

void IssacCore::Update()
{

}
void IssacCore::End()
{

}