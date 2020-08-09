//994. Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<int> row, col;
        int fresh = 0, cnt, rtemp, ctemp, temp, minNumTurns = 0;
        
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 2){
                    row.push(i);
                    col.push(j);
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        while(!row.empty()){
            cnt = row.size();
            temp = fresh;
            while(cnt--){
                rtemp = row.front(); row.pop();
                ctemp = col.front(); col.pop();
                
                if(rtemp > 0 && grid[rtemp-1][ctemp] == 1){
                    fresh--;
                    grid[rtemp-1][ctemp] = 2;
                    row.push(rtemp-1);
                    col.push(ctemp);
                }
                if(ctemp > 0 && grid[rtemp][ctemp-1] == 1){
                    fresh--;
                    grid[rtemp][ctemp-1] = 2;
                    row.push(rtemp);
                    col.push(ctemp-1);
                }
                if(rtemp < grid.size()-1 && grid[rtemp+1][ctemp] == 1){
                    fresh--;
                    grid[rtemp+1][ctemp] = 2;
                    row.push(rtemp+1);
                    col.push(ctemp);
                }
                if(ctemp < grid[0].size()-1 && grid[rtemp][ctemp+1] == 1){
                    fresh--;
                    grid[rtemp][ctemp+1] = 2;
                    row.push(rtemp);
                    col.push(ctemp+1);
                }
            }
            
            if(temp != fresh)
                minNumTurns++;
        }
        
        if(fresh != 0) return -1;
        return minNumTurns;
    }
};