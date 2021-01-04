﻿#pragma once
#define SET_NUMBERH(x)			( (BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x)			( (BYTE)((DWORD)(x) & 0xFF) )
#define SET_NUMBERHW(x)			( (WORD)((DWORD)(x)>>(DWORD)16) )
#define SET_NUMBERLW(x)			( (WORD)((DWORD)(x) & 0xFFFF) )
#define SET_NUMBERHDW(x)		( (DWORD)((unsigned __int64)(x)>>(DWORD)32) )
#define SET_NUMBERLDW(x)		( (DWORD)((unsigned __int64)(x) & 0xFFFFFFFF) )
#define MAKE_NUMBERW(x,y)		( (WORD)(((BYTE)((y)&0xFF)) |   ((BYTE)((x)&0xFF)<<8 ))  )
#define MAKE_NUMBERQW(x,y)		( (unsigned __int64)(((DWORD)((y)&0xFFFFFFFF)) | ((DWORD)((x)&0xFFFFFFFF)<<32))  )
#define MAKE_NUMBERDW(x,y)		( (DWORD)(((WORD)((y)&0xFFFF)) | ((WORD)((x)&0xFFFF)<<16))  )
#define MAKEQWORD(a, b)			((__int64)(((DWORD)((__int64)(a) & 0xffffffff)) | ((__int64)((DWORD)((__int64)(b) & 0xffffffff))) << 32))  
#define LODWORD(h)				((DWORD)(__int64(h) & __int64(0xffffffff)))   
#define HIDWORD(h)				((DWORD)(__int64(h) >> __int64(32)))


//NETWORK
#define LOGIN_MAX_LEN 26
#define PASSWORD_MAX_LEN 32
#define VERSION_MAX_LEN 32

#define AUTH_IP_ADDRESS "127.0.0.1"
#define AUTH_PORT 55900
#define LOADER_VERSION "0.00.01";
#define SERVER_NAME_MAX_LEN 12

enum
{
	INVALID_PASSWORD,
	GRANTED,
	INVALID_ACCOUNT,
	ALREADY_CONNECTED,
	SERVER_FULL,
	ACCOUNT_BLOCKED,
	INVALID_VERSION,
	UNKNOWN_ERROR,
	TOO_MUCH_TRIES,
	NO_CHARGE_INFO,
	SUBSCRIPTION_OVER,
	IP_SUBSCRIPTION_OVER,

	CONNECTION_ERROR,
	TOO_YOUNG,
	MAINTENANCE
};
//END NETWORK

enum
{
	OBJECT_ALL = 1,
	OBJECT_MOB = 2,
	OBJECT_BOSS = 4,
	OBJECT_PC = 8,
	OBJECT_MINE = 16,
	OBJECT_STONE = 32,
	OBJECT_NPC = 64
};



inline char* GetStr(DWORD offset) {
	if (*(int*)(offset + 0x10) > 15)
		return (char*)(*(DWORD*)offset);
	else
		return (char*)offset;
}

typedef struct
{
	DWORD unk;
	char  name[24];
	DWORD		m_dwBaseX;
	DWORD		m_dwBaseY;
	DWORD		m_dwSizeX;
	DWORD		m_dwSizeY;
	DWORD		m_dwEndX;
	DWORD		m_dwEndY;
} TMapInfoGlobal;

typedef struct
{
	char  name[24];
	DWORD		m_dwBaseX;
	DWORD		m_dwBaseY;
	DWORD		m_dwSizeX;
	DWORD		m_dwSizeY;
	DWORD		m_dwEndX;
	DWORD		m_dwEndY;
} TMapInfo;



enum
{
	FUNC_WAIT,
	FUNC_MOVE,
	FUNC_ATTACK,
	FUNC_COMBO,
	FUNC_MOB_SKILL,
	FUNC_EMOTION,
	FUNC_SKILL = 0x80,
};

enum
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
};


enum Color
{
	RED,
	GREEN,
	BLUE,
	WHITE,
	BLACK
};
enum Windows
{
	RESERVED_WINDOW,
	INVENTORY,				
	EQUIPMENT,
	SAFEBOX,
	MALL,
	DRAGON_SOUL_INVENTORY,
	GROUND,					
	BELT_INVENTORY,			

	WINDOW_TYPE_MAX,
};
enum Directions
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	
};

enum
{
	MAIN_RACE_WARRIOR_M,
	MAIN_RACE_ASSASSIN_W,
	MAIN_RACE_SURA_M,
	MAIN_RACE_SHAMAN_W,
	MAIN_RACE_WARRIOR_W,
	MAIN_RACE_ASSASSIN_M,
	MAIN_RACE_SURA_W,
	MAIN_RACE_SHAMAN_M,
	MAIN_RACE_MAX_NUM,
};
enum Type
{
	TYPE_ENEMY,
	TYPE_NPC,
	TYPE_STONE,
	TYPE_WARP,
	TYPE_DOOR,
	TYPE_BUILDING,
	TYPE_PC,
	TYPE_POLY,
	TYPE_HORSE,
	TYPE_GOTO,

	TYPE_OBJECT, // Only For Client
};
enum PointTypes
{
	POINT_NONE,                 // 0
	POINT_LEVEL,                // 1
	POINT_VOICE,                // 2
	POINT_EXP,                  // 3
	POINT_NEXT_EXP,             // 4
	POINT_HP,                   // 5
	POINT_MAX_HP,               // 6
	POINT_SP,                   // 7
	POINT_MAX_SP,               // 8  
	POINT_STAMINA,              // 9  ½ºÅ×¹Ì³Ê
	POINT_MAX_STAMINA,          // 10 ÃÖ´ë ½ºÅ×¹Ì³Ê

