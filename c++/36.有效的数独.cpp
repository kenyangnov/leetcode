class Solution {
public:
    bool isVaild(vector<int>& v){
        int a[11] = {0};
        for(int i=0; i< v.size(); i++){
            a[v[i]]++;
            if(a[v[i]]==2){
                return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> v;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='.'){
                    continue;
                }
                v.push_back(board[i][j]-'0');   
            }
            if(!isVaild(v)){
                return false;
            }
            v.clear();
        }
        v.clear();
        for(int i=0; i<board[0].size(); i++){
            for(int j=0; j<board.size(); j++){
                if(board[j][i]=='.'){
                    continue;
                }
                v.push_back(board[j][i]-'0');
            }
            if(!isVaild(v)){
                return false;
            }
            v.clear();
        }
        v.clear();
        for(int i=0; i<board.size(); i+=3){
            for(int j=0; j<board[0].size(); j+=3){
                for(int m=0; m<3; m++){
                    for(int n=0; n<3; n++){
                        if(board[i+m][j+n]=='.'){
                            continue;
                        }
                        v.push_back(board[i+m][j+n]-'0');
                    }
                }
                if(!isVaild(v)){
                    return false;
                }
                v.clear();
            }
        }
        return true;
    }
};