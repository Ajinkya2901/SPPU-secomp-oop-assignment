// Develop an object oriented program in C++ to create a database of student
// information system containing the following information : Name, Roll number, Class,
// Division, date of birth, Blood group, Contact address, Telephone number, Driving license no. and other.
//  Construct the database with suitable member functions for initializing and
// destroying the data viz constructor, default constructor, Copy constructor, destructor, static
// member functions, friend class, this pointer, inline code and dynamic memory allocation
// operators-new and delete.
#include<iostream>
using namespace std;

class studentdata{
    private:
        

    public:
        char name[40] , cls[40] , div[40] , dob[40];
        int roll;
        static int count  ;
        studentdata(){
            char *name = new char;
            char *cls = new char;
            char *div = new char;
            char *dob = new char;
            int  roll;
        }
    
    static void Totalrec(){
        cout<<"record"<<count;
    }
};
int studentdata :: count = 0;

class personaldata{
    private:
        char bloodgrp[10] , add[10], mob[10], polno[10], licno[10];
    public:
        personaldata()
        {
            add ;
        }
        friend class studentdata;
        void InputData(studentdata *obj);
        void Output(studentdata *obj);
        
};

void personaldata::InputData(studentdata *obj){
    
    cout <<"\nROLLNO : ";
    cin >> obj->roll;
    cout <<"\nNAME : ";
    cin >> obj->name;
    cout <<"\nCLASS : ";
    cin >> obj->cls;
    cout <<"\nDIVISION : ";
    cin >> obj->div;
    cout <<"\nDATE OF BIRTH(DD - MM - YYYY) : ";
    cin >> obj->dob;
    cout <<"\nBLOOD GROUP : ";
    cin >> this->bloodgrp;
    cout <<"\nADDRESS : ";
    cin >> this->add;
    cout <<"\nTELEPHONE NUMBER : ";
    cin >> this->mob;
    cout <<"\nDRIVING LICENSE NUMBER : ";
    cin >> this->licno;
    cout <<"\nPOLICY NUMBER : ";
    cin >> this->polno;
    obj->count++;
}
void personaldata::Output(studentdata *obj)
{
    cout << "\n";
    cout << obj->roll << " "
         << obj->name << " "
         << obj->cls << " "
         << obj->div << " "
         << obj->dob << " " << this->add << " " << this->mob
         << " " << this->bloodgrp << " "
         << this->licno << " " << this->polno;
}
int main()
{
    studentdata *a[100];
    personaldata *b[100] ; 
    int  choice;
    int n = 0;
    char ans;
    do{
        cout << """\n\n**********MENU********** \n\t1.Input Data \n\t2.Display Data\nEnter your choice :""";
        
        cin >> choice;
        switch (choice)
        {
        case 1:
        cout << "\n\n\tENTER THE DETAILS\n ***************************";
            do
            {
                a[n] =  new studentdata;
                b[n] = new personaldata;
                b[n] ->InputData(a[n]);
                n++;
                studentdata::Totalrec();
                cout << "\nDo you want to add more records? (y / n) : ";
                cin >> ans;
            } while (ans == 'y' || ans == 'Y');
            break;
        case 2 :
            cout << "\n*************************************************************************";
            cout << "\n Roll Name Class Div BirthDate Address Telephone Blood_Gr Licence Policy ";
            cout << "\n************************************************************************";
            for (int i = 0; i < n; i++)
                b[i]->Output(a[i]);
            studentdata::Totalrec();
            break;

        }
        cout << "\n\nDo you want to go to main menu ? (y / n) : ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');
    return 0;
}