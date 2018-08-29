#include "Object.h"

Object::Object() {
	id = 0;
	disp = 0;
	priority = 0;
	solid = false;
	x = 0;
	y = 0;

}

Object::Object(int id_input, int a, int b) {
	//So the compiler doesn't complain
	id = 0;
	disp = ' ';
	priority = 0;
	solid = false;
	x = 0;
	y = 0;

	switch (id_input) {
	case 0: //AIR
		id = 0;
		disp = ' '; //space
		priority = 0;
		solid = false;
		x = a;
		y = b;
		break;

	case 1: //FLOOR
		id = 1;
		disp = '.';
		priority = 0;
		solid = false;
		x = a;
		y = b;
		break;

	case 2: //WALL
		id = 2;
		disp = '#';
		priority = 100;
		solid = true;
		x = a;
		y = b;
		break;
	}
}
