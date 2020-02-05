/* This program implements the max algorithm to find a maximum value of an array.
 
 Lab 1: maxarray.cpp
 Programmmer: Ariadna Ayala
 Status: Completed
 IDE used: Xcode
*/


#include <iostream>
#include <algorithm>

//using namespace std;

template <class T>
T max(T arr[], int size)
{
   T maxNum = arr[0];

    for (int k = 1; k < size; k++)
    {
        if(arr[k] > maxNum)
        {
            maxNum = arr[k];
        }
    }
    return maxNum;
}

int main()
{
    int numArray[] = {3, 0, 7, 99, 13};
    std :: cout << "Maximum number is: " << max(numArray, 5) << std :: endl;
    char alphaArray[] = {'g', 'a', 'p','D', 'a'};
    std :: cout << "Maximum character is: " << max(alphaArray, 5) << std :: endl;
    return 0;
}
