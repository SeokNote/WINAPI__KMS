#include "IssacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "TitleLevel.h"
#include "IntroLevel.h"
#include "TestLevel.h"
// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// �߰��� ����� �������� �����ָ� ������������ ���� �����Ҵ��ؼ� ����Ѵٴ°�
// �������⿡�� ��??? �׷�������?
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

	// ������ ���� �������? ������ ������ ���ɴϴ�.
	// �Ǽ� 1.2 ���Ѵٸ� 
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