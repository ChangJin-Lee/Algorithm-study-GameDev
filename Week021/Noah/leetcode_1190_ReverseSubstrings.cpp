class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans = "";
        
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ')'){
                string str = "";
                
                while(!st.empty() && st.top() != '('){
                    str += st.top();
                    st.pop();
                }
                
                if(!st.empty()){
                    st.pop();
                }
                
                for(int j = 0; j < str.length(); ++j){
                    st.push(str[j]);
                }
            }else{
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};