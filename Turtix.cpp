#include "Turtix.h"

Turtix::Turtix()
{  
    init_variables();
    init_window(); 
    create_map();
}

Turtix::~Turtix()
{
    delete window;
}

void Turtix:: poll_events()
{
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event:: Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:

            if (ev.key.code == sf::Keyboard::Q)
            {
                window->close();
            }

            else if (ev.key.code == sf::Keyboard::Space)
            {
                pause = !pause;
            }

            
        default:
            break;
        }
    }
    
}

void Turtix::update()
{
    poll_events();
    
    if (!pause)
    {
        turtle.update(map, enemies);
        update_enemies();
        update_baby_turtles();
    }
    
}

void Turtix::render()
{

    camera_view.setCenter(Vector2f(turtle.get_x(), turtle.get_y()));
    camera_view.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

    window->setView(camera_view);
    window->clear(Color(50,115,220));

    if (pause)
    {
        pause_page.open_pause_window(window);
        return;
    }
    

    turtle.render(window);
    render_enemies();
    render_baby_turtles();

    draw_map();
    window->display();
    
}

void Turtix::init_variables()
{
    window = nullptr;
    pause = false;
}

void Turtix::init_window()
{
    video_mode.height = SCREEN_HEIGHT;
    video_mode.width = SCREEN_WIDTH;
    
    window = new sf::RenderWindow(this->video_mode, "Turix", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);
    
}

bool Turtix::running()
{
    if (window->isOpen() && baby_turtles.size() != 0 && turtle.is_alive())
        return true;
    
    return false;
}

void Turtix::create_map()
{
    string line_of_map; 
    ifstream game_map;
    game_map.open("map.txt");

    int y = 0;

    while (getline(game_map, line_of_map))
    {
        vector<Cell> single_floor;
        
        for (int x = 0; x < line_of_map.size(); x++)
        {
            if (line_of_map[x] == ' ')
            {
                single_floor.push_back(Cell::Empty);
            }

            else if (line_of_map[x] == '.')
            {
                single_floor.push_back(Cell::Wall);
            }
            
            else if (line_of_map[x] == '#')
            {
                single_floor.push_back(Cell::Ladder);
            }

            else if (line_of_map[x] == '-')
            {
                single_floor.push_back(Cell::Rope);
            }

            else if (line_of_map[x] == '$')
            {
                single_floor.push_back(Cell::Portal);
                portal_x = x*CELL_SIZE;
                portal_y = y*CELL_SIZE;
                turtle.set_cordinate(portal_x, portal_y);
                turtle.set_portal_cordinate(portal_x, portal_y);
            }
            
            else if(line_of_map[x] == '^')
            {
                single_floor.push_back(Cell::Daimond);
            }

            else if(line_of_map[x] == '*')
            {
                single_floor.push_back(Cell::Star);
            }

            else if(line_of_map[x] == 'E')
            {       
                single_floor.push_back(Cell::Empty);
                enemies.push_back(new Enemy_type_1(x*CELL_SIZE ,y*CELL_SIZE));
            }
            
            else if(line_of_map[x] == 'M')
            {       
                single_floor.push_back(Cell::Empty);
                enemies.push_back(new Enemy_type_2(x*CELL_SIZE ,y*CELL_SIZE));
            }

            else if(line_of_map[x] == 'O')
            {
                
                single_floor.push_back(Cell::Empty);
                baby_turtles.push_back(new Baby_Turtle(x*CELL_SIZE ,y*CELL_SIZE));
            }

            else if (line_of_map[x] == '|')
            {
                single_floor.push_back(Cell::Blade);
            }


            else 
            {
                single_floor.push_back(Cell::Empty);
            }
        }

        y++;
        map.push_back(single_floor);
        single_floor.clear();
    }
    
    game_map.close();     
}

