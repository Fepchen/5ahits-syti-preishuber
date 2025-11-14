#include "uart/uart.h"
#include <avr/io.h>
#include <util/delay.h>

namespace uart
{
  void init()
  {
    // TODO: Implement
    // Baudrate
    const uint16_t ubrr = 103;   // 9600 Baud  16 MHz
    UBRR0H = (ubrr >> 8);
    UBRR0L = ubrr;

    // USART Control and Status Register A
    UCSR0A = 0;

    // Enable and TX
    UCSR0B = (1 << TXEN0);

    // Frame format: 8N1
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  // 8 Bit
  }
  void send(uint8_t data)
  {
    // TODO: Implement
    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)))
      ;
    /* Put data into buffer, sends the data */
    UDR0 = data;
  }
  uint8_t receive()
  {
    // TODO: Implement
  }
}