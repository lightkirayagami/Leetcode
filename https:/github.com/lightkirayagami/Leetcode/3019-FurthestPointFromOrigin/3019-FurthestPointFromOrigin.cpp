// Last updated: 27/04/2026, 21:44:44
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int l=0;
        int r=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
            {
                l++;
            }
            else if(moves[i]=='R')
            {
                r++;
            }
        }



        int d=moves.size()-l-r;



        if(l>=r)
        {
            return l+d-r;
        }
        else
        {
            return r+d-l;
        }
        
    }
};