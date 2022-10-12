/* D15

Save your life.

P.S:- Given a string w, integer array b,  character array x and an integer n. n is the size of array b and array x. Find a substring which has the sum of the ASCII values of its every character, as maximum. ASCII values of some characters are redefined.
Note: Uppercase & lowercase both will be present in the string w. Array b and Array x contain corresponding redefined ASCII values. For each i, b[i] contain redefined ASCII value of character x[i].

Example 1:
Input:
W = abcde
N = 1
X[] = { 'c' }
B[] = { -1000 }

Output:
de

Explanation:
Substring "de" has the
maximum sum of ascii value,
including c decreases the sum value

Example 2:
Input:
W = dbfbsdbf
N = 2
X[] = { 'b','s' }
B[] = { -100, 45  }

Output:
dbfbsdbf

Explanation:
Substring "dbfbsdbf" has the maximum
sum of ascii value.

Constraints:
1<=|W|<=100000
1<=|X|<=52
-1000<=Bi<=1000

Expected Time Complexity: O(|W|)
Expected Auxiliary Space: O(1)

*/


//--------------------------------------------------------------SOLUTION-----------------------------------------------


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
  string maxSum(string s, char x[], int b[], int n) {
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
      mp[x[i]] = b[i];

    int ans = INT_MIN, curr = 0;
    string temp, res;

    for (int i = 0; i < s.length(); i++) {
      if (mp.find(s[i]) != mp.end())
        curr += mp[s[i]];
      else {
        curr += s[i];
      }

      temp += s[i];
      if (curr > ans) {
        ans = curr;
        res = temp;
      }
      if (curr < 0) {
        curr = 0;
        temp = "";
      }
    }
    return res;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string w;
    cin >> w;
    int n;
    cin >> n;
    char x[n];
    int b[n];
    for (int i = 0; i < n; i++)
      cin >> x[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    Solution ob;
    cout << ob.maxSum(w, x, b, n) << endl;
  }
  return 0;
}
// } Driver Code Ends