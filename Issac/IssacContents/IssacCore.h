#pragma once
#include <GameEngineCore/GameEngineCore.h>

// 이렇게 클래스를 만드는 방식 그자체를 싱글톤이라고 합니다.

// 설명 :
class IssacCore : public GameEngineCore
{
public:
	// delete Function
	IssacCore(const IssacCore& _Other) = delete;
	IssacCore(IssacCore&& _Other) noexcept = delete;
	IssacCore& operator=(const IssacCore& _Other) = delete;
	IssacCore& operator=(IssacCore&& _Other) noexcept = delete;

	// 싱글톤
	static IssacCore& GetInst()
	{
		return Core;
	}

	// 포인터로 만들시에는 중간에 삭제가 용이하다는 장점이 있다.
	//static StudyGameCore& Destroy()
	//{
	//	delete Core;
	//}

protected:
	void Start() override;
	void Update() override;
	void End() override;


private:
	// 생성자를 막아.
	// constrcuter destructer
	IssacCore();
	~IssacCore();

	// 자기를 자신이 가지면
	// 프로그램을 통틀어서 오직 1개의 객체만 만들어진다
	// static StudyGameCore* Core;
	static IssacCore Core;

};

