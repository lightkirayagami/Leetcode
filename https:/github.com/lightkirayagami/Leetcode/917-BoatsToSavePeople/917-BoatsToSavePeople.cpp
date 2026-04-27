// Last updated: 27/04/2026, 21:46:43
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int ans=0;
        int sum=0;
        sort(people.begin(),people.end());
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(people[j]==limit)
        {
            ans++;
            j--;
        }
        sum=people[i]+people[j];
        if(sum>limit)
        {
            j--;
            ans++;
        }
        else if(sum==limit)
        {
            i++;
            j--;
            ans++;
        }
        else
        {
            i++;
            j--;
            ans++;
        }
    }
    if(i==j&&people[j]<=limit)
    ans++;
    return ans;
    }
};