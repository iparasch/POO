#include <iostream>
#include <cstring>
#include <vector>
#include "Coada.h"
using namespace std;
Nod::Nod()
{
    info = "";
    next = NULL;

}
Nod::~Nod()
{


}
Coada::Coada()
{

    prim = NULL;
    ultim = NULL;
    dim_max = 0;
    dim = 0;

}
Coada::~Coada()
{
    cout << "Coada a fost stearsa\n";
    Nod* p = prim;
    while(prim != NULL)
    {
        prim = prim->next;
        delete p;
        p = prim;
    }

}
istream& operator >> (istream& in, Coada& c)
{

    c.Read();
    return in;

}
ostream& operator << (ostream& out, Coada& c)
{
    c.Print();
    return out;
}

void TipuriDeCozi::ReadCozi(int n) {

    for(int i = 0; i < n; i++) {
        int op;
        cout << "1 - coada\n";
        cout << "2 - deque\n";
        cin >> op;
        switch(op) {

            case 1: {
                cozi.push_back(new Coada());
                cin >> (*cozi[i]);
                break;
            }
            case 2: {
                cozi.push_back(new DEQUE());
                cin >> (*cozi[i]);
                break;
            }
        }

    }
    nrCozi += n;


}
void TipuriDeCozi::AfisareCozi(int n) {


    for(int i = 0; i < n; i++) {

        cout << (*cozi[i]);

    }



}
