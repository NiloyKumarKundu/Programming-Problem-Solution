class Trie {
    struct triNode {
        char val;
        int count;
        int endsHere;
        triNode *child[26];
    };
    
    triNode *root;
    triNode *getNode(int index) {
        triNode *newNode = new triNode();
        newNode->val = 'a' + index;
        newNode->count = newNode->endsHere = 0;
        
        for (int i = 0; i < 26; i++) {
            newNode->child[i] = NULL;
        }
        return newNode;
    }
    
    
public:

    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getNode('/' - 'a');
    }
    
    void insert(string word) {
        triNode *cur = root;
        int index;
        
        for (int i = 0; word[i] != '\0'; i++) {
            index = word[i] - 'a';
            if (cur->child[index] == NULL) {
                cur->child[index] = getNode(index);
            }
            cur->child[index]->count += 1;
            cur = cur->child[index];
        }
        cur->endsHere += 1;
    }
    
    bool search(string word) {
        triNode *cur = root;
        int index;
        for (int i = 0; word[i] != '\0'; i++) {
            index = word[i] - 'a';
            if (cur->child[index] == NULL) {
                return false;
            }
            cur = cur->child[index];
        }
        return (cur->endsHere > 0);
    }
    
    bool startsWith(string prefix) {
        triNode *cur = root;
        int index;
        for (int i = 0; prefix[i] != '\0'; i++) {
            index = prefix[i] - 'a';
            if (cur->child[index] == NULL) {
                return false;
            }
            cur = cur->child[index];
        }
        return (cur->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */