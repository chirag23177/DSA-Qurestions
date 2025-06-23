class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i : s){
            if(i == '(' || i == '{' || i == '['){
                st.push(i);
            }
            else{
                if(i == ')' || i =='}' || i==']'){
                    if(st.empty()){
                        return false;
                    }
                    else{
                        char ch = st.top();
                        st.pop();
                        if((i == ')' && ch == '(') || (i =='}' && ch=='{') || (i==']' && ch=='[') ){
                            continue;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }

        return st.empty();
    }
};