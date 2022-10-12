#include "DoublyLinkedList.h"

/*노드 생성*/
Node* DLL_CreateNode(ElementType NewData, int Priority)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->Priority = Priority;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

/*노드 소멸*/
void DLL_DestroyNode(Node* Node) { free(Node); }

/*노드 추가*/
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL) { *Head = NewNode; }
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL && Tail->Priority >= NewNode->Priority)
		{
			Tail = Tail->NextNode;
		}

		if (Tail->NextNode == NULL)	//테일
		{
			Tail->NextNode = NewNode;
			NewNode->PrevNode = Tail;
		}
		else
		{
			if (Tail->PrevNode == NULL)		//헤드
			{
				(*Head)->PrevNode = NewNode;
				NewNode->NextNode = (*Head);
				(*Head) = NewNode;
			}
			else
			{
				NewNode->NextNode = Tail;
				NewNode->PrevNode = Tail->PrevNode;
				Tail->PrevNode->NextNode = NewNode;
				Tail->PrevNode = NewNode;
			}
		}
	}
}

/*노드 삽입*/
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) { Current->NextNode->PrevNode = NewNode; }

	Current->NextNode = NewNode;
}

/*노드 제거*/
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
		if ((*Head) != NULL) { (*Head)->PrevNode = NULL; }

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		if (Remove->PrevNode != NULL)
		{
			Remove->PrevNode->NextNode = Temp->NextNode;
		}
		if (Remove->NextNode != NULL)
		{
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

/*노드 탐색*/
Node* DLL_GetNodeAt(Node* Head, int Location)	//헤드주소와 찾을 노드의 번호
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

/*노드 수 세기*/
int DLL_GetNodeCount(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}