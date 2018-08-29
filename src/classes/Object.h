#ifndef OBJECT_H
#define OBJECT_H

class Object {
protected:
	int id;
public:
	int x, y;
	int priority; //low = bottom
	char disp;
	bool solid;
	Object();
	Object(int id, int x, int y);

	bool checkMove(int deltaX, int deltaY);
};

#endif
