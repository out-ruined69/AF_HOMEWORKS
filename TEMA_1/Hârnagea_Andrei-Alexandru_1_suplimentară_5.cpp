#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> viz;
//O(N*M)
bool dfs(int i, int j, int n, int m, vector<vector<int>> grid, int& act) {
    if(i<0 || i>=n || j>=m || j<0 || grid[i][j]==0 || viz[i][j]==1) //daca am iesit de pe harta nu se adauga un patrat la insula
        return 0;
    viz[i][j]=1; //marcam patratul ca vizitat
//verificam vecinii N,S,E,V
    if(dfs(i+1,j,n,m,grid,act))
        act++;

    if(dfs(i-1,j,n,m,grid,act))
        act++;

    if(dfs(i,j-1,n,m,grid,act))
        act++;

    if(dfs(i,j+1,n,m,grid,act))
        act++;
    return 1;
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    viz.resize(n,vector<int>(m,0));

    if (n==0 || m==0)
        return 0;

    int rasp=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 and viz [i][j]==0){
                int act = 1; //daca se gaseste un patrat nedescoperit, se cauta patrate vecine
                dfs(i,j,n,m,grid,act);
                rasp = max(rasp,act);
            }
        }
    }

    return rasp;


}
int main() {

    int n = 2, m = 3;

vector<vector<int>> grid = {
        {0,1,1,1,0},
        {1,0,1,1,0},
        {1,1,1,1,1}
};
cout<<maxAreaOfIsland(grid);

        return 0;
}