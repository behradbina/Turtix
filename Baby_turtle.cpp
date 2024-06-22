#include "Baby_turtle.h"


Baby_Turtle:: Baby_Turtle(float x, float y)
{
    shape_of_baby_turtle.setPosition(x, y);
    init_shape();
    init_variables(x ,y);
}

void Baby_Turtle::init_shape()
{
    if (!texture.loadFromFile("locked_baby_turtle.png")){
        exit(EXIT_FAILURE);
    }

    shape_of_baby_turtle.setTexture(texture);
      
}

void Baby_Turtle:: init_variables(float i_x, float i_y)
{
    x = i_x;
    y = i_y;
    vertical_speed =0.f;
    horizontal_speed = BABY_TURTLE_WALK_SPEED;
    free = false;
}

void Baby_Turtle::update(vector<vector<Cell>>& map, float turtle_x, float turtle_y, float portal_x)
{
    if (free)
        move(map);
    else
        get_free(turtle_x, turtle_y, portal_x);


    gravity(map);
}  

void Baby_Turtle:: render(RenderTarget * target)
{
    shape_of_baby_turtle.setPosition(x, y);
    target->draw(shape_of_baby_turtle);
}

void Baby_Turtle::gravity(vector<vector<Cell>>& map)
{    
    if (!have_collision(x, y, map, Collision_dierction::Down))
    {
        vertical_speed += GRAVITY;
        y += vertical_speed;       
    }
    
    else
    {
        vertical_speed = 0;
    }
    
}

void Baby_Turtle::move(vector<vector<Cell>>& map)
{
    if(!have_collision(x, y, map, Collision_dierction::Right, Cell::Wall) && 
    have_collision(x, y, map, Collision_dierction::Left, Cell::Wall))
    {
        if(horizontal_speed < 0)
            horizontal_speed *= -1;
    }
    
    else if(!have_collision(x, y, map, Collision_dierction::Left, Cell::Wall) && 
        have_collision(x, y, map, Collision_dierction::Right, Cell::Wall))
    {
        if(horizontal_speed > 0)
            horizontal_speed *= -1;
    }

    x += horizontal_speed;
}

void Baby_Turtle::update_baby_turtle_shape()
{
    if (!texture.loadFromFile("free_baby_turtle.png")){
        exit(EXIT_FAILURE);
    }

    shape_of_baby_turtle.setTexture(texture);
}

void Baby_Turtle::get_free(float turtle_x, float turtle_y, float portal_x)
{
    if (have_collision_with_object(x/CELL_SIZE, y/CELL_SIZE, turtle_x, turtle_y))
    {
        update_baby_turtle_shape();
        free = true;
    }

    if (portal_x < x)
    {
        horizontal_speed *= -1;
    }
    
    
}

bool Baby_Turtle::is_arrived_to_portal(float portal_x, float portal_y)
{
    if (have_collision_with_object(portal_x/CELL_SIZE, portal_y/CELL_SIZE, x, y))
        return true;

    return false;
}