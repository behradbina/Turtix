#include "Turtle.h"


Turtle:: Turtle(float x, float y)
{
    shape_of_turtle.setPosition(x, y);
    init_shape();
    init_variables(x ,y);
}

void Turtle::init_shape()
{
    if (!texture.loadFromFile("turtle_right.png")){
        exit(EXIT_FAILURE);
    }

    shape_of_turtle.setTexture(texture);  
}

void Turtle:: init_variables(float i_x, float i_y)
{
    x = i_x;
    y = i_y;

    vertical_speed =0.f;
    score = 0;
    turtle_live = NUMBER_OF_TURTLE_LIVE; 
}

void Turtle:: update(vector<vector<Cell>>& map, vector<Enemy*>enemies)
{
    if (have_collision(x, y, map , Collision_dierction::Down, Blade))
        damage();
    
    update_input(map);
    get_points(map);
    gravity(map);
    behave_with_enemy(enemies);
} 

void Turtle:: render(RenderTarget * target)
{
    shape_of_turtle.setPosition(x, y);
    target->draw(shape_of_turtle);
}

void Turtle:: update_input(vector<vector<Cell>>& map)
{

    if (Keyboard::isKeyPressed(Keyboard::A))
    {   
        if(!have_collision(x, y, map, Collision_dierction::Left) || 
            have_collision(x, y, map, Collision_dierction::Left, Cell::Rope))
            x -= TURTLE_WALK_SPEED;
    }
    
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        if(!have_collision(x, y, map, Collision_dierction::Right) || 
            have_collision(x, y, map, Collision_dierction::Right, Cell::Rope))
            x += TURTLE_WALK_SPEED;
    }

    if (sf::Keyboard::isKeyPressed(Keyboard::W) && have_collision(x, y, map, Collision_dierction::Down))
    {
        if(!have_collision(x, y, map, Collision_dierction::Up))
            y+= TURTlE_JUMP_SPEED;
    }

    if (sf::Keyboard::isKeyPressed(Keyboard::W))
    {
        if(have_collision(x, y, map, Collision_dierction::Up, Cell::Ladder))
            y-= TURTLE_WALK_SPEED;
    }

    if (sf::Keyboard::isKeyPressed(Keyboard::S))
    {
        if(have_collision(x, y, map, Collision_dierction::Down, Cell::Ladder))
            y+= TURTLE_WALK_SPEED;
    }
}

void Turtle::gravity(vector<vector<Cell>>& map)
{    
    if (!have_collision(x, y, map, Collision_dierction::Down) &&
     !have_collision(x, y, map, Collision_dierction::Down, Cell::Rope)
        && !have_collision(x, y, map, Collision_dierction::Down, Cell::Ladder))
    {
        vertical_speed += GRAVITY;
        y += vertical_speed;
        
    }
    
    else
    {
        vertical_speed = 0;
    }
    
}

void Turtle::get_points(vector<vector<Cell>>& map)
{
    for (int index_y = 0; index_y < map.size(); index_y++)
    {
        for (int index_x = 0; index_x < map[index_y].size(); index_x++)
        {
            if (map[index_y][index_x] == Cell::Daimond && have_collision_with_object(index_x, index_y, x, y))
            {
                score += DAIMOND_SCORE;
                map[index_y][index_x] = Cell::Empty;
            }
            
            if (map[index_y][index_x] == Cell::Star && have_collision_with_object(index_x, index_y, x, y))
            {
                score += STAR_SCORE;
                map[index_y][index_x] = Cell::Empty;
            }
        }   
    }  
}

void Turtle::damage()
{
    turtle_live--;
    x = portal_x;
    y = portal_y;
}

void Turtle::behave_with_enemy(vector<Enemy*>enemies)
{
    for (auto enemy : enemies)
    {
        if (enemy->have_collision_with_turtle(shape_of_turtle))
        {
            if (find_the_direction_of_collision(x, y, enemy->get_x(), enemy->get_y()) == Collision_dierction::Down && 
            enemy->is_damageable())
            {  
                enemy->damage();
                return;
            }

            else
            {
                this->damage();
            }
        }
            
    }
    
}
