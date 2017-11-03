/// Source : https://leetcode.com/problems/longest-consecutive-sequence/description/
/// Author : liuyubobobo
/// Time   : 2017-11-03

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Sort
/// Remove duplicate elements on the fly
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int res = 1;
        int curres = 1;
        for(int i = 1 ; i <= nums.size() ; i ++){
            if(i == nums.size() || nums[i] - nums[i-1] > 1 ){
                res = max(res, curres);
                curres = 1;
            }
            else if(nums[i-1] + 1 == nums[i])
                curres ++;

        }

        return res;
    }
};

int main() {

    int nums1[6] = {100, 4, 200, 1, 3, 2};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().longestConsecutive(vec1) << endl;
    // 4

    // ---

    int nums2[4] = {1, 2, 0, 1};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    cout << Solution().longestConsecutive(vec2) << endl;
    // 3

    return 0;
}