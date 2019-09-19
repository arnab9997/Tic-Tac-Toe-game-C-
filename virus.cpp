#include<bits/stdc++.h>
using namespace std;

char board[3][3];
int i, j;
string name1, name2;
char mark;
int choice;
bool arr[9];

void printBoard(){
  cout<<"\t\t\t\t\t\t        #   #   \n";
  cout<<"\t\t\t\t\t\t      "<<board[0][0]<<" # "<<board[0][1]<<" # "<<board[0][2]<<" \n";
  cout<<"\t\t\t\t\t\t       1#  2#  3\n";
  cout<<"\t\t\t\t\t\t     ###########\n";

  cout<<"\t\t\t\t\t\t        #   #   \n";
  cout<<"\t\t\t\t\t\t      "<<board[1][0]<<" # "<<board[1][1]<<" # "<<board[1][2]<<" \n";
  cout<<"\t\t\t\t\t\t       4#  5#  6\n";
  cout<<"\t\t\t\t\t\t     ###########\n";

  cout<<"\t\t\t\t\t\t        #   #   \n";
  cout<<"\t\t\t\t\t\t      "<<board[2][0]<<" # "<<board[2][1]<<" # "<<board[2][2]<<" \n";
  cout<<"\t\t\t\t\t\t       7#  8#  9\n";
}

bool gameOver(int mark){
  for(j=0; j<3; j++){
      if(board[0][j] == mark && board[1][j] == mark && board[2][j] == mark)
        return true;
  }
  for(i=0; i<3; i++){
      if(board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
        return true;
  }
  if(board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
    return true;
  if(board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
    return true;
  return false;
}

void play(string turn){
  cout<<turn<<"\'s turn\n";
  cout<<"Select cell: ";
  (turn==name1)?(mark='X'):(mark='O');
  cin>>choice;
  if((choice>=1 && choice<=9) && !arr[choice-1]){                    // means 1<=choice<=9 and cell isn't occupied
    switch(choice){
      case 1: board[0][0]=mark;
              break;
      case 2: board[0][1]=mark;
              break;
      case 3: board[0][2]=mark;
              break;
      case 4: board[1][0]=mark;
              break;
      case 5: board[1][1]=mark;
              break;
      case 6: board[1][2]=mark;
              break;
      case 7: board[2][0]=mark;
              break;
      case 8: board[2][1]=mark;
              break;
      case 9: board[2][2]=mark;
              break;
    }
    arr[choice-1]=true;
    if(gameOver(mark)){
      system("cls");
      printBoard();
      cout<<turn<<" is the WINNER. Congratulations, my friend.\n";
    }
    else{
      system("cls");
      printBoard();
      for(i=0; i<9; i++)
        if(arr[i]==false)
          break;
      if(i==9){
        cout<<"Game is a tie\n";
        //exit(0);
      }
      else{
        turn = (turn==name1)?(name2):(name1);
        play(turn);
      }
    }
  }
  else{
    cout<<"try again: ";
    play(turn);
  }
}

int main(){
  cout<<"\t\t\t\t\t\tWELCOME TO THE GAME \n";
  cout<<"\t\t\t\t\t\tPlayer1 is to start\n";
  cout<<"\t\t\t\t\t  Player1 chooses X, Player2 chooses O\n";
  cout<<"\t\t\t\t\tEnter choices between 1-9 to select cell\n";
  cout<<"\t\t\t\t\t     Enter the name of players:\n";
  cout<<"\t\t\t\t\t\t\t";
  getline(cin, name1);
  cout<<"\t\t\t\t\t\t\t";
  getline(cin, name2);
  cout<<"\n\n";
  for(i=0; i<9; i++)
    arr[i]=false;

  printBoard();
  play(name1);
  return 0;
}
