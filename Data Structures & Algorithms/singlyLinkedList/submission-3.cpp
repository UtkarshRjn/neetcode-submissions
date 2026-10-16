class LinkedList {

    LinkedList* next = nullptr;
    int val = 0;
    bool isEmpty = true;

public:
    LinkedList() {
    }

    int get(int index) {

        if(isEmpty) return -1;

        LinkedList* temp = this;
        while(index--){
            if(!temp->next) return -1;
            temp = temp->next;
        }

        return temp->val;

    }

    void insertHead(int val) {
        
        if (isEmpty) {
            this->val = val;
            isEmpty = false;
            return;
        }

        LinkedList* node = new LinkedList();
        node->val = this->val;
        node->next = this->next;

        this->val = val;
        this->next = node;

    }
    
    void insertTail(int val) {

        if (isEmpty) {
            this->val = val;
            isEmpty = false;
            return;
        }

        LinkedList* temp = this;
        while(temp->next){
            temp = temp->next;
        }

        LinkedList* tail = new LinkedList();
        tail->val = val;
        temp->next = tail;

    }

    bool remove(int index) {
        if (isEmpty || index < 0) return false;

        if (index == 0) {
            if (!next) {
                isEmpty = true;
                return true;
            }

            LinkedList* node = next;
            val = node->val;
            next = node->next;
            delete node;
            return true;
        }

        LinkedList* temp = this;

        for (int i = 0; i < index - 1; i++) {
            if (!temp->next) return false;
            temp = temp->next;
        }

        if (!temp->next) return false;

        LinkedList* node = temp->next;
        temp->next = node->next;
        delete node;
        return true;
    }

    vector<int> getValues() {
        
        vector<int> values;

        if (isEmpty) return values;

        LinkedList* temp = this;
        while(temp){
            values.push_back(temp->val);
            temp = temp->next;
        }

        return values;

    }
};
