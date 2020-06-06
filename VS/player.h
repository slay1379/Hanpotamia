#include <iostream>
#include "resource.h"
#include "unit.h"
#include "map.h"


#pragma once

using namespace std;

class Player
{
private:
    string _player_name;
    int _max_control_time;
    int _current_control_time;
    Resource _my_resource;

public :
    Player(){_player_name = "입력필요" ; _max_control_time=0; _current_control_time=0;};
    Player(string player_name, int _current_control_time,int _max_control_time);

    //setter
    void set_player_name(string name);
    void set_maxControlCnt(int user_max_control_cnt);
    void set_currentControlCnt(int user_current_control_cnt);
    void set_my_resource(int Food , int Gold, int Water);
    void discount_currentControlCnt();

    //getter
    //Output 각 클래스별 배열 ( 배열의 첫 번쨰 주소 Return)
    int *get_myPlace();
    Resource *get_myResource();

    string get_player_name();
    //Turn getter
    int get_maxControlCnt();
    int get_currentControlCnt();

    //Control Function
    //병과, 생산 수 인자로 넘김
    void selectAction();
    Unit produce_unit(string tendency, int product_count,string area);
    static void MoveOrAttack_unit(string from, string to);
    static void fight(string from_area, string to_area);
    static void move(string from_area, string to_area);
    static void upgradeArea(string area);
    void conquerArea(string areaName);
    void display_movableArea();
    bool is_yourArea(string area);
    static bool is_attackableArea(string attack_Unit, string attacker_area);
    static void success_procedure(string type);
};
