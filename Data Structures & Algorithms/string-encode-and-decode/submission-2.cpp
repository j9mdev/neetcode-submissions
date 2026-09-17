/*

encoding rule: simple
- no endian consideration

[length][#][string]

- length and string is vriable length

read numbers until we meet #
then read length bytes

*/

class Solution {
public:

    string encode(vector<string>& strs) {
        string out;
        for (auto str: strs) {
            int len = str.size();
            out += std::to_string(len);
            out += "#";
            out += str;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        int i=0;
        while (i<(int)s.size()) {
            string len_str;
            while (s[i]!='#') {
                len_str += s[i];
                i++;
            }
            int len = stoi(len_str);
            i++;
            string str;
            str = s.substr(i,len);
            i+=len;
            out.push_back(str);
        }
        return out;
    }
};
