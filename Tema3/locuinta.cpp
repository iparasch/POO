#include "Locuinta.h"
float Locuinta::pret;
Locuinta::Locuinta()
{
    nume_client=NULL;
    suprafata_utila=discount=0;
}
Locuinta::Locuinta(char *nume, float s, float d)
{
    nume_client=new char[strlen(nume)+1];
    strcpy(nume_client,nume);
    suprafata_utila=s;
    discount=d;
}
Locuinta::Locuinta(const Locuinta &L2)
{
    nume_client=new char[strlen(L2.nume_client)+1];
    strcpy(nume_client,L2.nume_client);
    suprafata_utila=L2.suprafata_utila;
    discount=L2.discount;
}
Locuinta::~Locuinta()
{
    delete[] nume_client;
}
std::istream& operator >> (std::istream &input,Locuinta &a)
{
    char nume[100];
    float s,d;
    input>>nume>>s>>d;
    a.nume_client=new char[strlen(nume)+1];
    strcpy(a.nume_client,nume);
    a.suprafata_utila=s;
    a.discount=d;
    return input;
}
std::ostream& Locuinta::display(std::ostream &output)
{
    if(nume_client==NULL)
        return output;
    output<<"Locuinta:\n\tNume client: "<<nume_client<<"\n\tSuprafata utila: "<<suprafata_utila<<"\n\tDiscount: "<<discount<<"\n";
    return output;
}
std::ostream& operator << (std::ostream &output,Locuinta &a)
{
    return a.display(output);
}
Locuinta& Locuinta::operator = (const Locuinta &L2)
{
    if(&L2==this)
        return *this;
    if(nume_client!=NULL)
        delete[] nume_client;
    nume_client=new char[strlen(L2.nume_client)+1];
    strcpy(nume_client,L2.nume_client);
    suprafata_utila=L2.suprafata_utila;
    discount=L2.discount;
}
