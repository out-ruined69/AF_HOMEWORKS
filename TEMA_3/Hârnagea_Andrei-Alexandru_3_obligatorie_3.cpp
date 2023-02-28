#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
//O(N*M^2)
using namespace std;
ifstream f("harta.in");
ofstream g("harta.out");

vector<vector<int>> la;
int cap[201][201], s, t,n;
vector<int> tata;

bool bfs(){
        //BFS pentru a verifica fluxul maxim
    vector<bool> viz(t);
    queue<int> coada;
    coada.push(s);
    viz[s]=true;
    tata[s]=-1;
    while(!coada.empty())
    {
        int act=coada.front();
        coada.pop();
        for(auto vecin:la[act])
        {
            if(!viz[vecin] && cap[act][vecin])
            {
                tata[vecin]=act;
                if(vecin==t)
                    return true;
                viz[vecin]=true;
                coada.push(vecin);
            }
        }
    }
    return false;
}

int EdomondsKarp(){
    long fluxmax = 0;
    while(bfs()==true){
//cat timp mai exista muchii nevizitate
        int u, v=t;
        int flux = INT_MAX;
        while(v!=s){ //memoram cat putem avea pe acest drum
            u=tata[v];
            if(cap[u][v]<flux) //cautam un nod pe care sa-l putem adauga
                flux=cap[u][v];

            v=tata[v];
        }
        v=t;
        //in flux avem cat putem  adauga de la drum
        while(v!=s){
            u=tata[v];
            cap[v][u]+=flux;
            cap[u][v]-=flux;
            v=tata[v];
        }

        fluxmax+=flux;
    }
    return fluxmax;

}

int main() {

    f>>n;
    s = 0;
    t = 2*n+1;
    la.resize(201);
    tata.resize(2*n+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                la[i].push_back(j+n);
                la[j+n].push_back(i);
                cap[i][j+n]=1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        int x, y;
        f>>x>>y;
        la[s].push_back(i);
        la[i].push_back(s);
        cap[s][i] = x;
        la[t].push_back(i+n);
        la[i+n].push_back(t);
        cap[i+n][t]=y;
    }

    g<<EdomondsKarp()<<endl;
/*
    for(int i=1;i<=n+n;i++){
        for(int j=1;j<=n+n;j++){
            cout<<cap[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cap[j+n][i]==1){
                g<<i<<" "<<j<<endl; //nodurile finale sunt cele care au cap 1
            }
        }
    }

    return 0;
}
