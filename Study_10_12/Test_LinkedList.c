#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"
#include <Windows.h>

// 단일연결리스트로 구현하는 우선순위 큐

int main()
{
    int   i       = 0;
    int   Count   = 0;
    Node* List    = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

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

        NewNode = SLL_CreateNode(InputData, InputPriority);
        SLL_AppendNode(&List, NewNode);


        /*  리스트 출력 */
        Count = SLL_GetNodeCount(List);
        for (i = 0; i < Count; i++)
        {
            Current = SLL_GetNodeAt(List, i);
            printf("List[%d] :  Priority : %d\tData : %d\n", i, Current->Priority, Current->Data);
        }

    }



    /*  모든 노드를 메모리에서 제거     */
    printf("\nDestroying List...\n");

    for ( i = 0; i<Count; i++ )
    {
        Current = SLL_GetNodeAt(List, 0);

        if ( Current != NULL ) 
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }

    return 0;
}
