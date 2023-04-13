#pragma once

enum class SCENE_TYPE { START, STAGE1, STAGE2, GAMEOVER, CLEAR, EXIT, TEST, END };
enum class OBJECT_TYPE { PLAYER, MONSTER, ITEM, PLAYER_PROJECTILE, ENEMY_PROJECTILE, END};
enum class MONSTER_TYPE { NORMAL, BOSS, END };

enum class EVENT_TYPE { ADD_OBJ, DELETE_OBJ, CHANGE_SCENE, END};
enum class BRUSH_TYPE{ HOLLOW, BLACK, WHITE, END };
enum class PEN_TYPE{ RED, GREEN, BLUE, END };