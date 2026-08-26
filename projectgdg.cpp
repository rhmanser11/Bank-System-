
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct account
{
    int accnum; // رقم الحساب
    string frstnam;
    string lstnam;
    float blanc;
    int accno;
    void creat(int accno)
    {
        accnum = accno;
        cout << "Enter First Name:" << endl;
        cin >> frstnam;
        cout << "Enter Last Name:"<<endl;;
        cin >> lstnam;
        cout << "Enter Initial Balance:" << endl;
        cin >> blanc;
        cout << "Account created successfilly. Account No :" << accnum << endl;
    };

    void show()
    {
        cout << "Account Number:" << accnum << endl;
        cout << "Name:" << frstnam <<" "<< lstnam << endl;
        cout << "Balance:" << blanc << endl;
    };

    void deposi(float amount)
    {
        blanc += amount;
        cout << "Deposited successfully. New Balance:" << blanc<<endl;
    };

    void withdraw(float amount)
    {
        if (blanc - amount < 10)
        {
            cout << "nsufficient funds. Maintain minimum balance of 10" << endl;
        }
        else
        {
            blanc -= amount;
            cout << "Withdraw successfully.Now Balance:" << blanc << endl;
        }
    };
};

int main()
{
    vector<account *> acc;
   
    int nextaccountnumber = 1001;
    int cho;
    do
    {
        cout << "bank managment system" << endl;
        cout << "1.open account" << endl;
        cout << "2.blance " << endl;
        cout << "3.deposit" << endl;
        cout << "4.withdraw" << endl;
        cout << "5.close account" << endl;
        cout << "6.show all" << endl;
        cout << "7.exit" << endl;
        cout << "enter your choic 1:7" << endl;
        cin >> cho;

        switch (cho)
        {
        case 1:
        { 
            account *newacc = new account();
            newacc->creat(nextaccountnumber);
            nextaccountnumber++;
            // acc.push_back(person);
            acc.push_back(newacc);
            break;
        }
        case 2:
        { // blanceعرض رصيد
            int accno;
            int plac = -1;
            cout << "enter account number:";
            cin >> accno;
            for (int i = 0; i < acc.size(); i++)
            {
                if (acc[i]->accnum == accno)
                {
                    plac = i;
                    break;
                }
            }
            if (plac != -1)
            {
                acc[plac]->show();
            }
            else
            {
                cout << "not found" << endl;
            }
            break;
        }

        
        case 3:
        {
            float amount;
            int accno;
            cout<<"enter your account number:"<<endl;
            cin>>accno;
            int plac = -1;
            for (int i = 0; i < acc.size(); i++)
            {
                if (acc[i]->accnum == accno)
                {
                    plac = i;
                    break;
                }
            }
            if (plac != -1)
            {
                cout<<"enter amount:"<<endl;
                cin>>amount;
                acc[plac]->deposi(amount);
            }
            else
            {
                cout << "not found" << endl;
            }
            break;
        }
            
        case 4:
        {
            int accno;
            float amount;
            int plac = -1;
            cout << "enter account number:"<<endl;
            cin >> accno;
            for (int i = 0; i < acc.size(); i++)
            {
                if (acc[i]->accnum == accno)
                {
                    plac = i;
                    break;
                }
            }
            if (plac != -1)
            { 
                cout<<"enter amount:"<<endl;
                cin>>amount;
                acc[plac]->withdraw(amount);
            }
            else
            {
                cout << "not found!" << endl;
            }
            break;
        }
            
        case 5:
        {
            int accno;
            int plac = -1;
            cout << "enter account number:"<<endl;
            cin >> accno;
            for (int i = 0; i < acc.size(); i++)
            {
                if (acc[i]->accnum == accno)
                {
                    plac = i;
                    break;
                }
            }
            if (plac != -1)
            {
                delete acc[plac];
                acc.erase(acc.begin()+plac);
                cout << "closed successfully" << endl;
            }
            else
            {
                cout << "not found" << endl;
            }
            break;
        }

        case 6:
        {
            for (int i = 0; i < acc.size(); i++)
            {
                acc[i]->show();
            }

            break;
        }
        case 7:
        {
            cout << "exite" << endl;
            break;
        }
        default:
        {
            cout << "invalid choice" << endl;
        }
    }
 }
  while (cho != 7);

        return 0;
}




//g++ projectgdg.cpp -o projectgdg .\projectgdg.exe