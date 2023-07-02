// Here is the top-down approach of
// dynamic programming
#include <bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
int knapSackRec(int W, int wt[], int val[], int i, int dp[][4])
{
	// base condition
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	if (wt[i] > W) {

		// Store the value of function call
		// stack in table before return
		dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
		return dp[i][W];
	}
	else {
		// Store value in a table before return
		dp[i][W] = max(val[i]
						+ knapSackRec(W - wt[i], wt, val,
										i - 1, dp),
					knapSackRec(W, wt, val, i - 1, dp));

		// Return value of table after storing
		return dp[i][W];
	}
}
int main()
{
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };
	int W = 50;
	int dp[4][4];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{	
		 	dp[i][j]=-1;	
		}
	}
	int n = sizeof(profit) / sizeof(profit[0]);
	cout << knapSackRec(W, weight, profit, n,dp);
	return 0;
}

