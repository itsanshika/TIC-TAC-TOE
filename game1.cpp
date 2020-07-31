//Tic Tac Toe Game in C++

//Importing the inbuild libraries in CPP
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int row,column;
char turn = 'X';
int t=-1;
int flag=0;

bool draw = false;

//Function to show the current status of the gaming board

void display_board(){

  cout<<" BOARD "<<endl;

if(board[0][0]=='1')cout<<" " ;
else cout<<board[0][0];
cout<<"|";
if(board[0][1]=='2')cout<<" " ;
else cout<<board[0][1];
cout<<"|";
if(board[0][2]=='3')cout<<" " ;
else cout<<board[0][2];
cout<<endl;
cout<<"------"<<endl;
if(board[1][0]=='4')cout<<" " ;
else cout<<board[1][0];
cout<<"|";
if(board[1][1]=='5')cout<<" " ;
else cout<<board[1][1];
cout<<"|";
if(board[1][2]=='6')cout<<" " ;
else cout<<board[1][2];
cout<<endl;
cout<<"------"<<endl;
if(board[2][0]=='7')cout<<" " ;
else cout<<board[2][0];
cout<<"|";
if(board[2][1]=='8')cout<<" " ;
else cout<<board[2][1];
cout<<"|";
if(board[2][2]=='9')cout<<" " ;
else cout<<board[2][2];
cout<<endl;




return;


}

//Function to get the player input and update the board

void player_turn(char p1,char p2){
    int val;
    int k=1;
    while(k)
    {
        if(t==-1){
        cout<<" Player - 1 " <<p1<< " turn : ";
    }
    else {
       cout<<" Player - 2 " <<p2<< " turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

        cin>> choice;


if(choice >=1 && choice<=9)
{
    k=0;

}
else {cout<<"!INVALID MOVE!"<<endl;
                cout<<"You can choose any no. between 1 - 9"<<endl;}


    }

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;

    }

    if(t == -1 && board[row][column] != p1 && board[row][column] != p2){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = p1;
        t=t*-1;
        flag=0;

    }else if(t==1 && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = p2;
        t=t*-1;
        flag=0;
    }else {
        //if input position already filled
        cout<<"Box already filled!n Please choose another no."<<endl;
        player_turn(p1,p2);
        flag=1;
    }
    /* Ends */
    if(flag==0)display_board();

}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{
    cout<<"T I C K -- T A C -- T O E -- G A M E"<<endl;
    cout<<"Enter For 2 Players"<<endl;
    int k=1;
    char p1;
      char p2;
      while(k)
      {
        cout<<"Player1 can choose  X or O"<<endl;

      cin>>p1;
      if(p1=='X' || p1=='O')k=0;

      if(p1=='X')p2='O';
      else p2='X';

      if(k==1)cout<<"You can choose only between X or O . RETRY!!"<<endl;
      }

    while(gameover()){
       // display_board();
        player_turn(p1,p2);
        gameover();
    }
    if(t==-1 && draw == false){
        cout<<"Congratulations!! \n Player 2  has won the game"<<endl;
    }
    else if(t==1 && draw == false){
        cout<<"Congratulations!! \n Player 1 has won the game"<<endl;
    }
    else
    cout<<"GAME DRAW!!!"<<endl;
}
