class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++){
            map<int,int> count;
            for(int j=0;j<9;j++){
                if(board[i][j] != '.' && count.find(board[i][j]) != count.end()){
                    return false;
                }
                
                count[board[i][j]]++;
            }
        }

        for(int j=0;j<9;j++){
            map<int,int> count;
            for(int i=0;i<9;i++){
                if(board[i][j] != '.' && count.find(board[i][j]) != count.end()){
                    return false;
                }
                
                count[board[i][j]]++;
            }
        }

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){

                map<int,int> count;
                // micro kernel
                for(int ix=i*3;ix<(i*3+3);ix++){
                    for(int jy=j*3;jy<(j*3+3);jy++){

                        if(board[ix][jy] != '.' && count.find(board[ix][jy]) != count.end()){
                            return false;
                        }

                        count[board[ix][jy]]++;
                    }
                }

            }
        }

        return true;

    }
};
