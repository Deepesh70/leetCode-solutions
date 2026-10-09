class Solution {
public:

    vector<int> parent;
    vector<int> rank;


    int find_parent(int i){
        if(parent[i] == i){
            return i;
        }
        else{
            return parent[i] = find_parent(parent[i]);
        }
    }

    void Union(int x, int y){
        int parent_x = find_parent(x);
        int parent_y = find_parent(y);

        if(parent_x == parent_y){
            return;
        }
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x; 
        }
        else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        if(connections.size() < n-1) return -1;
        for(int i=0;i < n; i++){
            parent[i] = i;
        }
        int component = n;
        for(auto & vec: connections){
            if(find_parent(vec[0]) != find_parent(vec[1])){
                Union(vec[0], vec[1]);
                component--;
            }
        }
        return component-1;


    }
};