class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // O(n ^ 4) for four (for loops) each of length n
        // another approach would be to merge the tuples and then carry out four sum in the traditional way 
        // and that would take O(n ^ 3) time complexity and O(n) space complexity
        // O(n ^ 2) approach would be i can use two for loops for calculating two in one iteration and two on the 
        // other iteration. and use a hashtable to store the sum. While calculating the second iteration two sums 
        // i can use the values calculted by the first two for loops
        // O(n ^ 2) time complexity and hash table would take a space complexity of O(n)
        unordered_map<int,int>mpp;
        int n = nums1.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mpp[nums1[i] + nums2[j]]++;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mpp[-1 * (nums3[i] + nums4[j])]){
                    cnt += mpp[-1 * (nums3[i] + nums4[j])];
                }
            }
        }
        return cnt;
    }
};