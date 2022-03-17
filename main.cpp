#include <iostream>
#include <cstring>
using namespace std;
class persoana
{
    string nume;
    int varsta;
public:
    persoana(string n="", int v=0)
    {
        nume=n;
        varsta=v;
    }
    void setnume2(string n)
    {
        nume=n;
    }
    void setpersoana(string n, int v)
    {
        nume=n;
        varsta=v;
    }
    string getnume2()
    {
        return nume;
    }
    int getvarsta()
    {
        return varsta;
    }
    friend ostream& operator<<(ostream&, persoana&);
    friend istream &operator>>(istream&, persoana&);
    persoana(const persoana&);
    persoana &operator=(persoana &);
    ~persoana();

};
persoana::persoana(const persoana&p)
{
    this->nume=p.nume;
    this->varsta=p.varsta;
}
persoana& persoana::operator=(persoana &p)
{
    if(this!=&p)
    {
        this->nume=p.nume;
    this->varsta=p.varsta;
    }
    return *this;
}
ostream& operator<<(ostream& out, persoana& p)
{
    out<<"nume "<<p.nume<<", "<<"varsta "<<p.varsta<<" ";
}
istream &operator>>(istream&in, persoana&p)
{
    char n[255];
    in.ignore();
    cout<<"Nume: ";
    in>>p.nume;
    in.get();
    cout<<"Varsta: ";
    in>>p.varsta;
    cout<<endl;
    return in;
}
class carte
{
    char *nume, *autor;
    persoana autor2;
    int pret,nrpag;
    float rating;
    bool citita;
public:
    carte(char *n="", char *a="", int p=0,int np=0,float r=0.0, bool ci=false)
    {
        nume=new char[strlen(n)+1];
        strcpy(nume,n);
        autor=new char[strlen(a)+1];
        strcpy(autor,a);
        persoana autor2;
        pret=p;
        nrpag=np;
        rating=r;
        citita=ci;
    }
    friend istream& operator>>(istream&,carte&);
    friend ostream& operator<<(ostream&, carte&);
    carte &operator=(carte &);
    friend bool operator< (const carte &, const carte&);
    friend bool operator> (const carte &, const carte&);
    friend bool operator== (const carte &, const carte&);
    char* getnume()
    {
        return nume;
    }
    void setpret(int p)
    {
        pret=p;
    }
    void setcitita(bool ci)
    {
        citita=ci;
    }
    bool getcitita()
    {
        return citita;
    }
    ~carte();
};
carte::~carte()
{
    delete nume;
    delete autor;
}
persoana::~persoana(){}
istream &operator>>(istream&in, carte&c)
{
    char n[255],a[255],n2[255];
    in.ignore();
    cout<<"Nume carte: ";
    in.get(n,255);
    cout<<endl;
    c.nume=new char[strlen(n)+1];
    strcpy(c.nume,n);
    in.get();
    cout<<"Nume autor: ";
    in.get(a,255);
    cout<<endl;
    c.autor=new char[strlen(a)+1];
    strcpy(c.autor,a);
    in.get();
    cout<<"Pret carte: ";
    in>>c.pret;
    cout<<endl;
    in.get();
    cout<<"Numar de pagini: ";
    in>>c.nrpag;
    cout<<endl;
    in.get();
    cout<<"Rating carte: ";
    in>>c.rating;
    cout<<endl;
    cout<<"E deja citita? Apasati tasta 1 daca da si 0 daca nu. ";
    in>>c.citita;
    cout<<"Date autor secundar:"<<endl;
    in>>c.autor2;
    return in;
}
ostream& operator<<(ostream& out, carte& c)
{
    out<<"Nume carte: "<<c.nume<<"; "<<"Nume autor principal: "<<c.autor<<"; "<<"Pret carte: "<<c.pret<<"RON; "<<"Numar pagini: "<<c.nrpag<<"; "<<"Rating: "<<c.rating<<"; ";
    out<<"Autor2:"<<c.autor2;
    if(c.citita)
    {
        cout<<" Cartea e citita.";
    }
    else{
        cout<<" Cartea nu e citita.";
    }
    cout<<endl;
}
carte& carte::operator=(carte &c)
{
    if(this!=&c)
    {
        delete[] this->nume;
        delete[] this->autor;
        this->nume=new char[strlen(c.nume)+1];
        strcpy(this->nume,c.nume);
        this->autor=new char[strlen(c.autor)+1];
        strcpy(this->autor,c.autor);
        this->pret=c.pret;
        this->autor2=c.autor2;
        this->nrpag=c.nrpag;
        this->rating=c.rating;
        this->citita=c.citita;
    }
    return *this;
}

