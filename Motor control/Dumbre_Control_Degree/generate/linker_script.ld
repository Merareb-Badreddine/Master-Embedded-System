MEMORY
{
	VEC : ORIGIN = 0x0, LENGTH = 4
	IVEC : ORIGIN = 0x4, LENGTH = 188
	OPT : ORIGIN = 0xC0, LENGTH = 4
	SEC_ID : ORIGIN = 0xC4, LENGTH = 10
	OCDSTAD : ORIGIN = 0xCE, LENGTH = 10
	OCDROM : ORIGIN = 0x17E00, LENGTH = 512
	ROM : ORIGIN = 0xD8, LENGTH = 97576
	MIRROR : ORIGIN = 0xF3000, LENGTH = 40704
	RAM : ORIGIN = 0xFCF00, LENGTH = 12288
}
SECTIONS
{
	.vec 0x0: AT(0x0)
	{
		KEEP(*(.vec))
	} > VEC
	.vects 0x4: AT(0x4)
	{
		KEEP(*(.vects))
	} > IVEC
	.option_bytes 0xc0 : AT(0xc0)
	{
		KEEP(*(.option_bytes))
	} > OPT
	.security_id 0xc4 : AT(0xc4)
	{
		KEEP(*(.security_id))
	} > SEC_ID
	.lowtext 0xD8: AT(0xD8)
	{
		*(.plt)
		*(.lowtext)
		. = ALIGN(2);
	} > ROM
	.tors :
	{
		__CTOR_LIST__ = .;
		. = ALIGN(2);
		___ctors = .;
		KEEP(*(.ctors))
		___ctors_end = .;
		__CTOR_END__ = .;
		__DTOR_LIST__ = .;
		___dtors = .;
		KEEP(*(.dtors))
		___dtors_end = .;
		__DTOR_END__ = .;
		. = ALIGN(2);
		_mdata = .;
	} > ROM
	.text (. + __romdatacopysize): 
	{
		*(.text)
		*(.text.*)
		etext = .;
		. = ALIGN(2);
	} > ROM
	PROVIDE(__rl78_abs__ = 0);
	.init :
	{
		*(.init)
	} > ROM
	.fini :
	{
		KEEP(*(.fini))
	} > ROM
	.got :
	{
		*(.got)
		*(.got.plt)
	} > ROM
	PROVIDE(__mirror = 0x3000);
	PROVIDE(__mirror_end = __mirror + 40704);
	PROVIDE(__rodata = ADDR (.rodata)); 
	.rodata MAX(., 0x3000): 
	{
		. = ALIGN(2);
		*(.rodata)
		*(.rodata.*)
		_erodata = .;
		ASSERT (!(SIZEOF(.rodata) > (__mirror_end - __mirror)), 
			"Error: Too much const data-the size exceeds the mirror area. Please change some of them from 'const' to 'const __far' and uncheck 'Data sections (-fdata-sections)' of optimaize option.");
		ASSERT(!((SIZEOF(.rodata) <= (__mirror_end - __mirror)) && (SIZEOF (.rodata) > 0) && (ABSOLUTE(__rodata) >= __mirror_end) && (ABSOLUTE(.) > __mirror_end) && (ADDR(.text) < __rodata)),
			"Error: No room left for const data- the start address exceeds the mirror area. Please move the .text section from lower address to higher address.");
		ASSERT(!((SIZEOF(.rodata) <= (__mirror_end - __mirror)) && (SIZEOF (.rodata) > 0) && (ABSOLUTE(__rodata) >= __mirror_end) && (ABSOLUTE(.) > __mirror_end) && (__rodata < ADDR(.text))),
			"Error: No room left for const data- the start address exceeds the mirror area. Please check the map file.");
		ASSERT(!((SIZEOF(.rodata) <= (__mirror_end - __mirror)) && (SIZEOF (.rodata) > 0) && (ABSOLUTE(__rodata) < __mirror_end) && (ABSOLUTE(.) > __mirror_end) && (ADDR(.text) < __rodata)), 
			"Error : No room left for const data-the end address exceeds the mirror area. Please move the .text section from lower address to higher address.");
		ASSERT(!((SIZEOF(.rodata) <= (__mirror_end - __mirror)) && (SIZEOF (.rodata) > 0) && (ABSOLUTE(__rodata) < __mirror_end) && (ABSOLUTE(.) > __mirror_end) && (__rodata < ADDR(.text))), 
			"Error : No room left for const data-the end address exceeds the mirror area. Please check the map file.");
	} > ROM
	.frodata :
	{
		. = ALIGN(2);
		*(.frodata)
		*(.frodata.*)
		_efrodata = .;
	} > ROM
	.eh_frame_hdr :
	{
		*(.eh_frame_hdr)
	} > ROM
	.eh_frame :
	{
		*(.eh_frame)
	} > ROM
	.jcr :
	{
		*(.jcr)
		. = ALIGN(2);
	} > ROM
	.data 0xFCF00: AT(_mdata)
	{
		. = ALIGN(2);
		_data = .;
		*(.data)
		*(.data.*)
		. = ALIGN(2);
		_edata = .;
	} > RAM
	PROVIDE(__romdatacopysize = SIZEOF(.data));
	.bss :
	{
		. = ALIGN(2);
		_bss = .;
		*(.bss)
		*(.bss.**)
		. = ALIGN(2);
		*(COMMON)
		. = ALIGN(2);
		_ebss = .;
		. = ALIGN(128);
		_end = .;
	} > RAM
	PROVIDE(stack_size = 0x64);
	.stack 0xFFEDC (NOLOAD) : AT(0xFFEDC)
	{
		_stack = .;
		ASSERT((_stack > (_end + stack_size)), "Error: Too much data - no room left for the stack");
	} > RAM
}
