/*
getter or setter:

->Used to access the private data members(variales) of a class
-> not necessary to write set___() or get____().

Q: But why do we usually use get/set?

Because:
-> It follows standard naming practice.
-> Makes it easier for other developers (and your future self) to understand the code.
-> Some tools and libraries (like in Java or C#) auto-detect getters and setters based on these names.

*/

#include<iostream>
#include<vector>

using namespace std;

class Chai{
    private:
        string teaName;
        int servings;
        vector<string> ingridients;

    public:
        Chai(){
            teaName = "Unknow Tea";
            servings = 0;
            ingridients = {"Water","Tea Leaves"};

        }
        
    Chai(string name, int serve, vector<string> ingr){
        teaName = name;
        servings = serve;
        ingridients = ingr;
    }

    string getTeaName(){
        return teaName;
    }

    void setTeaName(string name){
        //logic
        teaName = name;
    }

    int getServings(){
        return servings;
    }

    void setServings(int serve){
        servings = serve;
    }

    vector<string> getIngridients(){
        return ingridients;
    }

    void setIngridients(vector<string> ingr){
        ingridients = ingr;
    }

    void displayChaiDetails(){
        cout << "Tea Name : " << teaName << "\n";
        cout << "Servings : " << teaName << "\n";
        cout << "Ingridients : ";
        for(string ingridient : ingridients){
            cout << ingridient << " ";
        }
        cout << "\n";

    }
};

int main(){

    Chai chai;
    chai.setTeaName("Ginger tea");
    
}