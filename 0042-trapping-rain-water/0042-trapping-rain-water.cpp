class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n);
        int res = height[0];
        maxLeft[0] = height[0];
        for (int i = 1; i < n; ++i){
            if (height[i] > res) res = height[i];
            maxLeft[i] = res;
        }
        vector<int> maxRight(n);
        res = height[n - 1];
        maxRight[n - 1] = res;
        for (int i = n - 2; i >= 0; --i){
            if (height[i] > res) res = height[i];
            maxRight[i] = res;
        }
        //reverse(maxRight.begin(), maxRight.end());
        //for (int x : maxLeft) cout << x << ' ';
        //cout << '\n';
        //for (int x : maxRight) cout << x << ' ';
        //cout << '\n';
        vector<int> maxLeftRightElement(n);
        for (int i = 0; i < n; i++) maxLeftRightElement[i] = min(maxLeft[i], maxRight[i]);
        //for (int x : maxLeftRightElement) cout << x << ' ';
        int ans = 0;
        for (int i = 0; i < n; i++) ans += abs(maxLeftRightElement[i] - height[i]);
        return ans;
    }
};