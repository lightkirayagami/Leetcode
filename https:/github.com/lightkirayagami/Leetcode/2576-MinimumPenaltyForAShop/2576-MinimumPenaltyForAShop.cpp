// Last updated: 27/04/2026, 21:44:49
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> pre(n + 1, 0);
        vector<int> suf(n + 1, 0);
        int cnt_y = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (customers[i] == 'Y') {
                cnt_y = cnt_y + 1;
                suf[i] = cnt_y;
            } else {

                suf[i] = cnt_y;
            }
        }

        suf.push_back(0);

        int cnt_n = 0;

        for (int i = 0; i < n; i++) {
            if (customers[i] == 'N') {
                pre[i] = cnt_n;
                cnt_n++;

            } else {

                pre[i] = cnt_n;
            }
        }

        pre[n]=cnt_n;

        for (int i = 0; i < n + 1; i++) {
            cout << suf[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n + 1; i++) {
            cout << pre[i] << " ";
        }


        int min_index=-1;
        int min_ans=INT_MAX;

        for(int i=0;i<n+1;i++)
        {
            if(pre[i]+suf[i]<min_ans)
            {
                min_index=i;
                min_ans=pre[i]+suf[i];
            }
        }


        return min_index;
    }
};