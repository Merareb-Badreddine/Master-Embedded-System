/*
 * FIFO.h
 *
 *     Author : Merareb Badreddine    
 */


/* Select Element Type:
 * uint8_t , uint16_t , uint32_t
 */
#define ELEMENT_TYPE   uint32_t

/* Create Buffer */
#define LENGTH  8
ELEMENT_TYPE Buff[LENGTH];

typedef struct{
	unsigned int  Length;
	unsigned int  Count;
	ELEMENT_TYPE* Base;
	ELEMENT_TYPE* Head;
	ELEMENT_TYPE* Tail;
}FIFO_Buf_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}FIFO_Buf_s;


FIFO_Buf_s FIFO_Init(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE* Buffer , uint32_t Length);


FIFO_Buf_s FIFO_IsFull(FIFO_Buf_t* FIFO_Buf);


FIFO_Buf_s FIFO_IsEmpty(FIFO_Buf_t* FIFO_Buf);


FIFO_Buf_s FIFO_EnQueue(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE Item);


FIFO_Buf_s FIFO_DeQueue(FIFO_Buf_t* FIFO_Buf , ELEMENT_TYPE* Item);


void FIFO_Print(FIFO_Buf_t* FIFO_Buf);


#endif /* FIFO_H_ */
