#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int n,m;
vector <vector<int>> la;
vector <bool> viz(100005,0);
vector <int> sol;
vector<int> v;
int poz[100005];
//PROB 2 O(N*n*LOG N)(SORTARE )
bool f(int x, int y){ //criteriul de comparare
    return poz[x]<poz[y];
}

void dfs(int n){
    if(!viz[n]){
        sol.push_back(n); //adaugam nodurile nevizitate in sol
        viz[n]=true;
        for(int i:la[n])
            if(!viz[i])
                dfs(i);
        //parcurgem graful dfs si daca este un nod nevizitat mergem la el
    }
}

int main(){

    cin>>n>>m;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        poz[a]=i; //memoram pe ce pozitii se afla numerele
    }

    la.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        la[a].push_back(b);
        la[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
        sort(la[i].begin(),la[i].end(),f); //sortam dupa pozitiile din v,
        // incercam sa "matchuim" sol cu v

    dfs(1);
    cout<<(sol==v); //daca sunt identice, inputul este corect
    return 0;
}
