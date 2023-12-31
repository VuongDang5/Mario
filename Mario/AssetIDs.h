#pragma once

//
// This file contains all IDs of game assets 
//

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_ENEMY_0 11
#define ID_TEX_ENEMY_1 12
#define ID_TEX_MISC 20
#define ID_TEX_MISC_1 21
#define ID_TEX_MISC_2 22

#pragma region MARIO 

#define ID_SPRITE_MARIO 10000
#define ID_SPRITE_MARIO_BIG (ID_SPRITE_MARIO + 1000)
#define ID_SPRITE_MARIO_BIG_IDLE (ID_SPRITE_MARIO_BIG + 100)
#define ID_SPRITE_MARIO_BIG_IDLE_LEFT (ID_SPRITE_MARIO_BIG_IDLE + 10)
#define ID_SPRITE_MARIO_BIG_IDLE_RIGHT (ID_SPRITE_MARIO_BIG_IDLE + 20)

#define ID_SPRITE_MARIO_BIG_WALKING (ID_SPRITE_MARIO_BIG + 200)
#define ID_SPRITE_MARIO_BIG_WALKING_LEFT (ID_SPRITE_MARIO_BIG_WALKING + 10)
#define ID_SPRITE_MARIO_BIG_WALKING_RIGHT (ID_SPRITE_MARIO_BIG_WALKING + 20)
#define ID_SPRITE_MARIO_BIG_RUNNING (ID_SPRITE_MARIO_BIG + 300)
#define ID_SPRITE_MARIO_BIG_RUNNING_LEFT (ID_SPRITE_MARIO_BIG_RUNNING + 10)
#define ID_SPRITE_MARIO_BIG_RUNNING_RIGHT (ID_SPRITE_MARIO_BIG_RUNNING + 20)
#define ID_SPRITE_MARIO_BIG_JUMP (ID_SPRITE_MARIO_BIG + 400)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK (ID_SPRITE_MARIO_BIG_JUMP + 10)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_LEFT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN (ID_SPRITE_MARIO_BIG_JUMP + 20)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_LEFT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 6)
#define ID_SPRITE_MARIO_BIG_SIT (ID_SPRITE_MARIO_BIG + 500)
#define ID_SPRITE_MARIO_BIG_SIT_LEFT (ID_SPRITE_MARIO_BIG_SIT + 10)
#define ID_SPRITE_MARIO_BIG_SIT_RIGHT (ID_SPRITE_MARIO_BIG_SIT + 20)
#define ID_SPRITE_MARIO_BIG_BRACE (ID_SPRITE_MARIO_BIG + 600)
#define ID_SPRITE_MARIO_BIG_BRACE_LEFT (ID_SPRITE_MARIO_BIG_BRACE + 10)
#define ID_SPRITE_MARIO_BIG_BRACE_RIGHT (ID_SPRITE_MARIO_BIG_BRACE + 20)

#define ID_SPRITE_MARIO_DIE (ID_SPRITE_MARIO + 3000)

#define ID_SPRITE_MARIO_SMALL (ID_SPRITE_MARIO + 2000)
#define ID_SPRITE_MARIO_SMALL_IDLE (ID_SPRITE_MARIO_SMALL + 100)
#define ID_SPRITE_MARIO_SMALL_IDLE_LEFT (ID_SPRITE_MARIO_SMALL_IDLE + 10)
#define ID_SPRITE_MARIO_SMALL_IDLE_RIGHT (ID_SPRITE_MARIO_SMALL_IDLE + 20)

#define ID_SPRITE_MARIO_SMALL_WALKING (ID_SPRITE_MARIO_SMALL + 200)
#define ID_SPRITE_MARIO_SMALL_WALKING_LEFT (ID_SPRITE_MARIO_SMALL_WALKING + 10)
#define ID_SPRITE_MARIO_SMALL_WALKING_RIGHT (ID_SPRITE_MARIO_SMALL_WALKING + 20)
#define ID_SPRITE_MARIO_SMALL_RUNNING (ID_SPRITE_MARIO_SMALL + 300)
#define ID_SPRITE_MARIO_SMALL_RUNNING_LEFT (ID_SPRITE_MARIO_SMALL_RUNNING + 10)
#define ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT (ID_SPRITE_MARIO_SMALL_RUNNING + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP (ID_SPRITE_MARIO_SMALL + 400)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK (ID_SPRITE_MARIO_SMALL_JUMP + 10)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN (ID_SPRITE_MARIO_SMALL_JUMP + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 6)

