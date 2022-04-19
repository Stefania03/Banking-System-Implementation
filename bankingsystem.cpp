/*********************************
 *         BANKING SYSTEM        *

OPTIONS
1 to open new account
2 to see all accounts
3 to see specific account
4 to withdraw
5 to deposit
6 to check balance
 *********************************/

#include<iostream>
#include<string.h>
using namespace std;


class bank
{
private:
    string name, mob, addr, email;
    float bal;
public:
    string accunt;

    // neew name
    void new1()
    {
        cin.ignore();
        cout << "enter name";
        getline(cin, name);
        bal = 0.0;
    }

    // show user details
    void show()
    {
        // print data
        cout << endl;
        cout << "name is " << name << endl;
        cout << "account number is " << accunt << endl;
        cout << "address is " << addr << endl;
        cout << "mobile number is " << mob << endl;
        cout << "email is " << email << endl;
        cout << "balance is " << bal << endl;
    }

    // withdraw money
    void withdraw(float n)
    {
        cout << endl;

        // decrease balance after withdrowing n money
        bal=bal - n;

        // print data
        cout << "name is "<< name << endl;
        cout << "account number is " << accunt << endl;
        cout << "address is " << addr << endl;
        cout << "mobile number is " << mob << endl;
        cout << "email is " << email << endl;
        cout << "new balance is " << bal << endl;
    }

    // deposit money
    void deposit(float n)
    {
        // increase balance after deposit
        bal = bal + n;

        // print data
        cout << endl;
        cout << "name is " << name << endl;
        cout << "account number is " << accunt << endl;
        cout << "address is " << addr << endl;
        cout << "mobile number is " << mob << endl;
        cout << "email is " << email << endl;
        cout << "balance is " << bal << endl;
    }

    // show account balance
    void bal1()
    {
        cout << "balance is " << bal << endl;
    }

    // return account
    string acunt()
    {
        return accunt;
    }
};

int main()
{
    // create a bank object
    bank ob[5];

    int ch, temp = 0, i, temp1, temp2, k = 1;
    string acc;
    float n;

    do
    {
        int temp1 = 0;
        cout << endl;

        // choose your option
        cout << "enter 1 to open new account \n 2 to see all accounts \n 3 to see specific account \n 4 to withdraw \n 5 to deposit \n 6 to check balance \n 0 to exit";
        cin >> ch;

        switch(ch)
        {
        // open new account
        case 1:
            cin.ignore();
            cout << "enter account number";
            do
            {
                getline(cin, ob[temp].accunt);
                for(i = 0; i < temp; i++)
                {
                    // 
                    if(ob[temp].accunt != ob[i].acunt())
                    {
                        k = 1; // create account number
                    }
                    else k = 0; //account number already exists
                }

                if(k==1)
                {
                    // create account number
                    ob[temp].new1();
                    temp++;
                } else
                {
                    cout<<"account number already exists.Enter new account number"<<endl;
                }
            }while(k != 1);
            break;

        // see all accounts
        case 2:
            for(i = 0; i < temp; i++)
            {   
                // print a list of existing accounts
                ob[i].show();
            }
            break;

        // see specific account
        case 3:
            // account to be seen
            cout << "enter account number";
            cin >> acc;

            // search in the list of existing accounts
            for(i = 0; i < temp; i++)
            {   
                // compare specific account with every existing account
                if(acc == ob[i].acunt())
                {   
                    // if they match the account exists and will be displayed
                    temp1 = 1;

                    // if there are no matches the account doesnt exists
                    temp2 = i;
                }
            }

            if(temp1 == 1)
                //show account details
                ob[temp2].show();
            else
                cout << "account does not exists";
                break;
        
        // withdraw
        case 4:
            // enter account number and amount to be withdrawn
            cout << "enter account number";
            cin >> acc;
            cout << "enter amount to be withdrawn";
            cin >> n;

            // search in the list of existing accounts
            for(i = 0; i < temp; i++)
            {
                // compare specific account with every existing account
                if(acc == ob[i].acunt())
                {
                    // if they match the account exists and you will be able to withdraw amount
                    temp1 = 1;

                    // if they don't match, error. the account doesn't exist
                    int temp2 = i;
                }
            }

            // if they match, withdraw amount
            if(temp1 == 1)
                ob[temp2].withdraw(n);
            else
                cout << "account does not exists";
                break;

        // deposit
        case 5:
            // enter account number and amount to deposit
            cout << "enter account number";
            cin >> acc;
            cout << "enter amount to deposit";
            cin >> n;

            // search in the list of existing accounts
            for(i = 0; i < temp; i++)
            {
                // compare specific account with every existing account
                if(acc == ob[i].acunt())
                {
                    // if they match the account exists and you will be able to deposit amount
                    temp1 = 1;

                    // if they don't match, error. the account doesn't exist
                    int temp2 = i;
                }
            }

            if(temp1 == 1)
                ob[temp2].deposit(n);
            else
                cout << "account does not exists";
                break;

        // check balance
        case 6:
            // enter account number
            cout << "enter account number";
            cin >> acc;

            // search in the list of existing accounts
            for(i = 0; i < temp; i++)
            {
                // compare specific account with every existing account
                if(acc == ob[i].acunt())
                {
                    // if they match the account exists and you will be able to check balance
                    temp1 = 1;

                    // if they don't match, error. the account doesn't exist
                    int temp2 = i;
                }
            }

            if(temp1 == 1)
                ob[temp2].bal1();
            else
                cout << "account does not exists";
                break;
        default:
            cout << "enter valid choice";
        }
        
        if(ch == 0)
            break;
    }while(temp != 5);


    return 0;
}
