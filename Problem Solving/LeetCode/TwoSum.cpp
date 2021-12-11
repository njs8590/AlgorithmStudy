/*
* problem: https://leetcode.com/problems/two-sum/
* algorithm:

*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef

// function pre-defined

// global var


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer; 
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                }
            }
        }

        return answer ;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = { 2,7,11,15 };
    int target = 9;
    vector<int> answer = sol.twoSum(nums, target);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}