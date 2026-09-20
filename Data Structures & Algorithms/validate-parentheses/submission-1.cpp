class Solution {
public:
    bool isValid(string s) {
        // q; Open brackets are closed in the correct order. like c
        // meaning latest open bracket should be closed first LIFO
        // possible solution
        // use stack; e.g.) stack./ or vector; can also use string itself as stack
        
        // vector
        vector<char> st;
        st.reserve(s.size());

        for(auto c: s) {
            if ( c == '(' || 
                 c == '{' || 
                 c == '[')
            {
                st.push_back(c);
            } else {
                if ( c == ')') {
                    if (st.size()==0) return false;
                    if ( st[st.size()-1] != '(' ) return false;
                    else st.pop_back();
                } else if ( c == '}') {
                    if (st.size()==0) return false;
                    if ( st[st.size()-1] != '{' ) return false;
                    else st.pop_back();
                } else if ( c == ']') {
                    if (st.size()==0) return false;
                    if ( st[st.size()-1] != '[' ) return false;
                    else st.pop_back();
                }
            }
        }
        if ( st.size() == 0 ) return true;
        else return false;
    }
};
