#include "LinkedList.h"

/*  ��� ���� */
Node* SLL_CreateNode(ElementType NewData, int Priority)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;  /*  �����͸� �����Ѵ�. */
    NewNode->NextNode = NULL; /*  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. */
    NewNode->Priority = Priority;

    return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

/*  ��� �Ҹ� */
void SLL_DestroyNode(Node* Node) { free(Node); }

/*  ��� �߰� */
void SLL_AppendNode(Node** Head, Node* NewNode)
{
    if ( (*Head) == NULL ) { *Head = NewNode; } 
    else
    {
        Node* Tail = (*Head);
        Node* PrevNode = NULL;

        while ( Tail->NextNode != NULL && Tail->Priority >= NewNode->Priority)
        {
            PrevNode = Tail;
            Tail = Tail->NextNode;
        }

        if (Tail->Priority < NewNode->Priority)     //�����尡 ������� �켱�������� �������
        {
            if (PrevNode == NULL) { SLL_InsertNewHead(Head, NewNode); } //������ϰ��
            else { SLL_InsertAfter(PrevNode, NewNode); }    //�������� ������ ���̿� ����
        }
        else if (Tail->NextNode == NULL) { Tail->NextNode = NewNode; }  //�����尡 �����ϰ��
    }
}

/*  ��� ���� */
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void  SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ( Head == NULL ) { (*Head) = NewHead; }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

/*  ��� ���� */
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if ( *Head == Remove ) { *Head = Remove->NextNode; }
    else
    {
        Node* Current = *Head;
        while ( Current != NULL && Current->NextNode != Remove )
        {
            Current = Current->NextNode;
        }

        if (Current != NULL) { Current->NextNode = Remove->NextNode; }
    }
}

/*  ��� Ž�� */
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while ( Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  ��� �� ���� */
int SLL_GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;

    while ( Current != NULL )
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}
