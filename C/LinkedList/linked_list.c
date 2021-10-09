#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
}*head = NULL;

struct node* createNode()
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    if(temp != NULL)
    {
        int item;
        printf("Enter item: ");
        scanf("%d", &item);
        temp->data = item;
        temp->link = NULL;
    }
    return temp;
}

void insertAtBeginning()
{
    struct node *temp;
    temp = createNode();
    if(temp == NULL)
    {
        printf("Memory Undeflow - No insertion");
        exit(1);
    }
    else
    {
        if(head == NULL)
            head = temp;
        else
        {
            temp->link = head;
            head = temp;
        }
    }
}

void insertAtEnd()
{
    struct node *temp;
    temp = createNode();
    if(temp == NULL)
    {
        printf("Memory Undeflow - No insertion");
        exit(1);
    }
    else
    {
        if(head == NULL)
            head = temp;
        else
        {
            struct node *p;
            p = head;
            while(p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
}

void insertAtSpecific()
{
    struct node *temp;
    temp = createNode();
    if(temp == NULL)
    {
        printf("Memory Undeflow - No insertion\n");
        exit(1);
    }
    else
    {
        int key;
        printf("Enter key: ");
        scanf("%d", &key);
        if(head == NULL)
            printf("Key not found - No insertion\n");
        else
        {
            struct node *p;
            p = head;
            while(p->data != key && p->link != NULL)
                p = p->link;
            if(p->data == key)
            {
                temp->link = p->link;
                p->link = temp;
            }
            else
                printf("Key not found - No insertion");
        }
    }
}

void deleteAtBeginning()
{
    if(head == NULL)
        printf("Empty list.\n");
    else
    {
        struct node *p;
        head = head->link;
        free(p);
    }
}

void deleteAtEnd()
{
    if(head == NULL)
        printf("Empty list.\n");

    else if (head->link == NULL)
    {
        struct node *ptr;
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else
    {
        struct node *ptr, *prev;
        prev = head;
        ptr = head->link;
        while(ptr->link != NULL)
        {
            prev = prev->link;
            ptr = ptr->link;
        }
        prev->link = NULL;
        free(ptr);
    }
}

void deleteAtSpecific()
{
    int key;
    printf("Enter key: ");
    scanf("%d", &key);

    if(head == NULL)
        printf("Empty list.\n");

    else if (head->data == key)
    {
        struct node *ptr;
        ptr = head;
        head = head->link;
        free(ptr);
    }
    else
    {
        struct node *ptr, *prev;
        prev = head;
        ptr = head->link;
        while(ptr->link != NULL && ptr->data != key)
        {
            prev = prev->link;
            ptr = ptr->link;
        }
        if(ptr->data != key)
        {
            printf("Key not found.\n");
        }
        else
        {
            prev->link = ptr->link;
            free(ptr);
        }
    }
}

void displayList()
{
    if(head == NULL)
        printf("Empty List.\n");
    else
    {
        struct node* p;
        p = head;
        printf("List: \n");
        while(p!= NULL)
        {
            printf("%d\n", p->data);
            p = p->link;
        }
    }
}

void main()
{
    int opt;
    while(1)
    {
        printf("Menu\n1. Insertion at Beginning\n2. Insertion at End\n3. Insertion at Specific\n");
        printf("4. Deletion at Beginning\n5. Deletion at End\n6. Deletion at Specific\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: insertAtBeginning();
                break;
            case 2: insertAtEnd();
                break;
            case 3: insertAtSpecific();
                break;
            case 4: deleteAtBeginning();
                break;
            case 5: deleteAtEnd();
                break;
            case 6: deleteAtSpecific();
                break;
            default:
                exit(1);
        }
        displayList();
    }
}
