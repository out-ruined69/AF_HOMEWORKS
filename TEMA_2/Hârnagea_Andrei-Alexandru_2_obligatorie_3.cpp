#include <iostream>
#include<string>
#include<fstream>
#include <vector>
#include<map>
#include<algorithm>
//O(N*N)
using namespace std;
fstream f("citire.txt");

vector <pair<string, int>> la;
vector <string> cuv;
string s1;
int ct=0;


int lev(string s1, string s2)
{

    int t;
    int dif;
    int l1= s1.length();
    int l2 = s2.length();

    int dist[50][50];


    for(int i=0;i<=l1;i++){
        dist[0][i] = i;
    }

    for(int i=0;i<=l2;i++){
        dist[i][0] = i;
    }

    for(int j=1;j<=l1;j++) {
        for (int i = 1; i <= l2; i++) {
            if (s1[i - 1] == s2[j - 1])
                dif = 0;
            else
                dif = 1;

            t = min((dist[i - 1][j] + 1), (dist[i][j - 1] + 1));
            dist[i][j] = min(t, (dist[i-1][j-1]+dif));
        }
    }

    return dist[l2][l1];
}

int main() {
/*
    cout<<lev("minim","arbore")<<endl;
    cout<<lev("martian","minim")<<endl;
    cout<<lev("care","minim")<<endl;
*/
    vector<int> clase;
    string s;

    int cls = 0;
    while (f >> s) {
        cuv.push_back(s);
        clase.push_back(cls++);
    }


    int k;
    cin >> k;

    int dist[100][100];		//facem o matrice de distante
    for (int i = 0; i < cuv.size(); i++) {
        for (int j = 0; j < cuv.size(); j++) {
            if (i < j)
                dist[i][j] = lev(cuv[i], cuv[j]);

        }
    }


    for (int i = 0; i < cuv.size() - k; i++) {
        int distantaMin = 2147483647;
        int cl1, cl2;
        for (int j = 0; j < cuv.size(); j++) {	//gasim cele doua cuv cu cea mica distanta si care sunt din clase diferite
             for (int h = 0; h < cuv.size(); h++) {
                if (i < j && clase[i] != clase[j] && dist[i][j] < distantaMin) {
                    distantaMin = dist[i][j];
                    cl1 = clase[i];
                    cl2 = clase[j];
                    //le retinem clasele
                }
            }
        }
    if(cl1<cl2){
        int aux;
        aux=cl1;
        cl1=cl2;
        cl2=aux;
    }
        for (int j = 0; j < clase.size(); j++) {	// facem reuniunea celor doua clase
            if (clase[j] == cl2)
                clase[j] = cl1;
        }
    }

    int distMinClase = 2147483647;
    for (int i = 0; i < cuv.size(); i++) {
        for (int j = 0; j < cuv.size(); j++) {
            if (i < j) { //cautam sub diagonala principala ca sa nu repete cuvinte
                if (clase[i] != clase[j])
                    distMinClase = min(distMinClase, dist[i][j]); //cautam distanta minicma dintre doua clase
            }
        }
    }

    vector<pair<int, string>> cuvclasa;

    for(int i=0;i<clase.size();i++)
    {
        cuvclasa.push_back({clase[i],cuv[i]});
    }


    sort(cuvclasa.begin(),cuvclasa.end());

    int init = clase[0];

    for(int i=0;i<cuvclasa.size();i++)
    {
        if(cuvclasa[i].first!=init)
            cout<<endl;
        cout<<cuvclasa[i].second<<" ";
        init = cuvclasa[i].first;
    }
    cout<<endl;
    cout << distMinClase;
    return 0;
}
