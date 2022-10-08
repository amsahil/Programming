/* D11

Substrings of length k with k-1 distinct elements

P.S:- Given a String S consisting only lowercase alphabets and an integer K.
      Find the count of all substrings of length K which have exactly K-1 distinct characters.

Example 1:
Input:
S = "abcc"
K = 2
Output:
1
Explanation:
Possible substrings of length K = 2 are
ab : 2 distinct characters
bc : 2 distinct characters
cc : 1 distinct character
Only one valid substring exists {"cc"}.

Example 2:
Input:
S = "aabab"
K = 3
Output :
3
Explanation:
Possible substrings of length K = 3 are
aab : 2 distinct characters
aba : 2 distinct characters
bab : 2 distinct characters.
All of these Substrings are a possible answer,
so the count is 3.

Constraints:
1 ≤ K ≤ |S| ≤ 105

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(constant)
*/


//--------------------------------------------------------------SOLUTION-----------------------------------------------

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int countOfSubstrings(string s, int k) {

        // code here

        unordered_map<char, int> mp;

        int ans = 0;

        int j = 0;

        for (int i = 0; i < s.size(); i++)

        {

            mp[s[i]]++;

            if (i - j + 1 >= k)

            {

                if (mp.size() == k - 1)

                    ans++;

                char ch = s[j];

                mp[s[j]]--;

                if (mp[ch] == 0)

                    mp.erase(ch);

                j++;

            }

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin >> S;
        cin >> K;

        Solution ob;
        cout << ob.countOfSubstrings(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends