/* SYSC 2006 Winter 2014 */

/* A node in a singly-linked list that stores values of type int. */

struct intnode 
{
    int    value;
    struct intnode *next;
};

typedef struct intnode IntNode;

// Functions
IntNode *intnode_construct(int value, IntNode *next);
void print_linked_list(IntNode *p);
_Bool contains(IntNode *head, int value);
_Bool contains_shorter(IntNode *head, int value);

IntNode *insert_front(IntNode *head, int value);
IntNode *append_rear(IntNode *head, int value);
IntNode *remove_first(IntNode *head);
IntNode *remove_last(IntNode *head);
IntNode *remove_last_one_pointer(IntNode *head);

int count(IntNode *head, int target);
int index(IntNode *head, int target);
int fetch(IntNode *head, int index);

IntNode *insert(IntNode *head, int index, int x);
IntNode *delete(IntNode *head, int index);
IntNode *delete_target(IntNode *head, int target, _Bool *removed);

