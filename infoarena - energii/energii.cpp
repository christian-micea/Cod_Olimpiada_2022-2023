#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("energii.in");
ofstream fout("energii.out");

int n, w;

void readAndSolve(void);

int main(){
    readAndSolve();
    fin.close();
    fout.close();
    }

void readAndSolve(void){
    int energ, cost, i, k = 1;
    int dp[2][5003];
    fin>>n>>w;
    fin>>energ>>cost;
    n--;
    for(i = 1; i <= energ; i++)
        dp[0][i] = cost;
    /*for(int u = 1; u <= w; u++)
        cout<<dp[0][u]<<" ";
    cout<<"\n";*/
    while(n--){
        fin>>energ>>cost;
        for(i = 1; i <= w; i++){
            if(dp[1 - k][i] && (i - energ >= 0) && (dp[1 - k][i - energ]))
                dp[k][i] = min(dp[1 - k][i], dp[1 - k][i - energ] + cost);
            else if(!dp[1 - k][i] && dp[1 - k][i - energ])
                dp[k][i] = dp[1 - k][i - energ] + cost;
            else if(!dp[1 - k][i] && (i - energ <= 0))
                dp[k][i] = cost;
            else if(dp[1 - k][i])
                dp[k][i] = dp[1 - k][i];
            }
        /*for(int u = 1; u <= w; u++)
            cout<<dp[k][u]<<" ";
        cout<<"\n";*/
        k = 1 - k;
        }
    k = 1 - k;
    if(dp[k][w])
        fout<<dp[k][w];
    else fout<<"-1";
    }