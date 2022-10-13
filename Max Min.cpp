/* D16

Max Min

P.S:- Given an array A of size N of integers. Your task is to find the sum of minimum and maximum element in the array.

Example 1:

Input:
N = 5
A[] = {-2, 1, -4, 5, 3}

Output: 1
Explanation: min = -4, max =  5. Sum = -4 + 5 = 1


Example 2:
Input:
N = 4
A[]  = {1, 3, 4, 1}

Output: 5
Explanation: min = 1, max = 4. Sum = 1 + 4 = 5

Constraints:
1 <= N <= 105
-109 <= Ai <= 109

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/


//--------------------------------------------------------------SOLUTION-----------------------------------------------


//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	int findSum(int A[], int N)
	{
		//code here.
		int max = A[0];
		int min = A[0];

		for (int i = 1; i < N; i++)
		{
			if (A[i] > max)
			{
				max = A[i];
			}
			if (A[i] < min)
			{
				min = A[i];
			}
		}
		return min + max;
	}

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		Solution ob;
		int ans = ob.findSum(arr, n);
		cout << ans;
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends