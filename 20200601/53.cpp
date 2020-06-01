#include <vector>
using namespace std;
// 1 O(n*n)
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        int size=nums.size();
        if(size==1)
            return nums[0];
        for(int i=0;i<size;i++)
        {
            int current=0;
            for(int j=i;j<size;j++)
            {
                current+=nums[j];
                maxsum=max(current,maxsum);
            }
        }
        return maxsum;
    }
};

//2 0(n)

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        if(size==0)
            return 0;
        int maxsum=nums[0];
        int currentsum=nums[0];
        int lastsum=nums[0];
        for(int i=1;i<size;i++)
        {
            if(lastsum<0)
            {
                currentsum=nums[i];
                maxsum=max(maxsum,currentsum);
                lastsum=currentsum;
            }
            else
            {
                currentsum=lastsum+nums[i];
                maxsum=max(maxsum,currentsum);
                lastsum=currentsum;
            }
        }
        return maxsum;
    }
};

class Solution3 {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        if(size==0)
            return 0;
        int maxsum=nums[0];
        int pre=0;
        for(auto& x:nums)
        {
            pre=max(pre+x,x);
            maxsum=max(maxsum,pre);
        }
        return maxsum;
    }
};

class Solution4 {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        if(size==0)
            return 0;
        int maxsum=nums[0];
        vector<int> temp(size);
        temp[0]=nums[0];
        for(int i=1;i<size;i++)
        {
            if(temp[i-1]>=0)
                temp[i]=temp[i-1]+nums[i];
            else
                temp[i]=nums[i];
            maxsum=max(maxsum,temp[i]);
        }
        return maxsum;
    }
};

class Solution5
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        result = maxSubArrayHelper(nums, 0, numsSize - 1);
        return result;
    }

    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right) / 2;
        int leftSum = maxSubArrayHelper(nums, left, mid);
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);
        int result = max(leftSum, rightSum);
        result = max(result, midSum);
        return result;
    }

    int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
    }
};
