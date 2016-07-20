/* 
    这里只是判断已有的数字合不合法，不管最后有没有解
    规则：也叫九宫格， 每行 每列 每一宫（小9格）数字只能出现一回
    flag1[i][num]表示i行数字num出现过否 flag2[i][num]i列数字num出现过否 flag3[i][num] i宫格数字num出现过否
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        int flag1[9][9] = {0}, flag2[9][9] = {0}, flag3[9][9] = {0};
        
        for(int i =0 ; i<board.size() ; i++){
            for(int j =0; j<board[i].size(); j++)
                if(board[i][j]!='.'){
                    int num = board[i][j]-'0'-1; 
                    int cell = i/3*3 + j/3; //determine which cell
                    if(flag1[i][num]||flag2[j][num]||flag3[cell][num])
                        return false;
                    //记得标记
                    flag1[i][num] =1; flag2[j][num] =1; flag3[cell][num] =1;
                }
        }
        return true;
    }