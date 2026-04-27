// Last updated: 27/04/2026, 21:46:11
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int>maxH;
        for(int i=0;i<stones.size();i++)
        {
            maxH.push(stones[i]);
        }

        while(maxH.size()>=2)
        {
            int a=maxH.top();
            maxH.pop();
            int b=maxH.top();
            maxH.pop();

            if(a==b)
            {
                continue;
            }
            else
            {
                maxH.push(a-b);
            }
        }
        if(maxH.size()==0)
        {
            return 0;
        }
        // return maxH.size();
        return maxH.top();
        
        
    }
};