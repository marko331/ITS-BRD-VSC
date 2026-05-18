;************************************************
;* Beginn der globalen Daten *
;************************************************
                   AREA MyData, DATA, align = 2
Base
VariableA          DCW 0x1234
VariableB          DCW 0x4711

VariableC          DCD  0

MeinHalbwortFeld   DCW 0x22 , 0x3e , -52, 78 , 0x27 , 0x45

MeinWortFeld       DCD 0x12345678 , 0x9dca5986
                   DCD -872415232 , 1308622848
                   DCD 0x27000000
                   DCD 0x45000000

MeinTextFeld       DCB "ABab0123",0

                   EXPORT VariableA
                   EXPORT VariableB
                   EXPORT VariableC
                   EXPORT MeinHalbwortFeld
                   EXPORT MeinWortFeld
                   EXPORT MeinTextFeld

;***********************************************
;* Beginn des Programms *
;************************************************
    AREA |.text|, CODE, READONLY, ALIGN = 3
; ----- S t a r t des Hauptprogramms -----
                EXPORT main
                EXTERN initITSboard
main            PROC
                bl    initITSboard                 ; HW Initialisieren

; Laden von Konstanten in Register
*** lädt die Konstante 0x12 in Register r0
                mov   r0,#0x12                      ; Anw-01
*** lädt die negative Konstante -128 in Register r1
                mov   r1,#-128                      ; Anw-02
*** lädt die große Konstante 0x12345678 in Register r2
                ldr   r2,=0x12345678                ; Anw-03


; Zugriff auf Variable
*** lädt die Adresse von VariableA in r0
                ldr   r0,=VariableA                 ; Anw-04
*** lädt 16 Bit von der Adresse in r0 in r1
                ldrh  r1,[r0]                       ; Anw-05
*** lädt 32 Bit von der Adresse in r0 in r2
                ldr   r2,[r0]                       ; Anw-06
*** speichert den 32-Bit-Wert aus r2 bei VariableC
                str   r2,[r0,#VariableC-VariableA]  ; Anw-07

; Zugriff auf Felder (Speicherzellen)
*** lädt die Anfangsadresse des Feldes in r0
                ldr   r0,=MeinHalbwortFeld          ; Anw-08
*** lädt das erste 16-Bit-Element in r1
                ldrh  r1,[r0]                       ; Anw-09
*** lädt das zweite 16-Bit-Element in r2
                ldrh  r2,[r0,#2]                    ; Anw-10
*** lädt den Offset 10 in r3
                mov   r3,#10                        ; Anw-11
*** lädt das Element an Adresse r0 + r3 in r4
                ldrh  r4,[r0,r3]                    ; Anw-12

*** erhöht r0 um 2 und lädt das nächste 16-Bit-Element in r5
                ldrh  r5,[r0,#2]!                   ; Anw-13
*** erhöht r0 wieder um 2 und lädt das nächste 16-Bit-Element in r6
                ldrh  r6,[r0,#2]!                   ; Anw-14
*** erhöht r0 um 2 und speichert 16 Bit aus r6 an diese Adresse
                strh  r6,[r0,#2]!                   ; Anw-15

; Addition und Subtraktion von unsigned / signed Integer-Werten
*** lädt die Anfangsadresse von MeinWortFeld in r0
                ldr  r0,=MeinWortFeld               ; Anw-16
*** lädt das erste 32-Bit-Element in r1
                ldr  r1,[r0]                        ; Anw-17
*** geht 4 Byte weiter und lädt dort 32 Bit in r2
                ldr  r2,[r0,#4]                     ; Anw-18
*** addiert r1 und r2, speichert das Ergebnis in r3 und aktualisiert 
*die Flags
                adds r3,r1,r2                       ; Anw-19

*** geht 8 Byte weiter und liest das dritte 32-Bit-Element in r4
                ldr  r4,[r0,#8]                     ; Anw-20
*** geht 12 Byte weiter und liest das vierte 32-Bit-Element in r5
                ldr  r5,[r0,#12]                    ; Anw-21
*** subtrahiert r5 von r4, speichert das Ergebnis in r6 und 
*aktualisiert die Flags
                subs r6,r4,r5                       ; Anw-22

*** geht 16 Byte weiter und liest das fünfte 32-Bit-Element in r7
                ldr  r7,[r0,#16]                    ; Anw-23
*** geht 20 Byte weiter und liest das sechste 32-Bit-Element in r8
                ldr  r8,[r0,#20]                    ; Anw-24
*** subtrahiert r8 von r7, speichert das Ergebnis in r9 und 
*aktualisiert die Flags
                subs r9,r7,r8                       ; Anw-25

forever         b   forever                         ; Anw-26
                ENDP
                END