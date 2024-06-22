#include "Enemy.h"


Enemy::Enemy(float i_x, float i_y)
{
    x = i_x;
    y = i_y;
    horizontal_speed = ENEMY_WALK_SPEED;
    number_of_enemy_live = NUMBER_OF_ENEMY_LIVE;
    dead = false;
}

void Enemy::move(vector<vector<Cell>>& map)
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

    if (!have_collision(x, y, map, Collision_dierction::Down, Cell::Wall))
    {
        horizontal_speed *= -1;
    }
    

    x += horizontal_speed;

}

void Enemy::damage()
{  
    number_of_enemy_live--;
    
    if (number_of_enemy_live <= 0)
        dead = true;
    
}

void Enemy::render(RenderTarget * target)
{
    shape_of_enemy.setPosition(x, y);
    target->draw(shape_of_enemy);
}

bool Enemy::have_collision_with_turtle(Sprite shape_of_turtle)
{
    if (shape_of_turtle.getGlobalBounds().intersects(shape_of_enemy.getGlobalBounds()))
    {
        return true;
    }

    return false;   
}

Enemy_type_1::Enemy_type_1( float i_x,float i_y) : Enemy(i_x, i_y)
{
    init_variable();
    init_shape();
}

void Enemy_type_1::init_variable()
{
    number_of_enemy_live = NUMBER_OF_ENEMY_LIVE;
    shield = false;
}

void Enemy_type_1::init_shape()
{
    if (!texture.loadFromFile("enemy1.png")){
        exit(EXIT_FAILURE);
    }

    shape_of_enemy.setTexture(texture);
    shape_of_enemy.setColor(Color::Red);
}

void Enemy_type_1::update(vector<vector<Cell>>& map)
{
    move(map);    
}

Enemy_type_2::Enemy_type_2( float i_x,float i_y) : Enemy_type_1(i_x, i_y)
{
    init_variable();
    init_shape();
}

void Enemy_type_2::init_variable()
{
    number_of_enemy_live = NUMBER_OF_ENEMY_LIVE;
    in_shiled_period = false;
    shield_end_time = clock();
}

void Enemy_type_2::init_shape()
{
    if (!texture.loadFromFile("enemy1.png")){
        exit(EXIT_FAILURE);
    }

    shape_of_enemy.setTexture(texture);
    shape_of_enemy.setColor(Color::Magenta);
}

void Enemy_type_2::get_shield()
{
    shield = true;
    shape_of_enemy.setColor(Color::Green);
}

void Enemy_type_2::remove_shield()
{
    shield = false;
    shape_of_enemy.setColor(Color::Magenta);
}

void Enemy_type_2::update(vector<vector<Cell>>& map)
{
    //shield_update();
    move(map);
    
}

void Enemy_type_2::shield_update()
{
    int shield_timer = SHIELD_PERIOD_TIME * CLOCKS_PER_SEC;
    int unshield_timer = SHIELD_PERIOD_TIME * CLOCKS_PER_SEC;
    
    clock_t now = clock();

    if (((now-shield_end_time) < unshield_timer) && !in_shiled_period)
    {
        remove_shield();
        return;
    }
    else if(((now-shield_end_time) == unshield_timer) && !in_shiled_period)
    {
        shield_start_time = clock();
        in_shiled_period = true;
        shield_end_time = 0;
        return;
    }
    
    if (((now-shield_start_time) < shield_timer) && in_shiled_period)
    {
        get_shield();
        return;
    }

    else if(((now-shield_start_time) == shield_timer) && in_shiled_period)
    {
        shield_end_time = clock();
        in_shiled_period = false;
        shield_start_time = 0;
        return;
    }

}
