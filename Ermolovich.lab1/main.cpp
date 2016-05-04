//
//  main.cpp
//  Ermolovich.lab1
//
//  Created by Evgeny on 09.03.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int EnterDimention (int );
void QuickSort (int* , int );
void QuickSort (int* , int , int );
void EnterArray (int* , int );
void DisplayArray (int* , int );
void Swap (int& , int& );
int* ArePositiveСhetn (int* , int , int );
int QuantityPositiveChetn (int* , int );
int QuantityElementsABCDEF (int );
void ConvertElementIn16Form(int );
void ConvertArray16 (int* , int );
void DeleteSimilarElements (int* , int& );
void CreateFile (char* , int* , int );
void FileOrMass (int* , int );

const int N = 100;

int main ()
{
    int n = EnterDimention(N);
    int* a = new int [n];
    FileOrMass(a, n);
    cout << "Array: " << endl;
    DisplayArray(a, n);
    cout << endl;
    int m = QuantityPositiveChetn(a, n);
    int* b = ArePositiveСhetn(a, n, m);
    cout << "Positive chetn numbers before negative of an array:" << endl;
    DisplayArray(b, m);
    cout << endl;
    int l = n - m;
    cout << "The last elements of an array:" << endl;
    DisplayArray(a, l);
    cout << endl;
    cout << "The last elements of an array in 16 form:" << endl;
    ConvertArray16(a, l);
    cout << endl;
    cout << "Sorted last elements of an array in 16 form whitout similar:" << endl;
    QuickSort(a, l);
    DeleteSimilarElements(a, l);
    ConvertArray16(a, l);
    cout << endl;
    cout << "Sorted last elements of an array whithout similar:" << endl;
    DisplayArray(a, l);
    cout << endl;
    char k;
    cout << "If you want to continue, type y or Y" << endl;
    cin >> k;
    if (k == 'y' || k == 'Y') main();
    return 0;
}

void FileOrMass (int* a, int n)
{
    char t;
    while (true)
    {
        cout << "If you want File, type F or f" << endl;
        cout << "If you want massiv, type m or M" << endl;
        cin >> t;
        if (t == 'f' || t == 'F' || t == 'm' || t == 'M') break;
        else cout << "Incorrect!!" << endl;
    }
    if (t == 'f' || t == 'F')
    {
        char fileName[N];
        cout << "Enter the name of file: ";
        cin >> fileName;
        CreateFile(fileName, a, n);
    }
    if (t == 'm' || t == 'M')
    {
        EnterArray(a, n);
    }
}
void CreateFile(char* fileName, int* a, int n)
{
	ofstream streamOut(fileName);
	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		exit(1);
	}
	cout << "Enter the elements of array" << endl;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << "enter temp variable:";
		cin >> temp;
        a[i] = temp;
		streamOut.width(5);
		streamOut << temp;
	}
	streamOut.close();
}
int QuantityPositiveChetn (int* a, int n)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && a[i] > 0 && a[i + 1] < 0)
            m++;
    }
    return m;
}
int* ArePositiveСhetn (int* a, int n, int m)
{
    int* b = new int [m];
    for (int j = 0; j < m; )
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0 && a[i] > 0 && a[i + 1] < 0)
            {
                b[j] = a[i];
                j++;
                for (int k = i; k <= n; k++)
                    a[k] = a[k + 1];
            }
        }
    }
    return b;
}
void DeleteSimilarElements (int* a, int& l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
            if (a[i] == a[j])
            {
                for (int k = j; k <= l; k++)
                    a[k] = a[k + 1];
                l--;
                j--;
            }
    }
}
void ConvertElementIn16Form (int a)
{
    const char b[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string s = "  ";
    int temp = a;
    while (temp)
    {
        s += b[abs(temp) % 16];
        temp /= 16;
    }
    if (a == 0) s += '0';
    if (a < 0) s += '-';
    reverse(s.begin(),s.end());
    cout << s;
}
void ConvertArray16 (int* a, int l)
{
    for (int i = 0; i < l; i++)
    {
        ConvertElementIn16Form(a[i]);
    }
}
int QuantityElementsABCDEF (int a)
{
    const char b[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string s = " ";
    int temp = a;
    while (temp)
    {
        s += b[abs(temp) % 16];
        temp /= 16;
    }
    if (a == 0) s += '0';
    if (a < 0) s += '-';
    reverse(s.begin(),s.end());
    int k = 0;
    for (int i = 0; i < s.length() ; i++)
    {
        if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'F')
            k++;
    }
    return k;
}
void QuickSort (int* a, int l)
{
    QuickSort(a, 0, l - 1);
}
void QuickSort (int* a, int left, int right)
{
    int i = left, j = right;
    int middle = a[(left + right) / 2];
    while (i <= j)
    {
        while (QuantityElementsABCDEF (a[i]) > QuantityElementsABCDEF(middle))
            i++;
        while (QuantityElementsABCDEF (a[j]) < QuantityElementsABCDEF(middle))
            j--;
        
        if (i <= j)
        {
            Swap (a[i], a[j]);
            i++;
            j--;
        }
        
    }
    if (left < j)
        QuickSort(a, left, j);
    if (i < right)
        QuickSort(a, i, right);
}
int EnterDimention (int n)
{
    int k;
    while (true)
    {
        cout << "Enter size of an array 0 <= n <= " << n << ": ";
        cin >> k;
        if (k > 0 && k <= n)
            return k;
        cout << "Error!" << endl;
    }
}
void EnterArray (int* a, int n)
{
    cout << "Enter the elements of an array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << (i + 1) << "] = ";
        cin >> a[i];
    }
}
void DisplayArray (int* a, int n)
{
    for (int* p = a; p < a + n; p++)
        cout << *p << "  ";
}
void Swap (int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}