bool operator< (const carte &c1, const carte &c2)
 {return c1.rating<c2.rating;
}
bool operator> (const carte &c1, const carte &c2)
 {return c1.rating>c2.rating;
}
bool operator== (const carte &c1, const carte &c2)
 {return c1.rating==c2.rating;
}
int main()
{
    int n,i,vv,N;
    carte *v;
    carte *temp;
    char* var;
    persoana sef;
    persoana *cititori;
    cout<<"Biblioteca personala!"<<endl;
    cout<<"1.Initializare Biblioteca."<<endl;
    cout<<"2.Adaugare carte noua la colectie."<<endl;
    cout<<"3.Afisare titluri carti."<<endl;
    cout<<"4.Afisare detalii carti."<<endl;
    cout<<"5.Schimbare carte"<<endl;
    cout<<"6.Afisare carti citite."<<endl;
    cout<<"7.Marcati o carte drept 'citita'."<<endl;
    cout<<"8.Comparati doua carti."<<endl;
    cout<<"9.Modificati pretul unei carti."<<endl;
    cout<<"10.Adaugati informatii detinator biblioteca."<<endl;
    cout<<"11.Initializati detinatorul drept cititor."<<endl;
    cout<<"12.Meniu."<<endl;
    cout<<"0.Iesire din biblioteca"<<endl;
    cout<<"Alegeti o actiune."<<endl;
    int alegere;
    cin>>alegere;
    while(alegere!=0)
    {
        if(alegere>12)
        {
            cout<<"Alegerea nu exista. Introduceti un alt numar.";
        }
        else
        {
            if(alegere==1)
            {
                cout<<"Introduceti numarul de carti din biblioteca dumneavoastra: ";
                cin>>n;
                v=new carte[n];
                for( i=0;i<n;i++)
                {
                    carte c;
                    cout<<"Introduceti informatiile cartii "<<i+1<<endl;
                    cin>>c;
                    v[i]=c;
                }
            }
            if(alegere==2)
            {
                temp=new carte[n];
                for (i=0;i<n;i++)
                {
                    temp[i] = v[i];
                }
                v= new carte[n+1];
                for (i=0;i<n; i++)
                {
                    v[i] = temp[i];
                }
                cin>>v[n];
                n++;
                delete[]temp;
            }
            if(alegere==3)
            {
                cout<<"Biblioteca contine:"<<endl;
                for( i=0;i<n;i++)
                {
                    cout<<i+1<<".";
                    cout<<v[i].getnume()<<endl;
                }
            }
            if(alegere==4)
            {
                cout<<"Biblioteca contine:"<<endl;
                for( i=0;i<n;i++)
                {
                    cout<<i+1<<".";
                    cout<<v[i];
                }
            }
            if(alegere==5)
            {
                cout<<"Numar carte de inlocuit: ";
                int x;
                cin>>x;
                cout<<"Cartea inlocuita: "<<v[x-1];
                carte inlocuitor;
                cin>>inlocuitor;
                v[x-1]=inlocuitor;
            }
            if(alegere==6)
            {
                int ok;
                ok=0;
                for(i=0;i<n;i++)
                {
                    if(v[i].getcitita()==1)
                    {
                        cout<<i+1<<".";
                        cout<<v[i];
                        ok=1;
                    }
                }
                if(ok==0)
                {
                    cout<<"Nu exista carti citite";
                }
            }
            if(alegere==7)
            {
                cout<<"Numarul cartii de marcat drept citita: ";
                cin>>vv;
                v[vv-1].setcitita(1);
            }
            if(alegere==8)
            {
                cout<<"Ce carti comparam?"<<endl;
                int z,c1,c2;
                cin>>c1>>c2;
                z=v[c1-1]<v[c2-1];
                if(z)
                {
                    cout<<"ratingul cartii "<<c1<<" este mai mic decat cel al cartii "<<c2<<endl;
                }
                z=v[c1-1]>v[c2-1];
                if(z)
                {
                    cout<<"ratingul cartii "<<c1<<" este mai mare decat cel al cartii "<<c2<<endl;
                }
                z=v[c1-1]==v[c2-1];
                if(z)
                {
                    cout<<"ratingul cartii "<<c1<<" este la fel ca si cel al cartii "<<c2<<endl;
                }
            }
            if(alegere==9)
            {
                cout<<"Numarul cartii al carei pret il inlocuim: ";
                int x;
                cin>>x;
                cout<<"Introduceti noul pret:";
                int nou;
                cin>>nou;
                v[x-1].setpret(nou);
            }
            if(alegere==10)
            {
                cin>>sef;
            }
            if(alegere==11)
            {
                persoana cititor(sef);
                cout<<cititor<<endl;
            }
            if(alegere==12)
            {
                cout<<"Biblioteca personala!"<<endl;
                cout<<"1.Initializare Biblioteca."<<endl;
                cout<<"2.Adaugare carte noua la colectie."<<endl;
                cout<<"3.Afisare titluri carti."<<endl;
                cout<<"4.Afisare detalii carti."<<endl;
                cout<<"5.Schimbare carte"<<endl;
                cout<<"6.Afisare carti citite."<<endl;
                cout<<"7.Marcati o carte drept 'citita'."<<endl;
                cout<<"8.Comparati doua carti."<<endl;
                cout<<"9.Modificati pretul unei carti."<<endl;
                cout<<"0.Iesire din biblioteca"<<endl;
            }
        }
        cout<<"O noua actiune:";
        cin>>alegere;
    }
    delete[]v;
}
