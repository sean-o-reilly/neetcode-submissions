class LinkedList {
public:
    LinkedList()
    : head_{nullptr}
    {}

    int get(int index)
    {
        int i = 0;
        Node* curr = head_;

        while (curr && i < index)
        {
            curr = curr->next;
            ++i;
        }

        if (curr && i == index)
        {
            return curr->data;
        }

        return -1;
    }

    void insertHead(int val)
    {
        Node* newHead = new Node{val, head_};
        head_ = newHead;
    }
    
    void insertTail(int val)
    {
        if (!head_)
        {
            head_ = new Node{val, nullptr};
            return;
        }

        Node* curr = head_;
        while (curr->next)
        {
            curr = curr->next;
        }

        curr->next = new Node{val, nullptr};
    }

    bool remove(int index)
    {
        if (!head_ || index < 0) // invalid index
        {
            return false;
        }

        if (index == 0) // delete front
        {
            Node* temp = head_->next;
            delete head_;
            head_ = temp;
            return true;
        }

        int i = 0;
        Node* curr = head_;
        Node* prev = curr;

        while (curr && i < index)
        {
            prev = curr;
            curr = curr->next;
            ++i;
        }

        if (!curr)
        {
            return false;
        }

        prev->next = curr->next;
        delete curr;

        return true;
    }

    std::vector<int> getValues() const
    {
        std::vector<int> res;
        Node* curr = head_;
        while (curr)
        {
            res.push_back(curr->data);
            curr = curr->next;
        }

        return res;
    }

private:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* head_;

};


/*

3 Cases:
    Size = 0
    Size = 1
    Size = n

*/
