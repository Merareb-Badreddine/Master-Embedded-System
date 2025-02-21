/*
 * FIFO.c
 *
 *     Author : Merareb Badreddine    
 */
#include "FIFO.h"

FIFO_Buf_s FIFO_Init(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE* Buffer , uint32_t Length)
{
	if(Buffer == NULL)
		return FIFO_FULL;

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
	if(FIFO_Buf->Head == (ELEMENT_TYPE*)(FIFO_Buf->Length * sizeof(ELEMENT_TYPE))){
		FIFO_Buf->Head = FIFO_Buf->Base;
	}
	else{
		FIFO_Buf->Head++;
	}

	return FIFO_NO_ERROR;

}

FIFO_Buf_s FIFO_DeQueue(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE* Item)
{
	if(FIFO_Buf->Base == NULL || FIFO_Buf->Head == NULL || FIFO_Buf->Tail == NULL)
		return FIFO_NULL;
	if(FIFO_IsEmpty(FIFO_Buf) == FIFO_EMPTY)
		return FIFO_EMPTY;

	*Item = *(FIFO_Buf->Tail);
	FIFO_Buf->Count--;

	/* For circular Queue */
	if(FIFO_Buf->Tail == (ELEMENT_TYPE*)(FIFO_Buf->Length * sizeof(ELEMENT_TYPE))){
		FIFO_Buf->Tail = FIFO_Buf->Base;
	}
	else{
		FIFO_Buf->Tail++;
	}

	return FIFO_NO_ERROR;

}

void FIFO_Print(FIFO_Buf_t* FIFO_Buf)
{
	ELEMENT_TYPE* Temp;
	int i;

	if(FIFO_Buf->Count == 0){
		printf("FIFO is Empty\n");
	}
	else{
		Temp = FIFO_Buf->Tail;
	}
	printf("\n=========FIFO_Print==========\n");
	for(i=0; i<FIFO_Buf->Count; ++i){
		printf("\t %X \n", *Temp);
		Temp++;
	}
	printf("============\n");
}
