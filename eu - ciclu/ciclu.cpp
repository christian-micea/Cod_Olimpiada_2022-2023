#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("ciclu.in");
ofstream fout("ciclu.out");

int n, m;
vector <int> g[100];
bool viz[100];

void read(void);
void dfsCiclu(int nod, vector <int> st, int tata);

int main(){
    vector <int> st;
    read();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            viz[j] = false;
        dfsCiclu(i, st, 0);
        }
    fin.close();
    fout.close();
    }

void read(void){
    int x, y;
    fin>>n>>m;
    while(m--){
        fin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        }
    }

void dfsCiclu(int nod, vector <int> st, int tata){
    int i, j;
    viz[nod] = true;
    st.push_back(nod);
    /*cout<<"in "<<nod<<"\n";
    for(int j = 0; j < st.size(); j++)
        cout<<st[j]<<" ";
    cout<<"\n";*/
    for(i = 0; i < g[nod].size(); i++){
        if(!viz[g[nod][i]])
            dfsCiclu(g[nod][i], st, nod);
        else if(g[nod][i] != tata){
            for(j = 0; j < st.size(); j++)
                if(st[j] == g[nod][i])
                    break;
            if(j == st.size())
                continue;
            fout<<"ciclu in "<<nod<<": ";
            for(j = st.size() - 1; st[j] != g[nod][i]; j--)
                fout<<st[j]<<" ";
            fout<<g[nod][i]<<"\n";
            }
        }
    }