// Last updated: 27/04/2026, 21:45:48
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>answer; 
        int max=0; 
        int i=0;
        for( i=0;i<candies.size();i++) 
        { 
            if(candies[i]>max) 
            { 
                max=candies[i]; 
            } 
        } 
       
        for(i=0;i<candies.size();i++)
        { 
            cout<<candies[i]+extraCandies;
            if((candies[i]+extraCandies)>=max)
            { 
                answer.push_back(true); 
            }
            else 
            { 
                answer.push_back(false); 
            } 
        } 
        return answer;
        
        
        
    }
};

