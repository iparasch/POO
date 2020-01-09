#ifndef LOCUINTA_H
#define LOCUINTA_H
#include<iostream>
#include<string.h>
class Locuinta
{
private:
protected:
    char *nume_client;
    float suprafata_utila,discount;
public:
    Locuinta();
    Locuinta(char *nume, float s, float d);
    Locuinta(const Locuinta &L2);
    ~Locuinta();
    friend std::istream& operator >> (std::istream &input,Locuinta &a);
    friend std::ostream& operator << (std::ostream &output,Locuinta &a);
    Locuinta& operator = (const Locuinta &a);
    virtual std::ostream& display(std::ostream &output);
    static float pret;
    virtual float cost()=0;
};
#endif // LOCUINTA_H
