## Functions in C++

A function is a block of code designed to perform a specific task. Functions in C++ follow this basic syntax:

```cpp
returnType functionName(parameters) {
  // function body
}
```

Return Type: Specifies the data type of the value returned by the function. Use void if no value is returned.
Function Name: Describes what the function does.
Parameters: Input values for the function (optional).

```cpp
#include <iostream>
using namespace std;

// Function to check tea temperature
int checkTeaTemperature(int temperature) {
  return temperature;
}

int main() {
  int temp = checkTeaTemperature(85);  // Function call
  cout << "The tea temperature is " << temp << "°C" << endl;
  return 0;
}
```

There are things in functions

function declaration
function defination
functions call


