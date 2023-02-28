#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
using namespace std;
//O(E SQRT(V)) - Alg lui HopcroftKarp
fstream f("cuplaj.in");
ofstream g("cuplaj.out");

//string crapa="crapa";
int n,m,e;
vector<vector<int>> la;
queue<int>coada;
vector<int> pairst, pairdr;
int sol;
int dist[20001]; //mentine distanta nodurilor din partea stanga
int u, v;

bool BFS(){
   // cautam nodurile libere si le adaugam in coada pentru a incepe cu ele
    for(int i=1;i<=n;i++){
        if(pairdr[i] == 0){
            dist[i]=0;
            coada.push(i);
        }
        else
        {
            dist[i] = INT_MAX;
        }
    }
    dist[0] = INT_MAX;
    //ii setam distanta catreinfinit pentru a fi luata urmatoarea data
    while(!coada.empty()){ //in coada sunt noduri din partea stanga
        u = coada.front();
        coada.pop();
        if(dist[u]<dist[0]){ //daca nodul nu e 0 si e un drum mai scurt catre 0
            for(auto v: la[u]){
                if(dist[pairdr[v]] == INT_MAX){
                    dist[pairdr[v]] = dist[u] + 1;
                    coada.push(pairst[v]);
                }
            }
        }
    }

    return dist[0]!=INT_MAX;
}

bool DFS(int nod){ //daca BFS-ul este adevarat, putem updatat nodurile cu drumurile minime gasite de la nod la vecin, deci folosim un dfs

    if(nod!=0)
    {
        for(auto vecin:la[nod]){
            if(dist[pairst[vecin]]==dist[nod]+1){
                if(DFS(pairst[vecin])==true){
                    pairdr[nod]=vecin;
                    pairst[vecin] = nod;
                    return true;
                }
            }
        }
        //nu exista drum
        dist[nod]=INT_MAX;
        return false;
    }
    return true;
}

int HopcroftKarp(){

    //pairst mentine perechile din partea stanga, iar pairdr mentine perechile nodurile din partea dreapta

    pairst.resize(20001,0);
    pairdr.resize(20001,0);
    sol=0;
    //cout<<"asd";
    while(BFS()==true){
        for(int i=1;i<=n;i++){
            if(pairst[i]==0){
                if(DFS(i)== true){
                    sol++;
                }
            }
        }
    }
    return sol;
}

int main() {

    f>>n>>m>>e;
    //cout<<n;
    la.resize(200001);
    for(int i=1;i<=e;i++){
        int x,y;
        f>>x>>y;
        la[x].push_back(y);
    }

/*
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(auto vecini:la[i]){
            cout<<vecini<<" ";
        }
        cout<<endl;
    }
    */
//cout<<crapa;

    cout<<HopcroftKarp()<<endl;

    for(int i=1;i<=m;i++){
        if(pairst[i])
            cout<<pairst[i]<<" "<<i<<endl;
    }

    return 0;
}