	POINT_GOLD,                 // 11
	POINT_ST,                   // 12 ±Ù·Â
	POINT_HT,                   // 13 Ã¼·Â
	POINT_DX,                   // 14 ¹ÎÃ¸¼º
	POINT_IQ,                   // 15 Á¤½Å·Â
	POINT_ATT_POWER,            // 16 °ø°Ý·Â
	POINT_ATT_SPEED,            // 17 °ø°Ý¼Óµµ
	POINT_EVADE_RATE,           // 18 È¸ÇÇÀ²
	POINT_MOV_SPEED,            // 19 ÀÌµ¿¼Óµµ
	POINT_DEF_GRADE,            // 20 ¹æ¾îµî±Þ
	POINT_CASTING_SPEED,        // 21 ÁÖ¹®¼Óµµ (Äð´Ù¿îÅ¸ÀÓ*100) / (100 + ÀÌ°ª) = ÃÖÁ¾ Äð´Ù¿î Å¸ÀÓ
	POINT_MAGIC_ATT_GRADE,      // 22 ¸¶¹ý°ø°Ý·Â
	POINT_MAGIC_DEF_GRADE,      // 23 ¸¶¹ý¹æ¾î·Â
	POINT_EMPIRE_POINT,         // 24 Á¦±¹Á¡¼ö
	POINT_LEVEL_STEP,           // 25 ÇÑ ·¹º§¿¡¼­ÀÇ ´Ü°è.. (1 2 3 µÉ ¶§ º¸»ó, 4 µÇ¸é ·¹º§ ¾÷)
	POINT_STAT,                 // 26 ´É·ÂÄ¡ ¿Ã¸± ¼ö ÀÖ´Â °³¼ö
	POINT_SUB_SKILL,            // 27 º¸Á¶ ½ºÅ³ Æ÷ÀÎÆ®
	POINT_SKILL,                // 28 ¾×Æ¼ºê ½ºÅ³ Æ÷ÀÎÆ®
	
	POINT_MIN_ATK,				// 29 ÃÖ¼Ò ÆÄ±«·Â
	POINT_MAX_ATK,				// 30 ÃÖ´ë ÆÄ±«·Â
	POINT_PLAYTIME,             // 31 ÇÃ·¹ÀÌ½Ã°£
	POINT_HP_REGEN,             // 32 HP È¸º¹·ü
	POINT_SP_REGEN,             // 33 SP È¸º¹·ü

	POINT_BOW_DISTANCE,         // 34 È° »çÁ¤°Å¸® Áõ°¡Ä¡ (meter)

	POINT_HP_RECOVERY,          // 35 Ã¼·Â È¸º¹ Áõ°¡·®
	POINT_SP_RECOVERY,          // 36 Á¤½Å·Â È¸º¹ Áõ°¡·®

	POINT_POISON_PCT,           // 37 µ¶ È®·ü
	POINT_STUN_PCT,             // 38 ±âÀý È®·ü
	POINT_SLOW_PCT,             // 39 ½½·Î¿ì È®·ü
	POINT_CRITICAL_PCT,         // 40 Å©¸®Æ¼ÄÃ È®·ü
	POINT_PENETRATE_PCT,        // 41 °üÅëÅ¸°Ý È®·ü
	POINT_CURSE_PCT,            // 42 ÀúÁÖ È®·ü

	POINT_ATTBONUS_HUMAN,       // 43 ÀÎ°£¿¡°Ô °­ÇÔ
	POINT_ATTBONUS_ANIMAL,      // 44 µ¿¹°¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_ORC,         // 45 ¿õ±Í¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_MILGYO,      // 46 ¹Ð±³¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_UNDEAD,      // 47 ½ÃÃ¼¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_DEVIL,       // 48 ¸¶±Í(¾Ç¸¶)¿¡°Ô µ¥¹ÌÁö % Áõ°¡
	POINT_ATTBONUS_INSECT,      // 49 ¹ú·¹Á·
	POINT_ATTBONUS_FIRE,        // 50 È­¿°Á·
	POINT_ATTBONUS_ICE,         // 51 ºù¼³Á·
	POINT_ATTBONUS_DESERT,      // 52 »ç¸·Á·
	POINT_ATTBONUS_UNUSED0,     // 53 UNUSED0
	POINT_ATTBONUS_UNUSED1,     // 54 UNUSED1
	POINT_ATTBONUS_UNUSED2,     // 55 UNUSED2
	POINT_ATTBONUS_UNUSED3,     // 56 UNUSED3
	POINT_ATTBONUS_UNUSED4,     // 57 UNUSED4
	POINT_ATTBONUS_UNUSED5,     // 58 UNUSED5
	POINT_ATTBONUS_UNUSED6,     // 59 UNUSED6
	POINT_ATTBONUS_UNUSED7,     // 60 UNUSED7
	POINT_ATTBONUS_UNUSED8,     // 61 UNUSED8
	POINT_ATTBONUS_UNUSED9,     // 62 UNUSED9

	POINT_STEAL_HP,             // 63 »ý¸í·Â Èí¼ö
	POINT_STEAL_SP,             // 64 Á¤½Å·Â Èí¼ö

	POINT_MANA_BURN_PCT,        // 65 ¸¶³ª ¹ø

	

	POINT_DAMAGE_SP_RECOVER,   

	POINT_BLOCK,               
	POINT_DODGE,               

