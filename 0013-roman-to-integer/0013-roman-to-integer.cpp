class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        map <char, int> mp;
        mp['I'] = 1; mp['V'] = 5; mp['X'] = 10;
        mp['L'] = 50; mp['C'] = 100;
        mp['D'] = 500; mp['M'] = 1000;
        //res += mp[s[0]];
        bool ok = false;
        int i = 0;
        while (i < s.size() - 1){
            if (mp[s[i]] < mp[s[i + 1]]){
                res += mp[s[i + 1]] - mp[s[i]];
                i += 2;
                ok = true;
            }else{
                res += mp[s[i]];
                ++i;
                ok = false;
            }
        }
        //cout << i;
        // for (int i = 0; i < s.size() - 1; i++){
        //     if (mp[s[i]] < mp[s[i + 1]]){
        //         res += mp[s[i + 1]] - mp[s[i]];
        //         ++i;
        //         ok = true;
        //     }else{
        //         res += mp[s[i]];
        //         ok = false;
        //     }
        // }
        //cout << ok;
        //if (mp[s[s.size() - 1]] >= mp[s[s.size() - 2]] && ok) res += mp[s[s.size() - 1]];
        //if (!ok) res += mp[s[s.size() - 1]];
        if (i == s.size() - 1) res += mp[s[s.size() - 1]];
        return res;
    }
};