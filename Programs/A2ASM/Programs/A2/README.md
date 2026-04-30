Anw01 bis Anw06 Beschreibung 

* Anw01
R0 bekommt die Adresse von VariableA (0x2000000c)
In R0 steht nicht der Wert 0xBEEF, sondern nur die Adresse wo VariableA im Speicher liegt.

* Anw02
R2 bekommt das erste Byte aus dem Speicher
R0 enthält die Adresse von VariableA
Mit [R0] wird auf den Speicher an dieser Adresse zugegriffen
Da VariableA den Wert 0xBEEF hat und Little Endian verwendet wird, steht im Speciher zuerst EF BE
Deshalb wird in R2 das erste Byte geladen R2 = 0xEF
Der Speicher bleibt unverändert 

* Anw03
In R3 wird das nächste Byte aus dem Speciher geladen.
[R0, #1] bedeutet, dass man zur Adresse in R0 geht und dann man 1 Schritt weiter geht und holt sich den Wert
Also hier wird nicht mehr das erste Byte geladen, sondern das zweite Byte R3 = 0xBE

* Anw04
Hier wird R2 um 8 Bit nach links verschoben 
Vorher ist R2 = 0xEF und Nachher ist R2 = 0xEF00
Um 8 Bit verschoben, weil 8 Bit genau ein Byte sind 
dadurch wird Platz für das zweite Byte gemacht

* Anw05
Hier werden R2 und R3 mit orr zusammengefügt
Vorher R2 = 0xEF00; R3 = 0xBE und Nachher R2 = 0xEFBE
Das bedeutet, dass aus den beiden einzelnen Bytes wieder ein 16 Bit Wert gebaut wurde

* Anw06
Der Wert wird zurück in den Speicher geschrieben.
Im Speicher steht danach BE EF aber im Debugger sieht man BEEF.