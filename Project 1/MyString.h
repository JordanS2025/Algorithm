// Jordan Scott 
// CST_201 
// MyString Project 
#ifndef MyString_H
#define MyString_H
#include <iostream>
#include <cstring>
using namespace std;
class MyString 
{
    private: 
    int arrSize ;
    char* nola;
    int curr_length;
    void ensureCapacity()
    {
    }

    public:
    MyString()
    {
        arrSize = 0;
        nola= new char [arrSize];
        curr_length = 0;
    }

    MyString (string user )
    {
        curr_length = user.length();
        nola = new char[curr_length + 1];
        strcpy(nola, user.c_str());
    }

  
    int Length(int i) // O(1)
    {
        return curr_length;
    }
     void toString() // O(n)
     {
        cout<< nola<< endl;
     }
    MyString concat(const MyString& other) // O(n) 
    {
        char* temp = new char[curr_length + other.curr_length + 1];
        strcpy(temp, nola);
        strcat(temp, other.nola);
        return MyString(temp);
    }

        bool equals(MyString& other) // O(n)
    {
        if (curr_length != other.curr_length)
            return false;
        for (int i = 0; i < curr_length; i++)
        {
            if (nola[i] != other.nola[i])
                return false;
        }
        return true;
    }
        int compareTo(MyString& other) // O(n) due the fucution being called 
        {
            return strcmp(nola, other.nola);
        }


     char get(int i) // O(1) since this is a constant 
    {
        return nola[i]; 
    }
    MyString toUpper()      // O(n)
    {
        char* temp = new char[curr_length + 1];
        for (int i = 0; i < curr_length; i++) {
            if (nola[i] >= 'a' && nola[i] <= 'z') {
                temp[i] = nola[i] - 32;
            } else {
                temp[i] = nola[i];
            }
        }
        temp[curr_length] = '\0';
        return MyString(temp);
    }
        MyString toLower()      // O(n)
    {
        char* temp = new char[curr_length + 1];
        for (int i = 0; i < curr_length; i++) {
            if (nola[i] >= 'A' && nola[i] <= 'Z') {
                temp[i] = nola[i] + 32;
            } else {
                temp[i] = nola[i];
            }
        }
        temp[curr_length] = '\0';
        return MyString(temp);
    }

        void substring(int x)       // O(n)
    {
        for (int i = x;i < arrSize;i++)
        {
            cout << nola[i];
        }
    }
         void substring2(int x, int y)      // O(n)
    {
        for (int i = x;i <= y;i++)
        {
            cout << nola[i];
        }
    }
    int indexOf(MyString& other)    // O(n*m)
    {
        char* p = strstr(nola, other.nola);
        if (p) {
            return p - nola;
        }
        else {
            return -1;
        }
    }
    int lastIndexOf(MyString& other)       // O(n*m)
    {
        char* p = strstr(nola, other.nola);
        if (p) {
            int index = -1;
            while (p) {
                index = p - nola;
                p = strstr(p + other.curr_length, other.nola);
            }
            return index;
        }
        else {
            return -1;
        }
    }

};
#endif