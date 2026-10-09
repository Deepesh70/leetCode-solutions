class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses,0);
        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        int count =0;
        vector<int> result;
        for(int i =0; i< numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }

        while(!q.empty()){
            int u = q.front();
            result.push_back(u);
            q.pop();
            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }
        if(count == numCourses){
            return result;
        }else return {};
    }
};