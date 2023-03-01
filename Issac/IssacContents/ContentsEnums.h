#pragma once

enum class IssacRenderOrder
{
	title,
	BackGround,
	Map,
	Player,
	Monster,
};

enum class  IssacCollisionOrder
{
	Player,
	Monster,
	PlayerAttack,
	MonsterAttack,
};