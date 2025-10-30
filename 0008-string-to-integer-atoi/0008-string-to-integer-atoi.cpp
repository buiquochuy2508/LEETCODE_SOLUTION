class Solution {
public:
    int myAtoi(string s) {
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' '){
                s = s.substr(i);
                break;
            }
        }
        if (s[0] != '+' && s[0] != '-' && !isdigit(s[0])) return 0;
        if ((s[0] == '+' || s[0] == '-') && !isdigit(s[1])) return 0;
        if (s[0] == '.') return 0;
        int sign = s[0] == '+' || s[0] == '-';
        string res = "";
        for (int i = 0; i < s.size(); i++){
            // if (sign){
            //     res += s[i];
            //     sign = 0;
            //     continue;
            // }
            // if (s[i] == ' ') continue;
            if (isdigit(s[i]) || (s[i] == '-' || s[i] == '+')) res += s[i];
            if (!isdigit(s[i + 1])){
                //res += s[i];
                break;
            }
        }
        int k = 1;
        cout << res;
        // if (res.size() > 18) return 0;
        long long ans = 0;
        // cout << res;
        for (int i = 0; i < res.size(); ++i){
            if (isdigit(res[i])) ans = ans * 10 + (res[i] - '0');
            if (ans > INT_MAX) break;
            else{
                if (res[i] == '-') k *= -1;
            }
        }
        ans *= k;
        if (ans > INT_MAX) ans = INT_MAX;
        if (ans < INT_MIN) ans = INT_MIN;
        return ans;
    }
};