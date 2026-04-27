// Last updated: 27/04/2026, 21:45:19
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        vector<vector<int>>temp;
        for(int i=0;i<triplets.size();i++)
        {
            if(triplets[i][0]<=target[0]&&triplets[i][1]<=target[1]&&triplets[i][2]<=target[2])
            {
                temp.push_back(triplets[i]);
            }
        }
        int x=0;
        int y=0;
        int z=0;

        for(int i=0;i<temp.size();i++)
        {
            x=max(x,temp[i][0]);
            y=max(y,temp[i][1]);
            z=max(z,temp[i][2]);

            if(x==target[0]&&y==target[1]&&z==target[2])
            {
                return true;
            }
        }

        return false;

        
        
    }
};