void Turtix::draw_map()
{
    Texture Wall_texture;
    if(!Wall_texture.loadFromFile("ground-grass_block.png"))
    {
        cout << "loading ground-grass_block.png error\n";
        exit(EXIT_FAILURE);
    }
    Sprite cell_shape(Wall_texture);
    
    Texture daimond_texture;
    if(!daimond_texture.loadFromFile("daimond.png"))
    {
        cout << "loading daimond.png error\n";
        exit(EXIT_FAILURE);
    }
    Sprite daimond_shape(daimond_texture);

    Texture star_texture;
    if(!star_texture.loadFromFile("star.png"))
    {
        cout << "loading star.png error\n";
        exit(EXIT_FAILURE);
    }
    Sprite star_shape(star_texture);

    Texture portal_texture;
    if(!portal_texture.loadFromFile("portal.png"))
    {
        cout << "loading star.png error\n";
        exit(EXIT_FAILURE);
    }
    Sprite portal_shape(portal_texture);

    Texture rope_texture;
    if(!rope_texture.loadFromFile("rope.png"))
    {
        cout << "loading rope.png error\n";
        exit(EXIT_FAILURE);
    }
    Sprite rope_shape(rope_texture);

    Texture blade_texture;
    if(!blade_texture.loadFromFile("blade.png"))
    {
        cout << "loading rope.png error\n";
        exit(EXIT_FAILURE);
    }
    Sprite blade_shape(blade_texture);

    Texture ladder_texture;
    if(!ladder_texture.loadFromFile("ladder.png"))
    {
        cout << "loading ladder.png error\n";
        exit(EXIT_FAILURE);
    }
    Sprite ladder_shape(ladder_texture);

    for (unsigned short y = 0; y < map.size(); y++)
    {
        for (unsigned short x = 0; x < map[y].size(); x++)
        {
            if (map[y][x] == Cell::Empty)
            {
                continue;
            }

            if (map[y][x] == Cell::Wall)
            {
                cell_shape.setPosition(CELL_SIZE * x, CELL_SIZE * y);
                (*window).draw(cell_shape);
            }

            else if (map[y][x] == Cell::Daimond)
            {
                daimond_shape.setPosition(CELL_SIZE * x, CELL_SIZE * y);
                (*window).draw(daimond_shape);
            }

            else if (map[y][x] == Cell::Star)
            {
                star_shape.setPosition(CELL_SIZE * x, CELL_SIZE * y);
                (*window).draw(star_shape);
            }

            else if (map[y][x] == Cell::Portal)
            {
                portal_shape.setPosition(CELL_SIZE * x, CELL_SIZE * y);
                (*window).draw(portal_shape);
            }   

            else if (map[y][x] == Cell::Ladder)
            {
                ladder_shape.setPosition(CELL_SIZE * x, CELL_SIZE * y);
                (*window).draw(ladder_shape);
            }  

            else if (map[y][x] == Cell::Rope)
            {
                rope_shape.setPosition(CELL_SIZE * x, CELL_SIZE * y);
                (*window).draw(rope_shape);
            }    

            else if (map[y][x] == Cell::Blade)
            {
                blade_shape.setPosition(CELL_SIZE * x, CELL_SIZE * y);
                (*window).draw(blade_shape);
            }      
        }
    }
    
}

void Turtix::update_enemies()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->update(map);

        if (enemies[i]->is_dead())
        {
            delete enemies[i];
            enemies.erase(enemies.begin() + i);      
        }
        
    }
}

void Turtix::render_enemies()
{    
    
    for (auto enemy : enemies)
        enemy->render(window);
}

void Turtix::update_baby_turtles()
{
    for (int i = 0; i < baby_turtles.size(); i++)
    {
        baby_turtles[i]->update(map, turtle.get_x(), turtle.get_y(), portal_x);

        if (baby_turtles[i]->is_arrived_to_portal(portal_x, portal_y))
        {
            delete baby_turtles[i];
            baby_turtles.erase(baby_turtles.begin() + i);          
        }
        
    }
}

void Turtix::render_baby_turtles()
{    
    for (auto b : baby_turtles)
        b->render(window);   
}
