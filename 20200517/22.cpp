#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>
using namespace std;

//backtrace method
class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        string s="";
        generate(0,0,n,s);
        return ans;
    }

private:
    void generate(int left,int right,int n,string s)
    {   
        if(left==n&&right==n){
            ans.push_back(s);
            return ;
        }
        if(left<n)
            generate(left+1,right,n,s+"(");

        if(right<left)
            generate(left,right+1,n,s+")");       
    }
    vector<string> ans;
};

//暴力解法/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s="";
        generate(0,2*n,s);
        return ans;
    }

private:
    void generate(int cur,int max,const string& s)
    {       
        if(cur==max)
        {
            if(is_vaild(s))
                ans.push_back(s);
            return ;
        }
        generate(cur+1,max,s+"(");
        generate(cur+1,max,s+")");        
    }
private:
    bool is_vaild(string s)
    {
        int count=0;
        for(char& c : s)
        {
            if(c=='(')
                count++;
            else count--;
            if(count<0)
                return false;
        }
        return (count==0);
    }

    vector<string> ans;
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
       return *generate(n);
    }

private:
    shared_ptr<vector<string>> generate(int n)
    {       
        if(ans[n]!=nullptr)
            return ans[n];
        if(n==0)
            ans[0]=shared_ptr<vector<string>>(new vector<string>{""});
        else{
            auto reslut=shared_ptr<vector<string>>(new vector<string>);
            for(int i=0;i!=n;i++)
            {
                auto lefts=generate(i);
                auto rights=generate(n-i-1);
                for(auto& left:*lefts)
                    for(auto& right:*rights)
                    {   
                        reslut->push_back("("+left+")"+right);
                    }
            }

            ans[n]=reslut;
        }    
        return ans[n];
    }
    shared_ptr<vector<string>> ans[100]={nullptr};  
};