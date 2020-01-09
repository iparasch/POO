#ifndef APARTAMENT_H
#define APARTAMENT_H
#include "Locuinta.h"
class Apartament:public Locuinta
{
private:
protected:
    short int etaj;
public:
    Apartament();
    Apartament(char *nume, float s, float d,short int e);
    Apartament(const Apartament &L2);
    ~Apartament();
    friend std::istream& operator >> (std::istream &input,Apartament &a);
    friend std::ostream& operator << (std::ostream &output,Apartament &a);
    Apartament& operator = (const Apartament &a);
    std::ostream& display(std::ostream &output);
    float cost();
};
#endif // APARTAMENT_H
