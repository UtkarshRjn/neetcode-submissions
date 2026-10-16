class DynamicArray {

    int* arr = nullptr;
    int size = 0;
    int capacity = 0;

public:

    DynamicArray(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
                
        if(size == capacity){
            resize();
        }

        arr[size++] = n;

    }

    int popback() {
        return arr[--size]; // Its ok if we have extra memory allocated
    }

    void resize() {

        int* temp = new int[capacity * 2];
        for(int i=0;i<size;i++){
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        capacity = 2*capacity;

    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
