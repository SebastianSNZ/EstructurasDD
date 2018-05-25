#ifndef LIST_H
#define LIST_H

template <class T>
class Node
{
public:
    Node(T *object);
    T* getElement() const;
    void setElement(T* value);
    int getIndex() const;
    void setIndex(int value);
    Node<T> *getPrev() const;
    void setPrev(Node<T> *value);
    Node<T> *getNext() const;
    void setNext(Node<T> *value);

private:
    Node<T> *next;
    Node<T> *prev;
    T* element;
    int index;
};

template <class T>
class List
{
public:
    List();
    void insert(T* object);
    void insertFirst(T* object);
    void insertAt(int index, T* object);
    void insertAfterAt(int index, T* object);
    Node<T>* getAt(int index);
    Node<T>* search(T object);
    void deleteAt(int index);
    void deleteThis(T object);
    //GETTER AND SETTER
    Node<T> *getHead() const;
    void setHead(Node<T> *value);
    Node<T> *getTail() const;
    void setTail(Node<T> *value);
    int getSize() const;
    void setSize(int value);
    QString getTitle() const;
    void setTitle(const QString &value);
    void setEmpty();

private:
    void deleteAt(Node<T>* toDelete);
    QString title;
    Node<T> *head;
    Node<T> *tail;
    int size;
};



#endif // LIST_H
