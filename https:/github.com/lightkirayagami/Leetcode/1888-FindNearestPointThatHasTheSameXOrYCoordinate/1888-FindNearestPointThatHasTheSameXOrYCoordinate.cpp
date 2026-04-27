// Last updated: 27/04/2026, 21:45:32
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) 
    {
        
        int min=INT_MAX;
        int res=-1;
        
        for(int i=0;i<points.size();i++)
        {
            
            if(points[i][0]==x||points[i][1]==y)
            {
            
                
                 int sum=abs(points[i][0]-x)+abs(points[i][1]-y);
                if(sum<min)
                {
                    min=sum;
                   res=i;
                }
            }
        }
        
        
        
      return res;  
    }
};     
                
                
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
                
            
        
    
            
           
    
    
        
    
