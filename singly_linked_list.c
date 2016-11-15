/* SYSC 2006 Winter 2014
   A module that implements a singly-linked list of integers. */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "singly_linked_list.h"

/* Return a pointer to a new IntNode (a node in a singly-linked list).

   Parameter value: the integer to be stored in the node.
   Parameter next: a pointer to the node that the new node should point to.
   This pointer should be NULL if the new node is the last node in the 
   linked list.
   Terminate (via assert) if memory for the node cannot be allocated. */
   
IntNode *intnode_construct(int value, IntNode *next)
{
    IntNode *p = malloc(sizeof(IntNode));
    assert (p != NULL);
    p->value = value;
    p->next = next;
    return p;
}

/* Print the linked list pointed to by p. */

void print_linked_list(IntNode *p)
{
	if (p == NULL) 
  {
		printf("empty list");
		return; 
 	}

	/* Print every node in the linked list except the last one,
	   using the format: value1 -> value2 -> value3 -> ... */
     
	for (; p->next != NULL; p = p->next) 
  {
		printf("%d -> ", p->value);
	}

	/* Print the last node. */
	printf("%d", p->value);
}

/* Return true if the linked list pointed to by head contains the
   specified value; otherwise return false. */
   
_Bool contains(IntNode *head, int value)
{
    IntNode *p;

    for (p = head; p != NULL; p = p->next) 
    {
        if (value == p->value) 
        {
            return true;
        }
    }
    
    return false;
} 


/* A version of contains that eliminates local variable p.
   Make sure you understand why we don't need that variable.
   Make sure you understand why the statement head = head->next
   does not mangle the linked list passed to this function.
   (Hint: draw a memory diagram showing the stack frames for
   this function and its caller.) */
   
_Bool contains_shorter(IntNode *head, int value)
{
    for ( ; head != NULL; head = head->next) 
    {
        if (value == head->value) 
        {
            return true;
        }
    }
    
    return false;
} 


/* Insert a node containing the specified integer value at the front 
   of the linked list pointed to by head, and return a pointer to the 
   first node in the modified list. */
   
IntNode *insert_front(IntNode *head, int value)
{
    return intnode_construct(value, head);
}


/* Append a node containing the specified integer value at the rear 
   of the linked list pointed to by head, and return a pointer to the 
   first node in the modified list.

   Exercise - can we replace local variable p with parameter head? */
   
IntNode *append_rear(IntNode *head, int value)
{
    if (head == NULL) 
    {
        /* Appending a node to the end of an empty linked list
         * is the same as inserting a node at the front of an 
         * empty linked list.
         */
        head = intnode_construct(value, head /* NULL */); 
    } 
    else 
    {
        IntNode *p;

		// Traverse the linked list until p points to the last node.

        for (p = head; p->next != NULL; p = p->next) 
        {}

        p->next = intnode_construct(value, p->next /* NULL */);
    }
    
    return head;
}


/* Remove the node at the front of the linked list pointed to by head, 
   and return a pointer to the first node in the modified list.
   Terminate (via assert) if asked to remove a node from an empty 
   linked list. */

IntNode *remove_first(IntNode *head)
{
    assert(head != NULL);

    /* We need to retrieve the pointer to the second node (or NULL, if the
       list contains one node) BEFORE we free the first node.
       Remember, the result of accessing a node after it has been
       freed in undefined. */
       
    IntNode *p = head;
    head = head->next;
    free(p);
    
	  return head;
}


/* Remove the node at the rear of the linked list pointed to by head, 
   and return a pointer to the first node in the modified list.
   Terminate (via assert) if asked to remove a node from an empty 
   linked list.

   Exercise: rewrite this function to use a single pointer to
   traverse and modify the linked list, instead of two pointers (p1 and p2). */
   
