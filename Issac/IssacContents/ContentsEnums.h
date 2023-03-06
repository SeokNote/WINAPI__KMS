#pragma once

enum class IssacRenderOrder
{
	title,
	BackGround,
	Object,
	Map,
	Player,
	Monster,
};

enum class  IssacCollisionOrder
{
	Door,
	Player,
	Monster,
	PlayerAttack,
	MonsterAttack,
};