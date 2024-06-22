#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include<vector>
#include<iostream>
#include"global_stuff.h"
#include"Collision_type.h"
#include"Enemy.h"

using namespace sf;
using namespace std;

class Turtle
{
private:
    
    Sprite shape_of_turtle;
    Texture texture;

    float vertical_speed;
    float x;
    float y;
    float portal_x;
    float portal_y;
    int turtle_live;
    int score;
    bool can_kill_enemy;

    void init_variables(float i_x, float i_y);
    void init_shape();
    
public:

    Turtle(float x = 100.f, float y = 100.f);

    float get_x(){return x;}
    float get_y(){return y;}
    bool is_alive(){return (turtle_live > 0);}  
    Sprite get_shape_of_turtle(){return shape_of_turtle;}
    void set_cordinate(float i_x, float i_y){x = i_x; y = i_y;}
    void set_portal_cordinate(float i_x, float i_y){portal_x = i_x; portal_y = i_y;}
    void update(vector<vector<Cell>>& map, vector<Enemy*>enemies); 
    void render(RenderTarget * target);
    void update_input(vector<vector<Cell>>& map);
    void gravity(vector<vector<Cell>>& map);
    void get_points(vector<vector<Cell>>& map);
    void damage();
    void behave_with_enemy(vector<Enemy*>enemies);
};
