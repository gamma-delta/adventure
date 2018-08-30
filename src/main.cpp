#include <iostream>
#include <vector>
#include <conio.h>
#include <math.h>

#include "classes/Object.h"
#include "classes/Player.h"

void introduce_object(Object o);
std::vector<Object*> getObjectsAtXY(int x, int y);
void refresh_map();
void display_map();

extern const int MAP_WIDTH = 30;
extern const int MAP_HEIGHT = 15; //extern const static void bool in var for MAP_HEIGHT

char disp_map [MAP_HEIGHT][MAP_WIDTH];

std::vector<Object> list_of_objects;

std::string mainOutput;

void introduce_object(Object o) {
	list_of_objects.push_back(o);
}

std::vector<Object*> getObjectsAtXY(int x, int y) {
	std::vector<Object*> _objects;
	for (int m = 0; m < (short) list_of_objects.size(); m++) {
		if (list_of_objects[m].x == x && list_of_objects[m].y == y) { //if it matches at that xy-pos
			_objects.push_back(&list_of_objects[m]); //add the address of that match
		}
	}
	return _objects;
}


void refresh_map() { //Go through every X and Y position in the map, and get each object at that position. Record the one with the highest priority
	int current_priority = -1;
	std::vector<Object*> _objects;
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			_objects = getObjectsAtXY(x, y);
			for (Object* _object : _objects) {
				if (_object->priority > current_priority) { //if the priority is good
					disp_map[y][x] = _object->disp; //assign the display
					current_priority = _object->priority; //update priority
				}
			}
			current_priority = -1; //reset priority
		}
	}
}

void display_map() {
	for (int i = 0; i < MAP_HEIGHT; i++) {std::cout << "\n";} //give space for next frame
	std::cout << mainOutput << "\n"; //show the output
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			std::cout << disp_map[y][x];
			if (x == MAP_WIDTH - 1) {std::cout << "\n";} //if its the last character in the line, newline
		}
	}
	mainOutput = ""; //clear the output
}


int main() {
	std::cout << "Starting...\n";
	//Set up the map

	Player player (5, 8); //set up the player
	introduce_object(player);

	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			introduce_object(Object(1, x, y)); //fills the room with floor
		}
	}

	char input;
	bool quit = false;
	while (!quit) { //the main loop!
		//cleanup
		refresh_map();
		display_map();

		std::cout << "Player pos: " << player.x << ", " << player.y << " | " << player.disp << "\n";

		//Input
		input = ' ';
		std::cin >> input;
		switch(input) {
		case 'w':
			player.move(0, -1);
			break;
		case 'a':
			player.move(-1, 0);
			break;
		case 's':
			player.move(0, 1);
			break;
		case 'd':
			player.move(1, 0);
			break;
		case 'q':
			quit = true;
			break;
		}
	} //end main loop

	std::cout << "Safely ending...";
	return 0;
}
