//Samuel Esparza
//Due October 26, 2026

//FILE FUCNTION - Contains the definitions of all functions used to 
//operate on the doubly-linked list, including adding, displaying, 
//deleting, counting, and finding the closest coordinate.






#include <iostream>
#include <iomanip>
#include <cmath>

#include "coordinate_functions.h"





// Return the number of coordinates in the list
int list_length(Coordinate *list_begining)
{
	int count = 0;

//starts at the start of list
	Coordinate *current = list_begining;


//move throughs entire list
	while(current != nullptr)
	{
		count++;

		//move to next coordinate
		current = current->next;
	}

//total # of coordinates
return count;
}






// Add a new coordinate to the end of the list
void add_coordinate(Coordinate *list_end, float x, float y)
{
	//Make sure that the list contains a node
	if (list_end == nullptr)
	{
		std::cout << "ERROR : Cannot add a coordinate because the list is empty.\n";

		return;
	}

//Start at the end and find the begining of the list
	Coordinate *list_begining = list_end;

//Move backward until the first node is reached
	while (list_begining->previous != nullptr)
	{
		list_begining = list_begining->previous;
	}

//dynamically create a new coordinate node
	Coordinate *new_coordinate = new Coordinate;

//Store the supplied x-y values
	new_coordinate->x = x;
	new_coordinate->y = y;

//Automaticallly assign the coordinate ID
	new_coordinate->coord_id = list_length(list_begining);

//New node becomes end of list
	new_coordinate->next = nullptr;

//Connect the new node backward to the old ending node
	new_coordinate->previous = list_end;

//connect the old ending node forward to the new node
	list_end->next = new_coordinate;


}






// Display the list from beginning to end
void forward_display(Coordinate *list_begining)
{
//Check if th e list is emty
	if(list_begining == nullptr)
	{
		std::cout << "\nThe list is empty. Nothing to display forward.\n";

		return;
	}

//Start at begin of list
	Coordinate *current = list_begining;

//Display section title
	std::cout << "\nFORWARD DISPLAY\n";
	std::cout << "------------------------------\n";


//move through every coordinate
	while (current != nullptr)
	{
	//Dsiplay coordinate ID and x-y values
		std::cout 
			<< "ID: "
			<< current->coord_id
			<< "  ("
			<< std::fixed
			<< std::setprecision(2)
			<< current->x
			<< ", "
			<< current->y
			<< ")\n";

		//move forward to the next node
			current = current->next;

	}

}







// Display the list from end to beginning
void backward_display(Coordinate *list_end)
{
	// Check if the list is empty
    if (list_end == nullptr)
    {
        std::cout
            << "\nThe list is empty. Nothing to display backward.\n";

        return;
    }

//Start at te end of the list
    Coordinate *current = list_end;

//Display section title
    std::cout << "\nBACKWARD DISPLAY\n";
    std::cout << "----------------------------\n";

// Move backward throug every coordinate
    while (current != nullptr)
    {
    	//Display coordinate ID and x-y values
    	std::cout
    		<< "ID: "
    		<< current->coord_id
    		<< "  ("
    		<< std::fixed
    		<< std::setprecision(2)
    		<< current->x
    		<< ", "
    		<< current->y
    		<< ")\n";
    

    //Move backward to the previous node
    current = current->previous;

	}	
}







// Delete a coordinate using its coordinate ID
void delete_coordinate(Coordinate *list_begining, int coord_id_to_delete)
{
//Make sure the list is not empty
	if (list_begining == nullptr)
	{
		std::cout << "\nERROR : Cannot delete a coordinate because the list is empty.\n";


		return;
	}


//Begin searching at first node
	Coordinate *current = list_begining;

//Search for the requested coordinate ID
	while (current != nullptr && current->coord_id != coord_id_to_delete)
	{
		current = current->next;
	}
//Check if the requested ID was found
	if (current == nullptr)
	{
		std::cout 
			<< "\nCoordinate ID "
			<< coord_id_to_delete
			<< " was not found.\n";


		return;
	}


/// Special case : Delete the first Node
	if (current->previous == nullptr)
	{
	//Check if the is the only node in the list
		if (current->next == nullptr)
		{
			std::cout	
				<< "\nCannot delete the only coordinate "
				<< "with the required function setup.\n";

			return;
		}

	//Temporarily store the second node
		Coordinate *node_to_delete = current->next;

	//Copy the second nodes dat into the first node
		current->x = node_to_delete->x;

		current->y = node_to_delete->y;

		current->coord_id = node_to_delete->coord_id;


	//Connect the first node to the following node
		current->next = node_to_delete->next;

	//Fix the backward connection if another node exists
		if (node_to_delete->next != nullptr)
		{
			node_to_delete->next->previous = current;
		}


	//Free the removed nodes memory
		delete node_to_delete;

	}


//NORMA CASE : Delete any node after the first node
else
{

//Connect the previous node to the next node
	current->previous->next = current->next;

//Fix the next nodes backward pointer if it exists 
	if(current->next != nullptr)
	{
		current->next->previous = current->previous;
	}

//Freeing deleted nodes memory
	delete current;
}

//Comfirm successful deletion 
	std::cout
		<< "\nCoordinate ID "
		<< coord_id_to_delete
		<< " deleted successfully.\n";
}






// Find the coordinate closest to a supplied x-y point
void closest_to(Coordinate *list_begining, float x, float y)
{
//Make sure the list contains coordinates
	if (list_begining == nullptr)
	{
		std::cout
            << "\nThe list is empty. "
            << "Cannot search for the closest coordinate.\n";

        return;
	}


//Start at firt coordinate
	Coordinate *current = list_begining;

//Assume the first coordinate is closest at first
	Coordinate *closest = list_begining;

//Calculate the x and y differences
	float dx = current->x - x;

	float dy = current->y - y;

//Calculate first distance
	float shortest_distance = std::sqrt(dx * dx + dy * dy);

//Move to second coordinate 
	current = current->next;

//Check every remaining coordinates
	while (current != nullptr)
	{
		//Calculate x andy differences
		dx = current->x - x;

		dy = current->y - y;

		//Calculate distane to this coordinate
		float distance = std::sqrt(dx * dx + dy * dy);
	

//check if this coordinate is closer
	if (distance < shortest_distance)
	{
		//save new shortest_distance
		shortest_distance = distance;

		//Save new closest coordinate
		closest = current;
	}

	//Move to the next coordinate
	current = current->next;
}


//Display target coordinate
	std::cout 
		<< "\nCLOSEST COORDINATE TO ("
		<< std::fixed
		<< std::setprecision(2)
		<< x
        << ", "
        << y
        << ")\n";


	std::cout
        << "-----------------------------\n";

 // Display closest ID
    std::cout
        << "Closest ID: "
        << closest->coord_id
        << '\n';

// Display closest coordinate
    std::cout
        << "Coordinate: ("
        << closest->x
        << ", "
        << closest->y
        << ")\n";

// Display distance
    std::cout
        << "Distance: "
        << shortest_distance
        << '\n';


}




