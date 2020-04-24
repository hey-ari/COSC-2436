/* Implementation of the class LinkedSortedList. Using STL random library to generate a set of random numbers from 1 to 100. Program will display a list of 21 random numbers followed by the same set in a sorted list, followed by the sorted list with the first value of the initial list removed.
 
 Lab 5: sortedlist.cpp
 Programmmer: Ariadna Ayala
 Status: Completed
 IDE used: Xcode
*/



#ifndef NODE_H
#define NODE_H

#include <memory>

template<class ItemType>
class Node
{
private:
    // A data item
   ItemType item;
    // A pointer to next node
   std::shared_ptr<Node<ItemType>> next;
   
public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr);
   ItemType getItem() const ;
   std::shared_ptr<Node<ItemType>> getNext() const ;

};



template <class ItemType>
Node<ItemType> :: Node()
{
}

template<class ItemType>
Node<ItemType> :: Node (const ItemType& anItem) : item(anItem)
{
}

template<class ItemType>
Node<ItemType> :: Node(const ItemType& anItem,
                     std :: shared_ptr<Node<ItemType>> nextNodePtr)
               : item(anItem), next(nextNodePtr)
{
}

template<class ItemType>
void Node<ItemType> :: setItem(const ItemType& anItem)
{
   item = anItem;
}

template<class ItemType>
void Node<ItemType> :: setNext(std :: shared_ptr<Node<ItemType>> nextNodePtr)
{
   next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType> :: getItem() const
{
   return item;
}

template<class ItemType>
std :: shared_ptr<Node<ItemType>> Node<ItemType> :: getNext() const
{
   return next;
}

#endif
