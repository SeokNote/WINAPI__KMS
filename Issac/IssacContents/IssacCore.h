#pragma once
#include <GameEngineCore/GameEngineCore.h>

// �̷��� Ŭ������ ����� ��� ����ü�� �̱����̶�� �մϴ�.

// ���� :
class IssacCore : public GameEngineCore
{
public:
	// delete Function
	IssacCore(const IssacCore& _Other) = delete;
	IssacCore(IssacCore&& _Other) noexcept = delete;
	IssacCore& operator=(const IssacCore& _Other) = delete;
	IssacCore& operator=(IssacCore&& _Other) noexcept = delete;

	// �̱���
	static IssacCore& GetInst()
	{
		return Core;
	}

	// �����ͷ� ����ÿ��� �߰��� ������ �����ϴٴ� ������ �ִ�.
	//static StudyGameCore& Destroy()
	//{
	//	delete Core;
	//}

protected:
	void Start() override;
	void Update() override;
	void End() override;


private:
	// �����ڸ� ����.
	// constrcuter destructer
	IssacCore();
	~IssacCore();

	// �ڱ⸦ �ڽ��� ������
	// ���α׷��� ��Ʋ� ���� 1���� ��ü�� ���������
	// static StudyGameCore* Core;
	static IssacCore Core;

};

