#include "Turtix.h"

int main()
{
    Turtix turtix;

    while (turtix.running())
    {
        turtix.update();
        
        turtix.render();
    }

}
