#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void allocate(char**& arr, int n) {
    arr=new char*[n];
    for(int i=0;i<n;i++){
        arr[i]=new char[n];
    }
}

void initialize(char** arr, int n) {
    srand(time(0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            arr[i][j]=(rand()%2)+'0';
        }
    }
    arr[0][0] = 'S';
    arr[n-1][n-1] = 'E';
}

void display(char** arr, int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout <<" "<< arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool magic_maze(char** maze, int n, int i = 0, int j = 0) {

    if(i<0||j<0||i>=n||j>=n||maze[i][j]=='0'||maze[i][j]=='P'){
        return false;
    }


    if(maze[i][j]=='E'){
        return true;
    }


    if(maze[i][j]!='S'){
       maze[i][j]='P';
    }


    if (magic_maze(maze,n,i,j+1)||magic_maze(maze,n,i+1,j)||magic_maze(maze,n,i,j-1)||magic_maze(maze,n,i-1,j)){
        return true;
    }


    if (maze[i][j]!='S'){
        maze[i][j]='1';
    }
    return false;
}

void deallocate(char** arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int n;
    cout << "Enter the size of the maze (Max 20): ";
    cin >> n;
    char** maze;
    allocate(maze, n);
    initialize(maze, n);

    cout << "\nGenerated Maze (Before Solving):" << endl;
    display(maze, n);

    if (magic_maze(maze, n)) {
        cout << "\nSolved Maze (Escape Path Marked with 'P'):" << endl;
        display(maze, n);
    } else {
        cout << "\nNo Escape!" << endl;
    }

    deallocate(maze, n);
    return 0;
}
