/* Implementation of the class LinkedSortedList. Using STL random library to generate a set of random numbers from 1 to 100. Program will display a list of 21 random numbers followed by the same set in a sorted list, followed by the sorted list with the first value of the initial list removed.
 
 Lab 5: sortedlist.cpp
 Programmmer: Ariadna Ayala
 Status: Completed
 IDE used: Xcode
*/



#ifndef PRECOND_VIOLATED_EXCEPT_H
#define PRECOND_VIOLATED_EXCEPT_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error
{
public:
   PrecondViolatedExcept(const std::string& message = "")
   : std::logic_error("Precondition Violated Exception: " + message)
    {
    }
};
#endif
