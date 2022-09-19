#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int solve(vector<int> &A, const int &k) {
	int n = A.size();
	int i = 0, j = 0, sum = 0;
	int mx = INT_MIN;
	while (j < n) {
		sum += A[j];
		if (sum < k) {
			j++;
		} else if (sum == k) {
			mx = max(mx, j - i + 1);
			j++;
		} else if (sum > k) {
			while (sum > k) {
				sum = sum - A[i];
				i++;
			}
			j++;
		}
	}
	return mx;
}
// It is good for positive Element, but it will not be wroking for Negative Element

So,Actual code for all the case & Element

  int subarraySum(vector<int>&nums, int k) {
        unordered_map<int,int>PreSum;
        int res =0;
        int CurrSum =0;
        for(int i =0;i<nums.size();i++){
            CurrSum+=nums[i];
            
            if(PreSum.find(CurrSum - k)!=PreSum.end())
                res+=PreSum[CurrSum-k];
            
            if(CurrSum == k) res++;
            PreSum[CurrSum]++;
        }
    return res;
    }
