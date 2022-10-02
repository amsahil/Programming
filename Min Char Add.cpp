/* D5

Minimum characters to be added at front to make string palindrome

P.S:-
Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
Note: A palindrome is a word which reads the same backward as forward.
Example: "madam"


Example 1:
Input:
S = "abc"
Output: 2
Explanation:
Add 'b' and 'c' at front of above string to make it
palindrome : "cbabc"

Example 2:
Input:
S = "aacecaaa"
Output: 1
Explanation: Add 'a' at front of above string
to make it palindrome : "aaacecaaa"


Constraints:
1 <= S.length <= 106

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/


//Solution:-

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     int minChar(string str) {
          //Write your code here
          int n = str.length();

          string rev(str);

          reverse(rev.begin(), rev.end());

          string new_str = str + "#" + rev;

          int new_len = new_str.length();

          vector<int> tmp(new_len + 1, 0);

          for (int i = 1; i < new_len; i++) {

               int t = tmp[i - 1];

               while (t > 0 && new_str[i] != new_str[t])t = tmp[t - 1];

               if (new_str[i] == new_str[t])++t;

               tmp[i] = t;

          }

          return n - tmp[new_len - 1];
     }
};


//{ Driver Code Starts.
int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          string str;
          cin >> str;
          Solution ob;
          int ans = ob.minChar(str);
          cout << ans << endl;
     }
     return 0;
}

// } Driver Code Ends