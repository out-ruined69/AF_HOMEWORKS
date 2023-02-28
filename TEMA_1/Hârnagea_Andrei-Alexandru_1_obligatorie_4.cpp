#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

ifstream f("ctc.in");
ofstream g("ctc.out");
//algoritmul lui Kosaraju, O(N+M)
//EX4

int n,m,nrctc;
int viz[100005];
vector<vector<int>> la,laT,rez(100000);
stack <int> q;
//se creeaza o stiva goala si parcurge graful folosind un dfs, in stiva se introduc nosurile in ordinea in care sunt gasite in dfs

void DFS(int n)
{
        viz[n]=1;
        for(int i=0;i<la[n].size();i++){
            int aux = la[n][i];

            if(!viz[aux])
                DFS(aux);
        }
        q.push(n);
    //se adauga nodurile vizitate la intoarcerea din recursivitate
}

void DFST(int n){

    // marcam ca l-am vizitat de doua ori pe nod, si adaugam pe pozitie nodul
    viz[n]=2;
    rez[nrctc].push_back(n);

    for(int i=0;i<laT[n].size();i++) {
        int aux = laT[n][i];
        //dfs la urmatorul vecin
        if(viz[aux]==1)
            DFST(aux);
    }


}
int main() {

    f>>n;
    f>>m;

    la.resize(n+1);
    laT.resize(n+1);

    for(int i=1;i<=m;i++)
    {
        int x,y;
        f>>x>>y;
        la[x].push_back(y);
        laT[y].push_back(x);
        //se construieste transpusa grafului

    }

    //daca nodul e nevizitat, atunci il marcam ca si vizitat,
    //vizitam fiecare vecin nevizitat al acestuia, si il adaugam in stiva
    for(int i=1;i<=n;i++)
        if(!viz[i])
            DFS(i);

    //golim elementele din stiva, daca elementul este nevizitat, at pornim un DSF in
    // graful transpus. pt fiecare nou DFST se adauga o componenta conexa
    while(!q.empty()) {
        int nod = q.top();
        if (viz[nod] == 1) {
            nrctc++;
            DFST(nod);

        }
        q.pop();
    }

    g<<nrctc<<endl;
    for(int i=1;i<=nrctc;i++) {
        for(int j=0;j<rez[i].size();j++)
            g<<rez[i][j]<<" ";
        g<<endl;
    }

return 0;
}
