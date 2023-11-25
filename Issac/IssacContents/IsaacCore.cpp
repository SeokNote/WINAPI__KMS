#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "TitleLevel.h"
#include "IntroLevel.h"
#include "TestLevel.h"
#include "EndLevel.h"

// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// �߰��� ����� �������� �����ָ� ������������ ���� �����Ҵ��ؼ� ����Ѵٴ°�
// �������⿡�� ��??? �׷�������?
IsaacCore IsaacCore::Core;

IsaacCore::IsaacCore()
{
}

IsaacCore::~IsaacCore()
{
}

void IsaacCore::Start()
{
	// GameEngineDebug::LeakPointBreak(557);
	new int();

	// ������ ���� �������? ������ ������ ���ɴϴ�.
	// �Ǽ� 1.2 ���Ѵٸ� 
	GameEngineWindow::SettingWindowSize({ 1280, 720 });


	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<TestLevel>("TestLevel");
	CreateLevel<IntroLevel>("IntroLevel");
	CreateLevel<EndLevel>("EndLevel");

	ChangeLevel("TitleLevel");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{
}