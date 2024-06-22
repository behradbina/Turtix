#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include"global_stuff.h"

using namespace sf;
using namespace std;

class Pause
{
private:

    string guide = "Back : Click Space Button\nExit : Click Q Button\n";
    Text guide_text;
    Font guide_font;

public:

    Pause(); 

    void open_pause_window(RenderWindow *window);


};

