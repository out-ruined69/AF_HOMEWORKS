#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//O(n+m)
long long maxm = -2147483647;
fstream f("easygraph.in");
ofstream  g("easygraph.out");

vector<int> la[15005];
int v[15005];
long long dist[15005];
bool viz[15005];

//dfs modificat, cauta prin nodurile vecine cea mai mare suma
void dfs(int nod) {
    viz[nod]=1;
    dist[nod]=v[nod];
    for(auto i : la[nod]){
        if(!viz[i]){
            dfs(i);
        }
        dist[nod] = max(dist[nod], dist[i]+v[nod]); //se verifica daca s-a gasit o sub-distanta mai mare

    }
    maxm = max(maxm, dist[nod]);
}//in caz daca se gaseste un drum mai lung

int main() {

    int t,n,m;

    f>>t;

    for(int i=1;i<=t;i++){
        f>>n>>m;
        int x,y;
        for(int j=1;j<=n;j++){
            f>>x;
            v[j]=x;
            viz[j]=0;
            dist[j] = 0;
            la[j].clear(); //initializare
        }

        for(int j=1;j<=m;j++){
            f>>x>>y;
            la[x].push_back(y);
        }
//se cauta noduri nevizitate
        for(int j=1;j<=n;j++)
            if(!viz[j])
                dfs(j);
            g<<maxm<<"\n";


        maxm=-2147483647;
    }

    f.close();
    g.close();

    return 0;
}
