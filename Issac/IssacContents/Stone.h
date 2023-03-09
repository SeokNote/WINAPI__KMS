#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class STone : public GameEngineActor
{
public:
	STone();
	~STone();


	STone(const STone& _Other) = delete;
	STone(STone&& _Other) noexcept = delete;
	STone& operator=(const STone& _Other) = delete;
	STone& operator=(STone&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);
	void MoveCalculation(float _DeltaTime);


private:
	GameEngineRender* SToneRender = nullptr;
	GameEngineCollision* SToneCol = nullptr;

};

