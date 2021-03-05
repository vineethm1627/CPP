#include<bits/stdc++.h>
using namespace std;

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    long long int product = 1;
    vector<long long int> result(n), suffix(n);
    suffix[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] * nums[i + 1];
    
    for(int i = 0; i < n; i++) {
        result[i] = product * suffix[i];
        // build the prefix product
        product *= nums[i];
    }
    return result;
}

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
            cin>>arr[i];
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}


