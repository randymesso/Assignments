///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Randy Messo
// Email:            Rmesso0807@my.msutexas.edu
// Label:            P01
// Title:            Stack Upgrade
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       Example implementation of an array based stack that holds //integers. It also shows how to increase the size of a stack
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;

/**
 * Stack
 * 
 * Description:
 *      Integer array based stack implementation
 * 
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *      
 */
class Stack 
{
private:
    int *S;       //array pointer
    int *S2;      //bigger array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     * 
     * Returns:
     *     Void
     */
    Stack() 
    {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     * 
     * Returns:
     *     Void
     */
    Stack(int cap) 
    {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     * 
     * Returns:
     *     Void
     */
    void Push(int data) 
    {
        if (size == capacity)
        {
          S2 = new int[capacity*2]; //allocate new memory twice the original
          for(int i = 0;i<capacity;i++) //Fill new array
          {
              S2[i] = S[i];
          }
          delete [] S; //Prevent a memory leak
          S = S2;
        }
          top++;              // move top of stack up
          size++;             // increment size
          S[top] = data;      // add item to array
    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     * 
     * Returns:
     *     int
     */
    int Pop() 
    {
        if (size == 0)
        {
          cout << "Error stack is empty!\n";
          return -1;
        }
        else
        {
        int data = S[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size
        return data;        // send item back
        }
    }

    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        //return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     * 
     * Returns:
     *     void
     */    
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so 
     *                    it cannot be changed
     * 
     * Returns:
     *     ostream 
     */
    friend ostream &operator<<(ostream &os, const Stack s) {
        os << "Overloaded!!" << endl;
        for (int i = s.top; i >= 0; i--) {
            os << s.S[i] << endl;
        }
        return os;
    }
};

int main() {
    Stack S1;           // calls default constructor
    Stack S2(10);       // calls overloaded constructor
    S2.Pop();
    
    S2.Push(1);
    S2.Push(2);
    S2.Push(3);
    S2.Push(4);
    S2.Push(5);
    S2.Push(6);
    S2.Push(7);
    S2.Push(8);
    S2.Push(9);
    S2.Push(10);
    S2.Push(11);        //Tries to inset outside of the"cap"
    S2.Print();

    cout << "Popped a: " << S2.Pop() << endl;
    cout << "Popped a: " << S2.Pop() << endl;
    cout << "Put in a 45" << endl;
    
    S2.Push(45);         //Add a new value after popping
    S2.Print();          //Print out the new list
}
