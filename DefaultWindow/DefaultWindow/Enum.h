#pragma once

enum class SCENE_TYPE { START, STAGE1, STAGE2, GAMEOVER, CLEAR, EXIT, END };
enum class OBJECT_TYPE { PLAYER, MONSTER, ITEM, PLAYER_BULLET, ENEMY_BULLET, END};
enum class MONSTER_TYPE { NORMAL, BOSS, END };
enum class BULLET_TYPE { NORMAL, EPIC, LEGEND };

enum class ITEM_TYPE { EQUIP, CONSUM, END };
enum class EQUIP_TYPE { NOMAL, DOUBLE_BULLET, TREEPLE_BULLET, END };

enum class DIR_TYPE { RIGHT, UP, LEFT, DOWN, END };

enum class BRUSH_TYPE{ HOLLOW, BLACK, WHITE, END };
enum class PEN_TYPE{ RED, GREEN, BLUE, END };