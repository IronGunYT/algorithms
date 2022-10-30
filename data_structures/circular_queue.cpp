/****************************************************************
 * @file
 * @brief Circular Queue Data Structure
 * @details
 * Circular Queue is a data structure, that allows adding and removing elements
 * in a FIFO (First In First Out) order
 * It allows to get elements by circular order
 *
 * Realization using linked list
 *
 * ### Complexity
 *
 * Access : O(1)
 * Search : O(n)
 * Insert : O(1)
 * Delete : O(1)
 * Space Complexity : O(n)
****************************************************************/

#include <iostream>

template <typename T>
struct Node{
    T data;
    Node<T> *next;
};
template <typename T>
class CircularQueue{
    Node<T> *front = nullptr;
    Node<T> *rear = nullptr;

    /**
     * @brief Creates first node
     * @param val - value to add
     */
     void create_node(T val){
        auto *nd = new Node<T>;
        nd->data = val;
        nd->next = nullptr;
        front = nd;
        rear = nd;
    }

public:
    /**
     * @brief Constructor
     */
    CircularQueue() = default;

    /**
     * @brief Add element to the end of the queue
     */
    void add(T val){
        if(front == nullptr || rear == nullptr)
            create_node(val);
        else{
            auto *nd = new Node<T>;
            nd->data = val;
            rear->next = nd;
            nd->next = front;
            rear = nd;
        }
    }

    /**
     * @brief Get and remove element from the front of the queue
     * @returns value of the element
     */
    T remove(){
        if(front == nullptr || rear == nullptr)
            throw std::runtime_error("Queue is empty");
        else{
            T val = front->data;
            if(front == rear){
                delete front;
                front = nullptr;
                rear = nullptr;
            }else{
                Node<T> *temp = front;
                front = front->next;
                rear->next = front;
                delete temp;
            }
            return val;
        }
    }

    /**
     * @brief Get and move to the end element from the front of the queue
     * @returns value of the element
     */
     T move(){
        if(front == nullptr || rear == nullptr)
            throw std::runtime_error("Queue is empty");
        else{
            T val = front->data;
            if(front != rear){
                Node<T> *temp = front;
                front = front->next;
                rear->next = temp;
                rear = temp;
                rear->next = front;
            }
            return val;
        }
     }

    /**
     * @brief Traverse the queue
     */
    void traverse(){
        if(front == nullptr || rear == nullptr)
            throw std::runtime_error("Queue is empty");
        else{
            Node<T> *temp = front;
            while(temp->next != front){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << temp->data << std::endl;
        }
    }

    /**
     * @brief Destructor
     */
    ~CircularQueue(){
        if(front == nullptr || rear == nullptr)
            return;
        else{
            Node<T> *temp = front;
            while(temp->next != front){
                Node<T> *temp2 = temp;
                temp = temp->next;
                delete temp2;
            }
            delete temp;
        }
    }
};

int main(){
    std::cout << "Circular Queue test" << std::endl;
    CircularQueue<int> queue;
    queue.add(1);
    queue.add(2);
    queue.add(3);
    queue.add(4);
    queue.add(5);
    queue.traverse();
    std::cout << "Moving element" << std::endl;
    queue.move();
    queue.traverse();
    std::cout << "Removing element: " << queue.remove() << std::endl;
    queue.traverse();
    std::cout << "Removing element: " << queue.remove() << std::endl;
    queue.traverse();
    return 0;
}
