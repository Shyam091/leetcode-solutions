class Trie {
public:
    char ch;
    Trie* children[26];
    bool isTerminated;
    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminated = false;
    }

    void insert(string word) {
        if (word.size() == 0) {
            this->isTerminated = true;
            return ;
        }

        int ind = word[0] - 'a';
        Trie* child;

        if (this->children[ind] != nullptr) {
            child = this->children[ind];
        } else {
            child = new Trie();
            child->ch = word[0];
            this->children[ind] = child;
        }
        child->insert(word.substr(1));
    }

    bool search(string word) {
        if (word.size() == 0) {
            return this->isTerminated;
        }

        int ind = word[0] - 'a';

        if (this->children[ind] != nullptr) {
            return  this->children[ind]->search(word.substr(1));
        } else {
            return false ;
        }

    }

    bool startsWith(string prefix) {
        if(prefix.size() == 0)
        {
            return true;
        }
        int ind = prefix[0] - 'a';

        if(this->children[ind] != nullptr)
        {
            return this->children[ind]->startsWith(prefix.substr(1));
        }
        else{
            return false ;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */