#include <iostream>
#include<vector>
#include<queue>
#include <string.h>
#include<list>
using namespace std;
//EX3 B O(N+M)
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){

    int n=numCourses;
    vector<vector<int>> la(n);
    vector<int> rasp;
    vector<int> gradint(n,0);

    for(auto i:prerequisites){
        la[i[1]].push_back(i[0]);
        gradint[i[0]]++;
    }
    //se creeaza o lista de adiacenta si un vecotr care memoreaza gradul intern al nodurilor
    queue<int> q;

    for(int i=0;i<n;i++)
        if(gradint[i]==0)
            q.push(i);
    //se creeaza o stiva cu nodurile care pot fi "capete"
    while(!q.empty())
    {
        int aux=q.front();
        q.pop();
        rasp.push_back(aux); //se adauga varful stivei si se adauga rezultatul la ans
        for(auto i:la[aux]) {
            if(--gradint[i]==0) //decrementan copilul nodului, si daca gradul interior al acestuia e zero, il putem baga in stiva
                q.push(i);
        }
        n--;
    }

    if(n!=0)
        return rasp;
    else return {};

}

int main()
{
    int n=2;
    vector<vector<int>> dislikes ;
    dislikes.resize(n);
    dislikes[0].push_back(1);
    dislikes[0].push_back(0);
    dislikes[1].push_back(0);
    dislikes[1].push_back(1);

    vector<int> rez=findOrder(n,dislikes);

    for(auto i:rez){
        cout<<i<<" ";
    }

    return 0;
}