	POINT_RESIST_SWORD,         
	POINT_RESIST_TWOHAND,       
	POINT_RESIST_DAGGER,
	POINT_RESIST_BELL,
	POINT_RESIST_FAN,
	POINT_RESIST_BOW,
	POINT_RESIST_FIRE,
	POINT_RESIST_ELEC, 
	POINT_RESIST_MAGIC,
	POINT_RESIST_WIND,
	POINT_REFLECT_MELEE,
	POINT_REFLECT_CURSE,
	POINT_POISON_REDUCE,
	POINT_KILL_SP_RECOVER,
	POINT_EXP_DOUBLE_BONUS,    
	POINT_GOLD_DOUBLE_BONUS,    
	POINT_ITEM_DROP_BONUS,      
	POINT_POTION_BONUS,        
	POINT_KILL_HP_RECOVER,  
	POINT_IMMUNE_STUN,        
	POINT_IMMUNE_SLOW,          
	POINT_IMMUNE_FALL,         
	POINT_PARTY_ATT_GRADE,    
	POINT_PARTY_DEF_GRADE,  
	POINT_ATT_BONUS,
	POINT_DEF_BONUS,
	POINT_ATT_GRADE_BONUS,
	POINT_DEF_GRADE_BONUS,
	POINT_MAGIC_ATT_GRADE_BONUS,
	POINT_MAGIC_DEF_GRADE_BONUS,
	POINT_RESIST_NORMAL_DAMAGE,
	POINT_STAT_RESET_COUNT = 112,
	POINT_HORSE_SKILL = 113,
	POINT_MALL_ATTBONUS,	
	POINT_MALL_DEFBONUS,		
	POINT_MALL_EXPBONUS,	
	POINT_MALL_ITEMBONUS,	
	POINT_MALL_GOLDBONUS,		
	POINT_MAX_HP_PCT,		
	POINT_MAX_SP_PCT,			

	POINT_SKILL_DAMAGE_BONUS,       
	POINT_NORMAL_HIT_DAMAGE_BONUS, 
	POINT_SKILL_DEFEND_BONUS,   
	POINT_NORMAL_HIT_DEFEND_BONUS,  
	POINT_PC_BANG_EXP_BONUS,       
	POINT_PC_BANG_DROP_BONUS,   
	POINT_ENERGY = 128,
	POINT_ENERGY_END_TIME = 129,
	POINT_MIN_WEP = 200,
	POINT_MAX_WEP,
	POINT_MIN_MAGIC_WEP,
	POINT_MAX_MAGIC_WEP,
	POINT_HIT_RATE
};
enum ChatType
{
	CHAT_TYPE_TALKING,  
	CHAT_TYPE_INFO,   
	CHAT_TYPE_NOTICE, 
	CHAT_TYPE_PARTY,  
	CHAT_TYPE_GUILD,   
	CHAT_TYPE_COMMAND,	
	CHAT_TYPE_SHOUT,	
	CHAT_TYPE_WHISPER,	
	CHAT_TYPE_BIG_NOTICE,
	CHAT_TYPE_MAX_NUM,
};

