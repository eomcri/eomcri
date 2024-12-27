#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void makeSound(){
        cout << "Animal speaks" << endl;
    };
};

class Dog : public Animal{
    public:
    void makeSound(){
        cout << "meong~" << endl;
    }
};
class Cat : public Animal{
    public:
    void makeSound(){
        cout << "nyang~" << endl;
    }
};
class Cow : public Animal{
    public:
    void makeSound(){
        cout << "ummeo~" << endl;
    }
};

int main(){
    Animal* animal[3];
    Dog dog;
    Cat cat;
    Cow cow;
    animal[0] = &dog;
    animal[1] = &cat;
    animal[2] = &cow;

    for(int i=0; i<3; i++)
        animal[i]->makeSound();

}
