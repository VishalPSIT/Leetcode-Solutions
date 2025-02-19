class Solution {
public:
    vector <char> ch = {'a','b','c'};
    
    string generate(string str , int n , char prev , int &k){
        if(str.size() == n){
            k--;
            if(k == 0) return str;
            return "";
        }

        for (char c :ch){
            if(c != prev){
                string ans = generate(str+c , n , c , k);
                if(!ans.empty()) return ans;
            }
        }
        return "";
    }
    string getHappyString(int n, int k) {
        return generate("" , n , '\0' , k);
        
    }
};