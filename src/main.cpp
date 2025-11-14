#include "uart/uart.h"
#include <stdint.h>
#include <util/delay.h>

int main()
{
  uart::init();
  while(1)
  {
    // examples:
    uart::send('a');
    // uint8_t data = uart::receive();
    //_delay_ms(200);
    //uart::send('b');
    //_delay_ms(200);
  }
  return 0;
}
