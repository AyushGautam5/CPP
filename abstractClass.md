## Abstract Class
A class that contains at least one pure virtual function.

-> Cannot be instantiated
-> Meant to be inherited by other classes
-> Used to define an interface or common contract

```cpp
class Animal {
public:
    virtual void speak() = 0;  // Pure virtual → abstract class
};
```

## Concrete Class
A class that provides complete implementation for all its member functions (including inherited virtual/pure virtual ones).

-> Can be instantiated (objects can be created)
-> Can inherit from abstract classes and provide definitions for pure virtual functions

```cpp
class Dog : public Animal {
public:
    void speak() override {
        cout << "Bark\n";
    }
};
```
## What do we call a base class that can be instantiated?

It is called a **Concrete Base Class** (or simply a non-abstract base class).

| Term                    | Meaning                                                                                           |
| ----------------------- | ------------------------------------------------------------------------------------------------- |
| **Abstract Base Class** | A base class that **contains at least one pure virtual function**, and **cannot be instantiated** |
| **Concrete Base Class** | A base class that **does not contain any pure virtual function**, and **can be instantiated**     |

# Why you cannot create an object of an abstract class?

You cannot create an object of an abstract class because it has incomplete behavior — due to at least one pure virtual function that has no implementation.

```cpp
class Animal {
public:
    virtual void sound() = 0;  // No definition
};

Animal a;  // ❌ Error
```
You're asking the compiler to create an object a that must have a sound() method —
But you haven’t told the compiler what sound() actually does.

So the compiler says:
❌ "You can’t create this object because I don’t know how to fully define its behavior."

### Real life analogy 
```cpp
class Shape {
public:
    virtual void draw() = 0;
};
```
This says:
"Every shape must have a draw() function"
But we haven’t specified how to draw anything

So asking C++ to create a Shape object would be like saying:

“Build me a shape!”
But not telling what kind of shape — Circle? Square? Triangle?
❌ That’s not possible until you specify the details in a derived class.

### 📌 When does a class become abstract?

✅ A class becomes abstract if it contains **at least one pure virtual function** (`= 0`),  
even if other virtual or non-virtual functions are fully defined.

📌 Example:
```cpp
class A {
    virtual void definedFunc() { ... }   // ✅ Okay
    virtual void pureFunc() = 0;         // ❌ Makes A abstract
};
```
⛔ Cannot create object of A
✅ Must override pureFunc() in derived class to make it concrete

### ❓ Why does a class become abstract if it has even one pure virtual function?

- A pure virtual function is declared but not defined (`= 0`)
- It makes the class **incomplete**
- The compiler cannot allow creating objects of an incomplete class
- It's the derived class's job to provide the missing implementation

📌 Even if other functions are defined, just one pure virtual function makes the whole class **abstract**.

### ❓ When is a class abstract?

✅ A class becomes **abstract** if it contains **at least one pure virtual function**:
```cpp
virtual void func() = 0;  // Pure virtual → abstract class
