#include <iostream>
#include <queue>
#include <vector>
using namespace std;


double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//o(n *m)
    vector <pair<int,double>> la[n];

    for(int i=0;i<edges.size();i++)
    {
        la[edges[i][0]].push_back({edges[i][1], succProb[i]});
        la[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }

    vector<double> prob(n,0);

    priority_queue<pair<double,int>> coada;
    coada.push({1,start});
//dijkstra modificat
    while(!coada.empty()){
        double prob_curenta = coada.top().first;
        int nod_curent = coada.top().second;
        coada.pop();

        if(nod_curent == end)
            return prob_curenta;

        for(auto i : la[nod_curent]){
            if(prob_curenta * i.second > prob[i.first]){
                prob[i.first] = prob_curenta * i.second; //am modifcat astefel incat sa returneze maximul
                coada.push({prob[i.first], i.first}); //se adauga urmatorul nods
            }

        }


    }
    return 0;
}


int main() {
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    cout<<maxProbability(3,edges,succProb,0,2);

    return 0;
}