IntNode *remove_last(IntNode *head)
{
    assert(head != NULL);
    
    if (head->next == NULL) 
    {
        /* There is exactly one node in the linked list. */
        free(head);
        head = NULL;
    } 
    else 
    {
        IntNode *p1, *p2 = NULL;
        for (p1 = head; p1->next != NULL; p1 = p1->next) 
        {
            p2 = p1;
        } 

        /* Now p1 points to the last node and p2 points to the node before
         * the last node.
         */
        free(p1);
        p2->next = NULL;
    }
    
	  return head;
}


int count(IntNode *head, int target)
{
	int count = 0;
	IntNode *p;

	if(head == NULL)
	{
    	return 0;
	}
	else
  {
		for(p = head; p != NULL; p = p->next)
		{
			if(p->value == target)
			{
				count++;
			}
		}
    
		return count;
	}
} 

 
int index(IntNode *head, int target)
{
	int index = -1;
	IntNode *p;

	if(head != NULL)
	{
		for(p = head; p != NULL; p = p->next)
		{
			index += 1;

			if(p->value == target)
			{
				return index;
			}
		}
	}
  
	return -1;
}


int fetch(IntNode *head, int index)
{
	assert(head != NULL);

	int i = 0; //number of nodes
	IntNode *p = head;

	for(p = head; p != NULL; p = p->next)
	{
		if(i == index)
		{
			return p->value;
		}
    
		i++;
	}
  
	assert(0); 	//if the code gets here, then the index is not valid, and index < 0 or index > i. 
				      //So, terminate via assert no matter what!
}	


IntNode *remove_last_one_pointer(IntNode *head)
{
	assert(head != NULL);
    
  if(head->next == NULL) 
	{
        /* There is exactly one node in the linked list. */
        free(head);
        head = NULL;
  } 
	else
	{
        IntNode *p1;

        for (p1 = head; (p1->next)->next != NULL; p1 = p1->next)
		    {}
        
		    p1->next = NULL;
  }
  
	return head;
}


IntNode *insert(IntNode *head, int index, int x)
{
	if(head == NULL)
	{
		if(index == 0)
		{
			return intnode_construct(x, NULL);
		}
	}

	int n = 0;
	IntNode *p = head;
	IntNode *NewNode = malloc(sizeof(IntNode));

	while(p != NULL)
	{
		if(index == 0)
		{
			return insert_front(head, x);
		}
			
		else if(index == n)
		{
			NewNode->next = p->next;
			NewNode->value = p->value;
			p->next = NewNode;
			p->value = x;
			return head;
		}
		else if(index == n+1 && p->next == NULL)
		{
			p->next = intnode_construct(x, NULL);
			return head;
		}
    
		p = p->next;
		n++;
	}	
  
	assert(0);	// assert; index is INVALID
}


IntNode *delete(IntNode *head, int index)
{
	assert(head != NULL);

	if(head->next == NULL)
	{
		if(index == 0)
		{
			free(head);
			return NULL;
		}
	}

	IntNode *p = head;
	int n = 0;

	while(p != NULL)
	{
		if(index == 0)
		{
			head = head->next;
			free(p);
			return head;
		}
		else
    {
			if(index == n+1)
			{
				p->next = p->next->next;
				return head;
			}
			else if(index == n && p->next == NULL)
			{
				remove_last(head);
				return head;
			}
			p = p->next;
			n++;
		}
	}
	assert(0);	// assert; index is INVALID
}


IntNode *delete_target(IntNode *head, int target, _Bool *removed)
{
	*removed = contains(head, target);

	if(head == NULL)	// The list is empty
	{
		return NULL;
	}
	else if(head->next == NULL && head->value == target)	// The list only has one element
	{
		free(head);
		return NULL;	
	}
	else	// The list has more than 1 element
	{
		if(head->value == target)
		{
			head = remove_first(head);
		}
		else
		{
			IntNode *p;

			for(p = head; p->next != NULL; p = p->next)
			{
				if(p->next->value == target && p->next->next == NULL)
				{
					head = remove_last(head);
					break;
				}
				else if(p->next->value == target) 
				{
					p->next = p->next->next;
				}
			}
		}
	}
  
	return head;
}