#define ID_SPRITE_MARIO_SMALL_SIT (ID_SPRITE_MARIO_SMALL + 500)
#define ID_SPRITE_MARIO_SMALL_SIT_LEFT (ID_SPRITE_MARIO_SMALL_SIT + 10)
#define ID_SPRITE_MARIO_SMALL_SIT_RIGHT (ID_SPRITE_MARIO_SMALL_SIT + 20)

#define ID_SPRITE_MARIO_SMALL_BRACE (ID_SPRITE_MARIO_SMALL + 500)
#define ID_SPRITE_MARIO_SMALL_BRACE_LEFT (ID_SPRITE_MARIO_SMALL_BRACE + 10)
#define ID_SPRITE_MARIO_SMALL_BRACE_RIGHT (ID_SPRITE_MARIO_SMALL_BRACE + 20)

#pragma endregion 

#define ID_SPRITE_BRICK 20000

#define ID_SPRITE_GOOMBA 30000
#define ID_SPRITE_GOOMBA_WALK (ID_SPRITE_GOOMBA + 1000)
#define ID_SPRITE_GOOMBA_DIE (ID_SPRITE_GOOMBA + 2000)

#define ID_SPRITE_COIN 40000

#define ID_SPRITE_TURTLE 50000
#define ID_SPRITE_TURTLE_WALK (ID_SPRITE_TURTLE + 1000)
#define ID_SPRITE_TURTLE_DIE (ID_SPRITE_TURTLE + 2000)

#define ID_SPRITE_EATER 60000

#define ID_SPRITE_GREEN_EATER 70000

#define ID_SPRITE_BULLET 80000

#define ID_SPRITE_PIRANHA 90000

#define ID_SPRITE_GTURTLE 100000

#define ID_SPRITE_MARIO_TAIL (ID_SPRITE_MARIO + 3000)
#define ID_SPRITE_MARIO_TAIL_IDLE (ID_SPRITE_MARIO_TAIL + 100)
#define ID_SPRITE_MARIO_TAIL_IDLE_LEFT (ID_SPRITE_MARIO_TAIL_IDLE + 10)
#define ID_SPRITE_MARIO_TAIL_IDLE_RIGHT (ID_SPRITE_MARIO_TAIL_IDLE + 20)

#define ID_SPRITE_MARIO_TAIL_WALKING (ID_SPRITE_MARIO_TAIL + 200)
#define ID_SPRITE_MARIO_TAIL_WALKING_LEFT (ID_SPRITE_MARIO_TAIL_WALKING + 10)
#define ID_SPRITE_MARIO_TAIL_WALKING_RIGHT (ID_SPRITE_MARIO_TAIL_WALKING + 20)
#define ID_SPRITE_MARIO_TAIL_RUNNING (ID_SPRITE_MARIO_TAIL + 300)
#define ID_SPRITE_MARIO_TAIL_RUNNING_LEFT (ID_SPRITE_MARIO_TAIL_RUNNING + 10)
#define ID_SPRITE_MARIO_TAIL_RUNNING_RIGHT (ID_SPRITE_MARIO_TAIL_RUNNING + 20)
#define ID_SPRITE_MARIO_TAIL_JUMP (ID_SPRITE_MARIO_TAIL + 400)
#define ID_SPRITE_MARIO_TAIL_JUMP_WALK (ID_SPRITE_MARIO_TAIL_JUMP + 10)
#define ID_SPRITE_MARIO_TAIL_JUMP_WALK_LEFT (ID_SPRITE_MARIO_TAIL_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_TAIL_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_TAIL_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_TAIL_JUMP_RUN (ID_SPRITE_MARIO_TAIL_JUMP + 20)
#define ID_SPRITE_MARIO_TAIL_JUMP_RUN_LEFT (ID_SPRITE_MARIO_TAIL_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_TAIL_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_TAIL_JUMP_RUN + 6)

#define ID_SPRITE_MARIO_TAIL_SIT (ID_SPRITE_MARIO_TAIL + 500)
#define ID_SPRITE_MARIO_TAIL_SIT_LEFT (ID_SPRITE_MARIO_TAIL_SIT + 11)
#define ID_SPRITE_MARIO_TAIL_SIT_RIGHT (ID_SPRITE_MARIO_TAIL_SIT + 21)

#define ID_SPRITE_MARIO_TAIL_BRACE (ID_SPRITE_MARIO_TAIL + 500)
#define ID_SPRITE_MARIO_TAIL_BRACE_LEFT (ID_SPRITE_MARIO_TAIL_BRACE + 10)
#define ID_SPRITE_MARIO_TAIL_BRACE_RIGHT (ID_SPRITE_MARIO_TAIL_BRACE + 20)

#define ID_SPRITE_MARIO_TAIL_SWIPE (ID_SPRITE_MARIO_TAIL + 501)
