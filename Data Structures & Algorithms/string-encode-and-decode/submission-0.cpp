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
        cout << out << "\n";
        return out;
    }

    vector<string> decode(string s) {
        int len = 0;
        string len_str = "";
        string curr_str;
        vector<string> out;
        int str_counter = 0;
        for (auto c: s) {
            if (len == 0) {
                if (c != '#') {
                    // assert(c >= '0' && x <= '9')
                    len_str += c;
                } else {
                    len = std::stoi(len_str);
                    len_str = "";
                    curr_str = "";
                    if (len == 0) {
                        out.push_back("");
                    }
                }
            } else {
                curr_str += c;
                if (curr_str.size() == len) {
                    len = 0;
                    out.push_back(curr_str);
                    curr_str = "";
                }
            }
        }
        return out;
    }
};
