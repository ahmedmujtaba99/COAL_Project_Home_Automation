

#include<reg51.h>
#include<intrins.h>
sbit load1= p1^0;
sbit load2= p2^1;
sbit load3= p3^2;
SBIT load4= p4^3;

void main()
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = -3;
	TR = 1;
	while(1)
	{
				while(RI == 0);
				x=SBUF;
				SBUF=x;
				while(TI == 0);
				TI = 0;
		    if(x == '1')
				{
					   load1=1;          //load1 off
				}
				 if(x == '2')
				{
					   load1=0;        //load1 on
				}
				
				
				//now for load2
				 if(x == '3')
				{
					   load2=1;          //load2 off
				}
				 if(x == '4')
				{
					   load3=0;        //load2 on
				}
				
				//now for load3
				 if(x == '5')
				{
					   load3=1;          //load3 off
				}
				 if(x == '6')
				{
					   load3=0;        //load3 on
				}
				
					//now for load4
				 if(x == '7')
				{
					   load4=1;          //load4 off
				}
				 if(x == '8')
				{
					   load4=0;        //load4 on
				}
		
		
	}	
	
}
	