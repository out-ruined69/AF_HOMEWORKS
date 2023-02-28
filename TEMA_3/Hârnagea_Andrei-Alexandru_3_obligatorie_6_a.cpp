#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//O(N*M)

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    int sol[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0)
                sol[i][j] = 0; //marcam marginile

            else
            if(text1[i-1] == text2[j-1])
                sol[i][j] = sol[i-1][j-1] + 1; //marcam in matrice literele identice
            else
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
        }
    }

    return sol[m][n]; //raspunsul este in coltul matricei


}

int main() {

    cout << longestCommonSubsequence("AGGTAB", "GXTXAYB");

    return 0;
}