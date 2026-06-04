Kontrollstrukturen im Assembler Code

** Aufbau des Siebs im Speicher
Das Feld istPrim liegt im Datensegment (AREA MyData).
Es hat 1001 Bytes. Der Index ist die Zahl selbst.

DCB 0       -> istPrim[0] = 0  (0 ist keine Primzahl)
DCB 0       -> istPrim[1] = 0  (1 ist keine Primzahl)
FILL 999, 1 -> istPrim[2] bis istPrim[1000] = 1 (alle erstmal als Primzahl)

** Registerbelegung
r0 = p              aktuelle Zahl (Laufvariable aeussere Schleife)
r1 = p * p          Ergebnis der Multiplikation (Abbruchbedingung + Startwert innere Schleife)
r2 = Adresse istPrim
r3 = istPrim[p]     gelesener Wert (0 oder 1)
r4 = j              Vielfaches (Laufvariable innere Schleife)
r5 = 0              Wert zum Streichen

** Schleifen und Sprungbefehle
Es gibt zwei Schleifen und eine Fallunterscheidung.

1.Äußere Schleife (until_01 / enddo_01)
Läuft solange p*p <= 1000.
Abbruchbedingung: p*p > 1000
MUL r1, r0, r0      ; p*p berechnen
CMP r1, #1000       ; p*p mit 1000 vergleichen
BHI enddo_01        ; springe zu enddo_01 wenn p*p > 1000 (unsigned: higher)
BHI wird verwendet weil p*p ein unsigned Wert ist.
BHI bedeutet: branch if higher (unsigned groesser als)

2.Fallunterscheidung (if_01 / endif_01)
Prüft ob istPrim[p] noch 1 ist.
Wenn die Zahl schon gestrichen wurde (Wert = 0) wird der then-Block uebersprungen.
LDRB r3, [r2, r0]   ; istPrim[p] laden
CMP r3, #0          ; mit 0 vergleichen
BEQ endif_01        ; springe zu endif_01 wenn istPrim[p] == 0
BEQ bedeutet: branch if equal (Z-Flag == 1)

3.Innere Schleife (until_02 / enddo_02)
Streicht alle Vielfachen von p ab pp.
Startet bei j = pp, erhoeht j um p nach jedem Schritt.
Abbruchbedingung: j > 1000
CMP r4, #1000       ; j mit 1000 vergleichen
BHI enddo_02        ; springe zu enddo_02 wenn j > 1000 (unsigned: higher)
BHI wieder weil j ebenfalls unsigned ist.

 ** Warum startet die innere Schleife bei p*p?
Alle Vielfachen kleiner als pp wurden schon durch fruehere Primzahlen gestrichen.
Beispiel: Bei p=7 wurden 27, 37 und 57 schon durch 2, 3 und 5 gestrichen.
Deshalb beginnt das Streichen erst bei 7*7 = 49.

** Verwendete Sprungbefehle im Ueberblick
BHI  (branch if higher)      unsigned groesser als   -> Abbruch beider Schleifen
BEQ  (branch if equal)       gleich                  -> Fallunterscheidung
B    (branch unconditional)  immer                   -> Schleife wiederholen




** Abspeichern der Primzahlen

Nach dem Sieb enthält das Feld istPrim für jede Zahl eine Markierung.

0 = keine Primzahl
1 = Primzahl

Zusätzlich wird das Feld primFeld angelegt.

primFeld
FILL 200, 4

In diesem Feld werden die gefundenen Primzahlen gespeichert.

** Registerbelegung Abspeichern

r0 = i              aktuelle Zahl (Laufvariable)
r2 = Adresse istPrim
r3 = istPrim[i]     gelesener Wert (0 oder 1)
r4 = Adresse primFeld
r5 = Offset zur nächsten freien Speicherstelle

** Schleife zum Abspeichern

Die Schleife läuft von i = 2 bis i = 1000.

CMP r0, #1000
BHI enddo_03

Für jede Zahl wird geprüft, ob istPrim[i] = 1 ist.

LDRB r3, [r2, r0]
CMP r3, #1
BNE endif_03

Ist der Wert 1, wird die Zahl in primFeld gespeichert.

STR r0, [r4, r5]

Danach wird der Offset um 4 Byte erhöht.

ADD r5, r5, #4

Es werden nur Primzahlen gespeichert.
Nicht-Primzahlen werden übersprungen.

** Kontrolle der gespeicherten Primzahlen

Die gespeicherten Primzahlen können im Watch-Fenster angezeigt werden.

*((uint32_t *)&primFeld)@200

Im Watch-Fenster erscheinen anschließend die Primzahlen:
2, 3, 5, 7, 11, 13, ...