class PrefixTree {
public:

    static constexpr char offset = 'a';

    struct Node
    {
        std::array<Node*, 26> children_{};
    };

    Node* head_{};
    std::unordered_set<std::string> words_;

    PrefixTree() : head_{new Node}
    {}
    
    void insert(string word)
    {
        words_.insert(word);

        Node* curr = head_;
        for (auto c : word)
        {
            Node*& next = curr->children_.at(c - offset);
            if (!next) next = new Node;
            curr = next;
        }
    }
    
    bool search(string word) const
    {
        return words_.contains(word);
    }
    
    bool startsWith(string prefix) const
    {
        const Node* curr = head_;
        for (auto c : prefix)
        {
            Node* next = curr->children_.at(c - offset);
            if (!next) return false;
            curr = next;
        }

        return true;
    }
};
