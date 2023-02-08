#include<iostream>
using namespace std ;

class Complex{
    private:
        int real ,img ;
    public:
        
        Complex(int r = 0 , int i = 0 ){
            real = r;
            img = i;
        }
        void print(){
            cout<< real << "+" << img <<"i" <<endl;
        }

        Complex operator +(Complex &c){
            Complex temp;
            temp.real = real + c.real;
            temp.img = img + c.img;
            return temp;
        }

        Complex operator *(Complex c){
            Complex temp ;
            temp.real = real*(c.real) - img*(c.img);
            temp.img = real*(c.img) + c.real *(img);
            return temp;
        }

        friend ostream &operator <<(ostream &out , Complex &c){
            out << c.real ;
            cout <<"+";
            out<<c.img;
            cout<<"i";
            cout<< endl;
        }

        
        friend istream &operator >> (istream &in , Complex &c){
            in >> c.real;
            in >> c.img;
        }

        };
int main()
{
    Complex c1;
    cout<<"Enter value in c1:";
    cin>>c1;                   //operator << (cin,c1)

    Complex c2;
    cout<<"Enter value in c2:";
    cin>>c2;

    Complex c3;
    Complex c4;
    c3 = c2 + c1;  //c3 = c2.add(c1);
    c4 = c2*c1;   //c4 = c2.multi(c1);
    cout<< c1;
    cout<< c2;
    cout<< c3;        //operator << (cout,c3)
    cout<< c4;

    int x = 4;
    int y =5 ;
    int z = x + y;
    cout<<"z value : " << z << endl;

    return 0;

}