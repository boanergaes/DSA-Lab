#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int colms = maze[0].size();
        queue<pair<int,int>>q;
        int steps = 1;
        vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        while(!q.empty()){

            int d=q.size();

            for(int i=0;i<d;i++)
            {
                auto [x_cord,y_cord]=q.front();
                q.pop();

                for(int k=0;k<4;k++)
                {
                    int x=x_cord+dir[k][0];
                    int y=y_cord+dir[k][1];

                    if(x<0 || y<0 || x>=rows || y>=colms || maze[x][y]=='+')
                        continue;
                    if(x==0 || y==0 || x==rows-1 || y==colms-1)
                        return steps;
                    maze[x][y]='+';
                    q.push({x,y});
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    return 0;
}