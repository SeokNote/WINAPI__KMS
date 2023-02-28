#pragma once

enum class IssacRenderOrder
{
	title,
	BackGround,
	Map,
	Player,
	Monster,
};

enum class BubbleCollisionOrder
{
	Player,
	Monster,
	PlayerAttack,
	MonsterAttack,
};