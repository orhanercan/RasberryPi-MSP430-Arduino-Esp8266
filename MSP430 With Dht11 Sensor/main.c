#include <msp430.h>                                       //Orhan ERCAN 21604418
volatile int temp[50];
volatile int diff[50];
volatile unsigned int i=0;
volatile unsigned int j=0;
volatile unsigned char humdty_high = 0;      //humidity high byte
volatile unsigned char humdty_low = 0;      //humidity low byte
volatile unsigned char temp_high = 0;   //temperature high byte
volatile unsigned char temp_low = 0;    //temperature low byte
volatile unsigned char checksum = 0;
volatile unsigned char check = 0;
volatile unsigned char dataok = 0 ;
unsigned char outdata[5];
unsigned char indata[5];

void gonder(unsigned char d){      // function that sending message to ESP8266
  Serial.print(d);
  delay(1000);
  }
char Al(){
  if (Serial.available()) {
    return Serial.read();

      }
  }

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    BCSCTL1 = CALBC1_1MHZ;     //setting clock 1MHz
    DCOCTL = CALDCO_1MHZ;    //digital control oscillator
    __delay_cycles(2000000);
    P2DIR |= BIT4;    // Set P2.4 to output
    P2OUT &= ~BIT4;
    __delay_cycles(20000); // wait 20 ms
    P2OUT |= BIT4;
    __delay_cycles(20);
    P2DIR &= ~BIT4;
    P2SEL |= BIT4;
    TA1CTL = TASSEL_2|MC_2;     //Timer A1 Control register set  SMCLK  and continuous mode
    TA1CCTL2 = CAP | CCIE | CCIS_0 | CM_2 | SCS ; //TA1 Capture control register capture mode
    _enable_interrupts();
    while(1){
        if (i >= 40){                           // 5 different 8 byte variables for 40 indices temperature(high-low) , humidity (high-low), checksum
            for (j = 1; j <= 8; j++){
                if (diff[j] >= 110)
                    humdty_high |= (0x01 << (8-j));
            }
            for (j = 9; j <= 16; j++){
                if (diff[j] >= 110)
                    humdty_low |= (0x01 << (16-j));
            }
            for (j = 17; j <= 24; j++){
                if (diff[j] >= 110)
                    temp_high |= (0x01 << (24-j));
            }
            for (j = 25; j <= 32; j++){
                if (diff[j] >= 110)
                    temp_low |= (0x01 << (32-j));
            }
            for (j = 33; j <= 40; j++){
                if (diff[j] >= 110)
                    checksum |= (0x01 << (40-j));
            }
            check = humdty_high+humdty_low+temp_high+temp_low;
            if (check == checksum)
                dataok = 1;
            else
                dataok = 0;
        }  //gonder(th);
        Serial.println(temp_high + humdty_high);
    delay(1000);
      }

    }
}

#pragma vector = TIMER1_A1_VECTOR
__interrupt void Timer_A1(void){
    temp[i] = TA1CCR2;
    i += 1;
    if (i>=2) diff[i-1]=temp[i-1]-temp[i-2];
    TA1CCTL2 &= ~CCIFG ;
}
