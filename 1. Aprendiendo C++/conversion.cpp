#include <iostream>

using namespace std;

int main()
{
    double fahrenheit = 0.0;
    cout << "Favor de ingresar temperatura en grados Fahrenheit: ";
    cin >> fahrenheit;
    double celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
    cout << fahrenheit << " ºF es igual a " << celsius << " ºC." << endl;
    return 0;
}