enum ClientToServer
{
	HEADER_CG_LOGIN = 1,
	HEADER_CG_ATTACK = 2,
	HEADER_CG_CHAT = 3,
	HEADER_CG_PLAYER_CREATE = 4,
	HEADER_CG_PLAYER_DESTROY = 5,
	HEADER_CG_PLAYER_SELECT = 6,
	HEADER_CG_CHARACTER_MOVE = 7,
	HEADER_CG_SYNC_POSITION = 8,
	HEADER_CG_DIRECT_ENTER = 9,
	HEADER_CG_ENTERGAME = 10,
	HEADER_CG_ITEM_USE = 11,
	HEADER_CG_ITEM_DROP = 12,
	HEADER_CG_ITEM_MOVE = 13,
	HEADER_CG_ITEM_PICKUP = 15,
	HEADER_CG_QUICKSLOT_ADD = 16,
	HEADER_CG_QUICKSLOT_DEL = 17,
	HEADER_CG_QUICKSLOT_SWAP = 18,
	HEADER_CG_WHISPER = 19,
	HEADER_CG_ITEM_DROP2 = 20,
	HEADER_CG_ON_CLICK = 26,
	HEADER_CG_EXCHANGE = 27,
	HEADER_CG_CHARACTER_POSITION = 28,
	HEADER_CG_SCRIPT_ANSWER = 29,
	HEADER_CG_QUEST_INPUT_STRING = 30,
	HEADER_CG_QUEST_CONFIRM = 31,
	HEADER_CG_PVP = 41,
	HEADER_CG_SHOP = 50,
	HEADER_CG_FLY_TARGETING = 51,
	HEADER_CG_USE_SKILL = 52,
	HEADER_CG_ADD_FLY_TARGETING = 53,
	HEADER_CG_SHOOT = 54,
	HEADER_CG_MYSHOP = 55,
	HEADER_CG_ITEM_USE_TO_ITEM = 60,
	HEADER_CG_TARGET = 61,
	HEADER_CG_WARP = 65,
	HEADER_CG_SCRIPT_BUTTON = 66,
	HEADER_CG_MESSENGER = 67,
	HEADER_CG_MALL_CHECKOUT = 69,
	HEADER_CG_SAFEBOX_CHECKIN = 70,
	HEADER_CG_SAFEBOX_CHECKOUT = 71,
	HEADER_CG_PARTY_INVITE = 72,
	HEADER_CG_PARTY_INVITE_ANSWER = 73,
	HEADER_CG_PARTY_REMOVE = 74,
	HEADER_CG_PARTY_SET_STATE = 75,
	HEADER_CG_PARTY_USE_SKILL = 76,
	HEADER_CG_SAFEBOX_ITEM_MOVE = 77,
	HEADER_CG_PARTY_PARAMETER = 78,
	HEADER_CG_GUILD = 80,
	HEADER_CG_ANSWER_MAKE_GUILD = 81,
	HEADER_CG_FISHING = 82,
	HEADER_CG_GIVE_ITEM = 83,
	HEADER_CG_EMPIRE = 90,
	HEADER_CG_REFINE = 96,
	HEADER_CG_MARK_LOGIN = 100,
	HEADER_CG_MARK_CRCLIST = 101,
	HEADER_CG_MARK_UPLOAD = 102,
	HEADER_CG_MARK_IDXLIST = 104,
	HEADER_CG_CRC_REPORT = 103,
	HEADER_CG_HACK = 105,
	HEADER_CG_CHANGE_NAME = 106,
	HEADER_CG_SMS = 107,
	HEADER_CG_CHINA_MATRIX_CARD = 108,
	HEADER_CG_LOGIN2 = 109,
	HEADER_CG_DUNGEON = 110,
	HEADER_CG_LOGIN3 = 111,
	HEADER_CG_GUILD_SYMBOL_UPLOAD = 112,
	HEADER_CG_GUILD_SYMBOL_CRC = 113,
	HEADER_CG_SCRIPT_SELECT_ITEM = 114,
	HEADER_CG_LOGIN4 = 115,
	HEADER_CG_LOGIN5_OPENID = 116,
	HEADER_CG_RUNUP_MATRIX_ANSWER = 201,
	HEADER_CG_NEWCIBN_PASSPOD_ANSWER = 202,
	HEADER_CG_HS_ACK = 203,
	HEADER_CG_XTRAP_ACK = 204,
	HEADER_CG_DRAGON_SOUL_REFINE = 205,
	HEADER_CG_STATE_CHECKER = 206,
	HEADER_CG_KEY_AGREEMENT = 0xfb,
	HEADER_CG_TIME_SYNC = 0xfc,
	HEADER_CG_CLIENT_VERSION = 0xfd,
	HEADER_CG_CLIENT_VERSION2 = 0xf1,
	HEADER_CG_PONG = 0xfe,
	HEADER_CG_HANDSHAKE = 0xff,
};
enum ServerToClient
{
	HEADER_GC_CHARACTER_ADD = 1,
	HEADER_GC_CHARACTER_DEL = 2,
	HEADER_GC_CHARACTER_MOVE = 3,
	HEADER_GC_CHAT = 4,
	HEADER_GC_SYNC_POSITION = 5,
	HEADER_GC_LOGIN_SUCCESS3 = 6,
	HEADER_GC_LOGIN_FAILURE = 7,
	HEADER_GC_PLAYER_CREATE_SUCCESS = 8,
	HEADER_GC_PLAYER_CREATE_FAILURE = 9,
	HEADER_GC_PLAYER_DELETE_SUCCESS = 10,
	HEADER_GC_PLAYER_DELETE_WRONG_SOCIAL_ID = 11,
	HEADER_GC_STUN = 13,
	HEADER_GC_DEAD = 14,
	HEADER_GC_MAIN_CHARACTER = 15,
	HEADER_GC_PLAYER_POINTS = 16,
	HEADER_GC_PLAYER_POINT_CHANGE = 17,
	HEADER_GC_CHANGE_SPEED = 18,
	HEADER_GC_CHARACTER_UPDATE = 19,
	HEADER_GC_ITEM_SET = 20,
	HEADER_GC_ITEM_SET2 = 21,
	HEADER_GC_ITEM_USE = 22,
	HEADER_GC_ITEM_DROP = 23,
	HEADER_GC_ITEM_UPDATE = 25,
	HEADER_GC_ITEM_GROUND_ADD = 26,
	HEADER_GC_ITEM_GROUND_DEL = 27,
	HEADER_GC_QUICKSLOT_ADD = 28,
	HEADER_GC_QUICKSLOT_DEL = 29,
	HEADER_GC_QUICKSLOT_SWAP = 30,
	HEADER_GC_ITEM_OWNERSHIP = 31,
	HEADER_GC_LOGIN_SUCCESS4 = 32,
	HEADER_GC_ITEM_UNBIND_TIME = 33,
	HEADER_GC_WHISPER = 34,
	HEADER_GC_ALERT = 35,
	HEADER_GC_MOTION = 36,
	HEADER_GC_SHOP = 38,
	HEADER_GC_SHOP_SIGN = 39,
	HEADER_GC_DUEL_START = 40,
	HEADER_GC_PVP = 41,
	HEADER_GC_EXCHANGE = 42,
	HEADER_GC_CHARACTER_POSITION = 43,
	HEADER_GC_PING = 44,
	HEADER_GC_SCRIPT = 45,
	HEADER_GC_QUEST_CONFIRM = 46,
	HEADER_GC_MOUNT = 61,
	HEADER_GC_OWNERSHIP = 62,
	HEADER_GC_TARGET = 63,
	HEADER_GC_WARP = 65,
	HEADER_GC_ADD_FLY_TARGETING = 69,
	HEADER_GC_CREATE_FLY = 70,
	HEADER_GC_FLY_TARGETING = 71,
	HEADER_GC_SKILL_LEVEL = 72,
	HEADER_GC_SKILL_COOLTIME_END = 73,
	HEADER_GC_MESSENGER = 74,
	HEADER_GC_GUILD = 75,
	HEADER_GC_SKILL_LEVEL_NEW = 76,
	HEADER_GC_PARTY_INVITE = 77,
	HEADER_GC_PARTY_ADD = 78,
	HEADER_GC_PARTY_UPDATE = 79,
	HEADER_GC_PARTY_REMOVE = 80,
	HEADER_GC_QUEST_INFO = 81,
	HEADER_GC_REQUEST_MAKE_GUILD = 82,
	HEADER_GC_PARTY_PARAMETER = 83,
	HEADER_GC_SAFEBOX_MONEY_CHANGE = 84,
	HEADER_GC_SAFEBOX_SET = 85,
	HEADER_GC_SAFEBOX_DEL = 86,
	HEADER_GC_SAFEBOX_WRONG_PASSWORD = 87,
	HEADER_GC_SAFEBOX_SIZE = 88,
	HEADER_GC_FISHING = 89,
	HEADER_GC_EMPIRE = 90,
	HEADER_GC_PARTY_LINK = 91,
	HEADER_GC_PARTY_UNLINK = 92,
	HEADER_GC_REFINE_INFORMATION = 95,
	HEADER_GC_OBSERVER_ADD = 96,
	HEADER_GC_OBSERVER_REMOVE = 97,
	HEADER_GC_OBSERVER_MOVE = 98,
	HEADER_GC_VIEW_EQUIP = 99,
	HEADER_GC_MARK_BLOCK = 100,
	HEADER_GC_MARK_DIFF_DATA = 101,
	HEADER_GC_MARK_IDXLIST = 102,
	HEADER_GC_TIME = 106,
	HEADER_GC_CHANGE_NAME = 107,
	HEADER_GC_DUNGEON = 110,
	HEADER_GC_WALK_MODE = 111,
	HEADER_GC_CHANGE_SKILL_GROUP = 112,
	HEADER_GC_MAIN_CHARACTER2_EMPIRE = 113,
	HEADER_GC_SEPCIAL_EFFECT = 114,
	HEADER_GC_NPC_POSITION = 115,
	HEADER_GC_CHINA_MATRIX_CARD = 116,
	HEADER_GC_CHARACTER_UPDATE2 = 117,
	HEADER_GC_LOGIN_KEY = 118,
	HEADER_GC_REFINE_INFORMATION_NEW = 119,
	HEADER_GC_CHARACTER_ADD2 = 120,
	HEADER_GC_CHANNEL = 121,
	HEADER_GC_MALL_OPEN = 122,
	HEADER_GC_TARGET_UPDATE = 123,
	HEADER_GC_TARGET_DELETE = 124,
	HEADER_GC_TARGET_CREATE_NEW = 125,
	HEADER_GC_AFFECT_ADD = 126,
	HEADER_GC_AFFECT_REMOVE = 127,
	HEADER_GC_MALL_SET = 128,
	HEADER_GC_MALL_DEL = 129,
	HEADER_GC_LAND_LIST = 130,
	HEADER_GC_LOVER_INFO = 131,
	HEADER_GC_LOVE_POINT_UPDATE = 132,
	HEADER_GC_GUILD_SYMBOL_DATA = 133,
	HEADER_GC_DIG_MOTION = 134,
	HEADER_GC_DAMAGE_INFO = 135,
	HEADER_GC_CHAR_ADDITIONAL_INFO = 136,
	HEADER_GC_MAIN_CHARACTER3_BGM = 137,
	HEADER_GC_MAIN_CHARACTER4_BGM_VOL = 138,
	HEADER_GC_AUTH_SUCCESS = 150,
	HEADER_GC_PANAMA_PACK = 151,
	HEADER_GC_HYBRIDCRYPT_KEYS = 152,
	HEADER_GC_HYBRIDCRYPT_SDB = 153,
	HEADER_GC_AUTH_SUCCESS_OPENID = 154,
	HEADER_GC_RUNUP_MATRIX_QUIZ = 201,
	HEADER_GC_NEWCIBN_PASSPOD_REQUEST = 202,
	HEADER_GC_NEWCIBN_PASSPOD_FAILURE = 203,
	HEADER_GC_HS_REQUEST = 204,
	HEADER_GC_XTRAP_CS1_REQUEST = 205,
	HEADER_GC_SPECIFIC_EFFECT = 208,
	HEADER_GC_DRAGON_SOUL_REFINE = 209,
	HEADER_GC_RESPOND_CHANNELSTATUS = 210,
	HEADER_GC_KEY_AGREEMENT_COMPLETED = 0xfa,
	HEADER_GC_KEY_AGREEMENT = 0xfb,
	HEADER_GC_HANDSHAKE_OK = 0xfc,
	HEADER_GC_PHASE = 0xfd,
	HEADER_GC_BINDUDP = 0xfe,
	HEADER_GC_HANDSHAKE = 0xff,
};
enum
{
	POINT_MAX_NUM = 255,
	CHARACTER_NAME_MAX_LEN = 24,
#if defined(LOCALE_SERVICE_JAPAN)
	PLAYER_NAME_MAX_LEN = 16,
#else
	PLAYER_NAME_MAX_LEN = 12,
#endif
};

