// Last updated: 27/04/2026, 21:49:14
class Solution {
public:
    bool wordPattern(string pattern, string s) {
    
        bool a=is(pattern,s);
        bool b=and1(s,pattern);
       return a&b;
    }
    bool is(string pattern, string s)
    {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
      if(words.size()!=pattern.size())
      {
        return false;
      }
        map<string, char> m;
        cout<<words.size()<<endl;
        for (int i = 0; i < words.size(); i++) {
            string aword = words[i];
            if (m.find(aword) != m.end()) {
                if (m.at(aword) != pattern[i]) {
                    return false;
                }
            }
            m.insert({words[i], pattern[i]});
        }
        return true;
    }
    bool and1(string pattern, string s)
    {
        stringstream ss(pattern);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        map<char, string> m;
        cout<<words.size()<<endl;
        for (int i = 0; i <words.size(); i++) {
            char alpha = s[i];
            if (m.find(alpha) != m.end()) {
                if (m.at(alpha) != words[i]) {
                    return false;
                }
            }
            m.insert({alpha, words[i]});
        }
        return true;
    }
};




 