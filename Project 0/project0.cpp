// Jordan scott 
// CST_201 
// Project 0
#include <iostream> 
#include <fstream>
using namespace std;

#include <iostream> 
#include <fstream>
using namespace std;
// explain the search method and bubble sorting method for the video 

string*  Sort (string myArray[])  // Used a bubble sorting method 
{
    string temp; 
     for (int i=0; i<100; i++)  // 
    {
        cout<< " "<<myArray[i]<< " ";
    }
    for(int i = 0; i < 50; i++)  // neseted for loop 
    {
    for(int j = 1; j < (50 - i); j++)
    {
        if(myArray[j -1] > myArray[j]) // 
        {
            temp = myArray[j-1];
            myArray[j-1] = myArray[j];
            myArray[j] = temp; 
        }
    }
     
    }
     for (int i=0; i<100; i++)
    {
        cout<<myArray[i]<< " ";
    }
  return myArray;

}

string* Search ( string myArray[]) // Binary search method was used 
{
     int bottomHalf = 0; 
    int len = 100;
    int topHalf = len -1; 
    string key;
    cout << " What word do you want to find ? .... 0 to stop   ";
    cin >> key;

     while(bottomHalf<= topHalf)
    {
        int mid = bottomHalf+ (topHalf-bottomHalf)/2 ; 
        if(myArray[mid] == key)
        {  
            cout << key << " is in the text at index "<< mid << endl;
            Search(myArray);
            break;              
        }
        if(key > (myArray[mid]))
        { 
        bottomHalf = mid + 1;
        }
        else
        {
             topHalf = mid - 1; 
        }
    } 
}

int main ()
{
       // 
    string temp;
    fstream myfile;
    string myArray[100];
    int m = 0;
    myfile.open("/Users/bignola/Desktop/CST-201/Naruto.txt");
    while(!myfile.eof())
    {
        myfile>>myArray[m];
        m++;
    }
    myfile.close();
    Sort(myArray) ;
    Search(myArray);
    
}