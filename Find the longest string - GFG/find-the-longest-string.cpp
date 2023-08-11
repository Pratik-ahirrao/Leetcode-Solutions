//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    void setFlag(){
        flag = true;
    }
};

class Trie{
    private:
        Node* root;

    public:

        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* node = root;

            for(int i = 0;i < word.size();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }

            node->setFlag();
        }

        bool isPrefixExists(string word){
            Node* node = root;

            for(int i = 0;i < word.size();i++){
                if(!node->containsKey(word[i])) return false;

                node = node->get(word[i]);
                if(node->flag == false) return false;
            }
            return node->flag;
        }
};

class Solution
{
public:
    string longestString(vector<string> &a)
    {
        // code here
        Trie tr;

    for(auto it: a){
        tr.insert(it);
    }

    string longest = "";

    for(auto it: a){
        if(tr.isPrefixExists(it)){
            if(it.size() > longest.size()) longest = it;

            else if(it.size() == longest.size() && it < longest) longest = it;
        }
    }
    return longest;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends