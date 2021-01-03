#include <bits/stdc++.h>
using namespace std;

void fun(vector<vector<int>>& v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout<< v[i][j] << " ";
        }
    }
}

int main() {
	
   vector<vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   
   fun(v);
   return 0;
}
/*
    #include <bits/stdc++.h>
    using namespace std;

    void fun(int *arr, int M, int N){
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cout<< *((arr + i * N) + j) << " ";
            }
        }
    }

    int main() {
        
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    fun(&arr[0][0], 3, 3);
        
        
        return 0;
    }
*/
	
	