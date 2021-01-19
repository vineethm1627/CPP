/*
    First non-repeating characters in a running stream of characters.
    
    example: 
        input:  
        a a b c c b c d
        output: 
        a -1 b b b -1 -1 d

    we need to store the frequency of each character.

    the front of the queue will contain the potential answer, else pop the element if the freq
    of that element is greater than 1.
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<char> q;
    int freq[27] = {};
    // a will be stored at 0
    // running stream until a '.' is encountered
    char ch;
    cin >> ch;

    while(ch != '.') {
        // insert in the queue and freq table
        // to get the integer index subtract 'a'
        q.push(ch);
        freq[ch - 'a']++;

        while(!q.empty() and freq[q.front() - 'a'] > 1)
            q.pop();
        
        if(q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";

        cin >> ch;
    }

    return 0;
}