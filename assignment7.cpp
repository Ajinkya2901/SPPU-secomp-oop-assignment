#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    cout << "Enter data : ";
    map<string,string> population;

    int n;
    cout << "\nEnter number of states : ";
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        string state;
        cout << "Enter name of state  : ";
        cin >> state;

        string p;
        cout << "Enter population : ";
        cin.ignore();
        getline(cin,p);
        population.insert(pair<string, string>(state, p));
    }

    while(true)
    {
        cout << "\ndo you want to search population ? (y/n)"<<endl;
        char choice ;
        cin >> choice;
        if(choice == 'y')
        {
            string searchkey;
            cout << "Enter key to search : " ;
            cin >> searchkey;
            cout << population[searchkey] ;
        }
        else{
            break;
        }


    }


    return 0;
}