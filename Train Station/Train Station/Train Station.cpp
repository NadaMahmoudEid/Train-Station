#include <iostream>
#include <string>
using namespace std;

struct carige {
    bool avi[10][30];
};

carige train;
void book(int numtic)
{

    for (int j = 1; j <= 10; j++)
    {
        for (int i = 1; i <= 30; i++)
        {
            if (numtic > 0)
            {
                if (train.avi[j][i] == 0)
                {
                    cout << "Your car is num [ " << j << " ] and your set num [ " << i << " ].\n";
                    train.avi[j][i] = 1;
                    numtic--;
                }
            }
        }
    }
}
void cancel(int car, int seet)
{
    if (train.avi[car][seet] == 0)
    {
        cout << "The seat does not reserved" << endl;
    }
    else {
        train.avi[car][seet] = false;
        cout << "The reservation is canceled" << endl;
    }
}
void line() {
    for (int i = 0; i < 90; i++)if (i < 30)cout << " "; else cout << '_'; cout << '\n';
}


void checkcar(int car)//num of car he want to know num of available seat in it//
{
    int fl = 0;
    cout << "The available seats is num [ ";
    for (int i = 1; i <= 30; i++)
    {
        if (train.avi[car][i] == 0)
        {
            cout << i << ",";
            fl = 1;
        }
    }
    if (fl == 0)
        cout << "0";
    cout << " ]" << endl;
}



void checkseatavia(int numofseat)
{
    int fl = 0;
    cout << " This seat is available in cars num [ ";
    for (int j = 1; j <= 10; j++)
    {
        if (train.avi[j][numofseat] == 0) {
            cout << j << ",";
            fl = 1;
        }
    }
    if (fl == 0)
        cout << "Sorry ! there is not seat with this num available in any cars";
    cout << " ]" << endl;
}

void checkavail(int carnum)
{
    int fl = 0;
    for (int i = 1; i <= 30; i++)
    {
        if (train.avi[carnum][i] == 0)
        {
            cout << "YES there is available seats" << endl;
            fl = 1;
            break;
        }
    }
    if (fl == 0)
        cout << "SORRY there is no available seats." << endl;
}
void checkstatus(int carnum)
{
    for (int i = 1; i <= 30; i++)
    {
        if (train.avi[carnum][i] == 0)
            cout << "[" << i << "] is available." << endl;
        else
            cout << "[" << i << "] is not available." << endl;
    }


}
void choice()
{
    int a;
    do {
        cout << endl;
        cout << "Press { 1 } if you want to book a ticket.\n\n";
        cout << "Press { 2 } if you want to cancel a ticket.\n\n";
        cout << "Press { 3 } if you want to check if a specific car has available seats or not.\n\n";
        cout << "Press { 4 } if you want to check if a set is available or not.\n\n";
        cout << "Press { 5 } if you want to know available seat in a specific car.\n\n";
        cout << "Press { 6 } if you want to know all the seats status of a specific car.\n\n";
        cout << "Press { 0 } if you want to exit.\n\n";
        for (int i = 0; i < 120; i++)cout << ":"; cout << '\n\n';
        cin >> a;
        if (a == 1)
        {

            int numtic;
            cout << "Enter num of tickets ?" << endl;
            cin >> numtic;
            book(numtic);
            line();
       }
        if (a == 2)
        {
            int i, j;
            cout << "Enter car num" << endl;
            cin >> j;
            cout << "Enter set num " << endl;
            cin >> i;
            cancel(j, i);
            line();
        }
        if (a == 3)
        {
            int numofccar;
            cout << "Enter num of car " << endl;
            cin >> numofccar;
            checkavail(numofccar);
            line();
        }
        if (a == 4) {
            int seatnum;
            cout << "Enter num of a seat you want to know is available or not " << endl;
            cin >> seatnum;
            checkseatavia(seatnum);
            line();
        }
        if (a == 5)
        {
            int numofcar;
            cout << "Enter num of car " << endl;
            cin >> numofcar;
            checkcar(numofcar);
            line();
        }
        if (a == 6)
        {
            int carnum;
            cout << "Enter the num of car" << endl;
            cin >> carnum;
            checkstatus(carnum);
            line();
        }
        
    } while (a != 0);
   
}
int main() {

    choice();
    
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

}