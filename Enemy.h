#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include<vector>
#include<iostream>

#include"global_stuff.h"
#include"Collision_type.h"

using namespace sf;

class Enemy
{
protected:

    float x;
    float y;
    float horizontal_speed;
    unsigned char number_of_enemy_live;
    bool shield;
    bool dead;
    Sprite shape_of_enemy;
    Texture texture;

public:

    Enemy(float i_x, float i_y);
    float get_x(){return x;}
    float get_y(){return y;}
    bool is_dead(){return dead;}
    bool is_damageable(){return (!shield);}
    void damage();
    virtual void update(vector<vector<Cell>>& map) = 0;
    bool have_collision_with_turtle(Sprite shape_of_turtle);
    void render(RenderTarget * target);
    void move(vector<vector<Cell>>& map);

};

class Enemy_type_1 : public Enemy
{
private:
    
    void init_variable();
    void init_shape();
    
public:

    Enemy_type_1( float i_x,float i_y);
    
    void update(vector<vector<Cell>>& map);
};

class Enemy_type_2 : public Enemy_type_1
{
private:

    int number_of_enemy_live;
    bool in_shiled_period;
    clock_t shield_start_time;
    clock_t shield_end_time; 

    void init_variable();
    void init_shape();
    void get_shield();
    void remove_shield();
    void shield_update();
    void update(vector<vector<Cell>>& map);

public:
    Enemy_type_2( float i_x,float i_y);
};

