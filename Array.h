#ifndef ARRAY_H
#define ARRAY_H

class Array {
public:
    explicit Array(int capacity);
    ~Array();

    bool Add(int value);
    bool InsertAt(int index, int value);
    bool DeleteAt(int index);
    bool UpdateAt(int index, int new_value);
    void Print() const;

    int Size() const;
    int Capacity() const;
    int GetAt(int index) const;

private:
    int* data_;
    int capacity_;
    int size_;
    
    
    bool IsValidIndex(int index) const;
    bool IsValidInsertIndex(int index) const;
    void ShiftRight(int startIndex);
    void ShiftLeft(int startIndex);
};

#endif  // ARRAY_H
