class List {
    int val;
    List *next, *prev;
public:
    List() {}
    List(int x) {
        val = x;
        next = nullptr;
        prev = nullptr;
    }
    friend class MyCircularDeque;
};

class MyCircularDeque {
public:
    int len = 0, total;
    List *front = nullptr, *back = nullptr;

    MyCircularDeque(int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        total = k;
        front = nullptr;
        back = nullptr;
    }

    bool insertFront(int value) {
        if (len >= total) return false;
        List *temp = new List(value);
        if (front == nullptr) {
            front = temp;
            back = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        len++;
        return true;
    }

    bool insertLast(int value) {
        if (len >= total) return false;
        List *temp = new List(value);
        if (back == nullptr) {
            front = temp;
            back = temp;
        } else {
            back->next = temp;
            temp->prev = back;
            back = temp;
        }
        len++;
        return true;
    }

    bool deleteFront() {
        if (len == 0) return false;
        if (front == back) {
            delete front;
            front = nullptr;
            back = nullptr;
        } else {
            List *temp = front;
            front = front->next;
            front->prev = nullptr;
            delete temp;
        }
        len--;
        return true;
    }

    bool deleteLast() {
        if (len == 0) return false;
        if (front == back) {
            delete back;
            front = nullptr;
            back = nullptr;
        } else {
            List *temp = back;
            back = back->prev;
            back->next = nullptr;
            delete temp;
        }
        len--;
        return true;
    }

    int getFront() {
        if (len == 0) return -1;
        return front->val;
    }

    int getRear() {
        if (len == 0) return -1;
        return back->val;
    }

    bool isEmpty() {
        return len == 0;
    }

    bool isFull() {
        return len == total;
    }
};
