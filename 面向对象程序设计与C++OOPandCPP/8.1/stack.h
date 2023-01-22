//
// Created by Planck Chang on 2021/12/6.
//

#ifndef INC_8_1_8_2_STACK_H
#define INC_8_1_8_2_STACK_H

#include <iostream>
template<class T>
class STACK
{
private:
    struct link{
        link *next;
        T * data;

        link(T * data, link * next){
            this->data = data;
            this->next = next;
        }
    } * head;
public:
    STACK():head(NULL){}
    virtual  ~STACK();
    void push(T * data){head = new link(data, head);}
    T * pop();
    T * peek() const { return head->data;}


};

template<class T>T * STACK<T>::pop() {
    if(head== NULL) return NULL;
    else{
        T * result = head->data;
        link * oldhead = head;
        head = head->next;
        delete oldhead;
        return result;
    }
}

template<class T>STACK<T>::~STACK<T>() {
    link *cur = head;
    while(head != NULL){
        cur = cur->next;
        delete head->data;
        delete head;
        head = cur;
    }
}

#endif //INC_8_1_8_2_STACK_H
