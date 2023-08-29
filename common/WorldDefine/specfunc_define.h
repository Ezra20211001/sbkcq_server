#pragma once


#pragma pack(push, 1)

//------------------------------------------------------------------------------
// 物品特殊功能类型定义
//------------------------------------------------------------------------------

/** \物品特殊功能类型(该处用<val1, val2>表示有2个参数,<val>表示1个,没有注明表示没有)
*/
enum EItemSpecFunc	
{
	EISF_Null										= 0,	// 无

	EISF_AcceptQuest								= 1,	// 接取任务
	// nSpecFuncVal1: 任务编号
	// nSpecFuncVal2: 保留
	EISF_IdetifyEquip								= 2,	// 鉴定装备
	// nSpecFuncVal1: 0:普通 1:高级 2:史诗 3:传说
	// nSpecFuncVal2: 
	EISF_HoleGem									= 3,    // 镶嵌
	// nSpecFuncVal1: 装备最小等级
	// nSpecFuncVal2: 装备最大等级
	EISF_Luck										= 4,	// 祝福油
	// nSpecFuncVal1: 0 低级 1 高级
	// nSpecFuncVal2: 保留
	EISF_RemoveAttPt								= 6,	// 属性洗点
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留.

	EISF_RemoveTalentPt								= 7,	// 天资洗点
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EISF_LearnSkill									= 8,	// 学习技能
	// nSpecFuncVal1: 技能ID
	// nSpecFuncVal2: 保留
	EISF_Grind										= 9,	// 修复神水
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EISF_ComposeAdvance								= 10,	// 强化材料
	// nSpecFuncVal1: 最小强化等级	
	// nSpecFuncVal2: 最大强化等级
	EISF_OpenSafeGuard								= 11,	// 强开PK保护
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EISF_RevieveItem								= 12,	// 复活道具
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EISF_FriendGift									= 13,	// 好友礼物
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EISF_Chisel										= 15,	// 打孔
	// nSpecFuncVal1: 孔数限制
	// nSpecFuncVal2: 最大等级
	EISF_ProtectSign								= 16,	// 强化保护石
	// nSpecFuncVal1: 强化等级最小
	// nSpecFuncVal2: 强化等级最大
	EISF_Chest										= 17,	// 宝箱
	// nSpecFuncVal1: 宝箱开出的物品(宝箱表)
	// nSpecFuncVal2: 钥匙的TypeID
	EISF_ChestKey									= 18,	// 宝箱钥匙
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留

	//EISF_Chest*                                     = 19,   // 宝箱保留
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留

	EISF_PetEgg										= 20,	// 宠物蛋
	// nSpecFuncVal1: 原型ID
	// nSpecFuncVal2: 保留
	EISF_PetFood									= 21,	// 宠物食物
	// nSpecFuncVal1: 携带等级
	// nSpecFuncVal2: 精气值
	EISF_PetSkillBook								= 22,	// 宠物技能书
	// nSpecFuncVal1: 技能原型ID
	// nSpecFuncVal2: 保留
	EISF_PetLvlupStep								= 23,	// 宠物升阶
	// nSpecFuncVal1: 灵阶后将要到达的灵阶值
	// nSpecFuncVal2: 保留
	EISF_PetEquipment                               = 24,	// 宠物装备
	// nSpecFuncVal1: 装备原型ID
	// nSpecFuncVal2: 保留
	EISF_ColorProbability                           = 25,   // 指定颜色阶段几率提升
	// nSpecFuncVal1: 数字1-4，由低到高分别表示四个颜色稀有程度阶段：低，中，高，极高
	// nSpecFuncVal2: 1-10000，表示对指定阶段的几率的提升程度（10000表示提升100%）
	EISF_Dye                                        = 26,   // 染料
	// nSpecFuncVal1: 1-12，对应颜色贴图编号
	// nSpecFuncVal2: 保留
	EISF_CreateGuild								= 27,	// 创建帮会
	// nSpecFuncVal1: 
	// nSpecFuncVal2: 

	EISF_LeagueSkillBook							= 28,	// 家族技能典籍
	// nSpecFuncVal1: 上缴时提升进度增加量
	// nSpecFuncVal2: 家族贡献增加量

	EISF_PetExpPour									= 29,	// 宠物经验灌注
	// nSpecFuncVal1: 灌注经验值
	// nSpecFuncVal2: 保留
	EISF_PetEnhance									= 30,	// 宠物资质提升
	// nSpecFuncVal1: 灵兽的品级
	// nSpecFuncVal2: 最大资质值
	EISF_EquipLock									= 31,	// 装备锁定
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EISF_EquipUnLock								= 32,	// 装备解锁
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EISF_PetLock									= 33,	// 宠物锁定
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EISF_PetUnLock									= 34,	// 宠物解锁
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EISF_Repair										= 35,   //维修
	// nSpecFuncVal1: 维修物品数量加值
	// nSpecFuncVal2: 可以维修装备的品质
	EISF_Easy										= 36,	//易用
	// nSpecFuncVal1: 易用降低的等级
	// nSpecFuncVal2: 保留
	EIST_Unbeset									= 37,	//拆嵌
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EIST_ShengPin									= 38,	//升品
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EIST_EquipProduce								= 39,	//装备合成
	// nSpecFuncVal1: 配方ID
	// nSpecFuncVal2: 需要的合成必需品
	EIST_ShengXing									= 40,	//升星
	// nSpecFuncVal1: 升星物品等级
	// nSpecFuncVal2: 0：攻击强化 1：防御强化
	//	EISF_		= ,	// 
	EIST_Sing										= 41,   // 签名
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EIST_Delate										= 42,	// 弹劾
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留

