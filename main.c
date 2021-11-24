#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
void linkedlisttraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node * deleteFirst(struct Node * head)
{
    struct Node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct Node * deleteAtIndex(struct Node * head,int index)
{
    struct Node * p=head;
    struct Node * q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct Node * deleteAtLast(struct Node * head)
{
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *thrid;
    //allocate memory for nodes in the linked list in heap
    head=(struct Node *)malloc(sizeof (struct Node));
    second=(struct Node *)malloc(sizeof (struct Node));
    thrid=(struct Node *)malloc(sizeof (struct Node));
    //link frist and second nodes;
    head->data=7;
    head->next=second;
    //link second and thrid nodes;
    second->data=11;
    second->next=thrid;
    //terminate list at the thried node;
    thrid->data=66;
    thrid->next=NULL;
    printf("Linked List before deletion\n");
    linkedlisttraversal(head);
    //head=deleteFirst(head);
    //head=deleteAtIndex(head,2);
    head=deleteAtLast(head);
    printf("Linked list after deletion \n");
    linkedlisttraversal(head);
    return 0;
}
