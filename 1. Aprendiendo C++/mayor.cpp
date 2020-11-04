#include <iostream>

using namespace std;

int main() 
{
    int mayor = 0;
    int entrada = 0;
    bool primera_vez = true;
    
    while (entrada != -1) {
        cout << "Ingresa un número entero (-1 para terminar): ";
        cin >> entrada;
        if (entrada != -1) {
            if (primera_vez) {
                primera_vez = false;
                mayor = entrada;
            } else {
                if (entrada > mayor) {
                    mayor = entrada;
                }
            }
        }
    }
    if (!primera_vez) {
        cout << "El número más grande fue: " << mayor << endl;
    }
    
    return 0;
}