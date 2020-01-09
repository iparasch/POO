#include "Casa.h"
float Casa::pret_curte;
Casa::Casa(): Locuinta()
{
    curte=etaje=0;
    supr_pe_etaj=NULL;
}
Casa::Casa(char *nume, float s, float d,float c, short int e, float *s_e): Locuinta(nume,s,d)
{
    curte=c;
    etaje=e;
    supr_pe_etaj=new float[etaje];
    for(e=0; e<etaje; e++)
        supr_pe_etaj[e]=s_e[e];
}
Casa::Casa(const Casa &L2): Locuinta(L2)
{
    curte=L2.curte;
    etaje=L2.etaje;
    supr_pe_etaj=new float[etaje];
    for(int i=0; i<etaje; i++)
        supr_pe_etaj[i]=L2.supr_pe_etaj[i];
}
Casa::~Casa()
{
    delete[] nume_client;
    delete[] supr_pe_etaj;
}
std::istream& operator >> (std::istream &input,Casa &a)
{
    char nume[100];
    float s,d,c;
    short int e;
    input>>nume>>s>>d>>c>>e;
    a.nume_client=new char[strlen(nume)+1];
    strcpy(a.nume_client,nume);
    a.suprafata_utila=s;
    a.discount=d;
    a.curte=c;
    a.etaje=e;
    a.supr_pe_etaj=new float[e];
    for(e=0; e<a.etaje; e++)
        input>>a.supr_pe_etaj[e];
    return input;
}
std::ostream& Casa::display(std::ostream &output)
{
    if(nume_client==NULL)
        return output;
    output<<"Casa:\n\tNume client: "<<nume_client<<"\n\tSuprafata utila: "<<suprafata_utila<<"\n\tDiscount: "<<discount<<"\n\tSuprafata curte: "<<curte<<"\n\tEtaje: "<<etaje<<"\n\tSuprafata/etaj (in ordine): "<<supr_pe_etaj[0];
    for(int i=1; i<etaje; i++)
        output<<", "<<supr_pe_etaj[i];
    output<<"\n";
    return output;
}
std::ostream& operator << (std::ostream &output,Casa &a)
{
    return a.display(output);
}
Casa& Casa::operator = (const Casa &L2)
{
    if(&L2==this)
        return *this;
    *(Locuinta*)this=*(Locuinta*)&L2;
    curte=L2.curte;
    etaje=L2.etaje;
    if(supr_pe_etaj!=NULL)
        delete[] supr_pe_etaj;
    supr_pe_etaj=new float[etaje];
    for(int i=0; i<etaje; i++)
        supr_pe_etaj[i]=L2.supr_pe_etaj[i];
    return *this;
}
float Casa::cost()
{
    return suprafata_utila*pret*(100-discount)/100+curte*pret_curte;
}
