/* Implementation of the class LinkedSortedList. Using STL random library to generate a set of random nubers from 1 to 100. Program will display a list of 21 random numbers followed by the same set in a sorted list, followed by the sorted list with the first value of the initial list removed.
 
 Lab 5: sortedlist.cpp
 Programmmer: Ariadna Ayala
 Status: Completed
 IDE used: Xcode
*/



#ifndef LINKED_SORTED_LIST_H
#define LINKED_SORTED_LIST_H

//#include <memory>
//#include <cmath>
//#include <cassert>
#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
// using namespace std;

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
    std :: shared_ptr<Node<ItemType>> headPtr;
    int itemCount;

    auto getNodeBefore(const ItemType& anEntry) const;
    auto getNodeAt(int position) const;
    auto copyChain(const std :: shared_ptr<Node<ItemType>>& origChainPtr);

public:
    // Constructor.
    LinkedSortedList();
    LinkedSortedList(const LinkedSortedList<ItemType>& aList);

    // Destructor.
    virtual ~LinkedSortedList();

    bool insertSorted(const ItemType& newEntry);
    bool removeSorted(const ItemType& anEntry);
    int getPosition(const ItemType& anEntry) const;

    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const throw(PrecondViolatedExcept);
};



template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : headPtr(nullptr), itemCount(0)
{
}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType> &aList)
{
    headPtr = copyChain(aList.headPtr);
    itemCount = aList.itemCount;
}

template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
    clear();
}

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType &anEntry) const
{
    auto curPtr = headPtr;
    std :: shared_ptr<Node<ItemType>> prevPtr;

    while ( (curPtr != nullptr) && (anEntry > curPtr->getItem()) )
    {
        prevPtr = curPtr;
        curPtr = curPtr->getNext();
    }
    return prevPtr;
}

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(int position) const
{
    // Check of precondition.
    assert( (position >= 1) && (position <= itemCount) );

    // Count from the beginning of the chain.
    auto curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();
    return curPtr ;
}

template<class ItemType>
auto LinkedSortedList<ItemType>::copyChain(const std :: shared_ptr<Node<ItemType>> &origChainPtr)
{
    std :: shared_ptr<Node<ItemType>> copiedChainPtr;
    if (origChainPtr != nullptr)
    {
        copiedChainPtr = make_shared<Node<ItemType>>(origChainPtr->getItem());
        copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    }
    return copiedChainPtr;
}



template<class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType &newEntry)
{
    int newPosition = abs(getPosition(newEntry));
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);

    if (ableToInsert)
    {
        // Create a new node containing a new entry.
        auto newNodePtr = std :: make_shared<Node<ItemType>>(newEntry);

        // Attach new node.
        if (newPosition == 1)
        {
            // Add a new node at the beginning.
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that goes before a new node.
            auto prevPtr = getNodeAt(newPosition - 1);

            // Insert a new node after the one to which prevPtr points.
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }
        // Increase entries count.
        itemCount++;
    }

    return ableToInsert;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType &anEntry)
{
    bool ableToDelete = false;
    if (!isEmpty())
    {
        auto nodeToRemovePtr = headPtr;
        auto prevPtr = getNodeBefore(anEntry);
        if (prevPtr != nullptr)
            nodeToRemovePtr = prevPtr->getNext();

        ableToDelete = (nodeToRemovePtr != nullptr) &&
                       (anEntry == nodeToRemovePtr->getItem());
        if (ableToDelete)
        {
            auto aftPtr = nodeToRemovePtr->getNext();
            if (nodeToRemovePtr == headPtr)
            {
                // Remove the first node.
                headPtr = aftPtr;
            }
            else
            {
                // Disconnect indicated node from chain by connecting the
                // previous node with the one that follows.
                prevPtr->setNext(aftPtr);
            }
            // Decrease entries count.
            itemCount--;
        }
    }

    return ableToDelete;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType &anEntry) const
{
    int position = 1;
    int length = getLength();

    while ( (position <= length) && (anEntry > getEntry(position)) )
        position++;

    if ( (position > length) || (anEntry != getEntry(position)) )
        position = -position;

    return position;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
    bool ableToDelete = (position >= 1) && (position <= itemCount);
    if (ableToDelete)
    {
        if (position == 1)
        {
            // Remove the first node.
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find a node that goes before the one that needs to be deleted.
            auto prevPtr = getNodeAt(position - 1);

            // Point to node to delete.
            auto curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // previous node with the one that follows.
            prevPtr->setNext(curPtr->getNext());
        }
        // Decrease entries count.
        itemCount--;
    }

    return ableToDelete;
}

template<class ItemType>
void LinkedSortedList<ItemType>::clear()
{
    headPtr.reset();

    itemCount = 0;
}

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        auto nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std :: string message = "getEntry() called with an empty linked sorted list or ";
        message  = message + "invalid position.";
        throw(PrecondViolatedExcept(message));
    }
}


#endif
