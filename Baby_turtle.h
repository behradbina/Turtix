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

class Baby_Turtle
{
private:
    
    Sprite shape_of_baby_turtle;
    Texture texture;

    float horizontal_speed;
    float vertical_speed;
    float x;
    float y;

    bool free;
    
    void init_variables(float i_x, float i_y);
    void init_shape();
    
public:

    Baby_Turtle(float x = 100.f, float y = 100.f);
    float get_x(){return x;}
    float get_y(){return y;}
    void set_cordinate(float i_x, float i_y){x = i_x; y = i_y;}
    void update(vector<vector<Cell>>& map, float turtle_x, float turtle_y, float portal_x);    
    void render(RenderTarget * target);
    void gravity(vector<vector<Cell>>& map);
    void move(vector<vector<Cell>>& map);
    void get_free(float turtle_x, float turtle_y, float portal_x);
    void update_baby_turtle_shape();
    bool is_arrived_to_portal(float portal_x, float portal_y);
};
