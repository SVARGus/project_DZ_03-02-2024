#include <iostream>
template<class T>
class Node {
    template<class T1>
    friend class OneLinkedList;

    T data;
    Node* next;

public:
    explicit Node(T data) : data{ data }, next{ nullptr } {}

    T getData() const {
        return data;
    }
    void setData(T data) {
        this->data = data;
    }

    void print() const {
        std::cout << " data = " << data << std::endl;
    }
};

template<class T1>
class OneLinkedList {

    Node<T1>* head, * tail;

public:

    OneLinkedList() : head{ nullptr }, tail{ nullptr } {}

    ~OneLinkedList() {
        while (head)
            pop_front();
    }

    void push_front(T1 data) {
        Node<T1>* node = new Node<T1>(data);
        node->next = head;
        head = node;
        if (!tail)
            tail = node;
    }

    void push_back(T1 data) {
        Node<T1>* node = new Node<T1>(data);
        if (!head)
            head = node;
        if (tail)
            tail->next = node;
        tail = node;
    }

    void pop_front() {
        if (!head)
            return;

        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }

        Node<T1>* node = head;
        head = node->next;
        delete node;
    }

    void pop_back() {
        if (tail == nullptr) return;

        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }

        Node<T1>* node = head;
        for (; node->next != tail; node = node->next);
        node->next = nullptr;
        delete tail;
        tail = node;
    }

    Node<T1>* getAt(int k) {

        if (k < 0) return nullptr;

        Node<T1>* node = head;
        int n = 0;
        while (node != nullptr) {
            if (n == k)
                return node;
            ++n;
            node = node->next;
        }

        return nullptr;
    }

    void insert(int k, T1 data) {

        Node<T1>* left = getAt(k);
        if (!left)
            return;

        Node<T1>* right = left->next;
        Node<T1>* node = new Node(data);
        left->next = node;
        node->next = right;
        if (!right)
            tail = node;
    }

    void erase(int k) {
        if (k < 0) return;
        if (k == 0) {
            pop_front();
            return;
        }

        Node<T1>* left = getAt(k - 1);
        Node<T1>* node = left->next;
        if (!node)
            return;
        Node<T1>* right = node->next;

        left->next = right;
        if (node == tail)
            tail = left;
        delete node;
    }

    void print() {
        for (Node<T1>* node = head; node != nullptr; node = node->next) {
            node->print();
        }
        std::cout << std::endl << std::endl;
    }
};

int main() {

    OneLinkedList<int> list;

    list.print();

    list.push_front(1);
    list.print();

    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);

    list.print();

    /*list.pop_back();

    list.print();*/

    Node<int>* node = list.getAt(1);
    node->print();

    std::cout << std::endl;

    list.erase(1);

    list.print();

    OneLinkedList<char> listChar;
    listChar.push_front('h');
    listChar.push_back('x');
    listChar.push_back('y');
    listChar.print();
    listChar.pop_back();
    listChar.print();
    listChar.push_back('y');
    listChar.print();
    listChar.insert(1, 'Z');
    listChar.print();
    listChar.erase(1);
    listChar.print();

    OneLinkedList<double> listD;
    listD.push_front(1.65);
    listD.push_back(1.25);
    listD.push_back(3.25);
    listD.print();

    OneLinkedList<std::string> listString;
    listString.push_front("fjhdkfjgh");
    listString.push_back("Kadavr");
    listString.push_back("Rent");
    listString.print();


    return 0;
}

