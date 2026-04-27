// Last updated: 27/04/2026, 21:53:05
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> letter = {{"a", "b", "c"}, {"d", "e", "f"},
                                         {"g", "h", "i"}, {"j", "k", "l"},
                                         {"m", "n", "o"}, {"p", "q", "r", "s"},
                                         {"t", "u", "v"}, {"w", "x", "y", "z"}};
    

    vector<string>ans;
    string s="";
    solve(s,ans,letter,digits,0);
    return ans;
    }

    void solve(string &path,vector<string>&ans,vector<vector<string>>&letter,string &digit,int start)
    {
        if(path.size()==digit.size())
        {
            ans.push_back(path);
            return;
        }

        char index=digit[start];


        int letter_index=index-'0';
        letter_index=letter_index-2;

        for(int i=0;i<letter[letter_index].size();i++)
        {
            path=path+letter[letter_index][i];
            solve(path,ans,letter,digit,start+1);
            path.pop_back();
        }





        
    }



};