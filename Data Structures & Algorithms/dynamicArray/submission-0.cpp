class DynamicArray {
public:

    DynamicArray(int capacity)
    : size_{0}, capacity_{capacity}, data_{new int[capacity_]}
    {
        
    }

    int get(int i)
    {
        return data_[i];
    }

    void set(int i, int n)
    {
        data_[i] = n;
    }

    void pushback(int n)
    {
        // handle resize
        if (size_ == capacity_)
        {
            resize();
        }

        data_[size_] = n;
        ++size_;
    }

    int popback()
    {
        int res = data_[size_ - 1];
        --size_;
        return res;
    }

    void resize()
    {
        const int newCapacity = capacity_ * 2;

        std::unique_ptr<int[]> newData(new int[newCapacity]);

        for (int i = 0; i < capacity_; ++i)
        {
            newData[i] = data_[i]; // copy elements TODO move if no except
        }

        data_.swap(newData); // make newData point to the old data and delete it on scope exit
        capacity_ = newCapacity;
    }

    int getSize()
    {
        return size_;
    }

    int getCapacity()
    {
        return capacity_;
    }

private:

    std::unique_ptr<int[]> data_;
    int size_; // also tracks end of array
    int capacity_;

};
