#pragma once

#include <fstream>
#include "Turtle.h"
#include "global_stuff.h"
#include "Enemy.h"
#include "Baby_turtle.h"
#include "Pause.h"

using namespace std;
using namespace sf;


class Turtix
{
private:

    //variables
    RenderWindow* window;
    Event ev;
    VideoMode video_mode;
    View camera_view;    
    vector<vector<Cell> > map;
    vector<Enemy*> enemies;
    vector<Baby_Turtle*> baby_turtles;

    float portal_x;
    float portal_y;
    bool pause;
    //object
    Turtle turtle;
    Pause pause_page;

    //private_functions
    void init_variables();
    void init_window();

public:

    Turtix();

    virtual ~Turtix();

    void update();
    void poll_events();
    void render();
    bool running();
    void create_map();
    void draw_map();
    void update_enemies();
    void render_enemies();

    void update_baby_turtles();
    void render_baby_turtles();
};

