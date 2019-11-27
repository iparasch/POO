#include <iostream>
#include <cstring>
#include "Coada.h"
using namespace std;

int main()
{
    TipuriDeCozi t;
    int n;
    cout << "Numarul de cozi: ";
    cin >> n;
    t.ReadCozi(n);
    t.AfisareCozi(n);

    return 0;
}
