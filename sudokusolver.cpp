#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> > b, int row,int col,int a){
        for(int i=0;i<9;i++){
            //To check in the same row and column
            if(b[row][i]==a ||b[i][col]==a  ){
                
                return false;
            }
            //To check in the same 3x3 grid
            if(b[3*(row/3)+i/3][3*(col/3)+i%3]==a){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int> > & board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]== 0){
                    for(int k=1;k<=9;k++){
                        if(isSafe(board,i,j,k)){
                            board[i][j]=k;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j]= 0;                         
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int> > & board) {
        solve(board);
    }
    int main(){
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        int t;
        cin>>t;
        while(t--){
            vector<vector<int> > board(9,vector<int>(9));
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cin>>board[i][j];
                }
            }
            bool valid=solve(board);
            if(valid){
                cout<<"The solution for the sudoku is"<<endl;
                for(int i=0;i<13;i++){
                    cout<<"- ";
                }
                cout<<endl;
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        if(j==0){
                            cout<<"| ";
                        }
                        cout<<board[i][j]<<" ";
                        if(j%3==2){
                            cout<<"| ";
                        }
                    }
                    cout<<endl;
                    if(i%3==2){
                        for(int i=0;i<13;i++){
                            cout<<"- ";
                        }
                        cout<<endl;
                    }
                }
            }else{
                cout<<"no solution for the provided sudoku exists,Please enter a valid sudoku";
            }
            return 0;
        }
    }