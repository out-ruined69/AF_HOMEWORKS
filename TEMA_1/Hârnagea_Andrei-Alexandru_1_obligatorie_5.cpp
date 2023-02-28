#include<iostream>
#include<fstream>
#include<vector>
#include<list>

using namespace std;
#define INF 2147483647
ifstream f("file.in");

//O(n*m) EX5

bool BFS(vector<int> la[], int n, int sur, int dest, int dist[])
{
    //un bfs modificat
    list<int> q;
    bool viz[n+1];

    for (int i = 1; i <= n; i++) {
        viz[i] = false;
    }

    viz[sur] = true;
    dist[sur] = 0; //distanta de la sursa la ea insusi e 0
    q.push_back(sur);

    while(!q.empty())
    {
        int s;
        s= q.front();
        q.pop_front();
        for(int i=0;i<la[s].size();i++)
        {
            if(viz[la[s][i]]==false)
            {
                viz[la[s][i]] = true;
                dist[la[s][i]] = dist[s]+1; //distanta pana la nod este distanta pana la tata +1
                q.push_back(la[s][i]);

                if(la[s][i] == dest)
                    return true;
            }
        }

    }

    return false;
}


int distMin(vector<int> la[], int n, int sur, int dest)
{
    int dist[n];

    if(sur==dest)
        return 0;

    if (BFS(la, n, sur, dest, dist) == false) {
        return -1;
    }

    return dist[dest];

}


int main()
{
    int n ,m;
    f>>n;
    f>>m;
    vector<int> la[n+1];
    vector<int> u;

    for(int i=0;i<11;i++)
        {
            int x,y;
            f>>x;
            f>>y;
            la[x].push_back(y);
            la[y].push_back(x);

        }
    u.push_back(8);
    u.push_back(9);

    for(int i=1;i<=n;i++)
    {
        int m=-1;

        for(int j=0;j<u.size();j++)
        { //aleg distanta minima
            if(u[j]==i)
                m=0;
            else
            if(m==-1)
                m=distMin(la,n,u[j],i);
                    else
                        if(m>distMin(la,n,u[j],i))
                            m=distMin(la,n,u[j],i);

            //cout<<"sursa " <<u[j]<<" dest "<<i<<" dist "<<distMin(la,n,u[j],i)<<endl;
        }

        cout<<m<<" ";
    }

    return 0;
}
