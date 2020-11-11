#include <iostream>

using namespace std;

class Dog {

private:
    // Attributes (instance variables)
    string _name;
    string _breed;
    int _age;

public:
    // Behaviours
    Dog(string name, string breed, int age) // Constructor
    {
        _name = name;
        _breed = breed;
        _age = age;
    }

    string bark()
    {
        return _name + " barks: Woof!";
    }

    string eat()
    {
        return _name + " eats like this: Munch, munch, munch!";
    }

    string get_name() // Accessor
    {
        return _name;
    }

    string get_breed()
    {
        return _breed;
    }

    int get_age()
    {
        return _age;
    }

    void set_age(int age)
    {
        if (age >= 0) {
            _age = age;
        }
    }

    void print_info()
    {
        cout << "Name: " << get_name() << endl;
        cout << "Breed: " << get_breed() << endl;
        cout << "Age: " << get_age() << endl;
    }
};

int main()
{
    Dog d1 {"Snoopy", "Beagle", 70};
    Dog d2("Scooby Doo", "Great Dane", 51);
    Dog d3 {"Brian Griffin", "Labrador", 21};
    cout << d1.bark() << endl;
    cout << d1.eat() << endl;
    cout << d2.bark() << endl;
    cout << d2.eat() << endl;
    cout << d3.bark() << endl;
    cout << d3.eat() << endl;
    cout << "Combined age of all dogs: "
         << (d1.get_age() + d2.get_age() + d3.get_age())
         << endl;
    cout << endl;
    d1.set_age(-100); // Does nothing
    d1.set_age(d1.get_age() + 1); // Adds one to the current age
    d1.print_info();
    cout << endl;
    d2.print_info();
    cout << endl;
    d3.print_info();
    return 0;
}
