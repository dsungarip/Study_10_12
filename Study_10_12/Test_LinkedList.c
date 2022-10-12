#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"
#include <Windows.h>

// ���Ͽ��Ḯ��Ʈ�� �����ϴ� �켱���� ť

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
        printf("Data���� �Է��ϼ��� : ");
        scanf("%d", &InputData);

        if (InputData < 0) { break; }

        printf("�켱���� ���� �Է��ϼ���:");
        scanf("%d", &InputPriority);

        system("cls");  //ȭ�� Ŭ����

        NewNode = SLL_CreateNode(InputData, InputPriority);
        SLL_AppendNode(&List, NewNode);


        /*  ����Ʈ ��� */
        Count = SLL_GetNodeCount(List);
        for (i = 0; i < Count; i++)
        {
            Current = SLL_GetNodeAt(List, i);
            printf("List[%d] :  Priority : %d\tData : %d\n", i, Current->Priority, Current->Data);
        }

    }



    /*  ��� ��带 �޸𸮿��� ����     */
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