typedef MapaGlobal::std::map<DWORD, DWORD *> TCharacterInstanceMapGlobal;
typedef std::map<DWORD, DWORD*>	TCharacterInstanceMap;


#pragma pack (push, 1)

#define WORD_MAX 0xffff
typedef struct SItemPos
{
	BYTE window_type;
	WORD cell;
	//BYTE unk;
	SItemPos()
	{
		window_type = INVENTORY;
		cell = WORD_MAX;
	}
	SItemPos(BYTE _window_type, WORD _cell)
	{
		window_type = _window_type;
		cell = _cell;
		//unk = 0x00;
	}
} TItemPos;
#pragma pack(pop)
#pragma pack (push, 1)
typedef struct command_attack
{
	BYTE	header;
	BYTE	bType;			// °ø°Ý À¯Çü
	DWORD	dwVictimVID;	// Àû VID
	BYTE	bCRCMagicCubeProcPiece;
	BYTE	bCRCMagicCubeFilePiece;
} TPacketCGAttack;

typedef struct command_attack2
{
	BYTE	header;
	BYTE	unk1;			// °ø°Ý À¯Çü
	BYTE	size;
	BYTE	unk2;
	BYTE	unk3;
	BYTE	unk4;
	DWORD	dwVictimVID;	// Àû VID
	BYTE	app37;
} TPacketCGAttackAeldra;

typedef struct command_sync_position
{
	BYTE        header;
	WORD		wSize;
} TPacketCGSyncPosition;

typedef struct command_sync_position_element
{
	DWORD       dwVID;
	long        lX;
	long        lY;
} TPacketCGSyncPositionElement;

typedef struct packet_fly
{
	BYTE        bHeader;
	BYTE        bType;
	DWORD       dwStartVID;
	DWORD       dwEndVID;
} TPacketGCCreateFly;
typedef struct packet_add_char
{
	BYTE        header;

	DWORD       dwVID;

} TPacketGCCharacterAdd;

typedef struct packet_update_char
{
	BYTE        header;
	DWORD       dwVID;
} TPacketGCCharacterUpdate;

typedef struct packet_sfishing
{
	BYTE header;
} TPacketCGFishingX;

