class Solution {
public:
    int recurseCounter(vector<vector<int>> &grid, int i, int j){
        int count = 1;
        grid[i][j] = -1;
        
        if(i+1 < grid.size() && grid[i+1][j]==1)
            count += recurseCounter(grid, i+1, j);
        if(i-1 >= 0 && grid[i-1][j]==1)
            count += recurseCounter(grid, i-1, j);
        if(j+1 < grid[0].size() && grid[i][j+1]==1)
            count += recurseCounter(grid, i, j+1);
        if(j-1 >= 0 && grid[i][j-1]==1)
            count += recurseCounter(grid, i, j-1);
        
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        
        int maxArea = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1)
                    maxArea = max(recurseCounter(grid, i,j), maxArea);
            }
        }
        
        return maxArea;
    }
};