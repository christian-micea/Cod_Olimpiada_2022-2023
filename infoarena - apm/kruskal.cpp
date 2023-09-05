#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

const int mMax = 400003, nMax = 200003;
int n, m, tt[nMax];
struct Muchie{
    int start;
    int finish;
    int cost;
    }muchii[mMax];

void read(void);
void qSort(int left, int right);
void solve(void);
int root(int nod);

int main(){
    read();
    solve();
    fin.close();
    fout.close();
    }

void read(void){
    int i;
    fin>>n>>m;
    for(i = 1; i <= m; i++)
        fin>>muchii[i].start>>muchii[i].finish>>muchii[i].cost;
    qSort(1, m + 1);
    }

void solve(void){
    int i, costFin = 0, nrSol = 0;
    stack <pair<int, int>> st;
    for(i = 1; i <= m; i++){
        if(root(muchii[i].start) != root(muchii[i].finish)){
            tt[root(muchii[i].finish)] = muchii[i].start;
            costFin += muchii[i].cost;
            nrSol++;
            st.push(make_pair(muchii[i].start, muchii[i].finish));
            }
        }
    fout<<costFin<<"\n"<<nrSol<<"\n";
    while(!st.empty()){
        fout<<st.top().first<<" "<<st.top().second<<"\n";
        st.pop();
        }
    }

void qSort(int left, int right){
    if(left < right){
        int i = left;
        int j = right;
        int pivot = (left + right) / 2;
        while(i < j){
            do{
                i++;
                }while(muchii[i].cost <= muchii[left].cost);
            do{
                j--;
                }while(muchii[j].cost > muchii[left].cost);
            if(i < j)
                swap(muchii[i], muchii[j]);
            }
        swap(muchii[left], muchii[j]);
        qSort(left, j);
        qSort(j + 1, right);
        }
    }

int root(int nod){
    if(tt[nod] == 0)
        return nod;
    int r = root(tt[nod]);
    tt[nod] = r;
    return r;
    }