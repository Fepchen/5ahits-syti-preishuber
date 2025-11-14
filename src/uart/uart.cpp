#include "uart/uart.h"
#include <avr/io.h>
#include <util/delay.h>

namespace uart
{

  void init()
  {
    // TODO: Implement
     UBRR0 = 0;
    //UDR0
    UCSR0C &= (0 << UMSEL00) & (0<<UMSEL01);
    UCSR0C |= (1<< UPM00) | (1<< UPM01);
    UCSR0A |= (1<<U2X0);
    UBRR0L = 0b11001111; //set ubbr0l to 207 - ATMega hat frequenz 16Mhz - Baudrate dadurch 9600
   
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UBRR0 = 9600;
  }

  void send(uint8_t data)
  {
    // TODO: Implement
    while (!(UCSR0A & (1 << UDRE0))); // Wait for empty transmit buffer
    UDR0 = data; // Put data into buffer, sends the data
  }

  uint8_t receive()
  {
    // TODO: Implement
    while (!(UCSR0A & (1 << RXC0))); // Wait for data to be received
    return UDR0; // Get and return received data from buffer
  }
}