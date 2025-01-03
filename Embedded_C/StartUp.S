/*StarUP_Cortex_M3.s
Eng.MERAREB_Badreddine
*/

.section .vectors

.word 0x20001000 		        	/* stack top address */ 
.word _reset			         	/* 1 Reset */
.word NMI_Handler 		            /* 2 NMI  */
.word Hard Fault_Handler 		    /* 3 Hard Fault */
.word MM Fault_Handler 		        /* 4 MM Fault */
.word Bus_Handler 		            /* 5 Bus Fault */
.word Usage_Handler 		        /* 6 Usage Fault */
.word RESERVED_Handler 		        /* 7 RESERVED */
.word RESERVED_Handler 		        /* 8 RESERVED */
.word RESERVED_Handler 		        /* 9 RESERVED */
.word RESERVED_Handler 		        /* 10 RESERVED */
.word SV Call_Handler 		        /* 11 SV Call */
.word Debug Reserved_Handler 		/* 12 Debug Reserved */
.word RESERVED_Handler 		        /* 13 RESERVED */
.word PendSV_Handler 		        /* 14 PendSV */
.word SysTick_Handler 		        /* 15 SysTick */
.word IRQ0_Handler 		            /* 16 IRQ0 */
.word IRQ1_Handler 		            /* 17 IRQ1 */
.word IRQ2_Handler 		            /* 18 IRQ2 */
.word Vector_Handler 		        /* 19 IRQn... */
		
.section .text
_reset:
	bl main
	b . /*	If you finish main function loop in your self*/

.thumb_func /* For using 16 bits & 32 bits instruction if avilable */
NMI_Handler: 
	b _reset
Hard Fault_Handler: 
	b _reset
MM Fault_Handler:
	b _reset
Bus_Handler: 
	b _reset
Usage_Handler: 
	b _reset
RESERVED_Handler: 
	b _reset
RESERVED_Handler:
	b _reset
RESERVED_Handler:
	b _reset
RESERVED_Handler: 
	b _reset
SV Call_Handler:
	b _reset
Debug Reserved_Handler:
	b _reset
RESERVED_Handler:
	b _reset
PendSV_Handler:
	b _reset
SysTick_Handler:
	b _reset
IRQ0_Handler:
	b _reset
IRQ1_Handler:
	b _reset
IRQ2_Handler:
	b _reset
Vector_Handler:
	b _reset
