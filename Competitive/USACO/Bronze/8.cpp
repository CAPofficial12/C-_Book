#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){ 
    int n,m;
    cin >> n >> m;
    vector<string> spotty_genomes(n);
    vector<string> plain_genome(n);

    for(auto& i:spotty_genomes){
        cin >> i;
    }

    for(auto& i:plain_genome){
        cin >> i;
    }

    int count = 0;
    for(int a = 0;  a < m; a++){
        for(int b = a+1; b < m; b++){
            for(int c = b+1; c < m; c++){
                vector<string> triplet;
                for(int i = 0; i < n; i++){
                    string trip = "";
                    string genome = spotty_genomes[i];
                    trip += genome[a];
                    trip += genome[b];
                    trip += genome[c];
                    triplet.push_back(trip);
                }

                auto h = triplet[0];
                bool flag = false;
                for(auto& s:triplet){
                    if(s != h){
                        flag = true;
                    }
                }

                /*for(int i = n; i < 2*n; i++){
                    string trip = "";
                    string genome = plain_genome[i-n];
                    trip += genome[a];
                    trip += genome[b];
                    trip += genome[c];
                    if(trip == h){
                        flag = true;
                    }
                }
                */   
                if (flag = false){
                    count += 1;
                }
            }
        }
    }
    cout << count;
    return 0;
}