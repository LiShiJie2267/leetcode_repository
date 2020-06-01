#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandynumber=candies[0];
        vector<bool> ans;
        int size=candies.size();
        for(int index=1;index<size;index++)
            maxcandynumber=max(maxcandynumber,candies[index]);
        for(int index=0;index<size;index++)
            if((candies[index]+extraCandies)>=maxcandynumber)
                ans.push_back(true);
            else
                ans.push_back(false);
        return ans;
    }
};





