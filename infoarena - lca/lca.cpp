#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

const int nmax = 100003;
int n, m, eulerian[8 * nmax], eulPoz[nmax], k = 1, nivel[nmax], arbint[8 * nmax];
struct NOD{
    vector <int> fii;
    }nod[nmax];

void read(void);
void buildEuler(int poz);
void buildArbint(int left, int right, int poz);
int query(int qleft, int qright, int left, int right, int poz);

int main(){
    int l, r, x, y;
    read();
    //cout<<"nivele:\n";
    //for(int i = 1; i <= n; i++)
    //    cout<<nivel[i]<<" ";
    //cout<<"\n";
    buildEuler(1);
    //for(int i = 1; i <= k - 1; i++)
    //    cout<<nivel[eulerian[i]]<<" ";
    //cout<<"\n";
    buildArbint(1, k - 1, 1);
    //cout<<"built\n";
    //for(int i = 1; i <= 4 * k + 5; i++)
    //    cout<<arbint[i]<<" ";
    //cout<<"\n";
    //cout<<"here\n";
    while(m--){
        fin>>x>>y;
        l = min(eulPoz[x], eulPoz[y]);
        r = max(eulPoz[x], eulPoz[y]);
        //cout<<"l = "<<l<<", r = "<<r<<"\n";
        //fout<<"here\n";
        fout<<query(l, r, 1, k - 1, 1)<<"\n";
        }
    fin.close();
    fout.close();
    }

void read(void){
    int i, x;
    fin>>n>>m;
    //tt[1] = 0;
    nivel[1] = 0;
    for(i = 2; i <= n; i++){
        fin>>x;
        //tt[i] = x;
        nivel[i] = nivel[x] + 1;
        nod[x].fii.push_back(i);   
        }
    }

void buildEuler(int poz){
    eulerian[k] = poz;
    eulPoz[poz] = k++;
    for(int i = 0; i < nod[poz].fii.size(); i++){
        buildEuler(nod[poz].fii[i]);
        eulerian[k++] = poz;
        }
    }

void buildArbint(int left, int right, int poz){
    //cout<<"left = "<<left<<", right = "<<right<<"\n";
    //cout<<"poz = "<<poz<<"\n";
    if(left == right){
        arbint[poz] = eulerian[left];
        //cout<<"poz = "<<poz<<", eulerian[poz] = "<<eulerian[poz]<<"\n";
        return;
        }
    int mid = (left + right) / 2;
    //cout<<"mid = "<<mid<<", left = "<<left<<", right = "<<right<<"\n";
    buildArbint(left, mid, 2 * poz);
    buildArbint(mid + 1, right, 2 * poz + 1);
    if(nivel[arbint[2 * poz]] < nivel[arbint[2 * poz + 1]])
        arbint[poz] = arbint[2 * poz];
    else arbint[poz] = arbint[2 * poz + 1];
    //arbint[poz] = min(arbint[2 * poz], arbint[2 * poz + 1]);
    }

int query(int qleft, int qright, int left, int right, int poz){
    if(qleft <= left && qright >= right)
        return arbint[poz];
    if(right < qleft || left > qright)
        return 1000000;
    int mid = (left + right) / 2;
    int l = query(qleft, qright, left, mid, 2 * poz);
    //cout<<"l = "<<l<<", pt left = "<<left<<", right = "<<mid<<"\n";
    int r = query(qleft, qright, mid + 1, right, 2 * poz + 1);
    //cout<<"r = "<<r<<", pt left = "<<mid + 1<<", right = "<<right<<"\n";
    if(r == 1000000 && l == 1000000)
        return 1000000;
    else if(r == 1000000)
        return l;
    else if(l == 1000000)
        return r;
    if(nivel[l] < nivel[r]){
        //cout<<"l mai mic\n";
        return l;
        }
    else{
        //cout<<"r mai mic\n";
        return r;
        }
    }