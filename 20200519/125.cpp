#include <string>
using namespace std;

class Solution {
public:
    bool isallnum(char c)
    {
        if(tolower(c)>=tolower('a')&&tolower(c)<=tolower('z')||tolower(c)>='0'&&tolower(c)<='9')
            return true;
        else    
            return false;
    }

    bool isPalindrome(string s) {
        int size=s.size();
        if(size==0)
            return true;
        int left=0;
        int right=size-1;
        while(left<right)
        {   
            if(!isallnum(s[left])) 
                left++;
            if(!isallnum(s[right])) 
                right--;
            if(isallnum(s[left])&&isallnum(s[right]))
            {
                if(tolower(s[left])==tolower(s[right]))
                {
                    left++;
                    right--;
                }
                else
                    return false;
            }
        }
        return true;

    }
};