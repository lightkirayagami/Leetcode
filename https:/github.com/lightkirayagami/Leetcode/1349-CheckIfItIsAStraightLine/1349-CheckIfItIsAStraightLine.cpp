// Last updated: 27/04/2026, 21:45:53
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n=coordinates.size();
        int count=0;
        for(int i=1;i<n-1;i++)
        {
           if((coordinates[i][0]-coordinates[i-1][0])==0&&(coordinates[i+1][0]-coordinates[i][0])==0) 
           {
               continue;
           }   
           else if(((coordinates[i][0]-coordinates[i-1][0])==0&&(coordinates[i+1][0]-coordinates[i][0])!=0)||((coordinates[i][0]-coordinates[i-1][0])!=0&&(coordinates[i+1][0]-coordinates[i][0])==0))
           {
               count++;
           }
            else
        {
           float m1=float(float(coordinates[i][1]-coordinates[i-1][1])/float(coordinates[i][0]-coordinates[i-1][0]));
           float m2=float(float(coordinates[i+1][1]-coordinates[i][1])/float(coordinates[i+1][0]-coordinates[i][0]));
            
            if(m1!=m2)
            {count++;}
        }
        }
        
        
        if(count==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    
        
    
}
};