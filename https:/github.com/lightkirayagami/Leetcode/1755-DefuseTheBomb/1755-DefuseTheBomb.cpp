// Last updated: 27/04/2026, 21:45:35
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int i,j,m;
        int sum=0;
        vector<int>ans;
        int n=code.size();
        int arr[code.size()];
        if (k==0)
            
        {
            for(i=0;i<code.size();i++)
            {
                
                ans.push_back(0);
                
            }
        }
        
        
else if(k>0)
       {
           
           for(i=0;i<code.size();i++)
           {
               sum=0;
               for(j=i+1;j<=i+k;j++)
               {
                   m=j;
                   
                       m=(m%(n));
                       sum=code[m]+sum;
                   
                      
               }
               arr[i]=sum;
           }
       
       for(i=0;i<code.size();i++)
                 {
                      ans.push_back(arr[i]);        
                 }
       }
 else
 {
     k=-(k);
     int rev[n];
     for(i=0;i<n;i++)
     {
         rev[i]=code[n-i-1];
         
     }
      for(i=0;i<code.size();i++)
           {
               sum=0;
               for(j=i+1;j<=i+k;j++)
               {
                   m=j;
                   
                       m=(m%n);
                       sum=rev[m]+sum;
                   
                      
               }
               arr[i]=sum;
          sum=0;
           }
       
       for(i=0;i<code.size();i++)
                 {
                      ans.push_back(arr[i]);        
                 }
 
 reverse(ans.begin(),ans.end());
 
 
 }
       
     
     
 return ans;
     
 }
   
     
    
};