#include "LinkedList.h"

/*  노드 생성 */
Node* SLL_CreateNode(ElementType NewData, int Priority)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;  /*  데이터를 저장한다. */
    NewNode->NextNode = NULL; /*  다음 노드에 대한 포인터는 NULL로 초기화 한다. */
    NewNode->Priority = Priority;

    return NewNode;/*  노드의 주소를 반환한다. */
}

/*  노드 소멸 */
void SLL_DestroyNode(Node* Node) { free(Node); }

/*  노드 추가 */
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

        if (Tail->Priority < NewNode->Priority)     //현재노드가 새노드의 우선순위보다 작은경우
        {
            if (PrevNode == NULL) { SLL_InsertNewHead(Head, NewNode); } //헤드노드일경우
            else { SLL_InsertAfter(PrevNode, NewNode); }    //이전노드와 현재노드 사이에 삽입
        }
        else if (Tail->NextNode == NULL) { Tail->NextNode = NewNode; }  //현재노드가 테일일경우
    }
}

/*  노드 삽입 */
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

/*  노드 제거 */
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

/*  노드 탐색 */
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while ( Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  노드 수 세기 */
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
