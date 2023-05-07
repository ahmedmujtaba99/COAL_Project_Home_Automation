
#include<reg51.h>


	sbit rs=P2^0;
	sbit en=P2^1;
	sbit fan=P2^2;
	sbit bulb=P2^3;
	sbit led=P2^4;
	sbit buzzer=P3^2;

	unsigned int i;
	unsigned char a[100];
	sfr ldata=0x90;//port1 
	unsigned char input;

	void delay(unsigned int i);
	void lcd_cmd(unsigned char a);
	void lcd_data(unsigned char b);
	void lcd_init(void);
	void lcd_str(unsigned char *str);
	void clear(void);



void main()
{


	
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = -3;
	TR1=1;
	buzzer=1;
	lcd_init();
 
	
	while(1)
	{
				while(RI == 0);
				input=SBUF;
				SBUF=input;
				while(TI == 0);
				TI = 0;
		    RI=0;
		
		
					lcd_cmd(0x01);
					lcd_cmd(0x80);
					lcd_str(" Invalid ");
					lcd_cmd(0xc0);
					lcd_str("  Input  ");
	
	
		    if(input== '1')
				{
					
						lcd_cmd(0x01);
						lcd_cmd(0x80);
						lcd_str(" FAN is OFF ");
						lcd_cmd(0xc0);
					   fan=1;          //fan off
						delay(65000);
						clear();
					 buzzer=1;
				}
				 if(input == '2')
				{
					  lcd_cmd(0x01);
						fan=0;          //fan on
						lcd_cmd(0x80);
						lcd_str(" FAN is ONN ");
						lcd_cmd(0xc0);
						delay(65000);
						clear();
					  buzzer=0;
					 delay(65000);
					  buzzer=1;
				}
				
				
				//now for bulb
				 if(input == '3')
				{
					  // bulb=1;          //bulb off
					
					  lcd_cmd(0x01);
						lcd_cmd(0x80);
						lcd_str(" BULB is OFF ");
						lcd_cmd(0xc0);
					   bulb=1;          //bulb off
						//lcd_str(a);
						delay(65000);
						clear();
					buzzer=1;
				}
				 if(input== '4')
				{
					   bulb=0;        //bulb on
					
					 lcd_cmd(0x01);
						lcd_cmd(0x80);
						lcd_str(" BULB is on ");
						lcd_cmd(0xc0);
					   bulb=0;         // bulb on
						//lcd_str(a);
						delay(65000);
					  buzzer=0;
					  delay(65000);
					  buzzer=1;
				
				}
				
				//now for led
				 if(input == '5')
				{
					 // led=1;          //led off
					
					  lcd_cmd(0x01);
						lcd_cmd(0x80);
						lcd_str(" led is OFF ");
						lcd_cmd(0xc0);
					   led=1;         // led off
						delay(65000);
					buzzer=1;
				}
				 if(input== '6')
				{
					   //led=0;        //led on
					 lcd_cmd(0x01);
						lcd_cmd(0x80);
						lcd_str(" led is on ");
						lcd_cmd(0xc0);
					   led=0;         // led on
						delay(65000);
					  buzzer=0;
					  delay(65000);
					  buzzer=1;
				}
				
				
		     if(input == '0')
				 {
					 
					  lcd_cmd(0x01);
						lcd_cmd(0x80);
						lcd_str(" ALL is ON ");
						lcd_cmd(0xc0);
					  fan=bulb=led=0;  // all r on
						delay(65000);
					  buzzer=0;
					  delay(65000);
					  buzzer=1;
					 
					 
				//	 fan=bulb=led=0;  // all r off
				 }
				  if(input == '9')
				 {
					  lcd_cmd(0x01);
						lcd_cmd(0x80);
						lcd_str(" ALL is off ");
						lcd_cmd(0xc0);
					  fan=bulb=led=1;  // all r off
						delay(65000);
					 buzzer=1;
					 
					 
					 
					 
				 }
		
	}	
	
}


//program for lcd_init

void lcd_init()
{
 lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);


}

//program for delay
void delay(unsigned int i)
{
unsigned int j;
	for(j=0;j<i;j++);
}


//program for lcd_cmd
void lcd_cmd(unsigned char a)
{
  rs=0;//cmd 
	ldata=a;
	en=1;
	delay(5);
	en=0;
	delay(5);
}
//progeam for lcd_data
void lcd_data(unsigned char b)
{
  rs=1;//data 
	ldata=b;
	en=1;
	delay(5);
	en=0;
	delay(5);
}
//program for lec_str
void lcd_str(unsigned char *str)
{
while(*str)
{
	lcd_data(*str++);
}

}




//program for clear the lcd
void clear(void)
{

unsigned int i;
	for(i=0;i<100;i++)
	{
	a[i]='\0';
	
	}
}

