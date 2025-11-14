# UART Labor – Protokoll
```
  Name: Webersberger Fabian______________
  Team: Mayr, Mühlberger_________________
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
Wurde das Byte beim Empfänger korrekt empfangen? `[ ]` Ja `[X]` Nein
Tests mit verschiedenen Bytes durchgeführt? `[ ]` Ja `[X]` Nein
Probleme / Beobachtungen: `_Ich kann nicht beurteilen ob der Receiver nicht empfangen hat oder der Transmitter nichts gesendet hat, da das Messen nicht funktioniert hat_`

## 6. Erkenntnisse
 - UART-Initialisierung erfolgt über Baudrate und UCSRx-Bits
 - TXEN0 und RXEN0 müssen aktiviert werden
 - Standard-Config: 8 N 1 (8 Datenbits, kein Paritätsbit, 1 Stopbit)


## 7. Zusammenfassung
(3–5 Sätze: Was habe ich technisch gelernt?)
