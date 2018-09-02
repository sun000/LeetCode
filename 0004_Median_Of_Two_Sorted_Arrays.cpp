class Solution {
public:
    bool check(vector<int>& nums1, vector<int>& nums2, int a) {
        int l1 = nums1.size(), l2 = nums2.size(), b;
        if((l1 + l2) & 1) b = (l1 + l2 + 1) / 2 - a;
        else b = (l1 + l2) / 2 - a;
        if(!a || b >= l2) return true;
        else if(b < 0) return false;
        return nums1[a - 1] <= nums2[b];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int m = (l1 + l2) / 2;
        int l = 0, r = l1 + 1;
        int k = 0;
        while(r - l > 1) {
            k = (l + r) / 2;
            if(check(nums1, nums2, k)) l = k;
            else r = k;
        }
        if((l1 + l2) & 1) {
            int a = l, b = m + 1 - l;
            if(!a) return nums2[b - 1];
            else if(!b) return nums1[a - 1];
            return max(nums1[a - 1], nums2[b - 1]);
        } else {
            int a = l, b = m - l;
            int aa, bb;
            
            if(!a) aa = nums2[b - 1];
            else if(!b) aa = nums1[a - 1];
            else aa = max(nums1[a - 1], nums2[b - 1]);
            
            if(a == l1) bb = nums2[b];
            else if(b == l2) bb = nums1[a];
            else bb = min(nums1[a], nums2[b]);
            
            return (aa + bb) / 2.0;
        }
    }
};