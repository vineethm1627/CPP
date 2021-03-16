/*
    Given n friends whho want to go to a party, each guy can go as single or as a couple.
    Find the number of ways in which the n friends can go to the party.
*/
#include <bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    unsigned long long M = 1e9 + 7;
    
    int countFriendsPairings(int n) { 
        long long dp_1 = 1, dp_2 = 2, dp_3;
        if(n <= 2)
            return n;
        
        for(int i = 3; i <= n; i++) {
            dp_3 = (dp_2 + (i - 1) * dp_1) % M;
            dp_1 = dp_2;
            dp_2 = dp_3;
        }
        return dp_3;
    }
};    

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 