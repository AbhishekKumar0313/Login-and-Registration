#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;

    cout << "\tEnter Username :";
    cin.ignore();
    getline(cin, username);
    cout << "\tEnter Password :";
    getline(cin, password);
    ifstream read("d:/" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
        return true;
    else
        return false;
}

int main()
{
    system("color 4f");
    int choice;
    cout << "\n\tWelcome to Punjab National Bank e-Portal" << endl;
    cout << "___________________________________________________" << endl;
    cout << "___________________________________________________" << endl;
    cout << "\n\t\t1. Register\n\t\t2. Login\n\tSelect one of the option :";
    cin >> choice;
    if (choice == 1)
    {
        string username, password;
        cout << "\tEnter a username :";
        cin.ignore();
        getline(cin, username);
        cout << "\tEnter a password :";
        getline(cin, password);
        ofstream file;
        file.open("d:/" + username + ".txt");
        file << username << endl
             << password;
        file.close();
        main();
    }
    else if (choice == 2)
    {
        bool status = IsLoggedIn();
        if (!status)
        {
            cout << "Invalid username or password : " << endl;
            system("PAUSE");
            main();
        }
        else
        {
            cout << "Succesfully Logged In" << endl;
            system("PAUSE");
            return 1;
        }
    }
}