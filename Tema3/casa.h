#ifndef CASA_H
#define CASA_H
#include "Locuinta.h"
class Casa:public Locuinta
{
private:
protected:
    float curte,*supr_pe_etaj;
    short int etaje;
public:
    Casa();
    Casa(char *nume, float s, float d,float c, short int e, float *s_e);
    Casa(const Casa &L2);
    ~Casa();
    friend std::istream& operator >> (std::istream &input,Casa &a);
    friend std::ostream& operator << (std::ostream &output,Casa &a);
    Casa& operator = (const Casa &a);
    std::ostream& display(std::ostream &output);
    static float pret_curte;
    float cost();
};
#endif // CASA_H
