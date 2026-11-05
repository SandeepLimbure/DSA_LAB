#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int emp_id;
    char *ename;
    float esalary;
    struct node *next;
}node;

node* createNode(int emp_id, char *name, float salary)
{
    node *newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->emp_id = emp_id;
    newNode->ename = strdup(name);  
    newNode->esalary = salary;
    newNode->next = NULL;

    return newNode;
}

node* addEmployee(int emp_id, char *name, float salary, node *head)
{
    node *newNode = createNode(emp_id, name, salary);
    if (newNode == NULL) return head;

    node *prev = NULL;
    node *temp = head;

    while (temp != NULL && temp->emp_id < emp_id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->emp_id == emp_id)
    {
        printf("Employee Id cannot be similar.\n");
        free(newNode->ename);
        free(newNode);
        return head;
    }

    newNode->next = temp;
    if (prev == NULL)
        return newNode;     
    prev->next = newNode;     
    return head;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("The LinkedList is empty.\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("=========Employee details =================\n");
        printf("Employee id : %d\n", temp->emp_id);
        printf("Employee Name : %s\n", temp->ename);
        printf("Employee Salary : %.2f\n", temp->esalary);
        printf("===========================================\n");
        temp = temp->next;
    }
}

void displayEmployee(node *head)
{
    if (head == NULL)
    {
        printf("The LinkedList is empty.\n");
        return;
    }

    float maxSalary = head->esalary;
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->esalary > maxSalary)
            maxSalary = temp->esalary;
        temp = temp->next;
    }

    temp = head;   
    while (temp != NULL)
    {
        if (temp->esalary == maxSalary)
        {
            printf("=========Employee details =================\n");
            printf("Employee id : %d\n", temp->emp_id);
            printf("Employee Name : %s\n", temp->ename);
            printf("Employee Salary : %.2f\n", temp->esalary);
            printf("===========================================\n");
        }
        temp = temp->next;
    }
}

void Destroy(node *head)
{
    if (head == NULL) return;
    Destroy(head->next);
    free(head->ename);
    free(head);
}   