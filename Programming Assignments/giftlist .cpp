/* This program collects string input from a user for, both, names for Santa's nice list and gifts designeted for each name. When all data entered, the program displays a list of names and the gifts.
 
 Lab 4: giftlist.cpp
 Programmmer: Ariadna Ayala
 Status: Completed
 IDE used: Xcode
*/


#include <iostream>
#include <list>
#include <string>



// Virtual member functions
template<class T>
class List
{
public:
    
    virtual void setName(std::string initName) = 0;
    virtual void addGift(T initGift) = 0;
    virtual std :: string getName() const = 0;
    virtual std :: string giftStr(std :: string split) = 0;
};



// Variables and Functions
template<class T>
class Nice : public List<T>
{
private:
    std :: string name;
    std :: list<T> gift;
public:
    void setName(std :: string initName);
    void addGift(T initGift);
    std :: string getName() const;
    std :: string giftStr(std :: string split = ",");
};



template<class T>
void Nice<T>::setName(std :: string initName)
{
    name = initName;
}


template<class T>
void Nice<T>::addGift(T initGift)
{
    gift.push_back(initGift);
}



template<class T>
std :: string Nice<T> :: getName() const
{
    return name;
}


template<class T>
std :: string Nice<T> :: giftStr(std :: string split)
{
    std :: string result;

    for (typename std :: list<T> :: iterator i = gift.begin(); i != gift.end(); i++)
    {
        if (!result.empty())
            result += split;
        result += T(*i);
    }

    return result;
}




int main()
{
    std :: list<Nice<std :: string>> lists;
    std :: string nameInput;
    std :: string giftInput;

    std :: cout << "\n\t\t\t ** Nice list **" << std :: endl;
    std :: cout << "Add a name: ";
    getline(std :: cin, nameInput);

    while (!nameInput.empty())
    {
        
        Nice<std :: string> niceList;
        niceList.setName(nameInput);

        std :: cout << "Add gifts for " << nameInput  << std :: endl;

        do
        {
            std :: cout << "Gift: ";
            getline(std :: cin, giftInput);
            niceList.addGift(giftInput);
        }
        while (!giftInput.empty());

        lists.push_back(niceList);

        std :: cout << "Add a name: ";
        getline(std :: cin, nameInput);
    }

    std :: cout << "\n\t\t\t ** The list contains ** " << std :: endl;
    for (auto aList: lists)
        std :: cout << aList.getName() << " -- " << aList.giftStr("\t") << std :: endl;

    return 0;
}
