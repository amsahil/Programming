/* D14

Decode The Strings.

P.S:- An encoded string (s) is given, the task is to decode it. The encoding pattern is that the occurance of the string is given at the  starting of the string and each string is enclosed by square brackets.

Example 1:

Input: s = 1[b]
Output: b
Explaination: 'b' is present only one time.


Example 2:

Input: s = 3[b2[ca]]
Output: bcacabcacabcaca
Explaination: 2[ca] means 'ca' is repeated
twice which is 'caca' which concatenated with
'b' becomes 'bcaca'. This string repeated
thrice becomes the output.

Constraints:
1 ≤ |s| ≤ 103

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

*/


//--------------------------------------------------------------SOLUTION-----------------------------------------------




//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    string decodedString(string s) {

        string res = "";

        stack<char> st;

        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {

            if (s[i] == ']') {

                while (!st.empty() && st.top() != '[') {

                    res = st.top() + res;

                    st.pop();

                }

                if (!st.empty())

                    st.pop();

                string rnum = "";

                while (!st.empty() && st.top() >= '0' && st.top() <= '9') {

                    rnum = st.top() + rnum;

                    st.pop();

                }

                string sr = res;

                for (int j = 0; j < stoi(rnum) - 1; j++) {

                    res += sr;

                }

                for (auto x : res) {

                    st.push(x);

                }

                res = "";

            }

            else {

                st.push(s[i]);

            }

        }

        res = "";

        while (!st.empty()) {

            res = st.top() + res;

            st.pop();

        }

        return res;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends