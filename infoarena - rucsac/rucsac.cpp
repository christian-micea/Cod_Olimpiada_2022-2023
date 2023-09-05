#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

const int nmax = 10003;
int n, g, dp[2][nmax];
struct obiecte{
    int greutate;
    int pret;
    }v[nmax];

void read(void);
void solve(void);

int main(){
    read();
    solve();
    fin.close();
    fout.close();
    }

void read(void){
    int i;
    fin>>n>>g;
    for(i = 1; i <= n; i++)
        fin>>v[i].greutate>>v[i].pret;
    }

void solve(void){
    int k = 1, i, j;
    for(i = v[1].greutate; i <= g; i++)
        dp[0][i] = v[1].pret;
    for(i = 2; i <= n; i++){
        for(j = 1; j <= g; j++){
            if(j - v[i].greutate >= 0){
                dp[k][j] = max(dp[1 - k][j], (dp[1 - k][j - v[i].greutate] + v[i].pret));
                }
            else dp[k][j] = dp[1 - k][j];
            }
        k = 1 - k;
        }
    k = 1 - k;
    fout<<dp[k][g];
    }