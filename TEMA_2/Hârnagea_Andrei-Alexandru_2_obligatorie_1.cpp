#include <iostream>
#include <fstream>
#include<vector>
#include<math.h>
#include<climits>
#include <cmath>
#include <iomanip>
using namespace std;
fstream f("retea2.in");
ofstream g("retea2.out");

//Complexitate O(N*M), un fel de vector de tati in care initial tatal este cea mai apropiata centrala
//si dupa cel mai apropiat bloc

struct punct{
    int x,y;
};

double calcDist(punct a, punct b){ //functie de calculat distanta
    double aux = (1LL*(a.x-b.x))*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y);
    return sqrt(aux);
}

int main() {

    int n,m;
    f>>n>>m;

    punct blocuri [m+2];
    punct centrale [n+2];
    double distante[m+n+2]; //distanta de la un bloc la o centrala

    vector<bool> viz(m+n,0);

    for(int i=1;i<=n;i++)
        f>>centrale[i].x>>centrale[i].y;

    for(int i=1;i<=m;i++)
        f>>blocuri[i].x>>blocuri[i].y;

    for(int i=1;i<=m;i++){
        distante[i] = calcDist(blocuri[i],centrale[1]);
        for(int j=2;j<=n;j++)
            distante[i] = min(calcDist(blocuri[i],centrale[j]),distante[i]);
        //calculam distanta de la un bloc la cea mai apropiata centrala
    }

    double cost_min = 0, rez=0;

    int poz = 0;

    for(int i=1;i<=m;i++){
        //cautam pentru fiecare bloc cel mai apropriat bloc si ii retinem pozitia, daca acesta este mai aproape decat cea mai apropiata centrala
        cost_min = INT_MAX;
        poz=0;
        for(int j=1;j<=m;j++)
            if(viz[j] == 0 && distante[j] < cost_min)
            {
                cost_min = distante[j];
                poz = j;
            }

        viz[poz] = 1;
        rez += cost_min;
        for(int j=1;j<=m;j++)
            if(!viz[j])
                distante[j]=min(distante[j], calcDist(blocuri[poz],blocuri[j]));  //vedem care e mai mic
    }

    g<<fixed<<setprecision(6)<<rez;


    return 0;
}
