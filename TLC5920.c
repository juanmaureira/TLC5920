#ifndef		CLK
#define		CLK		PIN_A0
#define		BLANK	PIN_A1
#define		CSEL0	PIN_A2
#define		CSEL1	PIN_A3
#define		CSEL2	PIN_A4
#define		SIN		PIN_B0
#define		NOTDSEL	PIN_B1
#define		NOLATCH	PIN_B3
#endif

void init_TLC5920(void){
	output_low(NOLATCH);
	output_high(NOTDSEL);
}

void write_TLC5920(long int data){
int i;
	output_high(NOLATCH);
	for(i=0;i<16;i++){
		output_bit(SIN,shift_left(&data,2,0));
		output_high(CLK);
		delay_us(5);
		output_low(CLK);
		delay_us(5);
	}
	output_low(NOLATCH);	
}

void mux_TLC5920(int display, int data_displ_one, int data_displ_two){
long int data; 
	display=(display<<2)&0xFF;
	output_a((display);
	data=data_displ_one;
	data=(data<<8)|data_displ_two;
	write_TLC5920(data);
}
