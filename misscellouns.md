## ➤ What is the `->` (Arrow) Operator in C++?

✅ Used to access **members of an object via a pointer**

| Situation             | Operator | Example             |
|-----------------------|----------|---------------------|
| Direct object access  | `.`      | `obj.member`        |
| Pointer to object     | `->`     | `ptr->member`       |

🔁 `ptr->member` is same as `(*ptr).member`

📌 Very useful in:
- Accessing class members via pointers
- Dynamic memory (`new`)
- Polymorphism (`Base* ptr = new Derived(); ptr->func();`)

. is for object and -> is for pointer.
