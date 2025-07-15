/*
Abstraction:
Abstraction is one of the core principles of Object-Oriented Programming (OOP).
It hides the internal implementation and only shows the essential features of an object.

Think of a car:
You can drive it using the steering, accelerator, brake, etc.
But you don’t know (and don’t need to know) how the engine works internally.

Similarly, in C++:
The user interacts with a simple interface.
The complex code behind it is hidden.

-> to hide the complexity of code.
-> Like sort() function in STL(you directly used it in a code but you don't know the implementation behind it).

Virtual function  - In next md file
*/

#include<iostream>
#include<string>

class Tea{
    public:
        virtual void prepareIngredients() = 0; // pure virtual funtion

};

using namespace std;

int main(){

    return 0;
}