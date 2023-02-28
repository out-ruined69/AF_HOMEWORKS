#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
//O((2^N)*N*N)
int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    int mascaTot = (1<<n)-1;
    queue<pair<int,pair<int,int>>>coada; //  <nod actual <distanta, masca>>
    set<pair<int, int>> viz; //nodul curent, masca ca si traseu

    for(int i=0;i<n;i++){
        coada.push({i, {0, 1<<i}});
        viz.insert({i, 1<<i});
    }
        //BFS MODIFICAT
    while(!coada.empty()){
        pair<int,pair<int,int>> act = coada.front();
        coada.pop();
        int nod = act.first;
        int dist = act.second.first;
        int masca = act.second.second;

        if(masca == mascaTot)
            return dist;
        for(auto vecin : graph[nod]){
            int mascaUrm = masca | ( 1<< vecin); //masca urmatorului nod pe care il vom vizita depinde de actualul nod
            if(! viz.count({vecin,mascaUrm})){
                coada.push({vecin, {dist+1, mascaUrm}});
                viz.insert({vecin, mascaUrm});
            }
        }

    }
    return 0;


}

int main() {

    return 0;
}
