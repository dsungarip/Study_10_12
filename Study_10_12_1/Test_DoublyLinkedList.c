#define _CRT_SECURE_NO_WARNINGS
#include "DoublyLinkedList.h"
#include <windows.h>

// 이중연결리스트로 구현하는 우선순위 큐

int main()
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	int InputData = 0;
	int InputPriority = 0;

	while (1)
	{
		printf("Data값을 입력하세요 : ");
		scanf("%d", &InputData);

		if (InputData < 0) { break; }

		printf("우선순위 값을 입력하세요:");
		scanf("%d", &InputPriority);

		system("cls");  //화면 클리어

		NewNode = DLL_CreateNode(InputData, InputPriority);
		DLL_AppendNode(&List, NewNode);


		Count = DLL_GetNodeCount(List);
		for (i = 0; i < Count; i++)
		{
			Current = DLL_GetNodeAt(List, i);
			printf("List[%d] :  Priority : %d\tData : %d\n", i, Current->Priority, Current->Data);
		}
		printf("\n");
	}

	/*모든 노드를 메모리에서 제거*/
	printf("\nDestroying List...\n");

	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}

	return 0;
}