class Solution {
public:
    int N ;
    void dfs(vector<vector<int>> &isConnected, int i, vector<bool> &isVisited){
        isVisited[i] = true;

        for(int j=0; j< N ; j++){
            if((isVisited[j] == false) && isConnected[i][j] == 1){
                isVisited[j] = true;
                dfs(isConnected, j, isVisited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        N = isConnected.size();
        vector<bool> isVisited(N, false);

        int count=0;
        for(int i=0; i< N; i++) {
            if(isVisited[i] == false){
                dfs(isConnected, i, isVisited);
                count++;
            }
        }   
        return count;
        }
};