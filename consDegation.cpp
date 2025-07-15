#include<iostream>
#include<vector>

using namespace std;

class Chai{
    public:
        string teaName;
        int servings;
        vector<string> ingridients;

        //Delegating  Constructor
        Chai(string name): Chai(name, 1, {"Water", "Tea Leaves"}){}

        Chai(string name, int serve, vector<string> ingr){
            teaName = name;
            servings = serve;
            ingridients = ingr;
        }

        void displayChaiDetails(){
            cout << "Tea Name : " << teaName << "\n";
            cout << "Servings : " << servings << "\n";
            cout << "Ingridients : ";
            for(string ingridient : ingridients){
                cout << ingridient << " ";
            }
            cout << "\n";
        }

};


int main(){
    Chai cuttingChai("Ginger Tea");
    cuttingChai.displayChaiDetails();

    return 0;
}