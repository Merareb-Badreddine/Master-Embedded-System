/*StarUP_Cortex_M3.c
Eng.MERAREB_Badreddine
*/


extern unsigned int Stack_top ;
extern unsigned int E_text    ;
extern unsigned int S_data    ;
extern unsigned int E_data    ;
extern unsigned int S_bss     ;
extern unsigned int E_bss     ;

void Bus_Fault           ()__attribute__((weak,alias ,("Default_Handler ")));
void Usage_Fault_Handler ()__attribute__((weak,alias ,("Default_Handler ")));



uint32_t vectors[] __attribute__ ((section(".vectors"))) = {
	(uint32_t)	&_STACK_TOP,
	(uint32_t)	&Reset_Hundler,
	(uint32_t)	&NMI_Handler,
	(uint32_t)	&H_Fault_Handler,
	(uint32_t)	&MM_Fault_Handler,
	(uint32_t)	&Bus_Fault,
	(uint32_t)	&Usage_Fault_Handler
};


void Reset_Hundler (void)
{
	//copy data from ROM to RAM
	uint32_t DATA_Size = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA ;
	uint8_t* P_src = (uint8_t*)&_E_TEXT ;
	uint8_t* P_dst = (uint8_t*)&_S_DATA ;
	
	for (int i = 0; i < DATA_Size; ++i)
		{
			*((uint8_t*)P_dst++) = *((uint8_t*)P_src++) ; 
		}

	// init the .bss with zero
	uint32_t BSS_Size = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS ;
	P_dst = (uint8_t*)&_S_BSS ;

	for (int i = 0; i < BSS_Size; ++i)
		{
			*((uint8_t*)P_dst++) = (uint8_t)0 ; 
		}



void Default_Handler()
{


}
