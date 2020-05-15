//动态规划;
#include <vector>
#include <iostream>
using namespace std;
class Solution1 {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int ans=0;
        int size=height.size();
        vector<int> left_max(size);
        vector<int> right_max(size);
        left_max[0]=height[0];
        right_max[size-1]=height[size-1];
        for(int i=1;i<size;i++)
            left_max[i]=max(left_max[i-1],height[i]);
        for(int i=size-2;i>=0;i--)
            right_max[i]=max(height[i],right_max[i+1]);
        for(int i=1;i<size-1;i++)
            ans+=min(right_max[i],left_max[i])-height[i];
        return ans;   
    }
};
#include <stack>

class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans=0;
        int cur=0;
        int size=height.size();
        while(cur<size)
        {
            while(!s.empty()&&height[cur]>height[s.top()])
            {
                int low_top=s.top();
                s.pop();//把凹陷处取出；
                if(s.empty())
                    break;//前两个一定入栈
                int dist=cur - s.top() -1;
                int storge_height=min(height[cur],height[s.top()])-height[low_top];
                ans+=dist*storge_height;
            }
        s.push(cur++);
        }
        return ans;
    }
};

class Solution3 {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int size=height.size();
        int left=0;
        int right=size-1;
        int right_max=0;
        int left_max=0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=left_max)
                    left_max=height[left];
                else
                    ans+=(left_max-height[left]);
            ++left;
            }
            else{
                if(height[right]>=right_max)
                    right_max=height[right];
                else
                    ans+=(right_max-height[right]);
            --right;
            }
        }
        return ans;
    }
};