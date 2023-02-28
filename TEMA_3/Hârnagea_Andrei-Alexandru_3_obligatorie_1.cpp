#include <fstream>
#include<iostream>
#include <vector>
#include <queue>
#include <climits>

//EDMONDSKARP O(N*M^2)
using namespace std;
ifstream f("maxflow.in");
ofstream g("maxflow.out");
vector<vector<int>> la;

int cap[1005][1005];
int cap_rez[1005][1005];
int flow[1005][1005];
int viz[1005];
int tata[1005];
int s=1;
queue<int>q;

//folosim bfs pentru a gasi cel mai scurt drum de la s la t
int bfs(int n)
{
    int act,i,k;
    q.push(s);
    viz[s]=1;
    while(q.size())
    {
        act=q.front();
        q.pop();
        if(act!=n)
        {
        for(i=0; i<la[act].size(); i++)
        {
            k=la[act][i];
            if(flow[act][k]<cap[act][k] && viz[k]==0) //putem ajunge la un nod doar daca acesta este neviztat si capacitatea sa ne poate fi utila
            {
                viz[k]=1;
                tata[k]=act;
                q.push(k);
            }
        }
    }}
    if(viz[n]==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*
void taieturamin(int s, int t){
    la_rez = la;
    //cap_rez = cap;


}
*/
int main()
{
    int n,i,j,k,l,a,b,x,m,act;
    long long maxflow=0;
    f>>n>>m;
    la.resize(10005);
    for(i=1; i<=m; i++)
    {
        f>>a>>b>>x;
        cap[a][b]=x;
        la[a].push_back(b);
        la[b].push_back(a);
    }
    /*
    for(int i=1;i<=n;i++){

        cout<<i<<" ";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<cap[i][j]<<" ";
        }
        cout<<endl;
    }
*/

    //algoritmul se opreste cand ajunge la nodul final
    while(bfs(n)==1) //daca mai exista un lanturi nevizitate
    {
        for(i=0; i<la[n].size(); i++)
        {
            k=la[n][i];
            tata[n]=k;
            if(viz[k]==1)
            {
                int flux=INT_MAX;
                //Se parcurge lantul de doua ori, odata pentru a cauta capacitatea minima,
                //si dupa pentru a updata muchiile din lant pentru urmatoarele fluxuri
                act=n;
                while(act!=s)
                {
                    flux=min(flux,cap[tata[act]][act]-flow[tata[act]][act]); //cauta minimul dintre urmatoarul nod si cel pe care il are acum
                    act=tata[act];
                }
                if(flux!=0)
                {
                    act=n;
                    while(act!=s)
                    {
                        flow[tata[act]][act]=flow[tata[act]][act]+flux;
                        flow[act][tata[act]]=flow[act][tata[act]]-flux;
                        //capacitatea muchiei din graful initial scade, iar muchia inversa creste
                        act=tata[act];
                    }
                }
                maxflow=maxflow+flux;
            }
        }
        for(i=1; i<=n; i++)
        {
            viz[i]=0;
        }
    }
    cout<<maxflow;
    return 0;
}