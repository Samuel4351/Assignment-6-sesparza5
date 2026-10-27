//Samuel Esparza
//Due October 26, 2026

//FILE FUCNTION - Declares all functions used to add, display, 
//delete, count, and search coordinates in the doubly-linked list.






#ifndef COORDINATE_FUNCTIONS_H
#define COORDINATE_FUNCTIONS_H


#include "coordinate.h"




// Add a new coordinate to the end of the list
void add_coordinate(Coordinate *list_end, float x, float y);


// Display the list from beginning to end
void forward_display(Coordinate *list_begining);


// Display the list from end to beginning
void backward_display(Coordinate *list_end);


// Delete a coordinate using its coordinate ID
void delete_coordinate(Coordinate *list_begining, int coord_id_to_delete);


// Return the number of coordinates in the list
int list_length(Coordinate *list_beginning);


// Find the coordinate closest to a supplied x-y point
void closest_to(Coordinate *list_beging, float x, float y);




#endif
