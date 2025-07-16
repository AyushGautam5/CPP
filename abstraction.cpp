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

Virtual function  - In virtual md file

*/

#include<iostream>
#include<string>

using namespace std;

class Tea{
    public:
        virtual void prepareIngredients() = 0; // pure virtual funtion
        virtual void brew() = 0; // pure virtual funtion
        virtual void serve() = 0; // pure virtual funtion

        void maketea(){
            prepareIngredients();
            brew();
            serve();
        }
};
//Derived Class
class GreenTea : public Tea{
    public:
        void prepareIngredients() override {
            cout << "Green Leaves and Water is ready" << "\n";
        }
        void brew() override{
            cout << "Tea Brewed" << "\n";
        }
        void serve() override {
            cout << "Tea Served" << "\n";
        }
};

//Another Derived class
class MasalaTea : public Tea{
    public:
    void prepareIngredients() override {
            cout << "Spices and milk is already with water" << "\n";
        }
        void brew() override{
            cout << "Masala Tea Brewed" << "\n";
        }
        void serve() override {
            cout << "Masala Tea Served" << "\n";
        }
};

using namespace std;

int main(){

    GreenTea greenTea;
    MasalaTea masalaTea;

    greenTea.maketea();
    masalaTea.maketea();

    return 0;
}

/*
When greenTea.maketea() is called:

void maketea(){
    prepareIngredients();  // virtual
    brew();                // virtual
    serve();               // virtual
}

This method belongs to the base class (Tea), but the actual object is GreenTea.
So when it says prepareIngredients(); → it’s a virtual function, and the compiler generates:

vptr->prepareIngredients();  // indirect call via vtable

And since the vptr points to the GreenTea vtable, the GreenTea versions of the methods are called.

So WHY does this happen?
Because: Virtual functions in C++ are always dispatched through the vtable, and the vtable used belongs to the actual object, not the static type.

🔍 Why and How Does Base Class Use Derived Class Vtable?

🔹 When a class has virtual functions, C++ creates:
- A vtable (virtual function table)
- A hidden pointer `vptr` in each object that points to the class’s vtable

🔹 In derived classes:
- The vtable is updated to point to the overridden functions

🔹 At runtime:
- If you call a virtual function (even from a base class method),
- C++ uses the object’s `vptr` to look up the correct function in the vtable

📌 So even if `maketea()` is defined in the base class, the `vptr` in the `GreenTea` object points to the `GreenTea` vtable,
and that’s why the overridden functions are called.

✅ This is called dynamic dispatch or runtime polymorphism.

*/