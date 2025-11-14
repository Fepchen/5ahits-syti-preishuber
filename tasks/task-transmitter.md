# UART Labor – Protokoll
```
   Name: Webersberger Fabian_____________

  Datum: 2025-11-07______________________

 Gruppe: [X] Transmitter / [ ] Receiver / [ ] Measurement
```

## 1. Aufgabenstellung
Implementiere einen UART-Sender anhand des ATMega2560 Datenblatts.
Sende periodisch Bytes oder Zeichen (z. B. alle 100–300 ms).
Dokumentiere die Vorgehensweise sowie die Ergebnisse.


## 2. Kurzbeschreibung der eigenen Lösung
Ich habe einen einfachen UART-Sender gemäß ATmega2560-Datenblatt implementiert.
Der UART wird auf 9600 Baud bei 16 MHz Takt initialisiert.
Alle 200 ms werden die Zeichen 'a' und 'b' gesendet.


## 3. Quellcode
### uart.cpp
```cpp
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
```
### main.cpp
```cpp
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
    _delay_ms(200);
    uart::send('b');
    _delay_ms(200);
  }
  return 0;
}

```

## 4. Gesendete Daten
 - Gesendetes Byte 1: `_a________`
 - Gesendetes Byte 2: `_b________`

Erklärung, warum diese gewählt wurden: `___________________________`

## 5. Funktionstest
Wurde das Byte beim Empfänger korrekt empfangen? `[ ]` Ja `[ ]` Nein
Tests mit verschiedenen Bytes durchgeführt? `[ ]` Ja `[ ]` Nein
Probleme / Beobachtungen: `_______________________________________`

## 6. Erkenntnisse
 - UART-Initialisierung erfolgt über Baudrate und UCSRx-Bits
 - TXEN0 und RXEN0 müssen aktiviert werden
 - Standard-Config: 8 N 1 (8 Datenbits, kein Paritätsbit, 1 Stopbit)


## 7. Zusammenfassung
(3–5 Sätze: Was habe ich technisch gelernt?)
