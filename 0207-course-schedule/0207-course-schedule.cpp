class Solution {
public:

    bool isCycle(vector<vector<int>> &adj, vector<bool> & visited, vector<bool>& inRecursion, int i) {
        visited[i] = true;
        inRecursion[i] = true;
        for(int &v: adj[i]){
            if(visited[v] == false){
                if(isCycle(adj, visited , inRecursion, v) == true){
                    return true;
                }
            } else if(inRecursion[v] == true){
                return true;
            } 
        }
        inRecursion[i] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(const auto& j: prerequisites){
            adj[j[1]].push_back(j[0]);
        }

        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(visited[i] == false){
                if(isCycle(adj, visited, inRecursion, i) == true){
                    return false;
                }
            }
        }
        return true;
    }
};