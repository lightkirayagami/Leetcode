// Last updated: 27/04/2026, 21:48:00
class Solution {
public:
    map<string,string>m;
    int n=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ans="http://tinyurl.com/"+to_string(n);
        m[ans]=longUrl;
        n++;
        return ans;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));