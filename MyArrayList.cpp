// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class MyArrayList {
    private:
    unsigned size;
    unsigned capa = 1;
    int* elements;
    void resize() {
        if (size >= capa) {
            capa *= 2;
            int* new_arr = new int[capa];
            for (int i = 0; i < size; i++) {
                new_arr[i] = elements[i];
            }
            delete[] elements;
            elements = new_arr;
        }
    }
    
    public:
    
    //constructors
    MyArrayList() {
        size = 0;
        elements = new int[capa];
    }

    ~MyArrayList() {
        delete[] elements;
    }
    // template <typename t, typename... type>
    // MyArrayList(t first, type... args) {
    //     elements = new int[capa];
    //     elements[size] = first;
    //     MyArrayList(args...);
    //     // for (int i = 0; i < args.size(); i++) {
    //     //     resize();
    //     //     elements[size] = args[i];
    //     //     size++;
    //     // }
    // }
    
    //methods of my arraylist
    void push(int elem) {
        resize();
        elements[size] = elem;
        size++;
    }
    
    void pop() {
        if (size != 0) size--;
        else throw std::out_of_range("the list is empty!");
    }

    void addZero(int value) {
        addAt(0, value);
    }
    
    int at(unsigned index) const{
        if (index >= size) {
            throw std::out_of_range("index out of bounds!");
        }
        return elements[index];
    }

    int getsize() const{
        return size;
    }
    
    int getcapa() const{
        return capa;
    }
    
    void display() const {
        for (int i = 0; i < size; i++) {
            std::cout << elements[i] << ", ";
        }std::cout << std::endl;
    }

    void addAt(unsigned index, int value) {
        if (index > size) {
            throw std::out_of_range("index out of bounds!");
        }
        resize();
        if (index == size) {
            push(value);
            return;
        }
        for (int i = size; i > index; i--) {
            elements[i] = elements[i-1];
        }
        elements[index] = value;
        size++;

    }

    void removeAt(unsigned index) {
        for (int i = index; i < size; i++) {
            elements[i] = elements[i+1];
        }
        size--;
    }

    bool contains(int val) const {
        for (int i = 0; i < size; i++) {
            if (elements[i] == val) return true;
        }
        return false;
    }
    
};

int main() {
    MyArrayList n;

    n.push(5);
    n.push(6);
    n.push(22);
    n.push(0);

    n.addAt(0, 9);
    n.addAt(1, 11);
    n.addAt(5, 8);
    
    n.display();

    n.removeAt(0);
    n.removeAt(n.getsize());
    n.display();
    n.removeAt(3);
    n.display();

    n.addZero(8);
    n.display();
    cout << n.contains(89) << endl;

    return 0;
}