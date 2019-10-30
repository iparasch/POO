#include <iostream>
#include <cstring>

using namespace std;
class Nod
{

public:
    char info;
    Nod *next;
    Nod()
    {

        info = 0;
        next = NULL;
    }
    Nod(int info1,Nod *next1)
    {

        info = info1;
        next = next1;

    }
    ~Nod(){

        next = NULL;
        info = 0;

    }

};
class Stiva_de_caractere
{

    Nod *varfulStivei =NULL;
public:

    void push(char z)
    {

        if(varfulStivei == NULL)
        {

            varfulStivei = new Nod(z,NULL);
        }
        else
        {
            Nod *f = new Nod(z,varfulStivei);
            varfulStivei = f;
        }
    }
    void pop()
    {
        if(varfulStivei!=NULL)
        {
            Nod * f = varfulStivei->next;

            delete varfulStivei;
            varfulStivei = NULL;
            varfulStivei = f;


        }
    }
    char top()
    {

        if(varfulStivei!=NULL)
        {

            return varfulStivei->info;
        }
        return -1;
    }
    bool isEmpty()
    {

        if(varfulStivei==NULL)
        {
            return 1;
        }
        return 0;
    }

    friend ostream &operator<<(ostream &output,Stiva_de_caractere &p);
    friend istream &operator>>(istream &output,Stiva_de_caractere &p);
    char * inversare(char *z){
        Stiva_de_caractere *h = new Stiva_de_caractere();
        int n = strlen(z);
        char *f = new char[n+2];
        for(int i=0;i<n;i++){

            h->push(z[i]);
        }
        int i = -1;
        while(h->isEmpty()==0){

            i++;
            f[i] = h->top();
            h->pop();
        }
        f[++i] = NULL;
        return f;
    }
    Stiva_de_caractere  adaugareStiva3(Stiva_de_caractere f,Stiva_de_caractere g){
        Stiva_de_caractere z ;
        while(f.isEmpty()==0 && g.isEmpty()==0){
            if(f.top()>g.top())
                z.push(f.top());
            else
                z.push(g.top());
            g.pop();
            f.pop();

        }
        return z;
    }
};
ostream &operator<<(ostream &output,Stiva_de_caractere &p)
{

    while(p.isEmpty()==0)
    {

        output<<p.varfulStivei->info<<endl;
        p.pop();
    }
}
istream &operator>>(istream &input,Stiva_de_caractere &p)
{

    int n;
    char f;
    input >> n;
    for(int i=1; i<=n; i++)
    {

        input>>f;
        p.push(f);
    }
}
int main()
{
    Stiva_de_caractere f;
    Stiva_de_caractere g;
    Stiva_de_caractere g1;
    Stiva_de_caractere g2;
    char *v="Ana are mere";
    cout<<g2.inversare(v)<<endl;
    f.push('4');
    f.push('2');
    f.push('3');
    g.push('3');
    g.push('5');
    g.push('6');
    cout<<g.top()<<endl;
    g.pop();
    cout<<g.top()<<endl;
    cout<<endl;
    g1 = g1.adaugareStiva3(f,g);
    cout<<g1;

    return 0;
}
