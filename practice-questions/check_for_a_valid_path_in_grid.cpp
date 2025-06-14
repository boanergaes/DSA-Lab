#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool up(int x,int y,vector<vector<int>>&grid){
        return grid[x][y]==2 || grid[x][y]==5 || grid[x][y]==6;
    }
    bool down(int x,int y,vector<vector<int>>&grid){
        return grid[x][y]==2 || grid[x][y]==3 || grid[x][y]==4;
    }
    bool left(int x,int y,vector<vector<int>>&grid){
        return grid[x][y]==1 || grid[x][y]==3 || grid[x][y]==5;
    }
    bool right(int x,int y,vector<vector<int>>&grid){
        return grid[x][y]==1 || grid[x][y]==4 || grid[x][y]==6;
    }
    bool valid(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m) return false;
        return true;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>visited(n,vector<int>(m,0));
        visited[0][0]=1;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;
            if(x==n-1 && y==m-1) return true;
            if(valid(x+1,y,n,m) && down(x,y,grid) && up(x+1,y,grid) && visited[x+1][y]==0){
                visited[x+1][y]=1;
                q.push({x+1,y});
            }
            if(valid(x,y+1,n,m) && right(x,y,grid) && left(x,y+1,grid) && visited[x][y+1]==0){
                visited[x][y+1]=1;
                q.push({x,y+1});
            }
            if(valid(x-1,y,n,m) && up(x,y,grid) && down(x-1,y,grid) && visited[x-1][y]==0){
                visited[x-1][y]=1;
                q.push({x-1,y});
            }
            if(valid(x,y-1,n,m) && left(x,y,grid) && right(x,y-1,grid) && visited[x][y-1]==0){
                visited[x][y-1];
                q.push({x,y-1});
            }

        }
        return false;
    }
};

int main() {
    return 0;
}