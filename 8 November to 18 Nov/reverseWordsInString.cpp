/*
151. Reverse Words in a String
Medium

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/
class Solution {
public:
    string reverseWords(string s) {
    int n = s.length();
stack<string>st;
string temp ="";
string ans = "";
for(int i =0;i<n;i++)
{
	if(s[i] == ' ')
	{
        if(temp.length() > 0)
             st.push(temp);
        temp ="";
	}
	else
	{
		temp+=s[i];
	}
}

ans+=temp;

while(!st.empty())
{
	ans+= " " + st.top();
	st.pop();
}
if(ans.length() != 0 && ans[0] == ' ') ans=ans.substr(1);
return ans; 
    }
};