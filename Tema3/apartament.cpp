#include "Apartament.h"
Apartament::Apartament(): Locuinta()
{
    etaj=0;
}
Apartament::Apartament(char *nume, float s, float d, short int e): Locuinta(nume,s,d)
{
    etaj=e;
}
Apartament::Apartament(const Apartament &L2): Locuinta(L2)
{
    etaj=L2.etaj;
}
Apartament::~Apartament()
{
    delete[] nume_client;
}
std::istream& operator >> (std::istream &input,Apartament &a)
{
    char nume[100];
    float s,d;
    short int e;
    input>>nume>>s>>d>>e;
    a.nume_client=new char[strlen(nume)+1];
    strcpy(a.nume_client,nume);
    a.suprafata_utila=s;
    a.discount=d;
    a.etaj=e;
    return input;
}
std::ostream& Apartament::display(std::ostream &output)
{
    if(nume_client==NULL)
        return output;
    output<<"Apartament:\n\tNume client: "<<nume_client<<"\n\tSuprafata utila: "<<suprafata_utila<<"\n\tDiscount: "<<discount<<"\n\tEtaj: "<<etaj<<"\n";
    return output;
}
std::ostream& operator << (std::ostream &output,Apartament &a)
{
    return a.display(output);
}
Apartament& Apartament::operator = (const Apartament &L2)
{
    if(&L2==this)
        return *this;
    if(nume_client!=NULL)
        delete[] nume_client;
    nume_client=new char[strlen(L2.nume_client)+1];
    strcpy(nume_client,L2.nume_client);
    suprafata_utila=L2.suprafata_utila;
    discount=L2.discount;
    etaj=L2.etaj;
    return *this;
}
float Apartament::cost()
{
    return suprafata_utila*pret*(100-discount)/100;
}
