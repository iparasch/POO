#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED
#include <cstring>
#include <vector>
using namespace std;
class Nod
{
public:
    string info;
    Nod* next;
    Nod();
    ~Nod();
    Nod(string info_)
    {
        info = info_;
        next = NULL;
    }
};
class Coada
{
protected:
    Nod* prim;
    Nod* ultim;
    int dim_max;
    int dim;
public:
    Coada();
    ~Coada();
    virtual void insertEnd(string a)
    {
        Nod* new_node = new Nod(a);
        if(prim == NULL)
        {
            prim = new_node;
            ultim = new_node;
        }
        else
        {
            ultim->next = new_node;
            ultim = new_node;
        }
        dim++;
    }
    virtual void insertFront(string a)
    {
    }
    virtual void deleteFront()
    {
        if(prim == NULL)
        {
            return;
        }
        Nod* p = prim;
        prim = prim->next;
        delete p;
        dim--;

    }
    virtual void deleteEnd()
    {
    }
    virtual string getFront()
    {

        if(prim == NULL)
        {
            return "";
        }
        else
        {
            return prim->info;
        }

    }
    virtual string getRear()
    {
        return "";
    }
    virtual bool isEmpty() const
    {

        if(prim == NULL)
        {
            return true;
        }
        return false;

    }
    virtual bool isFull() const
    {
        return "";
    }
    virtual void Read()
    {
        int n;
        cout << "Numarul de elemente pe care vrem sa le adaugam in coada este: ";
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            string new_string;
            cin >> new_string;
            Nod* new_node = new Nod(new_string);
            if(prim == NULL)
            {
                prim = new_node;
                ultim = new_node;
            }
            else
            {
                ultim->next = new_node;
                ultim = new_node;
            }
            dim++;
        }
        dim += n;
    }
    virtual void Print() {

        Nod* p = prim;
        while(p)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;

    }
    friend istream& operator >> (istream&, Coada&);
    friend ostream& operator << (ostream&, Coada&);
};
class DEQUE : public Coada
{
public:
    void insertEnd(string a)
    {
        Nod* new_node = new Nod(a);
        if(prim == NULL)
        {
            prim = new_node;
            ultim = new_node;
        }
        else
        {
            ultim->next = new_node;
            ultim = new_node;
        }
        dim++;
    }
    void insertFront(string a)
    {
        Nod* new_node = new Nod(a);
        if(prim == NULL)
        {
            prim = new_node;
            ultim = new_node;
        }
        else
        {
            new_node->next = prim;
            prim = new_node;

        }
        dim++;

    }
    void deleteFront()
    {
        if(prim == NULL)
        {
            return;
        }
        Nod* p = prim;
        prim = prim->next;
        delete p;

    }
    void deleteEnd()
    {
        if(prim == NULL)
        {
            return;
        }
        Nod* p = prim;
        prim = prim->next;
        delete p;

    }
    bool isEmpty() const
    {

        if(prim == NULL)
        {
            return true;
        }
        return false;

    }
    bool isFull() const
    {
        if(dim == dim_max)
        {
            return true;
        }
        return false;
    }
    string getFront()
    {

        if(prim == NULL)
        {
            return "";
        }
        else
        {
            return prim->info;
        }

    }
    string getRear()
    {

        if(prim == NULL)
        {
            return "";
        }
        return ultim->info;

    }
    void Read()
    {
        int n;
        cout << "Dimensiunea maxima pe care poate sa o aiba coada\n";
        cin >> dim_max;
        cout << "Numarul de elemente pe care vrem sa le adaugam in coada este: ";
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            string new_string;
            cout << "sir nou = ";
            cin >> new_string;
            cout << "1 - insertFront\n";
            cout << "2 - insertEnd\n";
            int op;
            cin >> op;
            switch(op)
            {
            case 1:
            {
                Nod* new_node = new Nod(new_string);
                if(prim == NULL)
                {
                    prim = new_node;
                    ultim = new_node;
                }
                else
                {
                    new_node->next = prim;
                    prim = new_node;

                }
                dim++;
                break;
            }
            case 2:
            {
                Nod* new_node = new Nod(new_string);
                if(prim == NULL)
                {
                    prim = new_node;
                    ultim = new_node;
                }
                else
                {
                    ultim->next = new_node;
                    ultim = new_node;
                }
                dim++;
                break;
            }

            }
        }

    }
    void Print() {

        Nod* p = prim;
        while(p)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;

    }
    friend istream& operator >> (istream&, Coada&);
    friend ostream& operator << (ostream&, Coada&);
};
class TipuriDeCozi
{

private:
    vector <Coada*> cozi;
    int nrCozi;
public:
    void ReadCozi(int);
    void AfisareCozi(int);
};


#endif // COADA_H_INCLUDED
