#include <iostream>
#include <vector>
using namespace std;
 int id;
//clase person
class person
{
    int id;
    int age;
    string name;
    string lastname;

public:
    person(int id,int age, string name)
    {
        this->id = id;
        this->age = age;
        this->name = name;
    }
    person(){};
    void show();
    void insertDataIntoPerson();
    string deletePerson();
    void buscarPersona();
};
vector<person> personas;
string person::deletePerson(){
   
    cout << "enter the id" << endl;
    cin >> id;
    for(person p : personas){
        if(p.id == id){
            personas.erase(personas.begin() + id);
            cout<<"person deleted"<<endl;
            return "person deleted";
        }
    }
    cout<<"persona not found"<<endl;
    return "person not found";
   
}


void person::buscarPersona(){
    cout<<"enter the id"<<endl;
    cin>>id;
    for(person p : personas){
        if(p.id == id){
            cout<<"id: "<<p.id<<endl;
            cout<<"name: "<<p.name<<endl;
            cout<<"age: "<<p.age<<endl;
            return;
        }
    }
    cout<<"person not found"<<endl;
}
//es como un arrylist en java solo que en c++ se llama vector

void person::show()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

//inserta datos en el vector/arraylist
void person::insertDataIntoPerson(){
    person p(1,10, "Juan");
    personas.insert(personas.begin(), p);
    person p2(2,20, "Pedro");
    personas.insert(personas.begin(), p2);
    person p3(3,30, "Maria");
    personas.insert(personas.begin(), p3);
}
//muestra los datos del vector/arraylist
void showPerson(){
   //for each
    for (person p : personas)
    {
        p.show();
    }
}

int main()
{
    person p;
    p.insertDataIntoPerson();
    showPerson();
    cout<<"\n";
    p.deletePerson();
    showPerson();
    cout<<"\n";
    p.deletePerson();
    showPerson();
    cout<<"\n";
    p.buscarPersona();

    return 0;
}