typedef struct packet_fishing
{
	BYTE header;
	BYTE subheader;
	DWORD info;
	BYTE dir;
} TPacketGCFishing;

typedef struct packet_fishing_global
{
	BYTE header;
	BYTE subheader;
	DWORD info;
	WORD dir;
} TPacketGCFishingGlobal;

typedef struct packet_fishing_pangea
{
	BYTE header;
	BYTE subheader;
	
	DWORD vid;
BYTE unk;
	BYTE count;

} TPacketGCFishingPangea;

typedef struct packet_ground_del_item
{
	BYTE		header;
	DWORD		vid;
} TPacketGCItemGroundDel;

typedef struct packet_ground_add_item
{
	BYTE        bHeader;
	long        lX;
	long		lY;
	long		lZ;

	DWORD       dwVID;
	DWORD       dwVnum;
} TPacketGCItemGroundAdd;

typedef struct packet_item_ownership
{
	BYTE        bHeader;
	DWORD       dwVID;
	char        szName[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCItemOwnership;

typedef struct packet_del_char
{
	BYTE	header;
	DWORD	dwVID;
} TPacketGCCharacterDelete;


typedef struct packet_whisper   // °¡º¯ ÆÐÅ¶    
{
	BYTE        bHeader;
	WORD        wSize;
	BYTE        bType;
	char        szNameFrom[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCWhisper;

typedef struct SMobSkillLevel
{
	DWORD       dwVnum;
	BYTE        bLevel;
} TMobSkillLevel;

typedef struct SMobTable_r255
{
	DWORD       dwVnum;
	char        szName[CHARACTER_NAME_MAX_LEN + 1];
	char        szLocaleName[CHARACTER_NAME_MAX_LEN + 1];

	BYTE        bType;                  // Monster, NPC
	BYTE        bRank;                  // PAWN, KNIGHT, KING
	//BYTE        bBattleType;            // MELEE, etc..
	//BYTE        bLevel;                 // Level
	//BYTE        bSize;

	//DWORD       dwGoldMin;
	//DWORD       dwGoldMax;
	//DWORD       dwExp;
	//DWORD       dwMaxHP;
	//BYTE        bRegenCycle;
	//BYTE        bRegenPercent;
	//WORD        wDef;

	//DWORD       dwAIFlag;
	//DWORD       dwRaceFlag;
	//DWORD       dwImmuneFlag;

	//BYTE        bStr, bDex, bCon, bInt;
	//DWORD       dwDamageRange[2];

	//short       sAttackSpeed;
	//short       sMovingSpeed;
	//BYTE        bAggresiveHPPct;
	//WORD        wAggressiveSight;
	//WORD        wAttackRange;

	//char        cEnchants[6];
	//char        cResists[6];

	//DWORD       dwResurrectionVnum;
	//DWORD       dwDropItemVnum;

	//BYTE        bMountCapacity;
	//BYTE        bOnClickType;

	//BYTE        bEmpire;
	//char        szFolder[64 + 1];
	//float       fDamMultiply;
	//DWORD       dwSummonVnum;
	//DWORD       dwDrainSP;
	//DWORD		dwMonsterColor;
	//DWORD       dwPolymorphItemVnum;

	//TMobSkillLevel	Skills[5];

	//BYTE		bBerserkPoint;
	//BYTE		bStoneSkinPoint;
	//BYTE		bGodSpeedPoint;
	//BYTE		bDeathBlowPoint;
	//BYTE		bRevivePoint;
} TMobTable_r255;
typedef TMobTable_r255 SMobTable, TMobTable;


typedef struct SGroundItemInstance
{
	DWORD					Instance;
	DWORD					dwVirtualNumber;
	D3DXVECTOR3				v3EndPosition;
	D3DXVECTOR3				v3RotationAxis;
	D3DXQUATERNION			qEnd;
	D3DXVECTOR3				v3Center;
	DWORD* ThingInstance;
	DWORD					dwStartTime;
	DWORD					dwEndTime;
	DWORD					eDropSoundType;
	std::string				stOwnership;
} TGroundItemInstance;

typedef struct SGroundItemInstanceGlobal
{
	DWORD					Instance;
	DWORD					dwVirtualNumber;
	D3DXVECTOR3				v3EndPosition;
	D3DXVECTOR3				v3RotationAxis;
	D3DXQUATERNION			qEnd;
	D3DXVECTOR3				v3Center;
	DWORD* ThingInstance;
	DWORD					dwStartTime;
	DWORD					dwEndTime;
	DWORD					eDropSoundType;
	BYTE					unk2[756];
	char  stOwnership[24];
} TGroundItemInstanceGlobal;


typedef MapaGlobal::std::map<DWORD, TGroundItemInstanceGlobal*> TGroundItemInstanceMapGlobal;
typedef std::map<DWORD, TGroundItemInstance*> TGroundItemInstanceMap;

typedef struct SAttachingData
{
	DWORD dwType;

	BOOL isAttaching;
	DWORD dwAttachingModelIndex;
	std::string strAttachingBoneName;

	DWORD* pCollisionData;
	DWORD* pEffectData;
	DWORD* pObjectData;
} TAttachingData;

typedef std::vector<TAttachingData> TAttachingDataVector;


typedef struct SItemTable_r156
{
	DWORD       dwVnum;
	DWORD       dwVnumRange;
	char        szName[24 + 1];
	char        szLocaleName[24 + 1];
	BYTE        bType;
	BYTE        bSubType;
	BYTE        bWeight;
	BYTE        bSize;
	DWORD       dwAntiFlags;
	DWORD       dwFlags;
	DWORD       dwWearFlags;
	DWORD       dwImmuneFlag;
	DWORD       dwIBuyItemPrice;
	DWORD		dwISellItemPrice;
} TItemTable;

typedef struct CItemData
{
	TItemTable m_ItemTable;
} TCItemData;

typedef struct CItemDataGlobal
{
	BYTE	unk2[60];
	TItemTable m_ItemTable;
} TCItemDataGlobal;


typedef MapaGlobal::std::map<DWORD, TCItemDataGlobal*> TItemMapGlobal;
typedef std::map<DWORD, TCItemData*> TItemMap;

char* sServerToClient[] = {

	"UNKNOWN",
	"HEADER_GC_CHARACTER_ADD",
	"HEADER_GC_CHARACTER_DEL",
	"HEADER_GC_CHARACTER_MOVE",
	"HEADER_GC_CHAT",
	"HEADER_GC_SYNC_POSITION",
	"HEADER_GC_LOGIN_SUCCESS3",
	"HEADER_GC_LOGIN_FAILURE",
	"HEADER_GC_PLAYER_CREATE_SUCCESS",
	"HEADER_GC_PLAYER_CREATE_FAILURE",
	"HEADER_GC_PLAYER_DELETE_SUCCESS",
	"HEADER_GC_PLAYER_DELETE_WRONG_SOCIAL_ID",
	"UNKNOWN",
	"HEADER_GC_STUN",
	"HEADER_GC_DEAD",
	"HEADER_GC_MAIN_CHARACTER",
	"HEADER_GC_PLAYER_POINTS",
	"HEADER_GC_PLAYER_POINT_CHANGE",
	"HEADER_GC_CHANGE_SPEED",
	"HEADER_GC_CHARACTER_UPDATE",
	"HEADER_GC_ITEM_SET",
	"HEADER_GC_ITEM_SET2",
	"HEADER_GC_ITEM_USE",
	"HEADER_GC_ITEM_DROP",
	"UNKNOWN",
	"HEADER_GC_ITEM_UPDATE",
	"HEADER_GC_ITEM_GROUND_ADD",
	"HEADER_GC_ITEM_GROUND_DEL",
	"HEADER_GC_QUICKSLOT_ADD",
	"HEADER_GC_QUICKSLOT_DEL",
	"HEADER_GC_QUICKSLOT_SWAP",
	"HEADER_GC_ITEM_OWNERSHIP",
	"HEADER_GC_LOGIN_SUCCESS4",
	"HEADER_GC_ITEM_UNBIND_TIME",
	"HEADER_GC_WHISPER",
	"HEADER_GC_ALERT",
	"HEADER_GC_MOTION",
	"UNKNOWN",
	"HEADER_GC_SHOP",
	"HEADER_GC_SHOP_SIGN",
	"HEADER_GC_DUEL_START",
	"HEADER_GC_PVP",
	"HEADER_GC_EXCHANGE",
	"HEADER_GC_CHARACTER_POSITION",
	"HEADER_GC_PING",
	"HEADER_GC_SCRIPT",
	"HEADER_GC_QUEST_CONFIRM",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_GC_MOUNT",
	"HEADER_GC_OWNERSHIP",
	"HEADER_GC_TARGET",
	"UNKNOWN",
	"HEADER_GC_WARP",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_GC_ADD_FLY_TARGETING",
	"HEADER_GC_CREATE_FLY",
	"HEADER_GC_FLY_TARGETING",
	"HEADER_GC_SKILL_LEVEL",
	"HEADER_GC_SKILL_COOLTIME_END",
	"HEADER_GC_MESSENGER",
	"HEADER_GC_GUILD",
	"HEADER_GC_SKILL_LEVEL_NEW",
	"HEADER_GC_PARTY_INVITE",
	"HEADER_GC_PARTY_ADD",
	"HEADER_GC_PARTY_UPDATE",
	"HEADER_GC_PARTY_REMOVE",
	"HEADER_GC_QUEST_INFO",
	"HEADER_GC_REQUEST_MAKE_GUILD",
	"HEADER_GC_PARTY_PARAMETER",
	"HEADER_GC_SAFEBOX_MONEY_CHANGE",
	"HEADER_GC_SAFEBOX_SET",
	"HEADER_GC_SAFEBOX_DEL",
	"HEADER_GC_SAFEBOX_WRONG_PASSWORD",
	"HEADER_GC_SAFEBOX_SIZE",
	"HEADER_GC_FISHING",
	"HEADER_GC_EMPIRE",
	"HEADER_GC_PARTY_LINK",
	"HEADER_GC_PARTY_UNLINK",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_GC_REFINE_INFORMATION",
	"HEADER_GC_OBSERVER_ADD",
	"HEADER_GC_OBSERVER_REMOVE",
	"HEADER_GC_OBSERVER_MOVE",
	"HEADER_GC_VIEW_EQUIP",
	"HEADER_GC_MARK_BLOCK",
	"HEADER_GC_MARK_DIFF_DATA",
	"HEADER_GC_MARK_IDXLIST",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_GC_TIME",
	"HEADER_GC_CHANGE_NAME",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_GC_DUNGEON",
	"HEADER_GC_WALK_MODE",
	"HEADER_GC_CHANGE_SKILL_GROUP",
	"HEADER_GC_MAIN_CHARACTER2_EMPIRE",
	"HEADER_GC_SEPCIAL_EFFECT",
	"HEADER_GC_NPC_POSITION",
	"HEADER_GC_CHINA_MATRIX_CARD",
	"HEADER_GC_CHARACTER_UPDATE2",
	"HEADER_GC_LOGIN_KEY",
	"HEADER_GC_REFINE_INFORMATION_NEW",
	"HEADER_GC_CHARACTER_ADD2",
	"HEADER_GC_CHANNEL",
	"HEADER_GC_MALL_OPEN",
	"HEADER_GC_TARGET_UPDATE",
	"HEADER_GC_TARGET_DELETE",
	"HEADER_GC_TARGET_CREATE_NEW",
	"HEADER_GC_AFFECT_ADD",
	"HEADER_GC_AFFECT_REMOVE",
	"HEADER_GC_MALL_SET",
	"HEADER_GC_MALL_DEL",
	"HEADER_GC_LAND_LIST",
	"HEADER_GC_LOVER_INFO",
	"HEADER_GC_LOVE_POINT_UPDATE",
	"HEADER_GC_GUILD_SYMBOL_DATA",
	"HEADER_GC_DIG_MOTION",
	"HEADER_GC_DAMAGE_INFO",
	"HEADER_GC_CHAR_ADDITIONAL_INFO",
	"HEADER_GC_MAIN_CHARACTER3_BGM",
	"HEADER_GC_MAIN_CHARACTER4_BGM_VOL",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_GC_AUTH_SUCCESS",
	"HEADER_GC_PANAMA_PACK",
	"HEADER_GC_HYBRIDCRYPT_KEYS",
	"HEADER_GC_HYBRIDCRYPT_SDB",
	"HEADER_GC_AUTH_SUCCESS_OPENID",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_GC_RUNUP_MATRIX_QUIZ",
	"HEADER_GC_NEWCIBN_PASSPOD_REQUEST",
	"HEADER_GC_NEWCIBN_PASSPOD_FAILURE",
	"HEADER_GC_HS_REQUEST",
	"HEADER_GC_XTRAP_CS1_REQUEST",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_GC_SPECIFIC_EFFECT",
	"HEADER_GC_DRAGON_SOUL_REFINE",
	"HEADER_GC_RESPOND_CHANNELSTATUS",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_GC_KEY_AGREEMENT_COMPLETED",
	"HEADER_GC_KEY_AGREEMENT",
	"HEADER_GC_HANDSHAKE_OK",
	"HEADER_GC_PHASE",
	"HEADER_GC_BINDUDP",
	"HEADER_GC_HANDSHAKE"
};
char* sClientToServer[] = {
	"UNKNOWN",
	"HEADER_CG_LOGIN",
	"HEADER_CG_ATTACK",
	"HEADER_CG_CHAT",
	"HEADER_CG_PLAYER_CREATE",
	"HEADER_CG_PLAYER_DESTROY",
	"HEADER_CG_PLAYER_SELECT",
	"HEADER_CG_CHARACTER_MOVE",
	"HEADER_CG_SYNC_POSITION",
	"HEADER_CG_DIRECT_ENTER",
	"HEADER_CG_ENTERGAME",
	"HEADER_CG_ITEM_USE",
	"HEADER_CG_ITEM_DROP",
	"HEADER_CG_ITEM_MOVE",
	"UNKNOWN",
	"HEADER_CG_ITEM_PICKUP",
	"HEADER_CG_QUICKSLOT_ADD",
	"HEADER_CG_QUICKSLOT_DEL",
	"HEADER_CG_QUICKSLOT_SWAP",
	"HEADER_CG_WHISPER",
	"HEADER_CG_ITEM_DROP2",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_ON_CLICK",
	"HEADER_CG_EXCHANGE",
	"HEADER_CG_CHARACTER_POSITION",
	"HEADER_CG_SCRIPT_ANSWER",
	"HEADER_CG_QUEST_INPUT_STRING",
	"HEADER_CG_QUEST_CONFIRM",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_PVP",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_SHOP",
	"HEADER_CG_FLY_TARGETING",
	"HEADER_CG_USE_SKILL",
	"HEADER_CG_ADD_FLY_TARGETING",
	"HEADER_CG_SHOOT",
	"HEADER_CG_MYSHOP",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_ITEM_USE_TO_ITEM",
	"HEADER_CG_TARGET",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_WARP",
	"HEADER_CG_SCRIPT_BUTTON",
	"HEADER_CG_MESSENGER",
	"UNKNOWN",
	"HEADER_CG_MALL_CHECKOUT",
	"HEADER_CG_SAFEBOX_CHECKIN",
	"HEADER_CG_SAFEBOX_CHECKOUT",
	"HEADER_CG_PARTY_INVITE",
	"HEADER_CG_PARTY_INVITE_ANSWER",
	"HEADER_CG_PARTY_REMOVE",
	"HEADER_CG_PARTY_SET_STATE",
	"HEADER_CG_PARTY_USE_SKILL",
	"HEADER_CG_SAFEBOX_ITEM_MOVE",
	"HEADER_CG_PARTY_PARAMETER",
	"UNKNOWN",
	"HEADER_CG_GUILD",
	"HEADER_CG_ANSWER_MAKE_GUILD",
	"HEADER_CG_FISHING",
	"HEADER_CG_GIVE_ITEM",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_EMPIRE",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_REFINE",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_MARK_LOGIN",
	"HEADER_CG_MARK_CRCLIST",
	"UNKNOWN",
	"HEADER_CG_CRC_REPORT",
	"HEADER_CG_MARK_IDXLIST",
	"HEADER_CG_HACK",
	"HEADER_CG_CHANGE_NAME",
	"HEADER_CG_SMS",
	"HEADER_CG_CHINA_MATRIX_CARD",
	"HEADER_CG_LOGIN2",
	"HEADER_CG_DUNGEON",
	"HEADER_CG_LOGIN3",
	"HEADER_CG_GUILD_SYMBOL_UPLOAD",
	"HEADER_CG_GUILD_SYMBOL_CRC",
	"HEADER_CG_SCRIPT_SELECT_ITEM",
	"HEADER_CG_LOGIN4",
	"HEADER_CG_LOGIN5_OPENID",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_RUNUP_MATRIX_ANSWER",
	"HEADER_CG_NEWCIBN_PASSPOD_ANSWER",
	"HEADER_CG_HS_ACK",
	"HEADER_CG_XTRAP_ACK",
	"HEADER_CG_DRAGON_SOUL_REFINE",
	"HEADER_CG_STATE_CHECKER",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_CLIENT_VERSION2",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"UNKNOWN",
	"HEADER_CG_KEY_AGREEMENT",
	"HEADER_CG_TIME_SYNC",
	"HEADER_CG_CLIENT_VERSION",
	"HEADER_CG_PONG",
	"HEADER_CG_HANDSHAKE"

};