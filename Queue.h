
#ifndef _QUEUELIST_H
#define _QUEUELIST_H

#include "stdio.h"     /**< called for printf() */

/**
 * @brief Debug types for printf
 */
typedef enum debug_types_t
{
    IS_INFO    = 0x0001,    /**< for info messages */
    IS_FULL    = 0x0002,    /**< for queue full  */
    IS_FATAL   = 0x0004,    /**< for fatal errors messages */
    IS_ERROR   = 0x0008     /**< for errors messages */
}debug_types_t;

/**
 * @brief print debug message to stdout or semihosting channel
 * @tparam Debug type of message
 * @tparam debug message to print
 */
template<typename T,typename K>
void Print_Message(T debug_type, K debug_message)
{
    /*print to stdout or semihosting channel*/
    printf("%d,%s\n",debug_type, debug_message);
}

/**
 * @brief QueueList Class
 * @tparam type of queue(int,string??)
 */
template<typename T>
class QueueList {
public:

    /**
     * @brief Queuelist constructor
     */
    QueueList ();

    /**
     * @brief Queuelist deconstructor
     */
    ~QueueList ();

    // push an item to the queue.
    void push (const T i);

    // pop an item from the queue.
    T pop ();

    // get an item from the queue.
    T peek () const;

    /**
     * @brief Check queue is empty or full?
     */
    bool isEmpty () const;

    /**
     * @brief Get current items size of queue.
     */
    int Count () const;


private:

    /**
     * @brief the structure of each node in the list.
     */
    typedef struct node {
      T item;       /**< the node item in the list */
      node * next;  /**< the next node item in the list */
    } node;

    typedef node * link;  /**< point node to link */

    int  size;       /**<  size of queue list */
    link head;       /**<  head item of queue list */
    link tail;       /**<  tail item of queuelist */
};

/**
 * @brief QueueList constructor
 * @tparam type of queue(int,string??)
 */
template<typename T>
QueueList<T>::QueueList () {

  /* create a new queue list*/

  size = 0;      /* define size of queue */
  head = NULL;   /* define head item with null, because queue is now created  */
  tail = NULL;   /* define tail item with null, because queue is now created  */

}

/**
 * @brief QueueList deconstructor
 * @tparam type of queue(int,string??)
 */
template<typename T>
QueueList<T>::~QueueList () {

  /* destroy current queue list and deallocate memory*/

  /*scan queue from head to tail*/
  for (link t = head; t != NULL; head = t) {
    t = head->next; 
    delete head;
  }

  size = 0;       /* set the size of queue to zero. */
  tail = NULL;    /* set the tail of the list to point nowhere. */

}

// push an item to the queue.
template<typename T>
void QueueList<T>::push (const T i) {
    
  // create a temporary pointer to tail.
  link t = tail;

  // create a new node for the tail.
  tail = (link) new node;

  // if there is a memory allocation error.
  if (tail == NULL)
    Print_Message(IS_FATAL,"Memory Allocation Error");

  // set the next of the new node.
  tail->next = NULL;

  // store the item to the new node.
  tail->item = i;

  // check if the queue is empty.
  if (isEmpty ())
    // make the new node the head of the list.
    head = tail;
  else
    // make the new node the tail of the list.
    t->next = tail;
  
  // increase the items.
  size++;
}

// pop an item from the queue.
template<typename T>
T QueueList<T>::pop () {
  // check if the queue is empty.
  if (isEmpty ())
    int k=0;

  // get the item of the head node.
  T item = head->item;

  // remove only the head node.
  link t = head->next; delete head; head = t;

  // decrease the items.
  size--;

  // return the item.
  return item;
}

/**
 * @brief Check queue is empty or full?
 * @tparam Type of queue
 */
template<typename T>
T QueueList<T>::peek () const {
  // check if the queue is empty.
  if (isEmpty ())
    exit ("QUEUE: can't peek item from queue: queue is empty.");

  // return the item of the head node.
  return head->item;
}

/**
 * @brief Check queue is empty or full?
 * @tparam Type of queue
 */
template<typename T>
bool QueueList<T>::isEmpty () const {

  return head == NULL; /* return if head is not null*/
}

/**
 * @brief Get current items size of queue.
 * @tparam Type of queue
 */
template<typename T>
int QueueList<T>::Count () const {

  return size; /* return size of queue list*/

}

#endif // _QUEUELIST_H
