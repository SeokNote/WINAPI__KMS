#include <Windows.h>
#include <IssacContents/IssacCore.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineRandom.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	// std::vector<unsigned int> Value = GameEngineMath::GetDigits(-1000);

	//std::vector<float> RandomTest;

	//for (size_t i = 0; i < 1000; i++)
	//{
	//	RandomTest.push_back(GameEngineRandom::MainRandom.RandomFloat(-10.0f, 10.0f));
	//}

	//std::vector<int> RandomInt;

	//for (size_t i = 0; i < 1000; i++)
	//{
	//	RandomInt.push_back(GameEngineRandom::MainRandom.RandomInt(-10, 10));
	//}


	IssacCore::GetInst().CoreStart(hInstance);
	return 1;
}