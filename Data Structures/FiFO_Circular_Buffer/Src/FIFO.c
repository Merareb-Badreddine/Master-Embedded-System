/*/*
 * FIFO.c
 *
 *     Author : Merareb.Badreddine
 */

#include "FIFO.h"


FIFO_Buf_s FIFO_Init(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE* Buffer , uint32_t Length)
{
	if (Buffer == NULL || FIFO_Buf == NULL)
	    return FIFO_NULL;

	FIFO_Buf->Base   = Buffer;
	FIFO_Buf->Head   = FIFO_Buf->Base;
	FIFO_Buf->Tail   = FIFO_Buf->Base;
	FIFO_Buf->Length = Length;
	FIFO_Buf->Count  = 0;

	return FIFO_NO_ERROR;
}

FIFO_Buf_s FIFO_IsFull(FIFO_Buf_t* FIFO_Buf)
{
	if(FIFO_Buf->Base == NULL || FIFO_Buf->Head == NULL || FIFO_Buf->Tail == NULL)
		return FIFO_NULL;
	if(FIFO_Buf->Count == FIFO_Buf->Length)
		return FIFO_FULL;
	else
		return FIFO_NOT_FULL;
}

FIFO_Buf_s FIFO_IsEmpty(FIFO_Buf_t* FIFO_Buf)
{
	if(FIFO_Buf->Base == NULL || FIFO_Buf->Head == NULL || FIFO_Buf->Tail == NULL)
		return FIFO_NULL;
	if(FIFO_Buf->Count == 0)
		return FIFO_EMPTY;
	else
		return FIFO_NOT_EMPTY;
}

FIFO_Buf_s FIFO_EnQueue(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE Item)
{
	if(FIFO_Buf->Base == NULL || FIFO_Buf->Head == NULL || FIFO_Buf->Tail == NULL)
		return FIFO_NULL;
	/* Check if FIFO is full or not */
	if(FIFO_IsFull(FIFO_Buf) == FIFO_FULL)
		return FIFO_FULL;

	*(FIFO_Buf->Head) = Item;
	FIFO_Buf->Count++;

	/* For circular Queue */
	if(FIFO_Buf->Head == (FIFO_Buf->Base + FIFO_Buf->Length - 1))
	   FIFO_Buf->Head = FIFO_Buf->Base;
	else
		FIFO_Buf->Head++;

    return FIFO_NO_ERROR;

}

FIFO_Buf_s FIFO_DeQueue(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE* Item)
{
	if(FIFO_Buf->Base == NULL || FIFO_Buf->Head == NULL || FIFO_Buf->Tail == NULL)
		return FIFO_NULL;

	/* Check if FIFO is empty or not */
	if(FIFO_IsEmpty(FIFO_Buf) == FIFO_EMPTY)
		return FIFO_EMPTY;

	*Item = *(FIFO_Buf->Tail);
	FIFO_Buf->Count--;

	/* For circular Queue */
	if(FIFO_Buf->Tail == (FIFO_Buf->Base + FIFO_Buf->Length - 1))
	    FIFO_Buf->Tail = FIFO_Buf->Base;
	else
		FIFO_Buf->Tail++;

		return FIFO_NO_ERROR;

}

void FIFO_Print(FIFO_Buf_t* FIFO_Buf)
{
	if(FIFO_Buf == NULL || FIFO_Buf->Base == NULL){
		printf("FIFO is NULL\n");
		return;
	}

	if(FIFO_Buf->Count == 0){
		printf("FIFO is Empty\n");
		return;
	}

	ELEMENT_TYPE* Temp = FIFO_Buf->Tail;
	printf("\n========= FIFO_Print ==========\n");

	for(uint32_t i = 0; i < FIFO_Buf->Count; i++){
		printf("\t %X \n", *Temp);


		if(Temp == (FIFO_Buf->Base + FIFO_Buf->Length - 1))
			Temp = FIFO_Buf->Base;
		else
			Temp++;
	}

	printf("================================\n");
}



