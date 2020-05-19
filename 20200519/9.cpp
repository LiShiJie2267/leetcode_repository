
//回文数
//1: 1221 -> 22
//   (1221%1000)/10=22;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&x!=0))
            return false;
        int div=1;
        while(x/div>=10)   div*=10;
        while(x>0)
        {
            int left=x/div;
            int right=x%10;
            if(left!=right) return false;
            x=(x%div)/10;
            div/=100;
        }
        return true;
    }
};
//2:判断一半是否可以这回
// 1221 (12 ?== 12(这后面是21的反转))
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&x!=0))
            return false;
        int reverhalfnum=0;
        while(x>reverhalfnum)
        {
            int current_last=x%10;
            reverhalfnum=reverhalfnum* 10 + current_last;
            x/=10;
        }
        return x==(reverhalfnum/10)||(x==reverhalfnum);
    }
};