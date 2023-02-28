#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <queue>
#define inf 2147483646
using namespace std;
ifstream f("catun.in");
ofstream g("catun.out");

vector<vector<pair<int,int>>> la;
int fortarete[36005]; //cea mai apropiaza fortareata
int dist[36005]; //distanta pana la cea mai apropaiata fortareata
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;


//O( N LOG M), se foloseste lista de prioritati
void dijkstra() {
    //dijkstra modificat
    while(!q.empty()){
        int cost = q.top().first;
        int nod = q.top().second;
        q.pop();

        for(auto i : la[nod]){ //parcurgem vecinii nodului curent
            int cost_vecin = i.first;
            int vecin = i.second;

            if(cost+cost_vecin < dist[vecin]){ //daca se gaseste un drum mai eficient, se updateaza
                dist[vecin] = cost+cost_vecin;
                fortarete[vecin] = fortarete[nod]; //se actualizeaza vecinul
                q.push({dist[vecin], vecin}); //se adauga vecinul in coada pentru a-i cauta vecinii
            }
            else
                if (cost + cost_vecin == dist[vecin]){
                    fortarete[vecin] = min(fortarete[nod], fortarete[vecin]);
                }
        }
    }

}

int main() {

    int n,m,k;
    f>>n>>m>>k;
    la.resize(n+1);
    for(int i=1;i<=n;i++){
        dist[i] = inf;
    }

    for(int i=0;i<k;i++){ //citim fortaretele
        int fort;
        f>>fort;
        dist[fort] = 0;
        fortarete[fort] = fort;
        q.push(make_pair(0,fort)); //adaugam fortaretele in coada
    }

    for(int i=0;i<m;i++){
        //se creeaza lista de adiacenta, z este pretul
        int x,y,z;
        f>>x>>y>>z;
        la[x].push_back({z,y});
        la[y].push_back({z,x});
    }

    dijkstra();

    for(int i=1;i<=n;i++)
        if(fortarete[i]!=i)
            g<<fortarete[i]<<" ";
        else
            g<<0<<" ";

    f.close();
    g.close();
    return 0;
}
