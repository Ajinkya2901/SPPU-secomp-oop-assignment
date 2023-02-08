/*#using namespace std;

template<typename T>
void selectionSort(T arr[], int size)
{
    int minpos = 0;
    for ( int i = 0 ; i < size-1; i++)
    {
        T min = arr[i];
        for (int j = i + 1 ; j<size ; j++)
        {
            if (arr[j]<min){
                minpos = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[minpos];
        arr[minpos] = temp;
    }
}

template< class T1>
void display(T1 array)
{
    for (int i = 0; i < 7; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}



int main(){

    int a[7] = {7, 4, 1, 5, 2, 3, 6};
    float b[7] = {4.2, 2.5, 9.1, 6.8, 3.5, 8.3, 2.2};
    char c[7] = {'b', 'c', 'a', 'g', 'z', 'i', 'q'};

    selectionSort<int>(a, 7);
    selectionSort<float>(b, 7);
    selectionSort<char>(c, 7);
    display(a);
    display(b);
    display(c);

    
    return 0;
}*/

/*
 * 21451_OOP_assignment_5.cpp
 *
 *  Created on: 18-Oct-2022
 *      Author: se
 */
//Write a function template for selection sort that inputs, sorts and outputs an integer array and
//a float array.
// --------------------------------------------------------------------------------------------------

# include <iostream>
using namespace std;

template <typename T>

void sort(T arr[], int n){
	// selection sort
	for (int i=0; i<n-1; i++){
		int minIndex = i;
		for (int j=i+1; j<n; j++){
			if (arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		T temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}
}

int main(){
//  arrays of int and float ypes
//	int a[] = {21, 45, 73, 11, 89, 34};
//	int n = 6;
//	float b[] = {1.24, 9.56, 3.45, 10.01, 3.32, 5.67};
//	int m = 6;

	// user input
	int n, m;
	cout << "Enter No. of Elements for int array A:" << endl;
	cin >> n;
	cout << "Enter No. of Elements for float array B:" << endl;
	cin >> m;

	int *a = new int[n];
	float *b = new float[m];

	cout << "Enter " << n << " Integers:" << endl;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}

	cout << "Enter " << m << " Floats:" << endl;
	for (int i=0; i<m; i++){
		cin >> b[i];
	}

	// before sorting
	cout << "\nBefore Sorting : " << endl;
	cout << "A = {";
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << "}" << endl;

	cout << "B = {";
	for(int i=0; i<m; i++){
		cout << b[i] << " ";
	}
	cout << "}" << endl;

	sort<int>(a, n);
	sort<float>(b, m);

	// after sorting
	cout << "\nAfter Sorting : " << endl;
	cout << "A = {";
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << "}" << endl;

	cout << "B = {";
	for(int i=0; i<m; i++){
		cout << b[i] << " ";
	}
	cout << "}" << endl;

	return 0;
}