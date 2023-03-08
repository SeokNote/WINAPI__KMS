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
};

enum class  IssacCollisionOrder
{
//-----------
	ItemBomb,
	ItemCoin,
	ItemKey,
	ItemHeart,
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
};