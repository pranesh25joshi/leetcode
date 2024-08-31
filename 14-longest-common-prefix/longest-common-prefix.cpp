class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertFunction(TrieNode* root, string str) {
        if (str.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = str[0] - 'a';
        TrieNode* child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(str[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertFunction(child, str.substr(1));
    }

    void insertWord(string str) {
        insertFunction(root, str);
    }

    string getLongestCommonPrefix() {
        TrieNode* current = root;
        string prefix = "";

        while (current->childCount == 1 && !current->isTerminal) {
            for (int i = 0; i < 26; i++) {
                if (current->children[i] != nullptr) {
                    prefix += current->children[i]->data;
                    current = current->children[i];
                    break;
                }
            }
        }

        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie* t = new Trie('\0');
        for (auto i : strs) {
            t->insertWord(i);
        }

        return t->getLongestCommonPrefix();
    }
};
