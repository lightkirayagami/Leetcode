// Last updated: 27/04/2026, 21:46:55
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n=hand.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }


        while(!mp.empty())
        {
            int smallest=mp.begin()->first;

            mp[smallest]--;
            if(mp[smallest]==0)
            {
                mp.erase(smallest);
            }


            for(int i=smallest+1;i<groupSize+smallest;i++)
            {
                if(mp.find(i)==mp.end())
                {
                    return false;
                }

                mp[i]--;
                if(mp[i]==0)
                {
                    mp.erase(i);
                }


            }
            

        }
        return true;
        
    }
};