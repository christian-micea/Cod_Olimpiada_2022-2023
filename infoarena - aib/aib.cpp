#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("aib.in");
ofstream fout("aib.out");

const int nmax = 100003;
int n, m, v[nmax];
//unsigned int aib[nmax];
unsigned int sumPart[nmax]; 

void read(void);
void solveSumPart(void);
//void solveAib(void);
//void update(int index, int val);
//int sum(int index);
//int binSearchAib(int left, int right, int valCautat);
int binSearch(int left, int right, int valCautat);

int main(){
    read();
    //solveAib();
    solveSumPart();
    fin.close();
    fout.close();
    }

void read(void){
    int i;
    fin>>n>>m;
    for(i = 1; i <= n; i++){
        fin>>v[i];
        //update(i, v[i]);
        sumPart[i] = sumPart[i - 1] + v[i];
        }
    }

/*void solveAib(void){
    int x, y, z, i;
    while(m--){
        fin>>x;
        switch(x){
            case 0:
                fin>>y>>z;
                update(y, z);
                break;
            case 1:
                fin>>y>>z;
                fout<<sum(z) - sum(y - 1)<<"\n";
                break;
            case 2:
                fin>>y;
                fout<<binSearchAib(1, n, y)<<"\n";
                break;
            default:
                break;
            }
        }
    }

int sum(int index){
    int suma = 0;
    while(index > 0){
        suma += aib[index];
        index -= (index & -index);
        }
    return suma;
    }

void update(int index, int val){
    while(index <= n) {
        aib[index] += val;
        index += (index & -index);
        }
    }

int binSearchAib(int left, int right, int valCautat){
    int mid, suma;
    while(left <= right){
        mid = (left + right) / 2;
        suma = sum(mid);
        if(suma >= valCautat)
            right = mid - 1;
        else left = mid + 1;
        }
    if(sum(left) == valCautat)
        return left;
    else return -1;
    }*/

void solveSumPart(void){
    int x, y, z, i;
    while(m--){
        fin>>x;
        switch(x){
            case 0:
                fin>>y>>z;
                v[y] += z;
                for(i = y; i <= n; i++)
                    sumPart[i] += z;
                break;
            case 1:
                fin>>y>>z;
                fout<<sumPart[z] - sumPart[y - 1]<<"\n";
                break;
            case 2:
                fin>>y;
                z = binSearch(1, n, y);
                fout<<z<<"\n";
                break;
            default:
                break;
            }
        }
    }

int binSearch(int left, int right, int valCautat){
    int mid, suma;
    while(left <= right){
        mid = (left + right) / 2;
        suma = sumPart[mid];
        if(suma >= valCautat)
            right = mid - 1;
        else left = mid + 1;
        }
    if(sumPart[left] == valCautat)
        return left;
    else return -1;
    /*if(left == right && valCautat == sumPart[left])
        return left;
    else if(left == right)
        return -1;
    int mid = (left + right) / 2;
    int val = binSearch(left, mid, valCautat);
    if(val != -1)
        return val;
    else return binSearch(mid + 1, right, valCautat);*/
    }
