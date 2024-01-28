// SuperMarket Billing System Program in C++.
// It give the administration and buyer rooms to choose among the available options.

#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
    private:
        int pcode;  // price code
        float price;
        float disc; // discount
        string pname; // product name

        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void remv();  // remove
            void recpt(); // receipt
            void list();

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;  // password

    cout <<"\t\t\t\t**********************************************\n";
    cout <<"\t\t\t\t                                              \n";
    cout <<"\t\t\t\t                Welcome To Main Menu          \n";
    cout <<"\t\t\t\t                                              \n";
    cout <<"\t\t\t\t**********************************************\n";
    cout <<"\t\t\t\t                                              \n";
    cout <<"\t\t\t\t    (1) Administrator       \n";
    cout <<"\t\t\t\t    (2) Buyer               \n";
    cout <<"\t\t\t\t    (3) Exit                \n";
    cout <<"\t\t\t\t Please Select Your Option:  ";
    cin >>choice;

    switch(choice)
    {
        case 1:
            {
                cout <<"\t\t\t Please Login        \n";
                cout <<"\t\t\t Enter you email:      ";
                cin  >>email;
                cout <<"\t\t\t Enter your password:  ";
                cin  >> password;

                if(email=="mhdk@mail.com"  && password=="123456")
                {
                    administrator();
                }
                else
                {
                    cout <<"Invalid email/password";
                }
                break;
            }

        case 2:
            {
                buyer();
            }
        case 3:
            {
                exit(0);
            }

        default:
            {
                cout <<"Please select from the given options listed: ";
            }

    }
goto m;
}

void shopping :: administrator()
{
    m:
    int choice;
    cout <<"\n\n\n\t\t\t*****************Administrator menu*******************  ";
    cout <<"\n\t\t\t  1. Add the product    ";
    cout <<"\n\t\t\t  2. Modify the product ";
    cout <<"\n\t\t\t  3. Delete the product ";
    cout <<"\n\t\t\t  4. Back to main menu  ";

    cout <<"\n\n\t  Please enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            add();
            break;

        case 2:
            edit();
            break;

        case 3:
            remv();
            break;

        case 4:
            menu();
            break;


        default:
            cout <<"Invalid selection";

    }
goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout <<"\t\t\t  Buyer \n";
    cout <<"\t\t\t  (1) Buy Product \n";
    cout <<"\t\t\t  (2) Go back     \n";
    cout <<"\t\t\t   Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            recpt();
            break;

        case 2:
            menu();

        default:
            cout <<"Invalid choice";

    }
goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout <<"\n\n\n\t\t Add new product";
    cout <<"\n\n\t  Product code of the product:  ";
    cin  >>pcode;
    cout <<"\n\n\t Name of the product:  ";
    cin  >>pname;
    cout <<"\n\n\t price of the product: ";
    cin  >>price;
    cout <<"\n\n\t Discount on product: ";
    cin  >>disc;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data <<" " <<pcode << " "<< pname << " " << price <<" "<<disc <<"\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

    if(token == 1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app|ios::out);
        data <<" " <<pcode << " "<< pname << " " << price <<" "<<disc <<"\n";
        data.close();
    }
  }
    cout <<"\n\n\t\t Record Inserted !";

}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout <<"\n\t\t\t Modify the record";
    cout <<"\n't\t\t Product code: ";
    cin >>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout <<"\n\n File does not exit! ";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);

        data >> pcode >> pname >> price >> disc;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout  <<"\n\t\t Product of new code: ";
                cin   >>c;
                cout  <<"\n\t\t Name of the product: ";
                cin   >>n;
                cout  <<"\n\t\t Price: ";
                cin   >>p;
                cout  <<"\n\t\t Discount: ";
                cin   >>d;
                data1 << " " << c <<" " << n <<" "<< p << " "<< d <<"\n";
                cout  <<"\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1 <<" "<< pcode <<" "<< pname <<" "<< price <<" "<<disc << "\n";
            }
            data >> pcode >> pname >> price >> disc;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database.txt","database.txt");

        if(token==0)
        {
            cout <<"\n\n Record not found!";
        }
    }
}

void shopping :: remv()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout <<"\n\n\t Delete product";
    cout <<"\n\n\t product code: ";
    cin >>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout << "File does not exist";
    }
    else
    {
        data1.open("database1.txt",ios::app | ios::out);
        data >> pcode >> pname >> price >> disc;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout <<"\n\t\t Product deleted successfully";
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << disc << "\n";
            }
            data >> pcode >> pname >> price >> disc;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout <<"\n\n Record can not be found";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout <<"\n\n|                                                       \n";
    cout <<"ProNo\t\tName\t\tPrice\n";
    cout <<"\n\n                                                       \n";
    data >> pcode >> pname >> price >> disc;
    while(!data.eof())
    {
        cout <<pcode <<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data >> pcode >> pname >> price >> disc;
    }
    data.close();
}

void shopping :: recpt()
{
    fstream data;

    int arrc[200]; // array of codes
    int arrq[200]; // array of quantity
    char choice;
    int c=0;
    float amount;
    float disc=0;
    float total=0;

    cout <<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout <<"\n\n Empty database";
    }
    else
    {
        data.close();

        list();
        cout <<"\n*********************************************************\n";
        cout <<"\n                                                         \n";
        cout <<"\n           Please place the order                        \n";
        cout <<"\n*********************************************************\n";
        do
        {
            m:
            cout <<"\n\n Enter Product code: ";
            cin  >>arrc[c];
            cout << "\n\n Enter the product quantity: ";
            cin  >> arrq[c];
            for(int i = 0; i <c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout <<"\n\n Duplicate product code. Please try again";
                    goto m;
                }
            }
            c++;
            cout <<" Do you want to buy another product or get out from this website? if yes then press y else n :";
            cin >> choice;
        }
        while(choice == 'y');

        cout <<"\n\n\t\t\t ***************************RECEIPT*************************\n";
        cout <<"\nProduct No.\tProduct Name\tQuantity \tPrice \t Amount \tDiscount Amount\n";

        for(int i =0; i < c; i++)
        {
            data.open("database.txt",ios::in);
            data >> pcode >> pname >> price >> disc;
            while(!data.eof())
            {
                if(pcode == arrc[i])
                {
                    amount=price*arrq[i];
                    disc =amount-(amount*disc/100);
                    total=total+disc;
                    cout <<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<disc;
                }
                data >> pcode >> pname >> price >> disc;
            }
        }

        data.close();
    }
    cout <<"\n\n******************************************************************";
    cout << "\n Total Amount: " << total;

}

int main ()
{
    shopping s;
    s.menu();
}
