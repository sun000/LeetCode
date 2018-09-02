class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       for(int i = m - 1, j = n - 1, tail = nums1.size() - 1; tail >= 0; tail--) {
           if(j < 0 || (i >= 0 && nums1[i] > nums2[j])) nums1[tail] = nums1[i--];
           else nums1[tail] = nums2[j--];
       }
    }
};