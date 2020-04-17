#pragma once

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <SDL.h>

using namespace std;

class Sprite
{

public:
	
	Sprite(int a_pos_x, int a_pos_y, string a_resource_file, int a_resource_x, int a_resource_y);

	Sprite();
	
	int file_tile_x();
	int file_tile_y();

	int move_x(int new_pos_x);
	int move_y(int new_pos_y);

	int get_pos_x() const;
	int get_pos_y() const;
	string get_resource_file() const;;
	int get_resource_x() const;
	int get_resource_y() const;

private:

	int pos_x;
	int pos_y;
	string resource_file;
	int resource_x;
	int resource_y;

};


//Example subclass representing how a subclass will be made for each distinguishable minion in game
class Monk : public Sprite
{

public:

	Monk(int pos_x, int pos_y);


};


