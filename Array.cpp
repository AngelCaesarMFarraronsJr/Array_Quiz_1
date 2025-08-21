#include <iostream>
#include <stdexcept>
#include "Array.h"

Array::Array(int capacity) : capacity_(capacity), size_(0) {
    data_ = new int[capacity_];
}

Array::~Array() {
    delete[] data_;
}

bool Array::IsValidIndex(int index) const {
    return index >= 0 && index < size_;
}

bool Array::IsValidInsertIndex(int index) const {
    return index >= 0 && index <= size_;
}

void Array::ShiftRight(int startIndex) {
    for (int i = size_; i > startIndex; i--) {
        data_[i] = data_[i - 1];
    }
}

void Array::ShiftLeft(int startIndex) {
    for (int i = startIndex; i < size_ - 1; i++) {
        data_[i] = data_[i + 1];
    }
}

bool Array::Add(int value) {
    if (size_ == capacity_) {
        return false;  // no space
    }
    data_[size_] = value;
    size_++;
    return true;
}

bool Array::InsertAt(int index, int value) {
   
    if (size_ == capacity_ || !IsValidInsertIndex(index)) {
        return false;
    }
    
    
    ShiftRight(index);
    
    
    data_[index] = value;
    size_++;
    
    return true;
}


bool Array::DeleteAt(int index) {
    
    if (!IsValidIndex(index)) {
        return false;
    }
    
    
    ShiftLeft(index);
    
    
    size_--;
    
    return true;
}


bool Array::UpdateAt(int index, int new_value) {
    
    if (!IsValidIndex(index)) {
        return false;
    }
    
    
    data_[index] = new_value;
    
    return true;
}


void Array::Print() const {
    if (size_ == 0) {
        std::cout << "[Empty]" << std::endl;
        return;
    }
    std::cout << "[ ";
    for (int i = 0; i < size_; i++) {
        std::cout << data_[i];
        if (i != size_ - 1) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}


int Array::Size() const {
    return size_;
}


int Array::Capacity() const {
    return capacity_;
}


int Array::GetAt(int index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}
