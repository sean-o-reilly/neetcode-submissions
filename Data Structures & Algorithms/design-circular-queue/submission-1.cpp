void print(auto r)
{
    for (auto n : r)
        std::cerr << n << " ";
    std::cout << std::endl;
}

class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    : arr(k, 0)
    {}
    
    bool enQueue(int value)
    {
        if (isFull()) return false;

        arr.at(writeCursor % arr.size()) = value;
        ++writeCursor;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        readCursor++;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr.at(readCursor % arr.size());
    }
    
    int Rear() {
        if (isEmpty()) return -1;

        return arr.at((writeCursor - 1) % arr.size());
    }
    
    bool isEmpty() {
        return writeCursor == readCursor;
    }
    
    bool isFull() {
        return writeCursor - readCursor >= arr.size();
    }
private:
    std::vector<int> arr;

    int writeCursor{};
    int readCursor{};
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */