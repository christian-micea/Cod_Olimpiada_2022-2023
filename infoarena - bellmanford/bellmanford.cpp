#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

const int nmax = 50003, oo = 1000000;
int n, m, d[nmax], frecv[nmax];
bool isInQ[nmax];
vector <pair<int, int>> v[nmax];
queue <int> q;

void read(void);
int bellmanFord(int start);

int main(){
    int i;
    read();
    if(!bellmanFord(1))
        fout<<"Ciclu negativ!";
    else for(i = 2; i <= n; i++)
            fout<<d[i]<<" ";
    fin.close();
    fout.close();
    }

void read(void){
    int x, y, z;
    fin>>n>>m;
    while(m--){
        fin>>x>>y>>z;
        v[x].push_back(make_pair(y, z));
        }
    }

int bellmanFord(int start){
    int i, j, nod;
    for(i = 1; i <= n; i++){
        d[i] = oo;
        isInQ[i] = false;
        }
    d[start] = 0;
    isInQ[start] = true;
    q.push(start);
    while(!q.empty()){
        nod = q.front();
        q.pop();
        isInQ[nod] = false;
        if(++frecv[nod] > n)
            return 0;
        for(i = 0; i < v[nod].size(); i++){
            int vecin = v[nod][i].first;
            int cost = v[nod][i].second;
            if(d[nod] + cost < d[vecin]){
                d[vecin] = d[nod] + cost;
                if(!isInQ[vecin]){
                    isInQ[vecin] = true;
                    q.push(vecin);
                    }
                }
            }
        }
    return 1;
    }