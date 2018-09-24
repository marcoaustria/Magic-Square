#include <iostream>
//#include "pa1.h"

using namespace std;

void fillSquare(int** array);
void printSquare(int** array, int magicNum);
void flipOverY(int** array);
void flipOverX(int** array);

int sizeOfSquare;

int main() {

    //make sure value is within parameters
    //if it is, then takes in value and breaks out of loop
    while(true) {

        cout << "Enter the size of a magic square: ";

        //take in size of magic square
        cin>>sizeOfSquare;

        cout<<endl;

        //print out if number entered is not odd
        if(sizeOfSquare%2==0||sizeOfSquare>15||sizeOfSquare<3) {
            cout<<"Please enter an odd number between 3 inclusive and 15 inclusive\n"<<endl;
        } else {
            break;
        }
    }

    //creates 2D array
    int** array=new int*[sizeOfSquare];
    for (int i=0; i<sizeOfSquare; i++) {
        array[i]=new int[sizeOfSquare];
    }

    //initializes array values as 0
    for (int i=0; i<sizeOfSquare; i++) {
        for(int j=0; j<sizeOfSquare; j++) {
            array[i][j]=0;
        }
    }

    fillSquare(array);
    printSquare(array, 1);
    flipOverY(array);
    printSquare(array, 2);
    flipOverX(array);
    printSquare(array, 3);

}

//fill array with correct values
void fillSquare(int** array) {

    int i=0;
    int j=sizeOfSquare/2;

    int row=i;
    int col=j;

    //increments value that will be used from 1 to sizeOfSquare
    for(int val=1; val<=sizeOfSquare*sizeOfSquare; val++) {

        //assign empty cell value
        array[i][j]=val;

        //find the next cell going up one right one
        row--;
        col++;

        //if row is out of range wrap around
        if(row<0) {
            row=(sizeOfSquare-1);

        }

        //if column is out of range wrap around
        if(col==sizeOfSquare) {
            col=0;
        }

        //check if cell is empty
        //if yes, make it the next cell to be filled
        if(array[row][col]==0) {
            i=row;
            j=col;
        }

        //cell was full, go down one
        else {
            i++;
            row=i;
            col=j;
        }
    }

}

//prints out magic square
void printSquare(int** array,int magicNum) {
    cout << "Magic Square #" <<magicNum<< " is: \n" <<endl;
    for(int x=0; x<sizeOfSquare; x++) {
        for(int y=0; y<sizeOfSquare; y++) {
            cout<<array[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    //find sums of rows
    cout<<"Checking the sums of every row: ";
    int sum=0;
    for(int i=0; i<sizeOfSquare; i++) {


        for(int j=0; j<sizeOfSquare; j++) {
            sum+=array[i][j];
        }

        cout<<sum;

        sum=0;
    }
    cout<<endl;
    sum=0;

    //find sums of columns
    cout<<"Checking the sums of every column: ";

    for(int j=0; j<sizeOfSquare; j++) {

        for(int i=0; i<sizeOfSquare; i++) {
            sum+=array[i][j];
        }

        cout<<sum;

        sum=0;
    }
    cout<<endl;
    sum=0;

    //find sums of diagonals
    cout<<"Checking the sums of every diagonal: ";
    int a=0;
    int b=0;
    while(a!=sizeOfSquare) {
        sum+=array[a][b];
        a++;
        b++;

    }

    cout<<sum;
    sum=0;

    a=sizeOfSquare-1;
    b=sizeOfSquare-1;
    while(a!=-1) {
        sum+=array[a][b];
        a--;
        b--;

    }
    cout<<sum;
    cout<<"\n"<<endl;
    sum=0;

}

//flips along y axis
void flipOverY(int** array) {
    int temp;
    for(int i=0; i<sizeOfSquare; i++) {
        for(int j=0; j<(sizeOfSquare/2); j++) {
            temp=array[i][j];
            array[i][j]=array[i][(sizeOfSquare-j-1)];
            array[i][(sizeOfSquare-j-1)]=temp;
        }
    }

}

//flips along x axis
void flipOverX(int** array) {
    int temp;
    for(int j=0; j<sizeOfSquare; j++) {
        for(int i=0; i<(sizeOfSquare/2); i++) {
            temp=array[i][j];
            array[i][j]=array[(sizeOfSquare-i-1)][j];
            array[(sizeOfSquare-i-1)][j]=temp;
        }
    }

}
