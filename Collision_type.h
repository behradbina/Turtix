#pragma once

#include"global_stuff.h"
#include<vector>
#include<iostream>

using namespace std;

bool have_collision(float i_x, float i_y, vector<vector<Cell>>& i_map, Collision_dierction direction, Cell cell_type = Cell::Wall);

bool have_collision_with_object(int object_x, int object_y, float turtle_x, float turtle_y);

Collision_dierction find_the_direction_of_collision(float turtle_x, float turtle_y, float object_x, float object_y);
