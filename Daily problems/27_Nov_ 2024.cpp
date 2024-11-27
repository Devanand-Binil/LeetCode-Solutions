class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
         // Create an adjacency list for the graph
        unordered_map<int, unordered_set<int>> graph;
        for(int i=0; i<n-1;++i){graph[i].insert(i+1);}
        //-------------------------------------------------------------------------
        // BFS to compute the shortest path from 0 to n-1
        auto bfs = [&]() -> int {
            vector<bool> visited(n,false);
            queue<pair<int,int>> q; // (current node, distance)
            q.push({0,0});
            visited[0]=true;

            while (!q.empty()){
                auto[node,dist]=q.front();
                q.pop();

                if(node==n-1) return dist;

                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]){
                        visited[neighbor]=true;
                        q.push({neighbor,dist+1});
                    }
                }
            }
            return -1; // No path found
        };
        //---------------------------------------------------------------------
        vector<int> answer;
        for(const auto& query:queries){
            int u = query[0]; 
            int v = query[1];
            graph[u].insert(v); // Add the new road
            answer.push_back(bfs()); // Compute shortest path after this addition
        }
        //---------------------------------------------------------------------------
        return answer;
    }
};
