#include "Sprite.h"



Sprite::Sprite(int apos_x, int apos_y, string aresource_file, int aresource_x, int aresource_y)
{

	pos_x = apos_x;
	pos_y = apos_y;
	resource_file = aresource_file;
	resource_x = aresource_x;
	resource_y = aresource_y;

}



Sprite::Sprite()
{
	pos_x = 0;
	pos_y = 0;
	resource_file = "";
    resource_x = 0;
	resource_y = 0;
}



//Takes the desired tile of .png and turns it into the location of the top left pixel of that tile
int Sprite::file_tile_x()
{
	int find_x = (((resource_x - 1) * 16) + 1);

	return find_x;
}

int Sprite::file_tile_y()
{
	int find_y = (((resource_y - 1) * 16) + 1);

	return find_y;
}



//Public mutators
int Sprite::move_x(int new_pos_x)
{
	pos_x = new_pos_x;
}

int Sprite::move_y(int new_pos_y)
{
	pos_x = new_pos_y;
}



//Public accessors for class
int Sprite::get_pos_x() const
{
	return pos_x;
}

int Sprite::get_pos_y() const
{
	return pos_y;
}

string Sprite::get_resource_file() const
{
	return resource_file;
}

int Sprite::get_resource_x() const
{
	return resource_x;
}

int Sprite::get_resource_y() const
{
	return resource_y;
}



//Possible construction for monk class
Monk::Monk(int pos_x, int pos_y)
{
	int p_pos_x = pos_x;
	int p_pos_y = pos_y;
	string p_resource_file = "Sprites.png";
	int p_resource_x = 5;
	int p_resource_y = 2;
}

