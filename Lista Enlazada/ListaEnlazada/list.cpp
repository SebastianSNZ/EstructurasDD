#pragma once
#include "list.h"

template <class T>
List<T>::List()
{
    this->setHead(nullptr);
    this->setTail(nullptr);
    this->setSize(0);
    this->setTitle("");
}

template <class T>
Node<T>::Node(T* object)
{
    this->setElement(object);
    this->setIndex(0);
    this->setNext(nullptr);
    this->setPrev(nullptr);
}


template<class T>
void List<T>::setEmpty()
{
    this->setHead(nullptr);
    this->setTail(nullptr);
    this->setSize(0);
    this->setTitle("");
}


template <class T>
void List<T>::insert(T* object)
{
    Node<T> *newNode = new Node<T>(object);
    if(this->getHead() == nullptr)
    {
        setHead(newNode);
        setTail(newNode);
        newNode->setIndex(size);
        size++;
    }
    else
    {
        getTail()->setNext(newNode);
        newNode->setPrev(getTail());
        setTail(newNode);
        getTail()->setIndex(size);
        size++;
    }
}

template<class T>
void List<T>::insertFirst(T *object)
{
    if(this->getHead() == nullptr)
    {
        insert(object);
    }
    else
    {
        Node<T> *newNode = new Node<T>(object);
        newNode->setNext(this->getHead());
        this->getHead()->setPrev(newNode);
        this->setHead(newNode);

        this->getHead()->setIndex(0);

        Node<T> *aux = this->getHead()->getNext();
        while(aux != nullptr)
        {
            aux->setIndex(aux->getIndex() + 1);
            aux = aux->getNext();
        }
        size++;
    }
}

template<class T>
void List<T>::insertAt(int index, T *object)
{
    Node<T> *newNode = new Node<T>(object);
    if(index >= this->getSize())
    {
        this->insert(object);
        return;
    }
    else
    {
        Node<T> *aux = this->getHead();
        while(aux != nullptr && aux->getIndex() != index )
        {
            aux = aux->getNext();
        }

        if(aux == this->getHead()){
            this->insertFirst(object);
            return;
        }
        else
        {
            newNode->setIndex(index);
            newNode->setPrev(aux->getPrev());
            newNode->setNext(aux);
            aux->getPrev()->setNext(newNode);
            aux->setPrev(newNode);
            size++;
        }
        while(aux != nullptr)
        {
            aux->setIndex(aux->getIndex() + 1);
            aux = aux->getNext();
        }
    }
}

template<class T>
void List<T>::insertAfterAt(int index, T* object)
{
    Node<T> *newNode = new Node<T>(object);
    if(index >= this->getSize())
    {
        this->insert(object);
        return;
    }
    else
    {
        Node<T> *aux = this->getHead();
        while(aux != nullptr && aux->getIndex() != index )
        {
            aux = aux->getNext();
        }

        if(aux == this->getTail()){
            this->insert(object);
            return;
        }
        else
        {
            newNode->setIndex(index + 1);
            newNode->setPrev(aux);
            newNode->setNext(aux->getNext());
            aux->getNext()->setPrev(newNode);
            aux->setNext(newNode);
            aux = newNode->getNext();
            size++;
        }
        while(aux != nullptr)
        {
            aux->setIndex(aux->getIndex() + 1);
            aux = aux->getNext();
        }
    }

}

template<class T>
Node<T> *List<T>::getAt(int index)
{
    Node<T> *aux = this->getHead();
    while(aux != nullptr)
    {
        if(aux->getIndex() == index)
        {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}

template <class T>
Node<T> *List<T>::search(T object)
{
    Node<T>* aux = this->getHead();
    if(aux != nullptr)
    {
        while(aux != nullptr)
        {
            if(aux->getElement() == object)
            {
                return aux;
            }
            aux = aux->getNext();
        }
        return nullptr;

    }
    return nullptr;
}

template<class T>
void List<T>::deleteAt(int index)
{
    Node<T> *look = getAt(index);
    if(look != nullptr)
    {
        deleteAt(look);
    }
}

template<class T>
void List<T>::deleteThis(T object)
{
    Node<T> *look = search(object);
    if(look != nullptr)
    {
        deleteAt(look);
    }
}

template<class T>
void List<T>::deleteAt(Node<T> *toDelete)
{
    if(toDelete == this->getHead())
    {
        Node<T> *another = toDelete->getNext();
        this->setHead(another);
        if(another != nullptr)
        {
            another->setPrev(nullptr);
        }
        while(another != nullptr)
        {
            another->setIndex(another->getIndex() - 1);
            another = another->getNext();
        }
        size--;
    }
    else if (toDelete == this->getTail())
    {
        Node<T> *another = toDelete->getPrev();
        this->setTail(another);
        if(another != nullptr)
        {
            another->setNext(nullptr);
        }
        size--;
    }
    else
    {
        Node<T> *another = toDelete;
        Node<T> *newNext = another->getNext();
        another->getPrev()->setNext(another->getNext());
        another->getNext()->setPrev(another->getPrev());
        another->setNext(nullptr);
        another->setPrev(nullptr);
        while(newNext != nullptr)
        {
            newNext->setIndex(newNext->getIndex() - 1);
            newNext = newNext->getNext();
        }
        size--;

    }

}

/*
 *
 *
 * GETTER AND SETTER MEMBER FUNCTIONS
 *
 *
 */


template <class T>
Node<T> *List<T>::getHead() const
{
    return head;
}

template <class T>
void List<T>::setHead(Node<T> *value)
{
    head = value;
}

template <class T>
Node<T> *List<T>::getTail() const
{
    return tail;
}

template <class T>
void List<T>::setTail(Node<T> *value)
{
    tail = value;
}

template <class T>
int List<T>::getSize() const
{
    return size;
}

template <class T>
void List<T>::setSize(int value)
{
    size = value;
}

template <class T>
QString List<T>::getTitle() const
{
    return title;
}

template <class T>
void List<T>::setTitle(const QString &value)
{
    title = value;
}

template <class T>
T *Node<T>::getElement() const
{
    return element;
}

template <class T>
void Node<T>::setElement(T *value)
{
    element = value;
}

template <class T>
int Node<T>::getIndex() const
{
    return index;
}

template <class T>
void Node<T>::setIndex(int value)
{
    index = value;
}

template <class T>
Node<T> *Node<T>::getPrev() const
{
    return prev;
}

template <class T>
void Node<T>::setPrev(Node<T> *value)
{
    prev = value;
}

template <class T>
Node<T> *Node<T>::getNext() const
{
    return next;
}

template <class T>
void Node<T>::setNext(Node<T> *value)
{
    next = value;
}
