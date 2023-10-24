// Jordan Scott
// CST-201
// Project 8
// Graph
#include <iostream>
using namespace std;

 void display (int arr[][15]) // O(n^2)
    {
        for (int i = 0; i <15; i++) 
        {
            for (int j = 0; j <15; j++) 
            {
                cout << i << ": " << arr[i][j]<< " ";
            }
        }

    }
        void getNeighbors (int vertex, int arr[][15], string arr2[15]) // O(1)
    {
        for( int i = 0; i <15; i++)
        {
            if (arr[vertex][i] > 0)
            {
                cout << arr2[i]<< endl;
            }
        }

    }
    void  getDistance(int start, int end, int arr[][15], string arr2[15]) // O(v+e)
    {
        int totalDistance= 0; 
        int s = start;
        int e = end;
        // finding the distance between from start to end using dFS 
        // if they are next to each other 
        if (arr[start][end] > 0)
        {
            cout << "The distance between "<< arr2[start] << " and " << arr2[end]<< "is: " << arr[start][end];
            return;
        }
        else 
        {
            // findind the path to get to the end since we can not go straight to the end
                // need to start at the neighbor
                for (int i= 0; i <15; i++ )
                {
                        if ( arr[start][i]> 0)
                        {
                            totalDistance+=arr[start][i];
                            start++;
                            
                            // need to rest the value of i after finding a value at that 
                            i--;
                        } 
                        if(i == end) 
                        {
                            cout << "The distance between "<< arr2[s] << " and " << arr2[e]<< " is: " << totalDistance;

                            return;
                        }
                }
        }
    }

int main ()
{
    int array [15][15];
    string city [15];
    city[0]="Mohave";
    city[1]="Coconino";
    city[2]="Navajo";
    city[3]="Apache";
    city[4]="Greenlee";
    city[5]="Cochise";
    city[6]="Santa Cruz";
    city[7]="Pima";
    city[8]="Pinal";
    city[9]="Graham";
    city[10]="Gila";
    city[11]="Yavapai";
    city[12]="La Paz";
    city[13]="Yuma";
    city[14]="Maricopa";

    array [0][1]=14;
    array [0][11]=14;
    array [0][12]=9;

    array [1][0]=14;
    array [1][11]=9;
    array [1][10]=17;
    array [1][2]=9;

    array [2][1]=9;
    array [2][3]=5;
    array [2][10]=13;
    array [2][9]=20;

    array [3][2]=5;
    array [3][9]=19;
    array [3][4]=17;

    array [4][3]=17;
    array [4][9]=4;
    array [4][5]=16;

    array [5][4]=16;
    array [5][6]=8;
    array [5][9]=12;
    array [5][7]=6;

    array [6][5]=8;
    array [6][7]=6;

    array [7][6]=6;
    array [7][8]=7;
    array [7][9]=12;
    array [7][13]=23;
    array [7][14]=10;
    array [7][5]=9;

    array [8][10]=5;
    array [8][9]=13;
    array [8][7]=7;
    array [8][14]=6;

    array [9][2]=20;
    array [9][3]=19;
    array [9][4]=4;
    array [9][5]=12;
    array [9][7]=12;
    array [9][8]=13;
    array [9][10]=7;

    array [10][2]=13;
    array [10][9]=7;
    array [10][8]=5;
    array [10][11]=18;
    array [10][14]=8;
    array [10][1]=17;

    array [11][0]=14;
    array [11][1]=9;
    array [11][10]=18;
    array [11][12]=15;
    array [11][14]=15;

    array [12][0]=9;
    array [12][11]=15;
    array [12][13]=11;
    array [12][14]=15;

    array [13][7]=23;
    array [13][12]=11;
    array [13][14]=18;

    array [14][11]=9;
    array [14][12]=15;
    array [14][13]=18;
    array [14][10]=8;
    array [14][8]=6;
    array [14][7]=10;

    display(array);
     cout << endl;
     cout<< endl;
    int pelicans; 
    cout << " Which vertices neighbors would you like to see? : ";
    cin >> pelicans; 
    getNeighbors(pelicans, array,city);
    cout << endl;
    int et,gremlins;
    cout << " Which two vertices you will like to see the distance of? : " ;
    cin >> et;
    cout << " what is the second vertices you want? : ";
    cin >> gremlins;
    //call getDistance  here
    getDistance(et,gremlins,array,city);
}
