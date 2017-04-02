#ifndef __MANAGER_H__
#define __MANAGER_H__


#include "PugiXml\src\pugixml.hpp"
#include <list>
#include <map>
#include <string>
#include <vector>
#include "p2Point.h"



class Entity;
class Player;
class Enemy;
class Npc;
enum ENTITY_TYPE;
enum ENEMY_TYPE;
enum NPC_TYPE;

class j1EntityManager
{
public:

	j1EntityManager();
	bool Awake(pugi::xml_node&);
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();

	Player* CreatePlayer(int, int);
	Enemy* CreateEnemy(int, ENEMY_TYPE, int, int, std::vector<iPoint>);
	Npc*	CreateNPC(int, NPC_TYPE, int, int, int);

	bool CleanEntities();
	void SetSectorRef(int*);

public:

	Player* player;
	std::map<int, std::list<Entity*>> entities;
	std::map<ENTITY_TYPE, std::string> dir;

private:

	int* sector;

};

#endif