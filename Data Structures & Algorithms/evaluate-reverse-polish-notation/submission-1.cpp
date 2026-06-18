class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto &c : tokens){
            if(c == "+" || c=="-" || c=="*" || c=="/"){
                int num2 = stoi(st.top());
                st.pop();
                int num1 = stoi(st.top());
                st.pop();
                int res;
                if (c == "+") res = num1 + num2;
                else if (c == "-") res = num1 - num2;
                else if (c == "*") res = num1 * num2;
                else if (c == "/") res = num1 / num2;
                string x = to_string(res);
                st.push(x);
            } else{
                st.push(c);
            }
        }
        int ans = stoi(st.top());
        return ans;
    }
};
