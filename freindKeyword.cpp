#include<iostream>

using namespace std;

class Chai{
    private:
        string teaName;
        int servings;

    public:
        // new syntax: parameterized constructor
        Chai(string name, int serve): teaName(name), servings(serve){}

        friend bool compareServings(const Chai &chai1, const Chai &chai2);

        // new syntax: use the word const(so it will remain constant)
        void display() const{
            cout << "Tea Name: " << teaName << "\n";
        }
};
 
// chai1 and chai2 are objects
// they are passed by refercence because copying an object can be expensive(if it has large members like vector, strings)
// const is used so that the data remains same (it is reading data over here not modifying it)
bool compareServings(const Chai &chai1, const Chai &chai2){
    return chai1.servings > chai2.servings;
}

int main(){

    Chai masalaTea("Masala Tea", 4);
    Chai gingerTea("Ginger Tea", 8);

    masalaTea.display();
    gingerTea.display();

    if(compareServings(masalaTea, gingerTea)){
        cout << "Masala Tea has more servings";
    }else{
        cout << "Ginger Tea has more servings";
    }

    return 0;
}