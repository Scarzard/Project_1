#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"			// Following: Includes of all enemy headers
#include "Enemy_13_Greyball.h"
#include "RedLineShip_Enemy.h"
#include "PowerUp_Enemy.h"

#define MAX_ENEMIES 500

enum ENEMY_TYPES
{
	NO_TYPE,
	GREYBALL_UP_DOWN,
	GREYBALL_S,
	GREYBALL_K,
	REDLINE_SHIP,
	POWERUP_ENEMY,
	BIGGREY_ENEMY,
	GREY_YELLOW_SHIP,
	YELLOWSHIP_UP,
	YELLOWSHIP_DOWN,
	POWERUP_BONUS
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y);



private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
	SDL_Texture* table_enemy;
};

#endif // __ModuleEnemies_H__