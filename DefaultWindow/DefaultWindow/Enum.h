#pragma once

enum class SCENE_TYPE { START, STAGE1, STAGE2, GAMEOVER, CLEAR, EXIT, TEST, END };
<<<<<<< HEAD
enum class OBJECT_TYPE { PLAYER, MONSTER,ITEM, PLAYER_PROJECTILE, ENEMY_PROJECTILE, END};
enum class MONSTER_TYPE { NORMAL, BOSS, END };

enum class BULLET_TYPE { NORMAL, EPIC, LEGEND };


enum class ITEM_TYPE {	BULLET , CONSUM, END };
=======
enum class OBJECT_TYPE { PLAYER, MONSTER, ITEM, GUN, PLAYER_PROJECTILE, ENEMY_PROJECTILE, END};
enum class MONSTER_TYPE { NORMAL, BOSS, END };

enum class BULLET_TYPE { NORMAL, SHOT, MACHINE, SCREW, FOLLOW, END};
enum class GUN_TYPE { NORMALGUN, SHOTGUN, MACHINEGUN, SCRWGUN, FOLLOWGUN, END };

enum class ITEM_TYPE { EQUIP, CONSUM, END };
>>>>>>> feature/Jun

enum class DIR_TYPE { RIGHT, UP, LEFT, DOWN, END };

enum class EVENT_TYPE { ADD_OBJ, DELETE_OBJ, CHANGE_SCENE, END};
enum class BRUSH_TYPE{ HOLLOW, BLACK, WHITE, END };
enum class PEN_TYPE{ RED, GREEN, BLUE, END };