class Solution {
public:
    int n;

    bool checkBipartiteBFS(vector<vector<int>> & graph, vector<int> &color, int currentNode, int currentColor){
        queue<int> q;
        color[currentNode] = currentColor;
        q.push(currentNode);
        while(!q.empty()){

            int u = q.front();
            q.pop();
            for(int &v: graph[u]){
            if(color[v] == color[u]){
                return false;
            }
            else if(color[v] == -1){
                q.push(v);
                if(color[u] == 1){
                    color[v] = 0;
                }else if(color[u] == 0){
                    color[v] = 1;
                }
            }
            }
        }
        return true;
    }
   
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i< n; i++){
            if(color[i] == -1){
            if(checkBipartiteBFS(graph, color, i, 1) == false){
                return false;
            }
            }
        }
        return true;
    }
};