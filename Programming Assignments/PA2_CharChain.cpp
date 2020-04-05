/* This problem asks user to enter a command from the menu and performs the commands of choice on a list.
 
 Lab 2: charchain.cpp
 Programmmer: Ariadna Ayala
 Status: Completed (Reworked)
 IDE used: Xcode
 
 Note: If you choose option one second time, it appends it to the latest value of a.
 I tried to fix it but at this point it is too late..
*/


#include<iostream>
#include<iomanip>
#include <string>
// using namespace std;

class Node{
    public:
        Node* next;
        char c;
        Node(char c)
        {
            next = NULL;
            this->c = c;
        }
};

class LinkedChar
{
private:
    Node* head;
    int size;
    
public:
    LinkedChar()
        {
            size = 0;
            head = new Node('*');
        }
        
// A constructor
    LinkedChar(const std::string s)
    {
        size = s.size();
        head = new Node('*');
        Node* curr = head;
        for(int i=0; i<s.size(); i++)
        {
            curr->next = new Node(s[i]);
            curr = curr->next;
        }
    }
    int length() const
    {
        return size;
    }


// Finds the first occurence of a character in the list.
// Starts from 1 instead of 0 for non-programmer users convenience.
    int index(char ch) const
    {
        Node* curr = head->next;
        int count = 1;
        while(curr!=NULL)
        {
            if(curr->c==ch)
            return count;
            curr = curr->next;
            count++;
        }
            return -1;
    }


// Appends an additional list to first one
    void append(const LinkedChar& lc)
    {
        Node* curr = head;
        while(curr->next!=NULL)
        curr = curr->next;
        Node* curr2 = lc.getHead();
        curr2 = curr2->next;
        while(curr2!=NULL)
        {
            curr->next = new Node(curr2->c);
            curr = curr->next;
            curr2 = curr2->next;
        }
        size += lc.length();
    }

// Tests function sumbatch;
    bool checkMatch(Node* curr1, Node* curr2) const
    {
        while(curr2!=NULL)
        {
            if(curr1->c!=curr2->c)
            return 0;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return 1;
    }

// Checks of another list exists as a substring in this list;
    bool submatch(const LinkedChar& lc) const
    {
        Node* curr = head->next;
        for(int i=0; i<size-lc.length()+1; i++)
        {
            if(checkMatch(curr, lc.getHead()->next))
            return 1;
            curr = curr->next;
        }
        return 0;
    }

//  Returns pointer to head node;
    Node* getHead() const
    {
        return head;
    }


//  Prints the string if it is needed. I like to have it so
// I know how my strings look like before or after manupulated;
    void print()
    {
        Node* curr = head->next;
        while(curr!=NULL)
        std :: cout<<curr->c, curr = curr->next;
    }
    
};

int main()
{
    int command;
    char charIndex;
    std :: string stringAppend;
    std :: string stringInput;
    LinkedChar a(stringInput);
    
    std :: cout << "\t\tMenu: " << std :: endl;
    std :: cout << "1 - Enter a string"
         << "\n2 - Get current string length"
         << "\n3 - Find index of a character"
         << "\n4 - Append another character"
         << "\n5 - Run a submatch test"
         << "\n6 - Quit" << std :: endl;
    std :: cout << "\nEnter command key: ";
    std :: cin >> command;
            while (command !=6)
            {
                switch (command)
                {
                    case 1:
                        
                        std :: cout << "Enter a string: ";
                        std :: cin.ignore();
                        std :: getline(std :: cin, stringInput);
                        a.append(stringInput);
                        //a.print();
                        //cout << "\nEnter command key: ";
                        //cin >> command;
                        break;
                    case 2:
                        std :: cout << "The length of string is " << a.length() << std :: endl;
                        break;
                    case 3:
                        std :: cout<<"Enter character you are looking for:" <<std :: endl;
                        std :: cin >> charIndex;
                        std :: cout << "Index of character is: " << a.index(charIndex)<<std :: endl;
                        break;
                    case 4:
                        std :: cout << "Enter a string to append: ";
                        std :: cin.ignore();
                        std :: getline(std :: cin, stringAppend);
                        a.append(stringAppend);
                        a.print();
                        break;
                    case 5:
                        std :: cout << "Submatch test result: ";
                       std ::  cout<< a.submatch(stringInput)<<std :: endl;
                        break;
                    default:
                        std :: cout << "Invalid command key. Try again.";
                        break;
            }
            std :: cout << "\nEnter command key: ";
            std :: cin >> command;
                }
    return 0;
}
