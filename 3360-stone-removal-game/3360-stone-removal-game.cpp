class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool alice = true;

        while (n >= remove) {
            n -= remove;
            remove--;
            alice = !alice;
        }
        // jo player move nahi kar paya wo hara
        //agar ab Bob ki turn hai aur wo move nahi kar sakta, to alice jeeti
        return !alice; 
    }
};