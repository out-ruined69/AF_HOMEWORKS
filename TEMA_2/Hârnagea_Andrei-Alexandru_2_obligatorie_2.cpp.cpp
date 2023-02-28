#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("disjoint.in");
ofstream g("disjoint.out");

vector <int> arb;
//o(m)

int radacina(int x) { //gaseste radacina
    if(arb[x]==0)
        return x;
    return arb[x]= radacina(arb[x]);
}


void reuniune(int x, int y) {
    int rad_x = radacina(x);
    int rad_y = radacina(y);
    //actualizam radacina
    if(x>y) //cel mai mic
        arb[rad_x] = rad_y;//se unsec arborii in fct de cine e mai mic
    else
        arb[rad_y] = rad_x;
}

int main() {
    int n,m,x,y,op;
    f>>n>>m;
    arb.resize(n+1,0);

    for(int i=0;i<m;i++){
        f>>op>>x>>y;

        if(op==1)
            reuniune(x,y);
        else
        if(radacina(x)==radacina(y)) //daca au acelasi stramos fac parte din ac arbore
                g<<"DA"<<"\n";
            else
                g<<"NU"<<"\n";

    }


    f.close();
    g.close();



    return 0;
}
