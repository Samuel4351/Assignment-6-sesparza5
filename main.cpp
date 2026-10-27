//Samuel Esparza
//Due October 26, 2026

//Description - This program creates a doubly-linked list of randomly
//generated x-y coordinate pairs. It allows coordinates to be added, 
//displayed forward and backward, deleted by ID, counted, and compared 
//to find the point closest to a given x-y location.

//FILE FUCNTION - Runs the main program, reads the number of coordinates
//from the command line, generates random x-y values, creates the linked 
//list, and tests all required functions.

//HOW TO USE PROGRAM -
//Compile using:
// g++ -std=c++11 -Wall -Wextra main.cpp coordinate_functions.cpp -o main
//
//Run the program using:
//
// ./main 10

//The number after ./main determines how many random x-y coordinates 
//are created. For example, ./main 10 creates 10 coordinate pairs.









#include <iostream>
#include <cstdlib>
#include <ctime>

#include "coordinate.h"
#include "coordinate_functions.h"



int main(int argc, char *argv[])
{
    // Make sure the user supplied the number of coordinates
    if (argc != 2)
    {
        std::cout
            << "Usage: ./main number_of_coordinates\n";


        std::cout
            << "Example: ./main 10\n";


        return 1;
    }


    // GET NUMBER OF COORDINATES
    // Convert the command-line argument from text to an integer
    int number_of_coordinates =
        std::atoi(argv[1]);



    // VALIDATE USER INPUT
    // Number of coordinates must be greater than zero
    if (number_of_coordinates <= 0)
    {
        std::cout
            << "Please enter a number greater than 0.\n";


        return 1;
    }



    // SET UP RANDOM NUMBER GENERATOR
    // Produces different random values each time the program runs
    std::srand(
        static_cast<unsigned int>(
            std::time(nullptr)
        )
    );



    // GENERATE FIRST RANDOM X-Y COORDINATE
    // Values range from 0.00 to 100.00

    float x =
        static_cast<float>(
            std::rand() % 10001
        ) / 100.0f;


    float y =
        static_cast<float>(
            std::rand() % 10001
        ) / 100.0f;



    // CREATE FIRST NODE
    // The first coordinate becomes the beginning of the list
    Coordinate *list_beginning =
        new Coordinate;


    // Store first random x-y coordinate
    list_beginning->x = x;

    list_beginning->y = y;


    // First node receives ID 0
    list_beginning->coord_id = 0;


    // First node currently has no next node
    list_beginning->next = nullptr;


    // First node currently has no previous node
    list_beginning->previous = nullptr;



    // SET END OF LIST
    // With one node, the beginning and end are the same node
    Coordinate *list_end =
        list_beginning;



    // CREATE REMAINING RANDOM COORDINATES
    // Add new nodes until the requested amount is reached

    for (
        int i = 1;
        i < number_of_coordinates;
        i++
    )
    {
        // Generate random x value
        x =
            static_cast<float>(
                std::rand() % 10001
            ) / 100.0f;


        // Generate random y value
        y =
            static_cast<float>(
                std::rand() % 10001
            ) / 100.0f;


        // Add new coordinate to the end of the list
        add_coordinate(
            list_end,
            x,
            y
        );


        // Move list_end to the newly created node
        list_end =
            list_end->next;
    }


    // DISPLAY LIST FORWARD
    // Beginning to end
    forward_display(
        list_beginning
    );



    // DISPLAY LIST BACKWARD
    // End to beginning
    backward_display(
        list_end
    );



    // DISPLAY CURRENT LIST LENGTH

    std::cout
        << "\nList length: "
        << list_length(
               list_beginning
           )
        << '\n';



    // TEST DELETE FUNCTION
    // Delete a coordinate near the middle of the list

    if (number_of_coordinates > 1)
    {
        // Choose an ID near the middle
        int id_to_delete =
            number_of_coordinates / 2;


        // Delete the selected coordinate
        delete_coordinate(
            list_beginning,
            id_to_delete
        );



        // FIND THE NEW END OF THE LIST
        // Needed in case the old ending node was deleted

        list_end =
            list_beginning;


        while (
            list_end->next != nullptr
        )
        {
            list_end =
                list_end->next;
        }



        // DISPLAY LIST AFTER DELETION

        std::cout
            << "\nLIST AFTER DELETION\n";


        forward_display(
            list_beginning
        );
    }

    else
    {
        // Do not test deletion if only one node exists
        std::cout
            << "\nOnly one coordinate exists, "
            << "so the deletion test is skipped.\n";
    }


    // TEST CLOSEST COORDINATE FUNCTION
    // Find the coordinate closest to (50, 50)
    float target_x =
        50.0f;


    float target_y =
        50.0f;


    closest_to(
        list_beginning,
        target_x,
        target_y
    );



    // FREE ALL REMAINING MEMORY
    // Delete every dynamically allocated coordinate
    Coordinate *current =
        list_beginning;


    while (current != nullptr)
    {
        // Save the next node before deleting current node
        Coordinate *next_node =
            current->next;


        // Free current node's memory
        delete current;


        // Move to the saved next node
        current =
            next_node;
    }



    // RESET POINTERS
    // Good practice after freeing dynamic memory
    list_beginning =
        nullptr;


    list_end =
        nullptr;



    // PROGRAM FINISHED SUCCESSFULLY

    std::cout
        << "\nProgram completed successfully.\n";


    return 0;
}
