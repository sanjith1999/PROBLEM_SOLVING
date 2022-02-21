#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Compare(char a,char b){
    if (a>b){return 0;}
    if (a==b){return 1;}
    return 2;

}

int main() {
    string patient;
    string names[100];
    int p,n=0,ref=1;

    cin>> patient;
    cin>> p;
    cin>> n;

    for (int i=0;i<n-1;i++){
        cin>>names[i];
    }

    for (int i=0;i<n-1;i++){
        for (int j=0;j<patient.size();j++){
            if (Compare(patient[j],names[i][j])==0){ref+=1;break;}
            else if (Compare(patient[j],names[i][j])==2){break;}
        }
    }


    int position=0;
    if(ref%p){position=ref/p + 1;}
    else{position=ref/p;}

    cout<<position*20;
    return 0;
}
