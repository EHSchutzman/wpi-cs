/* File queue.h
 * Contains structure definition for the queue.
 * Also has prototypes for queue functions.
 * @author Tushar Narayan
 */

#ifndef QUEUE_H
#define QUEUE_H

/** Struct to define a queue; each entry can hold a pointer to anything.
 */

struct queue {
  void **queue_head; // Pointer to head of queue
  void **queue_tail; // Pointer to tail of queue
  void **next_head;  // Pointer to next free cell at the head of queue
  void **next_tail;  // Pointer to next free cell at the tail of queue
  int max_cells; // Maximum number of entries in the queue
  int cells_used; // Currently used number of cells
};

typedef struct queue Queue; // for convenience

/**
 *Design Decisions for Queues:
 *-Head and tail pointers point at full cells
 *-The next_head and next_tail  pointers point at empty cells
 *-The bottom of the array in memory is the head, the top is the tail
 *-When an entry is added to the queue, it is added at the tail
 *-When an entry is removed, it is removed from the head
 *-When an entry is added but the queue is full, -1 is returned (overflow)
 *and the element trying to be added is discarded, with the queue unchanged
 *-When there is a try to remove an element from an empty queue, 
 *NULL is returned (underflow)
 *
 *-The head and tail pointers always point to the memory locations for the head
 *and tail of the queue in memory respectively. Enqueuing and dequeuing
 *operations are carried out using the next_head and the next_tail pointers.
 *-If dequeue is done and next_head is at end of array, it wraps around to the 
 *head and will dequeue elements from those cells
 */

// Function prototypes

/** Create a queue by allocating a Queue structure, initializing it,
 *  and allocating memory to hold the queue entries.
 * @param max_cells Maximum entries in the queue
 * @return Pointer to newly-allocated Queue structure, NULL if error.
 */
Queue *create_queue(int max_cells);

/** Deletes the queue structure.
 * @param which_queue Pointer to Queue structure that has to be deleted.
 */
 void delete_queue(Queue *which_queue);

/** Adds a pointer at the end of a Queue.
 * @param which_queue Pointer to queue you want to add element to.
 * @param ptr Pointer to be pushed.
 * @return 0 if successful, -1 if not.
 */
int enqueue(Queue *which_queue, void *ptr);

/** Removes element from beginning of queue, and returns it.
 * @param which_queue Pointer to Queue you want to remove element from.
 * @return First entry of the queue, NULL if queue is empty.
 */
void* dequeue(Queue *which_queue);

/** Peek at top of queue, without dequeing
 * @param which_queue Pointer to Queue you want to peek at.
 * @return Top entry of the queue, NULL if queue is empty.
 */
void* at_queue_top(Queue *which_queue);

#endif
