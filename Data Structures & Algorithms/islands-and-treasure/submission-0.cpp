class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==0) {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {
            pair<int,int> t = q.front();
            int u = t.first;
            int v = t.second;
            q.pop();

            for(int i=0;i<4;i++) {
                if(u+1<grid.size() && grid[u+1][v]==2147483647) {
                    grid[u+1][v] = grid[u][v]+1;
                    q.push({u+1,v});
                }
                if(u-1>=0 && grid[u-1][v]==2147483647) {
                    grid[u-1][v] = grid[u][v]+1;
                    q.push({u-1,v});
                }
                if(v+1<grid[0].size() && grid[u][v+1]==2147483647) {
                    grid[u][v+1] = grid[u][v]+1;
                    q.push({u,v+1});
                }
                if(v-1>=0 && grid[u][v-1]==2147483647) {
                    grid[u][v-1] = grid[u][v]+1;
                    q.push({u,v-1});
                }
            }
        }
    }
};
