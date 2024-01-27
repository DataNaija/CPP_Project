#include <iostream>
using namespace std;

int main() {

    // Variable Declaration
    int quant;    //--quantity
    int choice;

    int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshake = 0, Qchicken = 0;  // Quantity of available food
    int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshake = 0, Schicken = 0;  // Quantity of food sold
    int Total_rooms = 0, Total_pasta = 0, Total_burger = 0, Total_noodles = 0, Total_shake = 0, Total_chicken = 0; // Price of items

    cout << "\n\t Quantity of item available: ";
    cout << "\n Available rooms: ";
    cin >> Qrooms;
    cout << "\n Quantity of pasta: ";
    cin >> Qpasta;
    cout << "\n Quantity of burger: ";
    cin >> Qburger;
    cout << "\n Quantity of noodles: ";
    cin >> Qnoodles;
    cout << "\n Quantity of shake: ";
    cin >> Qshake;
    cout << "\n Quantity of chicken: ";
    cin >> Qchicken;

    m:
    cout <<"\n\t\t\t Please choose your choice from the given options ";
    cout <<"\n\n1) Rooms";
    cout <<"\n2) Pasta";
    cout <<"\n3) Burger";
    cout <<"\n4) Noodles";
    cout <<"\n5) Shake";
    cout <<"\n6) Chicken";\
    cout <<"\n7) Information regarding sales and collections ";
    cout <<"\n8) Exit";

    cout <<"\n\n Please enter your choice! ";
    cin >> choice;

    switch(choice){
        case 1:
            cout << "\n\n Enter the number of rooms you want: ";
            cin >> quant;
            if(Qrooms - Srooms >= quant){
                Srooms = Srooms + quant;
                Total_rooms = Total_rooms + quant * 1200;
                cout <<"\n\n\t\t" << quant << " room/rooms have been assigned to you! ";
            }
            else
                cout << "\n\t Only " << Qrooms - Srooms << " Rooms remaining in hotel ";
            break;

         case 2:
            cout << "\n\n Enter the pasta quantity you want: ";
            cin >> quant;
            if(Qpasta - Spasta >= quant){
                Spasta = Spasta + quant;
                Total_pasta = Total_pasta + quant * 250;
                cout <<"\n\n\t\t" << quant << " Pasta is the order! ";
            }
            else
                cout << "\n\t Only" << Qpasta - Spasta << " Pasta remaining in hotel ";
            break;

         case 3:
            cout << "\n\n Enter the number of burger you want: ";
            cin >> quant;
            if(Qburger - Sburger >= quant){
                Sburger = Sburger + quant;
                Total_burger = Total_burger + quant * 120;
                cout <<"\n\n\t\t" << quant << " Burger is the order! ";
            }
            else
                cout << "\n\t Only" << Qburger - Sburger << " Burgers remaining in hotel ";
            break;

         case 4:
            cout << "\n\n Enter the number of noodles you want: ";
            cin >> quant;
            if(Qnoodles - Snoodles >= quant){
                Snoodles = Snoodles + quant;
                Total_noodles = Total_noodles + quant * 120;
                cout <<"\n\n\t\t" << quant << " Noodles is the order! ";
            }
            else
                cout << "\n\t Only" << Qburger - Sburger << " Noodles remaining in hotel ";
            break;

        case 5:
            cout << "\n\n Enter the number of shake you want: ";
            cin >> quant;
            if(Qshake - Sshake >= quant){
                Sshake = Sshake + quant;
                Total_shake = Total_shake + quant * 120;
                cout <<"\n\n\t\t" << quant << " Shake is the order! ";
            }
            else
                cout << "\n\t Only" << Qshake - Sshake << " Shake remaining in hotel ";
            break;

         case 6:
            cout << "\n\n Enter the number of chicken you want: ";
            cin >> quant;
            if(Qchicken - Schicken >= quant){
                Schicken = Schicken + quant;
                Total_chicken = Total_chicken + quant * 150;
                cout <<"\n\n\t\t" << quant << " Chicken is the order! ";
            }
            else
                cout << "\n\t Only" << Qchicken - Schicken << " Chicken remaining in hotel ";
            break;

        case 7:
            cout <<"\n\t\t Details of sales and collections ";
            cout<<"\n\n Number of rooms available: " << Qrooms;
            cout<<"\n\n Number of rooms sold: " << Srooms;
            cout<<"\n\n Remaining rooms : "<<Qrooms - Srooms;
            cout<<"\n\n Total rooms collection for the day: " << Total_rooms;

            cout<<"\n\n Number of pasta we had: " << Qpasta;
            cout<<"\n\n Number of pasta sold: " << Spasta;
            cout<<"\n\n Remaining pasta : "<<Qpasta - Spasta;
            cout<<"\n\n Total pasta collection for the day: " << Total_pasta;

            cout<<"\n\n Number of burger we had: " << Qburger;
            cout<<"\n\n Number of burger sold: " << Sburger;
            cout<<"\n\n Remaining burger : "<<Qburger - Sburger;
            cout<<"\n\n Total burger collection for the day: " << Total_burger;

            cout<<"\n\n Number of noodles we had: " << Qnoodles;
            cout<<"\n\n Number of noodles sold: " << Snoodles;
            cout<<"\n\n Remaining noodles : "<<Qnoodles - Snoodles;
            cout<<"\n\n Total noodles collection for the day: " << Total_noodles;

            cout<<"\n\n Number of shake we had: " << Qshake;
            cout<<"\n\n Number of shake sold: " << Sshake;
            cout<<"\n\n Remaining shake : "<<Qshake - Sshake;
            cout<<"\n\n Total shake collection for the day: " << Total_shake;

            cout<<"\n\n Number of chicken we had: " << Qchicken;
            cout<<"\n\n Number of chicken sold: " << Schicken;
            cout<<"\n\n Remaining chicken : "<<Qchicken - Schicken;
            cout<<"\n\n Total chicken collection for the day: " << Total_chicken;

            cout <<"\n\n\n Total collection for the day: " << Total_rooms + Total_burger + Total_chicken + Total_noodles + Total_pasta + Total_shake;
            break;

        case 8:
            exit(0);

        default:
            cout << "\n Please select from among the numbers above! ";

    }
    goto m;

    return 0;
}
