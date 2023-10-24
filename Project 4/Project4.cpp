//Source for MazeSolver

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "myStack.h"
#include "MazeCell.h"

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define DONE 4
#define SUCCESS 10
#define FAILURE 20

//method headers*******************************************************

//depthFirst header
void depthFirst(MazeCell start, MazeCell end,int x,int y);

//global variables*****************************************************

//# rows and cols in the maze
int rows, cols;
//pointer to the grid (2-d array of ints)
int** grid;
//pointer to the maze cells (2-d array of MazeCell objects)
MazeCell** cells;

int main() {
	
	//create the Maze from the file
	ifstream fin("/Users/bignola/Downloads/mazein.txt");	
	if(!fin){
		cout << "File not found\n";
		exit(2);
	}

	//read in the rows and cols
	fin >> rows >> cols;

	//create the maze rows
	grid = new int* [rows];
	
	//add each column
	for (int i = 0; i < rows; i++)
		grid[i] = new int[cols];

	//read in the data from the file to populate
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fin >> grid[i][j];
		}
	}

	//look at it 
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == 3)
				cout << "S" << " ";
			else if (grid[i][j] == 4)
				cout << "E" << " ";
			else
				cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	//make a 2-d array of cells
	cells = new MazeCell * [rows];
	for (int i = 0; i < rows; i++) {
		cells[i] = new MazeCell[cols];
	}

	//all MazeCell in the cells grid has a default init
	//only update those cells that are not walls

	MazeCell start, end;
	
	//iterate over the grid
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] != 0) {
				cells[i][j].setCoordinates(i, j);
				//look for the start and end cells
				if (grid[i][j] == 3)
					start = cells[i][j];
				if (grid[i][j] == 4) 
					end = cells[i][j];
				
			}

		}
	}
	
	//testing
	cout <<"start: "<< start << " end: " << end << endl;
	
	//solve it!
	depthFirst(start, end,0,2);


	return 0;
}


//this function should find a path through the maze
//if found, output the path from start to end
//if not path exists, output a message stating so

void depthFirst(MazeCell start, MazeCell end, int x, int y)
{	
	int i = x;
    int j = y;
    myStack<MazeCell> nola;
    //nola.push(cells[i][j]);
    while(cells[i][j]!= cells[end.getRow()][end.getCol()])
    {
		//cout<<cells[row][col];
		if( j<5) //&& cells[i][j+1].unVisited()&& cells[i][j+1].getCol()!= -1 )
		{
			cout<< cells[i][j].getRow();
			nola.push(cells[i][j]);
			cout<<cells[i][j];
			j++;
		}
        // hello mate 
         // if we are going to move right 
        // if ( cells[row][col].getCol() < 5)
        // {
        //      nola.push(cells[row][col]);
		// 	 cout<< cells[row][col];
        //      cells[row][col].visit();
        //      col++;
        // }
		// trying to move left
		// else if ( cells[row][col].getCol() > 0 && cells[row][col-1].unVisited() && cells[row][col-1].getCol() != -1 )
        // {
        //     nola.push(cells[row][col]);
        //      cells[row][col].visit();
        //      col--;
        // }
		// trying to move up
		// else if (cells[row][col].getRow() > 0 && cells[row-1][col].unVisited() && cells[row-1][col].getRow() != -1)
		// {
		// 	nola.push(cells[row][col]);
		// 	cells[row][col].visit();
		// 	row++;
		// }
		// trying to move down
		// else if (cells[row][col].getRow() < 4 && cells[row+1][col].unVisited() && cells[row+1][col].getRow() != -1)
		// {
		// 	nola.push(cells[row][col]);
		// 	cells[row][col].visit();
		// 	row--;	
		// }
		// else
		// {
		// 	cout<< " hello";
		// 	// cells[row][col].visit();
        //     // nola.pop();
        //     // row = nola.top().getRow();
        //     // col = nola.top().getCol();
		// }
    }
}