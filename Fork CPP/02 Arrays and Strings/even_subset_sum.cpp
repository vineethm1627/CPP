#include<bits/stdc++.h>
using namespace std;

int countSumSubsets(int[], int);

int countSumSubsets(int arr[], int N){
    int count = 0;
    for(int i = 1; i < pow(2, N); i++) {
        int sum = 0;
        int temp = i, j = 0;
        while(temp) {
            if(temp & 1)
                sum += arr[j];
            j++;
            temp = temp >> 1;
        }
        if(sum % 2 == 0 && sum != 0){
            count++;
        }
    }
    return count;
    
}

int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    int arr[N];
	    for(int i = 0;i<N;i++){
	            cin >> arr[i];
	        }
	    
	    cout << countSumSubsets(arr, N) << endl;
	}
	
	return 0;
}