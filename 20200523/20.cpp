#include <stack>
#include <string>
using namespace std;
class Solution {
public:
     bool isValid(string s) {
        if (s.empty()) return true;
		stack<char>	stc;
		for (char c : s)
			if (c == ')' || c == ']' || c == '}') 
				if (!stc.empty() && stc.top() == c)
					stc.pop();
				else return false;
			else
				switch (c) {
				case '(':
					stc.push(')');
					break;
				case '[':
					stc.push(']');
					break;
				case '{':
					stc.push('}');
					break;
				}
		return stc.empty();
    }

};


class Solution2 {
public:
    bool isValid(string s) {
        int size=s.size();
        stack<char> stc;
        int i=0;
        while(i<size)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                stc.push(s[i]);
            else
            {
                if(stc.empty())
                    return false;
                else
                {
                    if(stc.top()=='(')
                    {
                        if(s[i]!=')')
                            return false;
                        else
                            stc.pop();
                    }

                    else if(stc.top()=='[')
                    {
                        if(s[i]!=']')
                            return false;
                        else
                            stc.pop();
                    }
                    else if(stc.top()=='{')
                    {
                        if(s[i]!='}')
                            return false;
                        else
                            stc.pop();
                    }          
                }                
            }
            i++;
        }
        return stc.empty();
    }
};
