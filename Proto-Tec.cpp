#include <iostream>
#include <iomanip>
/*
Task: H5
Family Name: MAHFOUZ
Given Name: KAREEM
Matriculation number: 3085597
Uni-Email: kareem.mahfouz@stud.uni-due.de
Course of Studies: ISE CE
*/
using namespace std;

class Article
{
private:
    string model;
    double TaxRate,NetPrice;
public:
    Article();
    Article(string,double,double);
    ~Article();
    void set_model(string);
    void set_NetPrice(double);
    string get_model();
    double get_NetPrice();
    double get_GrossPrice();
    virtual void Print() ;
};

Article::Article()
{
    TaxRate=0.19;
}

Article::Article(string name, double Price, double tax )
{
    model=name;
    TaxRate=tax;
    NetPrice=Price;
}

Article::~Article()
{
//    cout<<model<<endl;
}

void Article::set_model(string name)
{
    model=name;
}

void Article::set_NetPrice(double Price)
{
    NetPrice=Price;
}

string Article::get_model()
{
    return model;
}

double Article::get_NetPrice()
{
    return NetPrice;
}

double Article::get_GrossPrice()
{
    double gp = NetPrice+TaxRate;
    return gp ;
}
void Article::Print()
{

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Accessory : public Article
{
private:
    bool Original;


public:
    Accessory(string,double,bool);
    virtual ~Accessory();
    virtual void Print() ;
};

Accessory::Accessory(string name, double Price, bool Originality = true)
{
    set_model(name);
    set_NetPrice(Price);
    Original=Originality;
}
Accessory::~Accessory()
{
//   cout<<"~Accessory()"<<endl;
}
void Accessory::Print()
{
    if(Original==1)
        cout<<get_model()<<"original and accessory"<<endl;
}
enum  OperatingSystem : unsigned int {Unknown=0,Android,iOS,MacOS,Linux,Proprietary,Unix,Windows};


ostream& operator<<(ostream &out, OperatingSystem &os)
{
    switch(os)
    {
    case OperatingSystem::Unknown:
        return out << "Unknown";
        break;
    case OperatingSystem::Android:
        return out << "Android";
        break;
    case OperatingSystem::iOS:
        return out << "iOS";
        break;
    case OperatingSystem::MacOS :
        return out << "MacOS";
        break;
    case OperatingSystem::Linux :
        return out << "Linux";
        break;
    case OperatingSystem::Proprietary :
        return out << "Proprietary";
        break;
    case OperatingSystem::Unix :
        return out << "Unix";
        break;
    case OperatingSystem::Windows :
        return out << "Windows";
        break;
    default:
        return out << "Unknown";


    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Device : public Article
{
protected:
    int main_memory;
    OperatingSystem OS;
public:
    Device();
    Device(string,double,int,OperatingSystem);
    virtual ~Device();
    OperatingSystem get_os();
    virtual void Print();

};
Device::Device()
{
    OS = Unknown;
}

Device::Device(string name,double Netprice,int memorySize,OperatingSystem os)
{

    set_model(name);
    set_NetPrice(Netprice);
    main_memory=memorySize;
    OS=os;

}
Device::~Device()
{
    // cout<<"~Device()"<<endl;
}

OperatingSystem Device::get_os()
{
    return OS;
}
void Device::Print()
{
    cout<<get_model()<<", "<<"RAM "<<main_memory<<", "<<OS<<" ";
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Notebook : public Device
{
private:

    string drive;
    bool convertible;

public:
    Notebook();
    Notebook(string,double,int,string,OperatingSystem,bool);
    virtual ~Notebook();
    bool is_a_convertible();
    virtual void Print();

};
Notebook::Notebook()
{
    convertible=false;
}

Notebook::Notebook(string Name,double Nettprice,int memory,string MyDrive,OperatingSystem x,bool isConvertible)
{
    Article::set_model(Name);
    Article::set_NetPrice(Nettprice);
    drive=MyDrive;
    main_memory=memory;
    OS=x;

}
Notebook::~Notebook()
{
    // cout<<"~Notebook()";
}

bool Notebook::is_a_convertible()
{
    if(convertible=true)
        return 1;
    else if (convertible=false)
        return 0 ;

}

void Notebook::Print()
{
    Device::Print();

    if(convertible==0)
        cout<<drive<<endl;

    else if(convertible==1)
        cout<<" (convertible)"<<drive;

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Phone : public Device
{
public:
    Phone();
    Phone(string , double , int ,OperatingSystem);
    virtual ~Phone();
    virtual void Print();

};
Phone::Phone()
{
    main_memory=4;
    OS=Android;
}
Phone::Phone(string Name , double Nettprice , int memory , OperatingSystem x)
{
    Article::set_model(Name);
    Article::set_NetPrice(Nettprice);
    main_memory=memory;
    OS=x;

}

Phone::~Phone()
{
   // cout<<"~Phone()"<<endl;
}

void Phone::Print()
{
    Device::Print();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class InCart
{
private:
    Article *article;
    int Amount;
    InCart *next;
public:

    InCart(Article * ,int,InCart *);
    virtual ~InCart();
    InCart* get_next();
    virtual void Print();

};

InCart::InCart(Article *x , int y=0 , InCart *z=nullptr)
{
    article=x;
    Amount=y;
    next=z;
}
InCart::~InCart()
{
//    cout<<"~InCart()"<<Amount<<endl;
//    article->~Article();
}

InCart* InCart::get_next()
{
 return next;
}

void InCart::Print()
{

    cout<<Amount<< " ";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


class ShoppingCart
{
private:

  InCart *articles;
  double minFreeShipping;
  double SumNetPrice;
  double SumGrossPrice;


public:

    ShoppingCart();
    ~ShoppingCart();
    void set_minFreeShipping(double);
    void AddArticle(int,Article*);
    virtual void Print();

};

ShoppingCart::ShoppingCart()
{
    articles=nullptr;
    SumGrossPrice=0.0;
    SumNetPrice=0.0;
    minFreeShipping=1000;
}

ShoppingCart::~ShoppingCart()
{
//    cout<<"~ShoppingCart()"<<endl<<"Delete Article : ";
//    delete articles;
}

void ShoppingCart::set_minFreeShipping(double minimum)
{
    minFreeShipping=minimum;
}

void ShoppingCart::AddArticle(int MyAmount,Article *art)

{

        if(articles==nullptr)
        {
            InCart *MyCart=new InCart(art,MyAmount);
            articles=MyCart;

            for(int i=0;i<MyAmount;i++)
            {
                SumNetPrice+=MyAmount*(art->get_NetPrice());
            }
            SumGrossPrice=SumNetPrice + (0.19 * SumNetPrice) ;
        }
        else

        {
            InCart *MyCart=new InCart(art,MyAmount,articles);
            articles=MyCart;
             for(int i=0;i<MyAmount;i++)
            {
                SumNetPrice+=MyAmount* (art->get_NetPrice());

        ;
            }
            SumGrossPrice=SumNetPrice + ( SumNetPrice * 0.19);
        }
}
void ShoppingCart::Print()
{
cout<<"Sum net price : "<<SumNetPrice<<" EUR"<<endl;
cout<<"Tax: "<<(SumGrossPrice-SumNetPrice)<<" EUR"<<endl;
cout<<"Sum gross price : "<<SumGrossPrice<<" EUR"<<endl;
cout<<"---------"<<endl;
cout<<"Shipping: "<<minFreeShipping<<fixed<<setprecision(2)<<endl;
cout<<"---------"<<endl;
cout<<"Total: "<< (SumGrossPrice+minFreeShipping)<<endl;
}



void PrintShapes()
{
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  "<<endl;
cout<<"+                        P R O T O - T E C - S H O P                         +  "<<endl;
cout<<"+                     Y O U R   S H O P P I N G C A R T                      +  "<<endl;
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  "<<endl;
};



int main()
{

    ShoppingCart S1;
    PrintShapes();
    Accessory A1("YOOLOX 10k Wireless Powerbank Qi",31.08,false);
    InCart I1(&A1,3);
    I1.Print();
   cout<< A1.get_model();
    cout<<endl<<"   \t \t"<<A1.get_NetPrice()<<"\t"<<3*A1.get_NetPrice()<<endl;
    S1.AddArticle(3,&A1);
    S1.set_minFreeShipping(5.90000);
    cout<< endl;

    Phone P1("Apple iPhone 11 Pro 265 ",1305.99,4,iOS);
    InCart I2(&P1,2);
    I2.Print();
    P1.Print();
    cout<<endl<<"   \t \t"<<P1.get_NetPrice()<<"\t "<<2*P1.get_NetPrice()<<endl<<endl;
    S1.AddArticle(2,&P1);

    Phone P2("Samsung Galaxy S10+ SM-G975F/DS Dual SIM",787.39,8,Android);
    InCart I3(&P2,1);
    I3.Print();
    P2.Print();
    cout<<endl<<"   \t \t"<<P2.get_NetPrice()<<"\t "<<1*P2.get_NetPrice()<<endl;
    S1.AddArticle(2,&P2);

    Notebook N1("ASUS ROG Strix Scar III G731",1887.99,16,"512 GB SSD + 1TB SSHD",Windows,0);
    InCart I4(&N1,1);
    I4.Print();
    N1.Print();
    cout<<endl<<"   \t \t"<<N1.get_NetPrice()<<"\t "<<1*N1.get_NetPrice()<<endl;
    S1.Print();






//    Phone P1("Samsung A70",2000,64,Android);
//    P1.Print();


    return 0;
}
