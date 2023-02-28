#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;
//O(N+M) , problema ne cere sa gasim un drum care foloseste toate nodurile din graf
void euler(unordered_map<int, stack<int>>&la, vector<vector<int>>&sol, int act){
    //DFS modificat, dupa ce trecem peste o muchie o stergem, putem trece peste acelasi nod de mai multe ori
    //folosim dfs pentru a parcurge toate muchiile, si ca sa facem mini-drumurile euleriene complete
    auto & i = la[act];
    while(!i.empty()){
        int vf = i.top();
        i.pop();
        euler(la, sol, vf);
        sol.push_back({act, vf});
    }
}

vector<vector<int>> validArrangement(vector<vector<int>>& pairs){
    int n = pairs.size();
    unordered_map<int, int> grad_int;
    unordered_map<int, int> grad_ext;
    unordered_map<int, stack<int>> la;

    grad_int.reserve(n);
    grad_ext.reserve(n);
    la.reserve(n);

    for(int i=0;i<n;i++){
        grad_int[pairs[i][1]]++;
        grad_ext[pairs[i][0]]++;
        la[pairs[i][0]].push(pairs[i][1]);
        //initializare
    }

    //prima oara cautam nodul de inceput

    int start = -1;
    for(auto& i: la){
        int j=i.first;
            if(grad_ext[j] - grad_int[j]==1 ) //nodul de incepute este acela are are cradul exterior mai mare
                start = j;
    }

    if(start == -1) //daca e circuit eulerian putem incepe de la orice nod
    {
        start = la.begin()->first;
    }

    vector<vector<int>> rasp;
    euler(la, rasp, start);
    reverse(rasp.begin(), rasp.end());
    return rasp;



}
int main() {

    return 0;
}
