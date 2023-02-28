#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class MapOne : public GameEngineActor
{
public:
	// constrcuter destructer
	MapOne();
	~MapOne();

	// delete Function
	MapOne(const MapOne& _Other) = delete;
	MapOne(MapOne&& _Other) noexcept = delete;
	MapOne& operator=(const MapOne& _Other) = delete;
	MapOne& operator=(MapOne&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
};

