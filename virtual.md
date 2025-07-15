# 📘 Virtual Functions in C++ 

## What is a Virtual Function?
A **virtual function** in C++ is a member function in the **base class** that is marked with the keyword `virtual` and can be **overridden** in derived classes.

It enables **runtime polymorphism**, meaning:
> The function that gets called is determined **at runtime**, based on the actual object type (not pointer type).

---

## Why Use Virtual Functions?

Without `virtual`:
```cpp
Animal* a = new Dog();
a->speak();  // Calls Animal::speak() ❌
```
With `virtual`:
```cpp
Animal* a = new Dog();
a->speak();  // Calls Dog::speak() ✅
```

## Key Concepts                 

| Term             | Meaning                                                                   |
| ---------------- | ------------------------------------------------------------------------- |
| `virtual`        | Keyword used to mark a function for dynamic (runtime) dispatch            |
| vtable           | A table storing pointers to virtual functions                             |
| vptr             | A hidden pointer inside each object that points to its class's vtable     |
| dynamic dispatch | Function call is resolved at runtime based on actual object               |
| static dispatch  | Function call is resolved at compile time based on pointer/reference type |


## Behavior Without Virtual Function

Function calls are bound at compile-time.
Based on type of pointer, not object.
❌ Does not support polymorphism.
```cpp
class Animal {
public:
    void speak() { cout << "Animal\n"; }
};

class Dog : public Animal {
public:
    void speak() { cout << "Dog\n"; }
};

Animal* a = new Dog();
a->speak();  // ❌ Output: Animal
```
## Behavior With Virtual Function

Function calls are bound at runtime.
Based on actual object type, even when using base class pointers.
✅ Enables polymorphism.

```cpp
class Animal {
public:
    virtual void speak() { cout << "Animal\n"; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Dog\n"; }
};

Animal* a = new Dog();
a->speak();  // ✅ Output: Dog
```
## Is virtual Needed in Derived Class?
No.
Once a function is declared virtual in the base class, it remains virtual in all derived classes, even if not re-marked.
```cpp
class Animal {
public:
    virtual void speak();  // virtual
};

class Dog : public Animal {
public:
    void speak();          // still virtual (inherited)
};
```

## What Happens Internally (Memory Layout)?

Compiler creates a vtable for each class that has virtual functions (inherited or declared).
Each object of such class has a hidden vptr that points to the correct vtable.
Function call like a->speak() is resolved by:
Using the vptr → to vtable → to the correct function.

Animal* a = new Dog();

a
|
v
[Dog object]
  |
  +-- vptr ----> [Dog's vtable]
                  |
                  +-- speak() --> Dog::speak()

##  Benefits of Virtual Functions

✅ Enables runtime polymorphism
✅ Makes code more flexible and maintainable
✅ Supports abstraction and interfaces via abstract classes

## What is a Pure Virtual Function in C++?

A pure virtual function is a virtual function that has no implementation in the base class.
It is declared by using = 0 syntax in the class definition.

```cpp
class Base {
public:
    virtual void show() = 0;  // Pure virtual function
};
```

### Purpose:

It tells the compiler:
"Every class that derives from me must override this function."

## Are There Any Other Types of Virtual Functions?
Yes! 

| Type                            | Syntax                                      | Purpose                                                       |
| ------------------------------- | ------------------------------------------- | ------------------------------------------------------------- |
| **Virtual Function**            | `virtual void show();`                      | Enables polymorphism; optional to override                    |
| **Pure Virtual Function**       | `virtual void show() = 0;`                  | Forces derived classes to override; makes base class abstract |
| **Virtual Destructor**          | `virtual ~ClassName();`                     | Ensures derived class destructor is called via base pointer   |
| **Overridden Virtual Function** | In derived class with or without `override` | Implements or customizes base class virtual function          |

