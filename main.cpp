// Login to the registration application system.
// It gives users rooms to create accounts.Sign in to the existing account and also help the user revise their password.


#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void signup();
void forgot_pswd();


int main()
{
    int choice;
     cout <<"\t\t\t ****************************************************\n\n\n";
     cout <<"\t\t\t               WELCOME TO THE LOGIN PAGE              \n\n\n";
     cout <<"\t\t\t ****************** MENU ***************************** \n\n\n";
     cout <<"                                                                   \n\n";
     cout <<"\t Press 1 to LOGIN                        " << endl;
     cout <<"\t Press 2 to SIGN UP                      " << endl;
     cout <<"\t Press 3 if you forgot your PASSWORD     " << endl;
     cout <<"\t Press 4 to EXIT                         " << endl;
     cout <<"\n\t\t\t Please enter your choice : ";
     cin >> choice;
     cout << endl;

     switch(choice){

        case 1:
            login();
            break;

        case 2:
            signup();
            break;

        case 3:
            forgot_pswd();
            break;

        case 4:
            cout <<"\t\t\t Thank you! \n\n";
            break;

        default:
            cout << "\t\t\t Please select from the options given above \n" << endl;
            main();


     }

    return 0;
}

void login(){

    int count;
    string userid, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password: " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userid;
    cout << "\t\t\t PASSWORD ";
    cin >> password;

    ifstream input("record.txt");

    while(input >> id >> pass){
        if(id==userid && pass==password){
            count = 1;
            system("cls");
        }
    }
    input.close();

    if(count==1){
        cout << userid << "\n Your login is successfull \n Thanks for logging in ! \n";
        main();
    }
    else{
        cout << "\n LOGIN ERROR \n Please check your username or password\n";
    }
}

void signup(){
    string ruserid, rpassword,rid,rpass;
    system("cls");
    cout << "\t\t\t Enter the username: ";
    cin >> ruserid;
    cout << "\t\t\t Enter the password: ";
    cin >>rpassword;

    ofstream f1("record.txt", ios::app);
    f1 << ruserid << ' '<<rpassword <<endl;
    system("cls");
    cout <<"\n\t\t\t Registration is successfull! \n";
    main();
}

void forgot_pswd(){
    int option;
    system("cls");
    cout <<"\t\t\t You forgot the password! \n";
    cout <<"Press 1 to search your id by username " <<endl;
    cout <<"Press 2 to go back to the main menu " << endl;
    cout <<"\t\t\t Enter your choice: ";
    cin>>option;

    switch(option){
        case 1: {
            int count = 0;
            string suserid, sid,spass;
            cout << "\n\t\t\t Enter the username which you remembered : ";
            cin>>suserid;

            ifstream f2("records.txt");
            while(f2 >> sid >> spass){
                if(sid==suserid){
                    count=1;

                }
            }
            f2.close();
            if(count==1){
            cout <<"\n\n Your account is found! \n";
            cout << "\n\n Your password is : "<<spass;
            main();
            }
            else{
                cout << "\n\t Sorry your account is not found! \n";
                main();
             }
            break;
        }
        case 2: {
            main();
        }
        default:
            cout << "\t\t\t Wrong choice! Try Again "<<endl;
            forgot_pswd();

    }
}

