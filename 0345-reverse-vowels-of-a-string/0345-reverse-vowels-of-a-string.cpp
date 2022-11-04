class Solution {
public:
    string reverseVowels(string s) {
        auto i = s.begin();
        auto j = s.end() - 1;
        string str = "aeiouAEIOU";
        while(i < j){
            while((str.find(*i) == string::npos) && i < j)
                i++;
            while((str.find(*j) == string::npos) && i < j)
                j--;
            if(i < j)
                swap(*i, *j);
            i++;
            j--;
        }return s;
    }
};