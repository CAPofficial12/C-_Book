#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> road(100);
    vector<int> spee(100);

    int last_dist = 0;
    for (int i = 0; i < n; i++){
        int dist, limit;
        cin >> dist >> limit;
        road[last_dist] = limit;
        last_dist += dist;
    }

    last_dist = 0;
    for (int i = 0; i < m; i++){
        int dist, speed;
        cin >> dist >> speed;
        spee[last_dist] = speed;
        last_dist += dist;
    }

    int speed_limit = 0;
    int Bspeed = 0;
    int max = 0;
    for (int i = 0; i < 100; i++){
        if (road[i] != 0){
            speed_limit = road[i];
        }

        if(spee[i] != 0){
            Bspeed = spee[i];
        }

        if (max < Bspeed - speed_limit){
            max = Bspeed - speed_limit;
        }
    }

    cout << max;
    return 0;
}