class MyCircularQueue {
   public:
    MyCircularQueue(int k) : arr(k, 0) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        arr.at(writeCursor++ % arr.size()) = value;
        return true;
    }

    bool deQueue() { return isEmpty() ? false : ++readCursor; }

    int Front() { return isEmpty() ? -1 : arr.at(readCursor % arr.size()); }

    int Rear() { return isEmpty() ? -1 : arr.at((writeCursor - 1) % arr.size()); }

    bool isEmpty() { return writeCursor == readCursor; }

    bool isFull() { return writeCursor - readCursor >= arr.size(); }

   private:
    std::vector<int> arr;
    int writeCursor{};
    int readCursor{};
};