#pragma once

enum class IsaacRenderOrder
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

enum class  IsaacCollisionOrder
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