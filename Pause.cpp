#include "Pause.h"

Pause::Pause()
{  
    if(!guide_font.loadFromFile("gameFont.ttf"))
    {
        cout << "guide_font loading from file error\n";
        exit(EXIT_FAILURE);
    }
    
    guide_text.setCharacterSize(360);
    guide_text.setFont(guide_font);
    
    guide_text.setFillColor(Color::Black);
    guide_text.setString(guide);    
    guide_text.setStyle(Text::Bold);
}

void Pause::open_pause_window(RenderWindow *window)
{
    window->clear(Color::White);
    window->draw(guide_text);
    window->display();
}
