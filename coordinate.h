//Samuel Esparza
//Due October 26, 2026

//FILE FUCNTION - Defines the Coordinate structure used for 
//each node in the doubly-linked list, including x-y values, an ID, 
//and next and previous pointers.






#ifndef COORDINATE_H
#define COORDINATE_H


//Structure that stores one x-y coordinate
struct _coordinate
{
	float x;
	float y;

//unique ID # for this coordinate
	int coord_id;

//Pointer to the next coordinate in the list
	struct _coordinate *next;

//Pointer to the previous coordinate in the list
	struct _coordinate *previous;
};

//allows to use "Coordinate" instead of whole name
typedef struct _coordinate Coordinate;



#endif
