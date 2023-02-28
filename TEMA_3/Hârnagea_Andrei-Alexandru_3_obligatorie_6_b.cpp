#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//O(N*M)

string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    //acelasi algoritm ca si la LCS
    int sol[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i == 0)
                sol[i][j] = j;
            else if(j == 0)
                sol[i][j] = i;
            else if(str1[i - 1] == str2[j - 1])
                sol[i][j] = 1 + sol[i - 1][j - 1];
            else
                sol[i][j] = 1 + min(sol[i - 1][j], sol[i][j - 1]);
        }
    }


    string rasp;


    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        //daca litera la care ne aflam este si in str1 si str2, o adaugam la stringul final
        if (str1[i - 1] == str2[j - 1])
        {
            rasp.push_back(str1[i - 1]);
            i--;
            j--;
        }

            //daca caracterele sunt diferite il alegem pe cel care are valoarea mai mare in matrice
        else
            if (sol[i - 1][j] > sol[i][j - 1])
        {
            rasp.push_back(str2[j - 1]);
            j--;
        }
        else
        {
            rasp.push_back(str1[i - 1]);
            i--;
        }
    }


    //daca mai raman caractere de la oricare string, le adaugam la final

    while (i > 0)
    {
        rasp.push_back(str1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        rasp.push_back(str2[j - 1]);
        j--;
    }


//intoarcem stringul
    reverse(rasp.begin(), rasp.end());
    return rasp;
}

int main() {

    cout << shortestCommonSupersequence("HELLO", "GEEK");

    return 0;
}