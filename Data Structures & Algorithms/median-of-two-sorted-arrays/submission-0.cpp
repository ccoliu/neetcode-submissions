class Solution {
public:
    int getkth(vector<int> a, vector<int> b, int k) {
        if (a.size() > b.size()) swap(a,b);
        if (a.size() == 0) return b[k-1];
        if (k == 1) return min(a[0], b[0]);

        int i = min((int)a.size(), k / 2);
        int j = min((int)b.size(), k / 2);

        if (a[i - 1] <= b[j - 1]) {
            return getkth(vector<int>(a.begin() + i, a.end()), b, k - i);
        }
        else {
            return getkth(a, vector<int>(b.begin() + j, b.end()), k - j);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if ((n1 + n2) % 2 == 0) {
            return (getkth(nums1,nums2,(n1+n2)/2) + getkth(nums1,nums2,(n1+n2)/2 + 1)) / 2.0;
        }
        else return getkth(nums1,nums2,(n1 + n2 + 1) / 2);
    }
};
