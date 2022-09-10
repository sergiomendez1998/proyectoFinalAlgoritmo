#include <iostream>
#include <vector>
using namespace std;


class person
{
    int age;
    string name;

public:
    person(int age, string name)
    {
        this->age = age;
        this->name = name;
    }
    person(){};
    void show();
    void insertDatintoPerson();
};
vector<person> personas;
void person::show()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

void person::insertDatintoPerson(){
    person p(20, "Juan");
    personas.insert(personas.begin(), p);
    person p2(30, "Pedro");
    personas.insert(personas.begin(), p2);
   
}

void showPerson(){
    for (int i = 0; i < personas.size(); i++)
    {
        personas[i].show();
    }
}

int main()
{
    person p;
    p.insertDatintoPerson();
    showPerson();
    return 0;
}