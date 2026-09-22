class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;

        // trailing spaces skip karo
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        int length = 0;
        // last word ke characters count karo
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};