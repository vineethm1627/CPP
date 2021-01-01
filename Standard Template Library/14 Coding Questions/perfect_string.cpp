/*
    Problem:
    Kartik Bhaiya has a string consisting of only 'a' and 'b' as the characters. Kartik Bhaiya describes perfectness of a string as the maximum length substring of equal characters. Kartik Bhaiya is given a number k which denotes the maximum number of characters he can change. Find the maximum perfectness he can generate by changing no more than k characters.

    Input Format
    The first line contains an integer denoting the value of K. The next line contains a string having only ‘a’ and ‘b’ as the characters.

    Constraints
    2 ≤ N ≤ 10^6

    Output Format
    A single integer denoting the maximum perfectness achievable.

    Sample Input
    2
    abba
    Sample Output
    4
    Explanation
    We can swap the a's to b using the 2 swaps and obtain the string "bbbb". This would have all the b's and hence the answer 4.
    Alternatively, we can also swap the b's to make "aaaa". The final answer remains the same for both cases.
*/
/*
    Approach - Two pointer approach
    You can solve this problem in O(n) time using the two pointer approach.

    Make two variabes , say i and j .
    i defines the beginning of a window and j defines its end.
    Start i from 0 and j from k.
    Let’s talk about the singular case when we are considering the max window for only 'a’s and consider only the swapping of b-> a. If we are able to get the answer for max window of consecutive 'a’s , we can simply implement the same algo for the max ‘b’ window as well.
    So we started i from 0 and j from k.
    Move j ahead freely as long as there are ‘a’ characters at s[ j ] position.
    Maintain a count variable which counts the number of swaps made or the number of 'b’s in our A window.
    If you encounter a ‘b’ char at s[ j ] position , increment the count variable. Count should never exceed k .
    Take the size of the window at every point using length = j - i + 1;
    Compute the max size window this way and do the same for ‘b’ as well.
    Output the maximum size window of ‘a’ and ‘b’.
*/
#include <iostream>
#include <cstring>
using namespace std;

//Function to count the length of window which can be made of char ch with <= k swaps
int countMaxWindowSize(const string &s, char ch, int k)
{
    int i = 0; //Left pointer
    int j = 0; //Right pointer

    //First move the right pointer forward by k steps.
    //If the character is already ch , do not count a swap and move freely

    int c = 0; //Variable to count the swaps so far

    int ans = 0; //Variable to store the final answer

    for (j; c < k && j < s.size() - 1; j++)
    {
        if (s[j] != ch)
        {
            //If s[j] is not ch then count it as a swap and move forward
            c++;
        }
        if (c == k)
        {
            //If no of swaps has reached k, stop moving j any more forward
            break;
        }
    }

    while (i < j)
    {

        //Move j ahead if next element is ch as it doesn't count as a swap
        while (j < s.size() - 1 && s[j + 1] == ch)
        {
            j++;
        }

        //Store the maximum length of all windows
        int currentLength = j - i + 1;
        ans = max(ans, currentLength);

        //Move left pointer by one to slide the window
        i++;

        //If the char at previous position of left pointer was not ch, then that position must
        //have counted as a swap earlier. Now we have a free swap available.
        //Iterate right pointer forward to use that one free swap
        if (j < s.size() - 1 && s[i - 1] != ch)
        {
            j++;
        }
    }

    return ans;
}

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    if (k >= s.size())
    {
        //If k is larger than s.size() then we can swap all the elements to either A or B
        //and obtain the answer equal to length of string
        cout << s.size();
        return 0;
    }

    //First let us check for longest perfect string of A's then we will find the same for B's and compare
    int ansForA = countMaxWindowSize(s, 'a', k);

    //Now we do the same for B's
    int ansForB = countMaxWindowSize(s, 'b', k);

    //Final answer is max of the two answers obtained above
    cout << max(ansForA, ansForB);

    return 0;
}