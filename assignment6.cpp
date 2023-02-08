#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class student
{
public:
        int Phn;
        string name;
        char dob[15];

        bool operator ==  (const student &student1)
        {
            return(Phn==student1.Phn);
        }
        bool operator<(const student &student1)
        {
            return(Phn<student1.Phn);
        }

        friend ostream& operator << (ostream &out, const student &);
        friend istream& operator >> (istream &in, student &k);
};

ostream & operator << (ostream &out, const student &k)        
{
    out<<"\n\t\t"<<k.Phn<<"\t\t"<<k.name<<"\t\t"<<k.dob;
    return out;
}

istream & operator >> (istream &in , student &k)
{
    cout<<"\nEnter phone No : ";
    in>>k.Phn;
    cout<<"\nEnter Name : ";
    in>>k.name;
    cout<<"\nEnter DOB  : ";
    in>>k.dob;
    return in;
}                    

bool myfunc(const student &k, const student &i2)
{
    return(k.Phn<i2.Phn);
}

vector<student> read()
{
    int n;
    student k;    
    vector<student> j;
    cout<< "\nEnter total no. of students : ";
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cin>>k;
            j.push_back(k);
        }
    return j;
}

void printfunction(const student &k)
{
    cout<<k;
}


void print( const vector<student> &j)
{
    cout<<"\n\t\tPhone NO\tNAME\tDATE OF BIRTH";
    for_each(j.begin(),j.end(),printfunction);

}


void insert(vector<student> &j)
            {
                student k;
                cin>>k;
                j.push_back(k);
            }


void delet(vector<student>&j)
{
    student k;
    cout<<"\nEnter Student phone No To Delete : ";
    cin>>k.Phn;
    vector<student>::iterator p;
    p=find(j.begin(),j.end(),k);
    if(p!=j.end())
        j.erase(p);
    else
        cout<<"\nNot found ";
}


void search( vector<student>&j )
{
    student k;
    cout<<"\nEnter Student phone No to Search  : ";
    cin>>k.Phn;
    cout<<"\n\n\t\tphone NO\t\tNAME\t\tDATE OF BIRTH";
    vector<student>::iterator p;
    p=find(j.begin(),j.end(),k);
    if(p!=j.end())
                cout<<*p;
    else
                cout<<"\nNot found ";
}


void sort( vector<student> &j)
{
    sort(j.begin(),j.end(),myfunc);

}

int main()
{
    vector<student> j;
    int op;
    do
    {
            cout<<"\n\n\t\t-------<< MENU >>---------";
            cout<<"\n\t\t1.Create ";
            cout<<"\n\t\t2.Display ";
            cout<<"\n\t\t3.Insert  ";
            cout<<"\n\t\t4.Delete ";
            cout<<"\n\t\t5.Search ";
            cout<<"\n\t\t6.Sort";
            cout<<"\n\t\t7.Quit";
            cout<<"\n\t\t--------------------------";
            cout<<"\n\t\tEnter your choice : ";
            cin >> op;
            switch(op)
            {
                case 1:
                    j = read();
                    break;
                case 2:
                    print(j);
                    break;
                case 3:
                    insert(j);
                    print(j);
                    break;
                case 4:
                    delet(j);
                    print(j);
                    break;
                case 5:
                    search(j);
                    break;
                case 6:
                    sort(j);
                    print(j);
                    break;
                }
    }while(op!=7);
}
