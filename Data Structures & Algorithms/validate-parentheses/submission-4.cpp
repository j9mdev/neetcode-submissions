class Solution {
public:
    bool isValid(string s) {
        // q; Open brackets are closed in the correct order. like c
        // meaning latest open bracket should be closed first LIFO
        // possible solution
        // use stack; e.g.) stack./ or vector; can also use string itself as stack
        
        stack<char> st;

        // cannot use in stack
        // st.reserve(s.size());

        for(auto c: s) {
            if ( c == '(' || 
                 c == '{' || 
                 c == '[')
            {
                st.push(c);
            } else {
                if ( c == ')') {
                    if (st.size()==0) return false;
                    if ( st.top() != '(' ) return false;
                    else st.pop();
                } else if ( c == '}') {
                    if (st.size()==0) return false;
                    if ( st.top() != '{' ) return false;
                    else st.pop();
                } else if ( c == ']') {
                    if (st.size()==0) return false;
                    if ( st.top() != '[' ) return false;
                    else st.pop();
                }
            }
        }
        if ( st.size() == 0 ) return true;
        else return false;
    }
};
