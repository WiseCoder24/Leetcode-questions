/*
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
unordered_map<char, string> L({{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});

class Solution {
public:
    vector<string> letterCombinations(string D) {
        int len = D.size();
        vector<string> ans;
        if (!len) return ans;
        bfs(0, len, "", ans, D);
        return ans;
    }

    void bfs(int pos, int &len, string str, vector<string> &ans, string &D) {
        if (pos == len) ans.push_back(str);
        else {
            string letters = L[D[pos]];
            for (int i = 0; i < letters.size(); i++)
                bfs(pos+1, len, str+letters[i], ans, D);
        }
    }
};