/*
Inheritance allows a class (derived/child) to reuse and extend features of another class (base/parent).
*/



#include<iostream>
#include<string>
#include<vector>

using namespace std;

//base class / original class / parent class

class Tea{
    protected:
        string teaName;
        int servings;

    public:
        Tea(string name, int serve): teaName(name), servings(serve){
            cout << "Tea Constructor called for " << teaName <<  "\n"; 
        }

        // const is written so that no members(variables) are modified. These type of methods are known as Read only methods because it can only read the object and canot modify it.
        virtual void brew() const{
            cout << "Brewing" << teaName << "with genric method" << "\n";
        }
        virtual void serve() const{
            cout << "Serving" << servings << " cup of tea with genric method" << "\n";
        }
        
        virtual ~Tea(){
            cout << "Tea destructor called for " << teaName << "\n";
        }
};

/*
Then GreenTea cannot publicly access the members and methods of Tea from outside the class — and neither can any code that tries to treat GreenTea as a Tea.

🔥 What actually happens with private inheritance?
All public and protected members of Tea become private in GreenTea.

That means:
✅ GreenTea can use the base class members inside its own methods.
❌ But outside code cannot treat GreenTea as a Tea.

class Tea {
public:
    void serve() const {
        cout << "Serving tea\n";
    }
};

class GreenTea : private Tea {
public:
    void brew() {
        serve(); // ✅ Allowed inside GreenTea
    }
};

int main() {
    GreenTea g;
    g.brew();   // ✅ OK
    g.serve();  // ❌ Error: 'serve' is private in GreenTea
}

*/
// syntax for derived class
class GreenTea : public Tea{
    public:
        // It is necessary to call the constructor of base class if it has parametised constructor. Not necessary in default constructor
        GreenTea(int serve): Tea("Green Tea", serve){
            cout << "GreenTea constructor called" << "\n";
        }

        // teaName can be acceesed because it is protected in the base class
        void brew() const override {
            cout << "Brewing " << teaName << " with steeping green tea leaves" << "\n";
        }

        ~GreenTea(){
            cout << "GreenTea destructor called" << "\n";
        }
};

class MasalaTea : public Tea{
    public:
        MasalaTea(int serve): Tea("Masala Tea", serve){
            cout << "MasalaTea constructor called" << "\n";
        }

        // final :- You do not want to override this method when you make a class derived from this class(MasalaTea)
        void brew() const override final {
            cout << "Brewing " << teaName << " with milk and spices" << "\n";
        }

        ~MasalaTea(){
            cout << "MasalaTea destructor called" << "\n";
        }
};

// class SpicyMasalaTea : public MasalaTea{
//     public:

//         // here you cannot override the function the brew which is defined in MasalaTea class
//         void brew() const override final {
//             cout << "Brewing" << teaName << "with milk and spices" << "\n";
//         }
// };

int main(){

    Tea* tea1 = new GreenTea(2);
    Tea* tea2 = new MasalaTea(4);

    tea1->brew();
    tea1->serve();

    tea2->brew();
    tea2->serve();

/*
t->vptr → points to GreenTea's vtable.
vtable[~Tea] → actually points to GreenTea’s destructor, because it's overriding the base destructor virtually.
Then what happens?
The call is dispatched to GreenTea's destructor.
GreenTea's destructor executes.
When GreenTea's destructor finishes, it automatically calls the base class destructor (Tea::~Tea) at the end — just like how constructors call base first, destructors call base last.

Why is this important?
Without a virtual ~Tea(), delete t; would only call Tea::~Tea() — not GreenTea::~GreenTea() — leading to incomplete cleanup and possibly memory leaks.

*/
    delete tea1;
    delete tea2;

    return 0;
}

/*
When GreenTea (or any derived class) does not override a virtual function like serve(), 
then its own vtable contains the base class's function pointer for serve().
So,
-> The vtable of GreenTea does include serve().
-> But that entry points to Tea::serve().

INTERNALLY the function is called as tea1->vptr->brew();

INTERNALLY WHAT happens:

Tea* tea1 = new GreenTea(2);
tea1->serve();  // Virtual function

-> tea1 points to a GreenTea object.
-> GreenTea does not override serve(), but serve() is still virtual.
-> So the compiler uses: tea1->vptr->serve();
-> And since serve() is not overridden, the vptr (which points to GreenTea's vtable) contains:

vtable[serve] = &Tea::serve

-> So Tea::serve() is called via GreenTea's vtable, not Tea's.

Key Principle:
-> Each class that has virtual functions gets its own vtable.
-> That vtable contains function pointers for all virtual functions,
-> and if a function is not overridden, it inherits the base class's implementation into its vtable.
*/



