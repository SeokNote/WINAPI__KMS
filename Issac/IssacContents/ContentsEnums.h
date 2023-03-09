#pragma once

enum class IssacRenderOrder
{
	title,
	BackGround,
	Map,
	UI,
	Door,
	Object,
	Player,
	Monster,
	Dead,
	Boss,
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

	Boss,
	BossAttack,


	MonsterSetting,
	BossSetting,
};