	EIST_RideEquip									= 43,	// 坐骑装备	
	// nSpecFuncVal1: 提升坐骑速度比例（1-10000）
	// nSpecFuncVal2: 保留

	EIST_GodStone									= 44,	//神石(提升坐骑强化几率)
	// nSpecFuncVal1: 提升几率（1-10000）
	// nSpecFuncVal2: 保留

	EIST_SoulStone									= 45,	//魂魄石(坐骑强化专用)
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留

	EIST_CrushStone									= 46,	//磨铁石(坐骑打磨专用)
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留

	EIST_PRACTICE									= 47,	//武器修炼用道具
	// nSpecFuncVal1: 0:加速 1:加值
	// nSpecFuncVal2: 加多少	
	EIST_Hang										= 48,	// 在线挂机丹药
	// nSpecFuncVal1: 提升经验值
	// nSpecFuncVal2: 提升义气值
	EIST_Exp										= 49,	// 经验丹
	// nSpecFuncVal1: 提升经验值
	// nSpecFuncVal2: 保留
	EIST_Brother									= 50,	// 义气丹
	// nSpecFuncVal1: 提升义气值
	// nSpecFuncVal2: 保留
	EIST_SpePetItem									= 51,	// 宠物特殊道具
	// nSpecFuncVal1: 0:扩充宠物栏 1：随机宠物普通技能 2:随机普通和buff技能 3:随机特长
	// nSpecFuncVal2: 保留
	EIST_EquipBind									= 52,	// 装备绑定
	// nSpecFuncVal1: 生成属性类型
	// nSpecFuncVal2: 生成属性数值
	EIST_EquipUnBind								= 53,	// 装备解绑
	// nSpecFuncVal1: 0:装备解绑 1:坐骑解绑
	// nSpecFuncVal2: 保留
	EIST_BagExtand									= 54,	// 包裹扩充
	// nSpecFuncVal1: 0 背包 1 仓库
	// nSpecFuncVal2: 扩充个数
	EIST_WeaponFusion								= 55,	// 武器融合等级不降低
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EIST_Killbadge									= 56,	// 追杀令
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留	
	EIST_Produce_Picture							= 57,	// 合成图纸
	// nSpecFuncVal1: 配方ID
	// nSpecFuncVal2: 生成品质						
	EIST_QuestBind									= 58,
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EIST_ProduceBox									= 59,	// 打造宝盒
	// nSpecFuncVal1: 等级
	// nSpecFuncVal2: 类型 0 打造 1 炼丹
	EIST_GuildTrans									= 60,	// 帮会传送符
	// nSpecFuncVal1: 保留
	// nSpecFuncVal2: 保留
	EIST_FishingRod									= 61,	// 鱼竿
	// nSpecFuncVal1: 熟练度提升
	// nSpecFuncVal2: 钓鱼成功几率提升
	EIST_Bait										= 62,	// 鱼饵
	// nSpecFuncVal1: 0 或者 宝箱ID
	// nSpecFuncVal2:  概率提升
	EIST_ReAtt_Equip								= 63,	// 重置装备属性
	// nSpecFuncVal1: 装备最低等级限制
	// nSpecFuncVal2: 装备最高等级限制
	EIST_Pet_Change									= 64,	// 宠物蜕变丹
	// nSpecFuncVal1: 需要宠物等级
	// nSpecFuncVal2: 
	EIST_Pet_Fusion									= 65,	// 宠物融合
	// nSpecFuncVal1: 0 护元丹 1 固元丹 2 培元丹
	// nSpecFuncVal2:	
	EIST_Equip_Get_Wuhuen							= 66,	// 提取武魂道具
	// nSpecFuncVal1: 提取比例 万分比
	// nSpecFuncVal2:
	EIST_Equip_fumo									= 67,	// 饰品附魔提升暴击率
	// nSpecFuncVal1: 提高多少 万分比
	// nSpecFuncVal2:
	EIST_Equip_shipin								= 68,	// 未鉴定饰品
	// nSpecFuncVal1: 蓝色饰品id
	// nSpecFuncVal2: 紫色饰品id
	EIST_Guild_mianzhan								= 69,	// 帮会免战牌
	// nSpecFuncVal1: 
	// nSpecFuncVal2: 
	EIST_Pet_Roborn									= 70,	// 宠物复活
	// nSpecFuncVal1: 品质
	// nSpecFuncVal2: 

	EIST_Lottery_key								= 71,	// 彩票所需道具
	// nSpecFuncVal1: 0:a类 1:b类
	// nSpecFuncVal2: 保留
};	


/** \合成几率提升符 EISF_ComposeAdvance 可提升几率类别
*/
enum ESpecFuncComposeAdvance			
{
	ESFCA_AllProduce		= 0,	// 所有生产都可提升
	ESFCA_Artisan,					// 巧匠
	ESFCA_DanTraining,				// 练丹
	ESFCA_Smith,					// 锻造
	ESFCA_Casting,					// 铸甲
	ESFCA_Dressmaker,				// 裁缝
	ESFCA_Aechnics,					// 工艺
	ESFCA_Smilt,					// 冶练

	EISFC_AllConsolidate	= 10,	// 所有装备强化都可提升
	EISFC_Posy,						// 铭纹
	EISFC_Engrave,					// 镌刻
	EISFC_Quench,					// 淬火
	EISFC_ShengXing,				// 升星
	EISFC_Fusion,					// 融合

	EISFC_All				= 20,	// 所有合成都可提升 
};


#pragma pack(pop)
