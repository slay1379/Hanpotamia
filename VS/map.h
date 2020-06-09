#pragma once
#include <iostream>
#include"player.h"
#include"resource.h"
#include "unit.h"
using namespace std;

typedef struct Army {
	Unit* Infantry;
	Unit* Navy;
	Unit* cavalry;
	Unit* Archer;
	int Infantrycount;
	int Navycount;
	int Cavalrycount;
	int Archercount;
}Army;


typedef struct areainformation{
	string areaname;
	int areanum;
	string areatype;
	int arealevel;
	string neighborarea[30];
	string areahost;
	Army areaunit;
	Resource* arearesource;
	Resource* occupationcost;
}areainformation;

class Map
{
private:
	char _area;
	Player* _host_player;
	int _acquirable_resource_water;
	int _acquirable_resource_gold;
	int _acquirable_resource_food;
	const int _max_area = 30;
	int** _route;
	areainformation area[30] = { NULL };

public:
	Map(int _max_area);
	~Map();
	string get_occupationPlayer(string areaname);
	Resource get_occupationCost(string areaname);
	void get_acquirableResource(string areaname);
	void get_upgradeCost(string areaname);
	string* get_movableArea(string areaname);
	Army get_unit(string areaname, Player* _host_player);
	Army get_unitWhole(Player* _host_player);
	areainformation get_areaInformation(string areaname);
	int* get_wholeArea(Player* _host_player);

	Resource set_occupationCost(string areaname);
	void set_areaInformation(areainformation area[]);
	void set_areaHost(Player* _host_player, string areaname);
	int set_acquirableFood(string areaname);
	int set_acquirableGold(string areaname);
	int set_acquirableWater(string areaname);
	void set_unit(string areaname, string tendency, int count);

	areainformation findArea(int areaNum);
	areainformation* get_wholeMap();
	void upgrade_Area(string areaname);
	areainformation findArea(string areaname);
	void showAreaInformation(string areaname);
	int attackable(string startarea, string endarea);
};