/*
    SPOJ Problem: https://www.spoj.com/problems/EXPEDI/
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

int main() {
    int t, D, F;
    cin >> t;

    while(t--) {
        int flag = 0, count = 0;
        priority_queue<int> maxHeap;
        int n;
        cin >> n;
        vector<pair<int, int> > v(n); // {distance from town, fuel}
        for(int i = 0; i < n; i++) 
            cin >> v[i].first >> v[i].second;

        // sort the fuel stations based on distance from the town.
        // the one farthest from the city will be closest to the truck.
        sort(v.begin(), v.end(), compare);
        cin >> D >> F;

        // update the distance of the fuel stations from the truck.
        for(int i = 0; i < n; i++)
            v[i].first = D - v[i].first;
        
        // prev denotes the previously visited fuel station
        int prev = 0, curr = 0;
        while(curr < n) {
            // if we have enough fuel to reach the next station
            if((v[curr].first - prev) <= F) {
                F -= (v[curr].first - prev);
                maxHeap.push(v[curr].second);
                prev = v[curr].first;
            }
            else {
                // previously encountered fuel stations
                if(maxHeap.empty()) {
                    flag = 1;
                    break;
                }
                else {
                    // refuel the truck with fuel station highest amount of fuel
                    F += maxHeap.top();
                    maxHeap.pop();
                    count++;
                    continue;
                }
            }
            curr++;
        }
        // you have covered all the fuel stations
        // try to reach the town from here
        if(flag) {
            cout << -1 << '\n';
            continue;
        }
        
        D -= v[n - 1].first;
        if(F >= D) {
            cout << count << '\n';
            continue;
        }
        // refuel your truck
        while(F < D) {
            if(maxHeap.empty()) {
                flag = 1;
                break;
            }
            F += maxHeap.top();
            maxHeap.pop();
            count++;
        }

        if(flag) {
            cout << -1 << '\n';
            continue;
        }
        cout << count << '\n';
    }
    return 0;
}
