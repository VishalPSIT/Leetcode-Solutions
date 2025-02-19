class Solution {
public:
    vector<char> ch = {'a', 'b', 'c'};
    vector<string> res;
    void generate(string str, int n, char prev) {
        if (str.size() == n) {
            res.push_back(str);
            return;
        }

        for (char c : ch) {
            if (c != prev) {
                generate(str + c, n, c);
            }
        }
    }
    string getHappyString(int n, int k) {
        generate("", n, '\0');
        if (res.size() < k)
            return "";
        sort(res.begin(), res.end());
        return res[k - 1];
    }
};