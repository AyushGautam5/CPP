# 📘 Virtual Functions in C++ 

## What is a Virtual Function?
A **virtual function** in C++ is a member function in the **base class** that is marked with the keyword `virtual` and can be **overridden** in derived classes.

It enables **runtime polymorphism**, meaning:
> The function that gets called is determined **at runtime**, based on the actual object type (not pointer type).

---

### ❓ Why use a base class pointer to refer to a derived class object?

✅ To achieve **runtime polymorphism**  
✅ To allow **one interface, many implementations**  
✅ To write **flexible and reusable code**  
✅ To handle **different objects uniformly**  
✅ To use **abstract classes** as interfaces

📌 Example:

```cpp
Animal* a;
Dog d;
a = &d;
a->speak();  // Calls Dog::speak() due to dynamic dispatch
```

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
This is called static binding or early binding — it happens at compile time.
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
Without virtual, the compiler uses static binding. Since a is an Animal*, the function call is resolved at compile time, and it always calls Animal::speak(), even if a points to a Dog object.

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
### Step-by-Step Internal Process with virtual:

1. vtable is created (at compile time): 
   -> Each class with virtual functions gets a vtable (a hidden static table of function pointers).

   eg: Animal's vtable → [ &Animal::speak ]
       Dog's vtable    → [ &Dog::speak ]

2. vptr is inserted in object (at runtime):
   -> A hidden pointer called vptr is added inside d
   -> vptr points to Dog's vtable
    Ex: Dog d:
        +---------------------+
        | vptr → Dog's vtable |
        +---------------------+

3. When you call: a->speak()
   C++ says:
    "Hmm, speak() is virtual, so don’t call based on a’s type"

    Instead:
    Follow a → points to d
    Follow d's vptr → Dog’s vtable
    Call Dog::speak() ✅

With virtual, C++ uses dynamic binding through a hidden mechanism called vtable.
Each object of a class with virtual functions has a hidden pointer called vptr that points to the class’s vtable, which stores function addresses.
So at runtime, the function call (a->speak()) is dispatched using the actual object’s vtable, not the pointer type.
That’s why Dog::speak() is called when a points to a Dog.



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

##  Pure Virtual Function in C++

- A virtual function with **no implementation** in the base class.
- Declared using `= 0` syntax.
- Makes the class **abstract**.
- Must be **overridden** in derived class.

```cpp
class Base {
    virtual void show() = 0;  // Pure virtual
};
```

### Purpose:

It tells the compiler:
"Every class that derives from me must override this function."

### Can a Pure Virtual Function Have a Body?

Yes! Though rare, a pure virtual function can have a body outside the class.
```cpp
class A {
public:
    virtual void func() = 0;  // Still pure virtual
};

void A::func() {
    cout << "Definition of pure virtual function\n";
}
```
This is allowed but usually used only when you want the derived class to override it, but still call the base version using Base::func().

## Are There Any Other Types of Virtual Functions?
Yes! 

| Type                            | Syntax                                      | Purpose                                                       |
| ------------------------------- | ------------------------------------------- | ------------------------------------------------------------- |
| **Virtual Function**            | `virtual void show();`                      | Enables polymorphism; optional to override                    |
| **Pure Virtual Function**       | `virtual void show() = 0;`                  | Forces derived classes to override; makes base class abstract |
| **Virtual Destructor**          | `virtual ~ClassName();`                     | Ensures derived class destructor is called via base pointer   |
| **Overridden Virtual Function** | In derived class with or without `override` | Implements or customizes base class virtual function          |

# NOTE 
### Is it necessary to override every virtual function of the base class?
Answer:
✅ Only pure virtual functions must be overridden in the derived class to make it concrete (instantiable).
❌ Regular virtual functions do not have to be overridden — the base class version will be used by default.

### ✅ How to override virtual / pure virtual functions in derived class

1. Use same function signature as base class
2. Use `override` keyword for safety (recommended)
3. For pure virtual (`= 0`), overriding is **mandatory**

📌 Example:

```cpp
class Animal {
public:
    virtual void speak() = 0;     // Pure virtual
    virtual void eat() {          // Regular virtual
        cout << "Animal eats\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks\n";
    }

    void eat() override {
        cout << "Dog eats bone\n";
    }
};
```

## What is a Virtual Destructor in C++?

✅ A virtual destructor ensures that both the **base and derived class destructors** are properly called  
when an object is deleted through a **base class pointer**.

🔁 Without `virtual`, only the base destructor is called → can cause **memory leaks**.
📌 Example:
```cpp
class Animal {
public:
    virtual ~Animal() {
        cout << "Animal destroyed\n";
    }
};

class Dog : public Animal {
public:
    ~Dog() {
        cout << "Dog destroyed\n";
    }
};

Animal* a = new Dog();
delete a;  // ✅ Both destructors called correctly
```
