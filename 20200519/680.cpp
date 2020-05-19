#include <string>
using namespace std;

class Solution {
public:
    bool subproblem(const string& s,int l,int r)
    {   
        for(int i=l,j=r;i<j;i++,j--)
        {
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int size=s.size();
        int left=0;
        int right=size-1;
        while(left<right)
        {
            if(s[right]==s[left])
            {
                right--;
                left++;
            }
            else
                return subproblem(s,left,right-1)||subproblem(s,left+1,right);
        }  
        return true;                      
    }
};

#include <vector>
class Solution {
public:
    bool k_validPalindrome(string s, int k){
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0x3f3f3f3f)); // 只需要用前后两行就好，0x3f3f3f3f拟定的无穷大，足够大也不容易溢出

        for (int i = 0; i <= n; ++ i) dp[0][i] = i; // 初始化,显然将t[:i-1]修改为空串需要i次操作
        
        for (int i = 1; i <= n; ++ i){
            dp[i & 1][0] = i; // 类似上述的初始化，只是在这里才赋值
            int from = max(1, i - k), to = min(n, i + k); // k是可以修改的次数,我们可以往前或者往后修改
            for (int j = from; j <= to; ++ j){
                if (s[i - 1] == s[n - j]) dp[i & 1][j] = dp[(i - 1) & 1][j - 1]; // 参看图中i = c, j = c
                dp[i & 1][j] = min({dp[i & 1][j], dp[(i - 1) & 1][j] + 1, dp[i & 1][j - 1] + 1}); // 从i - 1处和j - 1处转移
            }
        }
        return dp[n & 1][n] <= 2 * k; // 对原字符串的一次修改，反映在两个字符串上是两次。为了让s, t相同删除k代表可以对每个操作k次,共2*k
    }
    bool validPalindrome(string s) {
        return k_validPalindrome(s, 1);
    }
};

class Solution {
public:
    bool subvalidPalind(string s, int l,int r,int t){
        if(t>=2) return false;
        if(l>=r) return true;
        if(s[l]==s[r])   
            subvalidPalind(s,l+1,r-1,t);
        else 
            return subvalidPalind(s,l+1,r,t+1)||subvalidPalind(s,l,r-1,t+1); 
    }
    
    bool validPalindrome(string s) {
        return subvalidPalind(s,0,s.size()-1,0);
    }
};
