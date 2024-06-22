#include "Collision_type.h"


bool have_collision(float i_x, float i_y, vector<vector<Cell>>& i_map, Collision_dierction direction, Cell cell_type)
{
    if (direction == Collision_dierction::Up)
    {
        for (int y = 0; y < i_map.size(); y++)
        {              
            for (int x = 0; x < i_map[y].size(); x++)
            {   
                if(i_map[y][x] == cell_type && y*CELL_SIZE < i_y)
                {
                    if ((i_x < (x+1)*CELL_SIZE && (x+1)*CELL_SIZE < i_x + CELL_SIZE) && (y+1) * CELL_SIZE >= i_y)
                    {
                        return true;
                    }

                    else if ((i_x < x*CELL_SIZE && x*CELL_SIZE < i_x + CELL_SIZE) && (y+1) * CELL_SIZE >= i_y)
                    {
                        return true;
                    }

                    else if ((i_x == x*CELL_SIZE && (x+1)*CELL_SIZE == i_x + CELL_SIZE) && (y+1)*CELL_SIZE >= i_y)
                    {
                        return true;
                    } 
                    
                }       
            }      
        }
        
        return false;
    }

    else if (direction == Collision_dierction::Down)
    {
        for (int y = 0; y < i_map.size(); y++)
        {              
            for (int x = 0; x < i_map[y].size(); x++)
            {   
                if(i_map[y][x] == cell_type && y*CELL_SIZE > i_y)
                {
                    if ((i_x < (x+1)*CELL_SIZE && (x+1)*CELL_SIZE < i_x + CELL_SIZE) && (y)*CELL_SIZE <= i_y + CELL_SIZE)
                    {
                        return true;
                    }

                    else if ((i_x < x*CELL_SIZE && x*CELL_SIZE < i_x + CELL_SIZE) && (y) * CELL_SIZE <= i_y + CELL_SIZE)
                    {
                        return true;
                    }

                    else if ((i_x == x*CELL_SIZE && (x+1)*CELL_SIZE == i_x + CELL_SIZE) && (y)*CELL_SIZE <= i_y + CELL_SIZE)
                    {
                        return true;
                    } 
                    
                }       
            }      
        }
        
        return false;
    }

    else if (direction == Collision_dierction::Right)
    {
        for (int y = 0; y < i_map.size(); y++)
        {              
            for (int x = 0; x < i_map[y].size(); x++)
            {   
                if(i_map[y][x] == cell_type && x*CELL_SIZE > i_x)
                {
                    if ((i_y < (y+1)*CELL_SIZE && (y+1)*CELL_SIZE < i_y + CELL_SIZE) && (x)*CELL_SIZE <= i_x + CELL_SIZE)
                    {   
                        return true;
                    }

                    else if ((i_y < y*CELL_SIZE && y*CELL_SIZE + 10 < i_y + CELL_SIZE) && (x) * CELL_SIZE <= i_x + CELL_SIZE)
                    {   
                        return true;
                    }

                    else if ((i_y == y*CELL_SIZE && (y+1)*CELL_SIZE == i_y + CELL_SIZE) && (x)*CELL_SIZE <= i_x + CELL_SIZE)
                    {
                        return true;
                    } 
                    
                }       
            }      
        }
        
        return false;
    }

    else if (direction == Collision_dierction::Left)
    {
        for (int y = 0; y < i_map.size(); y++)
        {              
            for (int x = 0; x < i_map[y].size(); x++)
            {   
                if(i_map[y][x] == cell_type && x*CELL_SIZE < i_x)
                {
                    if ((i_y < (y+1)*CELL_SIZE && (y+1)*CELL_SIZE < i_y + CELL_SIZE) && (x+1) * CELL_SIZE >= i_x)
                    {
                        return true;
                    }

                    else if ((i_y < y*CELL_SIZE && y*CELL_SIZE + 10 < i_y + CELL_SIZE) && (x+1) * CELL_SIZE >= i_x)
                    {                        
                        return true;
                    }

                    else if ((i_y == y*CELL_SIZE && (y+1)*CELL_SIZE == i_y + CELL_SIZE) && (x+1)*CELL_SIZE >= i_x)
                    {
                        return true;
                    } 
                    
                }       
            }      
        }
        
        return false;
    }

    cout << "have collision function error\n";
    return false;
}

bool have_collision_with_object(int object_x, int object_y, float turtle_x, float turtle_y)
{
    float turtle_center_x = turtle_x + CELL_SIZE/2;
    float turtle_center_y = turtle_y + CELL_SIZE/2;

    if (object_x*CELL_SIZE < turtle_center_x && turtle_center_x < (object_x+1) * CELL_SIZE)
    {
        if (object_y*CELL_SIZE < turtle_center_y && turtle_center_y < (object_y+1) * CELL_SIZE)
        {
            return true;
        }
    }

    return false;
}

Collision_dierction find_the_direction_of_collision(float turtle_x, float turtle_y, float object_x, float object_y)
{
    if ((turtle_x <= object_x+CELL_SIZE && object_x+CELL_SIZE <= turtle_x ) && (turtle_y <=  object_y && object_y <= turtle_y + CELL_SIZE))
    {
        return Collision_dierction::Down;
    }

    else if ((turtle_x  < object_x && object_x < turtle_x + CELL_SIZE) && (turtle_y <=  object_y &&  object_y <= turtle_y + CELL_SIZE))
    {
        return Collision_dierction::Down;
    }

    return Collision_dierction ::Left;
}

