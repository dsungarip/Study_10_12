#include "DoublyLinkedList.h"

/*��� ����*/
Node* DLL_CreateNode(ElementType NewData, int Priority)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->Priority = Priority;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

/*��� �Ҹ�*/
void DLL_DestroyNode(Node* Node) { free(Node); }

/*��� �߰�*/
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

		if (Tail->NextNode == NULL)	//����
		{
			Tail->NextNode = NewNode;
			NewNode->PrevNode = Tail;
		}
		else
		{
			if (Tail->PrevNode == NULL)		//���
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

/*��� ����*/
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) { Current->NextNode->PrevNode = NewNode; }

	Current->NextNode = NewNode;
}

/*��� ����*/
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

/*��� Ž��*/
Node* DLL_GetNodeAt(Node* Head, int Location)	//����ּҿ� ã�� ����� ��ȣ
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

/*��� �� ����*/
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