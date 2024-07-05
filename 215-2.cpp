#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int qsort(vector<int>& nums, int l, int r, int k) {
        if (l>=r) return nums[r];
        int i = l-1, j = r+1, x = nums[(l+r)>>1];
        while(i<j) {
            do i++; while(nums[i]>x);
            do j--; while(nums[j]<x);
            if (i<j) swap(nums[i], nums[j]);
        }
        // 第k大，下标为k-1。
        if (k<=j)  return qsort(nums, l, j,k);
        else return qsort(nums, j+1, r,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return qsort(nums,0,nums.size()-1, k-1);
    }
};