#include <vector>
#include <iostream>
using namespace std;
class Solution {
  public:
    int countBattleships(vector<vector<char>>& board) {
      int res = 0;
      for(int i=0; i<board.size(); ++i){
        for(int j=0; j<board[i].size(); ++j){
          // use top left as identifier of a battle ship
          if(isValid(board[i][j]) && 
              (i==0 || (i-1>=0 && j<board[i-1].size() && !isValid(board[i-1][j]))) && 
              (j==0 || (j-1>=0 && !isValid(board[i][j-1])))
              ){
            ++res;
          }
        }
      }
      return res;
    }

    int countBattleships(vector<vector<char>>& board) {
      int res = 0;
      for(int i=1; i<board.size(); ++i){
        if(board[i].size() != board[i-1].size()){
          return -1;
        }
      }
      //scan horizontally
      for(int i=0; i<board.size(); ++i){
        int counter = 0;
        for(int j=0; j<board[i].size(); ++j){
          char x = board[i][j];
          if(isValid(x)){
            if(counter==1){
              ++res;
              ++counter;
            }
            else{
              ++counter;
            }
          }
          else{
            counter = 0;
          }
        }
      }
      //scan vertically
      for(int j=0; j<board[0].size(); ++j){
        int counter = 0;
        for(int i=0; i<board.size(); ++i){
          char x = board[i][j];
          if(isValid(x)){
            if(counter==1){
              ++res;
              ++counter;
            }
            else{
              ++counter;
            }
          }
          else{
            counter = 0;
          }
        }
      }
      vector<int> xx;
      xx.push_back(-1);
      xx.push_back(0);
      xx.push_back(0);
      xx.push_back(1);
      vector<int> yy;
      yy.push_back(0);
      yy.push_back(1);
      yy.push_back(-1);
      yy.push_back(0);
      //scan isolated
      for(int i=0; i<board.size(); ++i){
        for(int j=0; j<board[i].size(); ++j){
          if(isValid(board[i][j])){
            bool isIsolated = true;
            for(int z=0; z<xx.size(); ++z){
              int x = i+xx[z];
              int y = j+yy[z];
              if(0<=x && x<board.size() && 0<=y && y<board[0].size()){
                if(i==0 && j==0){
                  cout << x << " " << y << endl;
                }
                if(isValid(board[x][y])){
                  isIsolated = false;
                  break;
                }
              }
            }
            if(isIsolated){
              ++res;
            }
          }
        }
      }
      return res;
    }

    bool isValid(char x){
      return x=='X';
    }
};

int main(){
  return 0;
}
