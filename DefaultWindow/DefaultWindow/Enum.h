#pragma once

enum class SCENE_TYPE { START, STAGE1, STAGE2, GAMEOVER, CLEAR, EXIT, TEST, END };
enum class OBJECT_TYPE { PLAYER, MONSTER,ITEM, PLAYER_PROJECTILE, ENEMY_PROJECTILE, SATTELLITE, GUN, END};
enum class MONSTER_TYPE { NORMAL, BOSS, END };

enum class BULLET_TYPE { NORMAL, EPIC, LEGEND };


enum class ITEM_TYPE {	BULLET , CONSUM, END };

enum class DIR_TYPE { RIGHT, UP, LEFT, DOWN, END };

enum class EVENT_TYPE { ADD_OBJ, DELETE_OBJ, CHANGE_SCENE, END};

enum class BRUSH_TYPE{ HOLLOW, BLACK, WHITE, RED, BLUE, GREEN, END };
enum class PEN_TYPE{ RED, GREEN, BLUE, END };
enum class GUN_TYPE { NORMALGUN, SHOTGUN, MACHINEGUN, SCREWGUN, FOLLOWGUN, END};