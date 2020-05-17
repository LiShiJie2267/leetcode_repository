/**
 * －－－－－－找最近重复子问题－－－－－
递归基本步骤：
1.递归终结条件（递归基）
2.处理当前逻辑
3.下探到下一层（drill down）
4.清理当前层
**/

//Solution1　会导致超时　直接递归
class Solution1 {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

//动态规划
class Solution2 {
public:
    int climbStairs(int n) {
        int f_2=1;
        int f_1=2;
        int f_n=0;
        if(n<=2)
            return n;
        for(int i=3;i<=n;i++){
            f_n=f_2+f_1;
            f_2=f_1;
            f_1=f_n;       
        }
        return f_n;
    }     
};
//动态规划＋数组

#include <vector>
class Solution3 {
public:
    int climbStairs(int n) {
        std::vector<int> value;
        value.push_back(1);
        value.push_back(2);
        for(int i=3;i<=n;i++)
        {
            int this_value=value[i-2]+value[i-3];
            value.push_back(this_value);
        }
        return value[n-1];
    }     
};
//动态规划＋哈希表
#include <unordered_map>
class Solution4 {
public:
    int climbStairs(int n) {
        std::unordered_map <int,int> value;
        value[1]=1;
        value[2]=2;
        for(int i=3;i<=n;i++)
        {
            int this_value=value[i-1]+value[i-2];
            value[i]=this_value;
        }
        return value[n];
    }     
};