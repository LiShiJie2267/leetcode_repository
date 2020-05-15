#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
//＊＊暴力解法，两层ｆｏｒ循环＊＊
//第一层：遍历整个向量ｓｔａｒｔ
//第二层：从ｓｔａｒｔ往前遍历ｅｎｄ
//      sum+=ｎｕｍｓ［end:start］
//  判断是否ｓｕｍ＝ｋ
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size=nums.size();
        int start=0; int count=0;
        for(;start<size;++start)
        {
            int sum=0;
            for(int end=start;end>=0;--end){
                sum+=nums[end];
                if(sum==k)
                    count++;
            }
        }
        return count;
    }
};

//pre+unordered_map法
//int pre：前几项的和
//map:pre->count;
//init:pre=0 map[0]->1;
//when find a (pre-k),map[pre]+1,count+map[pre-k]
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int pre=0;
        int count=0;
        for(auto& x:nums){
            pre+=x;
            if(m.find(pre-k)!=m.end()) count+=m[pre-k];
            m[pre]++;
        }
        return count;
    }
};