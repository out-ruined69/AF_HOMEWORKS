#include <fstream>
#include<iostream>
#include <vector>
#include <queue>
#include <climits>

//EDMONDSKARP O(N*M^2)
using namespace std;
ifstream f("maxflow.in");
ofstream g("maxflow.out");
vector<vector<int>> la,la_rez;

int m,n;
vector<vector<int>> cap, cap_rez;
int flow[1005][1005];
vector<int> viz;
int tata[1005];
int s=1;
queue<int>q;

//folosim bfs pentru a gasi cel mai scurt drum de la s la t
bool BFS(int s, int t)
{
    vector<bool> viz(n+1);
    queue<int> coada;
    coada.push(s);
    viz[s]=1;
    tata[s]=-1;
    while(!coada.empty())
    {
        int u=coada.front();
        coada.pop();
        for(auto vecin:la[u])
        {
            if(viz[vecin]==0 && cap_rez[u][vecin])
            {
                tata[vecin]=u;
                if(vecin==t)
                    return 1;
                viz[vecin]=1;
                coada.push(vecin);
            }
        }
    }
    return 0;
}

void dfs(int s){
    viz[s]=1;
    for(int i=0;i<n;i++){
        if(cap_rez[s][i] && viz[i]==0)
            dfs(i);
    }
}


void taieturamin(int s, int t){
    la_rez = la;
    cap_rez = cap;
    while(BFS(s,t)==1){
        int u, v;
        int flux = INT_MAX;
        v=t;
        while(v!=s){
            u=tata[v];
            if(cap[u][v]<flux){
                flux = cap_rez[u][v];
            }
            v = tata[v];
        }
        v=t;
        while(v!=s){
            u=tata[v];
            cap_rez[u][v]-=flux;
            cap_rez[v][u]+=flux;
            v=tata[v];
        }
    }
    viz.resize(n+1);
    for(int i=0;i<=n;i++)
        viz[i]=0;
    dfs(s); //ne asigutam ca trecem prin toate nodurile
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(viz[i]==1 && viz[j]==0 && cap[i][j]!=0) //taieturile sunt muchiile care au capacitatea 0, nefiinf necesare
                cout<<i<<" "<<j<<endl;


}

int main()
{
    int i,j,k,l,a,b,x,act;
    long long maxflow=0;
    f>>n>>m;
    s=1;
    la.resize(10005);
    cap.resize(10005, vector<int>(10005));
    la_rez.resize(10005);
    cap_rez.resize(10005, vector<int>(10005));
    viz.resize(10005);
    for(i=1; i<=m; i++)
    {
        f>>a>>b>>x;
        cap[a][b]=x;
        la[a].push_back(b);
        la[b].push_back(a);
    }


    for(int u=2;u<=n;u++){
        cout<<u<<endl;
        taieturamin(s,u);
    }

    return 0;
}