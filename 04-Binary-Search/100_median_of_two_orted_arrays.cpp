/*
    Problem: Median of Two Sorted Arrays
    Platform: LeetCode
    Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
    Difficulty: Hard
    Approach: Binary Search on Partition — binary search on the smaller array to find a valid partition point where left side <= right side across both arrays combined
    Time: O(log(min(n,m)))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            findMedianSortedArrays(nums2,nums1);
        }
        int n1=nums1.size(),n2=nums2.size();
        int totalleft=(n1+n2+1)/2;
        int low=0,high=n1;
        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=totalleft-cut1;
            int left1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int left2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int right1=(cut1==n1)?INT_MAX:nums1[cut1];
            int right2=(cut2==n2)?INT_MAX:nums2[cut2];
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2 == 0) return (max(left1,left2) + min(right1,right2))/2.0;
                else return max(left1,left2);
            }
            else if(left1>right2) high=cut1-1;
            else low=cut1+1;
        }
        return 0.0;
    }
int main() {
    vector<int> nums1={2,4,6};
    vector<int> nums2={1,3,5};
    double median=findMedianSortedArrays(nums1,nums2);
    cout<<"Median of the two sorted arrays is: "<<median<<endl;
    return 0;
}