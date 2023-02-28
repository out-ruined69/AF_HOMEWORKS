#include <iostream>
#include<vector>
#include<queue>
#include <string.h>
#include<list>
using namespace std;
//O(N+M) ex1
vector<vector<int>> possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<int> viz(n+1);
    fill(viz.begin(),viz.end(),0);
    bool k=true;
    vector<int> la[n+1];

    for(int i=0;i<dislikes.size();i++){
        la[dislikes[i][0]].push_back(dislikes[i][1]);
        la[dislikes[i][1]].push_back(dislikes[i][0]);

    }
    //trasformam dislikes intr-o la
    //modificam vizita sa fie cu 1/-1
    for(int i=1;i<=n;i++) {
        if(viz[i]==0)
        {

            viz[i]=1;
            list<int> q;
            q.push_back(i); //daca nodul nu-i vizitat il bagam in stiva
            while(!q.empty()) {
                int vf=q.front(); //se ia varful stivei
                q.pop_front();
                for(int i : la[vf]){ //se iau la rand nodurile din lista de adiacenta a varfului
                    if(viz[vf] * viz[i] >0) //daca e 1 langa 1 sau -1 langa -1
                        k=  false;
                    if(viz[i]==0)
                    {
                        viz[i] = -viz[vf]; //ia valoare negativa a varfului
                        q.push_front(i); //se adauga un nod in stiva
                    }
                }
            }
        }
    }

    vector<vector<int>> gr(2);


    //separam nodurile dupa vizita
    if(k==true)
    {
        for (int i = 1; i < viz.size(); i++) {
            if (viz[i] < 0)
                gr[0].push_back(i);
            else
                gr[1].push_back(i);
        }
    }
    else
    {
        return {};
    }

    return gr;
    //return true;


}



int main()
{
    int n=4;
    vector<vector<int>> dislikes ;
    dislikes.resize(3);
    dislikes[0].push_back(1);
    dislikes[0].push_back(2);
    dislikes[1].push_back(1);
    dislikes[1].push_back(3);
    dislikes[2].push_back(2);
    dislikes[2].push_back(3);
/*
    cout<<dislikes[0][0]<<" "<<dislikes[0][1]<<endl;
    cout<<dislikes[1][0]<<" "<<dislikes[1][1]<<endl;
    cout<<dislikes[2][0]<<" "<<dislikes[2][1]<<endl;
*/
    vector<vector<int>> gr = possibleBipartition(n,dislikes);

    for (auto i: gr)
    {
        for (auto j: i)
            cout << j << " ";
        cout<<endl;
    }
    return 0;
}
