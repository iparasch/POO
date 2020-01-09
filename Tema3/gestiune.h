#ifndef GESTIUNE_H
#define GESTIUNE_H
#include"Apartament.h"
#include"Casa.h"
#include<vector>
template <class T>
class Gestiune{
private:
protected:
    std::vector<T> lista;
public:
    Gestiune();
    Gestiune(T *l, int n);
    Gestiune(const Gestiune<T> &a);
    ~Gestiune();
    template <class Q>
    friend std::istream& operator >> (std::istream &input,Gestiune<Q> &a);
    template <class Q>
    friend std::ostream& operator << (std::ostream &output,Gestiune<Q> &a);
    Gestiune<T>& operator = (const Gestiune<T> &a);
    std::ostream& display(std::ostream &output);
    Gestiune<T>& operator += (const T &a);
};
template <>
class Gestiune<char*>{
private:
protected:
    std::vector<char*> lista;
public:
    Gestiune();
    Gestiune(char **l, int n);
    Gestiune(const Gestiune<char*> &a);
    ~Gestiune();
    friend std::istream& operator >> (std::istream &input,Gestiune<char*> &a);
    friend std::ostream& operator << (std::ostream &output,Gestiune<char*> &a);
    Gestiune<char*>& operator = (const Gestiune<char*> &a);
    std::ostream& display(std::ostream &output);
    Gestiune<char*>& operator += (const char* a);
};
template <>
class Gestiune<Locuinta*>{
private:
protected:
    std::vector<Locuinta*> lista;
public:
    Gestiune();
    Gestiune(Locuinta **l, int n);
    Gestiune(const Gestiune<Locuinta*> &a);
    ~Gestiune();
    friend std::istream& operator >> (std::istream &input,Gestiune<Locuinta*> &a);
    friend std::ostream& operator << (std::ostream &output,Gestiune<Locuinta*> &a);
    Gestiune<Locuinta*>& operator = (const Gestiune<Locuinta*> &a);
    std::ostream& display(std::ostream &output);
    Gestiune<Locuinta*>& operator += (Locuinta* a);
};
template<class T>
Gestiune<T>::Gestiune()
{
    lista.clear();
}
template<class T>
Gestiune<T>::Gestiune(T *l, int n)
{
    for(int i=0;i<n;i++)
        lista.push_back(l[i]);
}
template<class T>
Gestiune<T>::Gestiune(const Gestiune<T> &a)
{
    lista=a.lista;
}
template<class T>
Gestiune<T>::~Gestiune()
{
    lista.clear();
}
template<class T>
std::istream& operator >> (std::istream &input,Gestiune<T> &a)
{
    T x;
    int n;
    input>>n;
    for(int i=0;i<n;i++)
    {
        input>>x;
        a.lista.push_back(x);
    }
    return input;
}
template<class T>
std::ostream& operator << (std::ostream &output,Gestiune<T> &a)
{
    return a.display(output);
}
template<class T>
Gestiune<T>& Gestiune<T>::operator = (const Gestiune<T> &a)
{
    if(&a==this)
        return *this;
    lista.clear();
    lista=a.lista;
}
template<class T>
std::ostream& Gestiune<T>::display(std::ostream &output)
{
    for(T i:lista)
        output<<i<<"\n";
    return output;
}
template<class T>
Gestiune<T>& Gestiune<T>::operator += (const T &a)
{
    lista.push_back(a);
    return *this;
}
//char* specialization
Gestiune<char*>::Gestiune()
{
    lista.clear();
}
Gestiune<char*>::Gestiune(char **l, int n)
{
    for(int i=0;i<n;i++)
    {
        char* aux=new char[strlen(l[i]+1)];
        strcpy(aux,l[i]);
        lista.push_back(aux);
    }
}
Gestiune<char*>::Gestiune(const Gestiune<char*> &a)
{
    for(char* i:a.lista)
    {
        char* aux=new char[strlen(i)+1];
        strcpy(aux,i);
        lista.push_back(aux);
    }
}
Gestiune<char*>::~Gestiune()
{
    for(char* i:lista)
        delete[] i;
    lista.clear();
}
std::istream& operator >> (std::istream &input,Gestiune<char*> &a)
{
    int n;
    char s[100];
    input>>n;
    for(int i=0;i<n;i++)
    {
        input>>s;
        char *aux=new char[strlen(s)+1];
        strcpy(aux,s);
        a.lista.push_back(aux);
    }
    return input;
}
std::ostream& operator << (std::ostream &output,Gestiune<char*> &a)
{
    return a.display(output);
}
Gestiune<char*>& Gestiune<char*>::operator = (const Gestiune<char*> &a)
{
    if(&a==this)
        return *this;
    for(char* i:a.lista)
        delete[] i;
    lista.clear();
    for(char* i:a.lista)
    {
        char* aux=new char[strlen(i)+1];
        strcpy(aux,i);
        lista.push_back(aux);
    }
}
std::ostream& Gestiune<char*>::display(std::ostream &output)
{
    for(char* i:lista)
        output<<i<<"\n";
    return output;
}
Gestiune<char*>& Gestiune<char*>::operator += (const char* a)
{
    char *aux=new char[strlen(a)+1];
    strcpy(aux,a);
    lista.push_back(aux);
    return *this;
}
//Locuinta* specialization
Gestiune<Locuinta*>::Gestiune()
{
    lista.clear();
}
Gestiune<Locuinta*>::Gestiune(Locuinta **l, int n)
{
    for(int i=0;i<n;i++)
    {
        Apartament *aux1=dynamic_cast<Apartament*> (l[i]);
        if(aux1==NULL)
        {
            Casa *aux2=dynamic_cast<Casa*> (l[i]);
            Casa *aux=new Casa;
            *aux=*aux2;
            lista.push_back(aux);
        }
        else
        {
            Apartament *aux=new Apartament;
            *aux=*aux1;
            lista.push_back(aux);
        }
    }
}
Gestiune<Locuinta*>::Gestiune(const Gestiune<Locuinta*> &a)
{
    for(Locuinta* i:a.lista)
    {
        Apartament *aux1=dynamic_cast<Apartament*> (i);
        if(aux1==NULL)
        {
            Casa *aux2=dynamic_cast<Casa*> (i);
            Casa *aux=new Casa;
            *aux=*aux2;
            lista.push_back(aux);
        }
        else
        {
            Apartament *aux=new Apartament;
            *aux=*aux1;
            lista.push_back(aux);
        }
    }
}
Gestiune<Locuinta*>::~Gestiune()
{
    for(Locuinta* i:lista)
        delete i;
    lista.clear();
}
std::istream& operator >> (std::istream &input,Gestiune<Locuinta*> &a)
{
    int n;
    Locuinta *aux;
    input>>n;
    for(int i=0;i<n;i++)
    {
        char c;
        input>>c;
        if(c=='A')
        {
            Apartament *auxs=new Apartament;
            input>>*auxs;
            aux=auxs;
        }
        else
        {
            Casa *auxs=new Casa;
            input>>*auxs;
            aux=auxs;
        }
        a.lista.push_back(aux);
    }
    return input;
}
std::ostream& operator << (std::ostream &output,Gestiune<Locuinta*> &a)
{
    return a.display(output);
}
Gestiune<Locuinta*>& Gestiune<Locuinta*>::operator = (const Gestiune<Locuinta*> &a)
{
    if(&a==this)
        return *this;
    for(Locuinta* i:lista)
        delete i;
    lista.clear();
    for(Locuinta* i:a.lista)
    {
        Apartament *aux1=dynamic_cast<Apartament*> (i);
        if(aux1==NULL)
        {
            Casa *aux2=dynamic_cast<Casa*> (i);
            Casa *aux=new Casa;
            *aux=*aux2;
            lista.push_back(aux);
        }
        else
        {
            Apartament *aux=new Apartament;
            *aux=*aux1;
            lista.push_back(aux);
        }
    }
    return *this;
}
std::ostream& Gestiune<Locuinta*>::display(std::ostream &output)
{
    for(Locuinta* i:lista)
        output<<*i<<"\n";
    return output;
}
Gestiune<Locuinta*>& Gestiune<Locuinta*>::operator += (Locuinta* a)
{
    Apartament *aux1=dynamic_cast<Apartament*> (a);
    if(aux1==NULL)
    {
        Casa *aux2=dynamic_cast<Casa*> (a);
        Casa *aux=new Casa;
        *aux=*aux2;
        lista.push_back(aux);
    }
    else
    {
        Apartament *aux=new Apartament;
        *aux=*aux1;
        lista.push_back(aux);
    }
    return *this;
}
#endif // GESTIUNE_H
