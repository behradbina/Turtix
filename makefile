turtix: main.o Baby_turtle.o Enemy.o Collision_type.o Turtix.o Turtle.o Pause.o
	g++ main.o Baby_turtle.o Enemy.o Collision_type.o Turtix.o Turtle.o Pause.o -o turtix.out -lsfml-graphics -lsfml-window -lsfml-system

main: main.cpp
	g++ -c main.cpp
	
game: Turtix.cpp
	g++ -c Turtix.cpp
	
babies: Baby_turtle.cpp
	g++ -c Baby_turtle.cpp
	
enemies: Enemy.cpp
	g++ -c Enemy.cpp
	
collision: Collision_type.cpp
	g++ -c Collision_type.cpp
	
turtle: Turtle.cpp
	g++ -c Turtle.cpp
	
pause: Pause.cpp
	g++ -c Pause.cpp
	
clean:
	rm *.o
