/* Implementation of the class LinkedSortedList. Using STL random library to generate a set of random numbers from 1 to 100. Program will display a list of 21 random numbers followed by the same set in a sorted list, followed by the sorted list with the first value of the initial list removed.
 
 Lab 5: sortedlist.cpp
 Programmmer: Ariadna Ayala
 Status: Completed
 IDE used: Xcode
*/

#include <iostream>
#include <random>
#include "SortedListInterface.h"
#include "LinkedSortedList.h"
void displayList(const std :: shared_ptr<SortedListInterface<int>>& listPtr);


int main()
{
    auto dice = bind(std :: uniform_int_distribution<int>{1, 100},
                     std :: default_random_engine{std :: random_device()()});

    const int LIST_SIZE = 21;
    std :: shared_ptr<SortedListInterface<int>> listPtr = std :: make_shared<LinkedSortedList<int>>();
    int number = 0, position;

    for (int i = 0; i < LIST_SIZE; i++)
    {
        if (i == 0)
            std :: cout << "\t** 21 Random Numbers: **" << std :: endl;
        else
            std :: cout << ", ";

        // Generate a random number.
        number = dice();
        std :: cout << number;

        listPtr->insertSorted(number);
    }


    std :: cout << "\n\n\t** Sorted List of 21 Random Numbers: **" << std :: endl;
    displayList(listPtr);

    if (number > 0)
    {
        position = listPtr->getPosition(number);

        listPtr->remove(position);
    }

    
    std :: cout << "\n\n\t** Sorted List of 20 Random Numbers: **" << std :: endl;
    displayList(listPtr);
    std :: cout << std :: endl;

    return 0;
}


// Display sorted list.
void displayList(const std :: shared_ptr<SortedListInterface<int>>& listPtr)
{
   
    for (int pos = 1; pos <= listPtr->getLength(); pos++)
    {
        if (pos > 1)
            std :: cout << ", ";
        std :: cout << listPtr->getEntry(pos);
    }

}
