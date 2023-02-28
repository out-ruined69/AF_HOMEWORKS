#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//sortare topologica
// O(n+m): n- nre de noduri si m nr de muchii
//EX3
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
    }
/*
 * punctul a
 * */
    if(rasp.size()==n)
        return rasp;
    else
    {   cout<<"nu merhe"<<endl;

        for(auto i:rasp)
            cout<<i<<" ";
        return vector<int>();}


//am ajuns la un raspuns daca marimea raspunului este numarul de cursuri



}

int main() {
    int n=4;
    vector<vector<int>> dislikes ;
    dislikes.resize(n);
    dislikes[0].push_back(1);
    dislikes[0].push_back(0);
    dislikes[1].push_back(2);
    dislikes[1].push_back(1);
    dislikes[2].push_back(3);
    dislikes[2].push_back(2);
    dislikes[3].push_back(3);
    dislikes[3].push_back(1);

    vector<int> rasp = findOrder(n,dislikes);
    for(auto i:rasp)
        cout<<i<<" ";
    return 0;
}
