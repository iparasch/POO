#include "Gestiune.h"
#include<fstream>
int main()
{
    std::ifstream f("date.in");
    f>>Locuinta::pret>>Casa::pret_curte;
    Gestiune<Locuinta*> l;
    Apartament a;
    Casa c1,c2;
    f>>c1>>a>>c2;
    ((l+=&c1)+=&a)+=&c2;
    std::cout<<l;
    return 0;
}
