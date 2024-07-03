/*
Домашнее задание от 02.07.2024

Переделать класс однонаправленный список для переменной одного типа в шаблон и тест

*/
#include <iostream>

template<class T>
class Node {
    friend class OneLinkedList<T>;
    T content;
    Node* next;

public:
    explicit Node(T content) : content{content}, next{nullptr}{}
    void setContent(T content) {
        this->content = content;
    }
    T getContent() const {
        return content;
    }
    void printContent() {
        std::cout << "Content = " << content << std::endl;
    }
};

template<class T>
class OneLinkedList {
    Node<T>* head;
    Node<T>* tail;
    
public:
    OneLinkedList() : head{nullptr}, tail{nullptr}{}

    ~OneLinkedList() {
        // дописать как разберусь с созданием, добавлением и перейду к удалению
    }

    void pushFront(T content) {
        Node<T> *node = new Node<T>(content);
        node->next = head;
        head = node;
        if (!tail)
            tail = node;
    }
    void pushBack(T content) {

    }

    void popFront() {

    }
    void popBack() {

    }


};


int main()
{
    setlocale(LC_ALL, "ru");



    return 0;
}
