// #include <iostream>
// using namespace std;

// class publication
// {
// public:
//     float price;
//     string title;

//     publication()
//     {
//         cout << "enter a title of a Publication :" << endl;
//         cin >> title;
//         cout << "enter a price for a Publication  :" << endl;
//         cin >> price;
//     }
// };

// class book : public publication
// {
//     public:
//         int pagecount;

//         book()
//         {
//             cout << "enter a page count :" << endl;
//             cin >> pagecount;
//         }

//         void display1()
//         {
            
//             exception1();
//             cout << "Title :" << title << endl;
//             cout << "Price :" << price << endl;
//             cout << "pagecount  :" << pagecount << endl;
//         }


//         void exception1()
//         {
//             try
//             {
//                 if (pagecount > 0)
//                 {
//                     // cout << "Title :" << title << endl;
//                     // cout << "Price :" << price << endl;
//                     // cout << "pagecount  :" << pagecount << endl;
//                 }
//                 else
//                     throw(pagecount);
//             }

//             catch (int pagecount)
//             {
//                 title = "  ";
//                 price = 0;
//                 pagecount = 0;
//                 cout << "\nEXCEPTION \n";
//             }
//         }
// };


// class tape : public publication
// {
//     public:
//         float playingtime;

//         tape()
//         {
//             cout << "enter a playing time: " << endl;
//             cin >> playingtime;
//             // exception2();
//         }

//         void display2()
//         {
//             exception2();
//             cout << "Title :" << title << endl;
//             cout << "Price :" << price << endl;
//             cout << "playing time   :" << playingtime << endl;
//         }

//         void exception2()
//         {
//             try
//             {
//                 if (playingtime > 0)
//                 {
//                     // cout << "Title :" << title << endl;
//                     // cout << "Price :" << price << endl;
//                     // cout << "playing time   :" << playingtime << endl;
//                 }
//                 else
//                     throw(playingtime);
//             }
//             catch (float playingtime)
//             {
//                 title = "  ";
//                 price = 0;
//                 playingtime = 0;
//                 cout << "\nExpection\n";
//             }
//         }
// };
// int main()
// {
//     book a1;
//     tape b1;

//     while(true){
//         int choice;
//         cout << "******************menu****************" << endl;
//         cout << "1.Details of book " << endl;
//         cout << "2. Details of tapes " << endl;
//         // cout<<"3.create publication"<<endl;
//         cout << "Enter your operation : ";

//         cin >> choice;
//         switch (choice)
//         {
//             case 1:
//                 a1.display1();
//                 break;

//             case 2:
//                 b1.display2();
//                 break;

//             // case 3:
//             //     b1.display2();
//             //     break;

//             default:
//                 cout << "INVALID !!!! ";
//                 break;

//                 return 0;
//         }
//         char ex;
//         cout<<"do you want to exit ?";
//         cin>>ex;
//         if(ex == 'y'){
//             break;
//         }
//     }
// }



/*
 * 21451_OOP_assignment_3.cpp
 *
 *  Created on: 20-09-2022
 *      Author: SE
 */
/*--------------------------------------------------
Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which
adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and
displays the data members. If an exception is caught, replace all the data member values with
zero values.
--------------------------------------------------*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Publication{
protected:
	string title;
	float price;

public:
	Publication(){
		title = "<title>";
		price = 0;
	}
};


class Book : public Publication{
private:
	int pageCount;

public:
	static int bookCount;
	Book(){
		pageCount = 0;
		Book::bookCount++;
	}
 
	void getData();
	void getPageCount();
	void display();
	static void bookCountDisplay(){
		cout << "Current no. of books =" << Book::bookCount << endl;
	}
};


class Tape : public Publication{
private:
	float playTime;

public:
	static int tapeCount;
	Tape(){
		playTime = 0;
		Tape::tapeCount++;
	}

	void getData();
	void getPlayTime();
	void display();
	static void tapeCountDisplay(){
		cout << "Current no. of tapes =" << Tape::tapeCount << endl;
	}
};

void Book :: getPageCount(){
	while(true){
		cout << "Enter no. of pages: " << endl;
		try{
			cin >> pageCount;
			if (pageCount < 0){
				throw pageCount;
			}
			break;
		}
		catch(int pageCount){
			this->pageCount = 0;
			cout << "Page count cannot be negative!" << endl;
		}
	}
}


void Tape :: getPlayTime(){
	while(true){
		cout << "Enter play time of tape: " << endl;
		try{
			cin >> playTime;
			if (playTime < 0){
				throw playTime;
			}
			break;
		}
		catch(float playTime){
			this->playTime = 0;
			cout << "playtime cannot be negative!" << endl << endl;
		}
	}
}


void Book :: getData(){
	cout << "Enter Title : ";
	cin.clear();
	cin.ignore(1000,'\n');
	getline(cin, this->title);
	while(true){
		cout << "Enter Price:";
		try{
			cin >> price;
			if (price < 0){
				throw price;
			}
			break;
		}
		catch(float price){
			this->price = 0;
			cout << "Price cannot be negative!" << endl;
		}
	}
	this->getPageCount();
}

void Tape :: getData(){
	cout << "Enter Title : ";
	cin.clear();
	cin.ignore(1000,'\n');
	getline(cin, this->title);
	while(true){
		cout << "Enter Price:";
		try{
			cin >> price;
			if (price < 0){
				throw price;
			}
			break;
		}
		catch(float price){
			this->price = 0;
			cout << "Price cannot be negative!" << endl;
		}
	}
	this->getPlayTime();
}

void Book :: display(){
	cout << "<Book Data>" << endl;
	cout << "Title = " << this->title << endl;
	cout << "Price = " << this->price << endl;
	cout << "Pages Count = " << this->pageCount << endl << endl;
}


void Tape :: display(){
	cout << "<Tape Data>" << endl;
	cout << "Title = " << this->title << endl;
	cout << "Price = " << this->price << endl;
	cout << "Play Time = " << this->playTime << endl;
}

int Book::bookCount;
int Tape::tapeCount;

//driver code
int main()
{
	int choice = 0;
	vector<Book> bookDB;
	vector<Tape> tapeDB;

	while(choice != -1){
		cout << "------Menu------" << endl;
		cout << "1. New Book Entry" << endl
			 << "2. New Tape Entry" << endl
			 << "3. Display No. of Books in DB" << endl
			 << "4. Display No. of Tapes in DB" << endl
			 << "5. Display Book Data" << endl
			 << "6. Display Tape Data" << endl
			 << "-1. Exit" << endl;
		cout << "----------------" << endl;
		cout << "Enter your choice :";
		cin >> choice;

		switch(choice){
		case 1: //New Book Entry
			{Book B;
			cout << "Enter Book Data: " << endl;
			B.getData();
			bookDB.push_back(B);
			break;}

		case 2: //New Tape Entry
			{Tape T;
			cout << "Enter Tape Data: " << endl;
			T.getData();
			tapeDB.push_back(T);
			break;}

		case 3: // Display No. of Books in DB
			{Book::bookCountDisplay();
			break;}

		case 4: // Display No. of Tapes in DB
			{Tape::tapeCountDisplay();
			break;}

		case 5: // Display Book Data
			{for (auto B : bookDB){
				B.display();
				cout << endl;
			}
			break;}

		case 6: // Display Tape Data
			{for (auto T : tapeDB){
				T.display();
				cout << endl;
			}
			break;}

		case -1: // Exit
			{cout << "----Exit from Database----" << endl;
			choice = -1;
			break;}

		default: // Exit
			{cout << "----Exit from Database----" << endl;
			choice = -1;
			break;}
		}
	}

	return 0;
}