/* This program implements the max algorithm to find a maximum value of an array.
 
 Lab 1: maxarray.cpp
 Programmmer: Ariadna Ayala
 Status: Completed (Reworked)
 IDE used: Xcode
*/


#include <iostream>
#include <algorithm>

//using namespace std;

template <class T>
 T maxArray(T arr[], int size)
{

    if (size <= 1)
    return arr[0];

    else if (size > 1)
    {
        return std::max(arr[size - 1], maxArray(arr, size - 1));
    }
    return arr[0];
}

int main()
{
    int numArray[] = {3, 0, 7, 99, 13};
    std :: cout << "Maximum number is: " << maxArray(numArray, 5) << std :: endl;
    char alphaArray[] = {'Z', 'a', 'p','D', 'a'};
    std :: cout << "Maximum character is: " << maxArray(alphaArray, 5) << std :: endl;
    return 0;
}
