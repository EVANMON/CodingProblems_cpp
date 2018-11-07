#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numIslands(vector<vector<char> >& grid) {
    int xAxis = grid.size();
    int yAxis = grid[0].size();
    vector<vector<bool> > mark(xAxis, vector<bool>(yAxis, false));
    int res = 0;
    vector<int> tmp;
    queue<vector<int> > points;
    
    for(int i=0; i<xAxis; i++){
        for(int j=0; j<yAxis; j++){
            if (grid[i][j] - '0' == 1){
                tmp[0] = 1;
                tmp[1] = i;
                tmp[2] = j;
                points.push(tmp);
            }
        }
    }
    
    while(!points.empty()){
        tmp = points.front();
        points.pop();
        if(tmp[0] == 1 && !mark[tmp[1]][tmp[2]]){
            mark[tmp[1]][tmp[2]] = true;
            res += 1;
            if(tmp[1]-1 >= 0) mark[tmp[1]-1][tmp[2]] = true;
            if(tmp[1]+1 < xAxis) mark[tmp[1]+1][tmp[2]] = true;
            if(tmp[2]-1 >= 0) mark[tmp[1]][tmp[2]-1] = true;
            if(tmp[2]+1 < yAxis) mark[tmp[1]][tmp[2]+1] = true;
        }
    }

    return res;
}

int main(){
	vector<vector<char> > input;
	vector<char> tmp;
	tmp.push_back('1');
	input.push_back(tmp);
	int x = input.size();
	int y = input[0].size();
	cout<<x<<y<<endl;
	return 0;
}