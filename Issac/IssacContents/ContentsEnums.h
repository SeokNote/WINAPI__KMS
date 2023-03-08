#pragma once

enum class IssacRenderOrder
{
	title,
	BackGround,
	Map,
	Door,
	Object,
	Player,
	Monster,
	Dead,
};

enum class  IssacCollisionOrder
{
//-----------
	ItemBomb,
	ItemCoin,
	ItemKey,
	ItemHeart,
	ItemGlasses,
	ItemLeo,
	Heart,
//-----------
	Door,
	Poop,
	Rock,
	Bomb,
	Spike,
//-----------	
	Player,
	PlayerAttack,

	Monster,
	MonsterAttack,
	MonsterSet,
};