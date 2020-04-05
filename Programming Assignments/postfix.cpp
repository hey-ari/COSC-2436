/* This program evaluates an entry of a postfix expression using an algorithm.
 
 Lab 3: postfix.cpp
 Programmmer: Ariadna Ayala
 Status: Completed
 IDE used: Xcode
*/

#include <iostream>
#include <stack>
#define MAX 100                                      // maximum size of the stack set to 100

class PostfixCalc                                    // PostfixCalc performs operations on
{                                                    // user input of a postfix expression;
private:
  int stack[MAX];
  int top;
  std :: string postfixExp;
  
public:
    PostfixCalc()                                     // Construct empty stack;
    {
        top = -1;
    }

    void setExp(std :: string s)                      // Sets expression string;
    {
        postfixExp = s;
    }


    void push(int value)                             // Pushes a stack;
    {
        if (top == MAX - 1)
            std :: cout << "Stack is full" << std :: endl;
        else
        {
            top++;
            stack[top] = value;
        }
    }

    
    int pop()                                          // Pops a stack;
    {
        if (top == -1)
        {
            std :: cout << "No values in the stack" << std :: endl;
            return 0;
        }
        int data = stack[top];
        top--;
        return data;
    }


    void evaluate()                                 // Evaluates expression string;
    {
        int i = 0;
        while (postfixExp[i])
        {
            // This allows to skip any empty space entries
            if (postfixExp[i] == ' ' || postfixExp[i] == '\t')
            {
                i++;
                continue;
            }
            // Pushes an operand into a stack
            if (isdigit(postfixExp[i]))
            {
                int temp = postfixExp[i] - '0';
                push(temp);
            }
            // If an operator enterd, will pop two operands and  apply
            // operator, then push again.
            else
            {
                int topStack1 = pop();
                int topStack2 = pop();
                int result;
                switch (postfixExp[i])
                {
                    case '+':
                        result = topStack2 + topStack1;
                        break;
                    case '-':
                        result = topStack2 - topStack1;
                            break;
                    case '/':
                        result = topStack2 / topStack1;
                        break;
                    case '*':
                        result = topStack2 * topStack1;
                        break;
                }
                push(result);
            }
            i++;
        }
    }

    
    void display()                              //Displays the result of expression;
    {
        int result = pop();
        std :: cout << " The result of evaluaton is: " << result << std :: endl;
        std :: cout << std :: endl;
  
    }
};


int main()                                      // Main tests postfix operations.
{
  std :: string postfixExp;
  while(postfixExp != "q")
  {
    std :: cout << "Enter your postfix expression or 'q' to quit the program: ";
    getline(std :: cin, postfixExp);
    PostfixCalc results;
    results.setExp(postfixExp);
    results.evaluate();
    results.display();
   }
   return 0;
}
