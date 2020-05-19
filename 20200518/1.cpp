#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int size=nums.size();
        if(size==0)
            return ans;
        for(int i=0;i<size;i++)
        {
            auto res=target-nums[i];
            for(int j=i+1;j<size;j++)
            {
                if(nums[j]==res)
                    {
                        ans.push_back(i);
                        ans.push_back(j);
                    }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<size;i++)
            m[nums[i]]=i;
        for(int i=0;i<size;i++)   
            if((m.find(target-nums[i])!=m.end())&&m[target-nums[i]]!=i)
                return {i,m[target-nums[i]]};
        return {};
    }
};

class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size=nums.size();
        unordered_map<int,int> m;      
        for(int i=0;i<size;i++) 
        {  
            m[nums[i]]=i;
            if((m.find(target-nums[i])!=m.end())&&m[target-nums[i]]!=i)
                return {i,m[target-nums[i]]};          
        }
        return {};
    }
};