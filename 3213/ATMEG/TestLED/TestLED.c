#include <avr/io.h>
#include <compat/ina90.h>    // needed for  _NOP()

void waitd()
{
    register unsigned short int t = 0;
    while(++t) _NOP();
}


int main()
{
	DDRC |= 0x20;

	while(1)
	{
		PORTC |= 0x20;  //set 1 on first position, or simpler: PORTC = 0x20;
		waitd();
		PORTC &= 0x5F; //remove position 5 value, or simpler: PORTC = 0;
		waitd();

	}
	return 1;
}
