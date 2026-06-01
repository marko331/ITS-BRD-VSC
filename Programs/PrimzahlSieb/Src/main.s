; Primzahlen von 1 bis 1000 finden 

; ----------------------------------------
; Feld für Primzahlen
; ----------------------------------------

; Für jede Zahl gibt es einen Platz im Feld

; Beispiel: 
; istPrim[5] = 1 
; -> 5 ist eine Primzahl

; istPrim[8] = 0 
; -> 8 ist keine Primzahl

; 1 bedeutet: 
; Zahl ist noch nicht gestrichen 

; 0 bedeutet: 
; Zahl wurde gestrichen

; ---------------------------------------- 
; Schritt 1 
; ----------------------------------------

; Alle Zahlen von 2 bis 1000 zuerst auf 1 setzen

; 0 und 1 auf 0 setzen, 
; weil sie keine Primzahlen sind

; ---------------------------------------- 
; Schritt 2 
; Sieb des Eratosthenes 
; ----------------------------------------

; Mit Zahl 2 beginnen

; Prüfen: 
; Ist die Zahl noch eine Primzahl?

; Wenn ja: 
; Alle Vielfachen streichen

; Das Streichen beginnt bei: 
; zahl * zahl

; Beispiel

; Bei 2: 
; 4, 6, 8, 10 streichen

; Bei 3: 
; 9, 12, 15, 18 streichen 

; Bei 5: 
; bei 25 beginnen

; Gestrichene Zahlen bekommen: 
; istPrim = 0

; Danach mit der nächsten Zahl weitermachen

; Ende: 
; wenn zahl * zahl größer als 1000 ist

; ---------------------------------------- 
; Schritt 3 
; ----------------------------------------

; Das Feld nochmal durchgehen

; Wenn istPrim[zahl] = 1: (Wenn bei einer Zahl eine 1 steht:)
; dann ist die Zahl eine Primzahl 

; Diese Zahl speichern oder ausgeben 

; Am Ende bleiben nur Primzahlen übrig

; ------------------------------------------------
; Aufgabe 5: Kontrollstrukturen
; ------------------------------------------------

	
	
	AREA MyData, DATA, READWRITE, ALIGN = 2

istPrim
    DCB 0
    DCB 0
    FILL 999, 1

	AREA |.text|, CODE, READONLY, ALIGN = 3
		EXPORT main
main 

    ; Register:
    ; r0 = p
    ; r1 = p * p
    ; r2 = Adresse von istPrim
    ; r3 = Wert von istPrim[p]
    ; r4 = vielfaches
	; r5 = 0 (zum Streichen)

; ------------------------------------------------
; Mit p = 2 beginnen
; ------------------------------------------------
    MOV r0, #2		; p = 2


; ------------------------------------------------
; Äußere Schleife: Solange p * p <= 1000
; ------------------------------------------------

until_01

    MUL r1, r0, r0 		; p * p berechnen
    CMP r1, #1000 	   ; prüfen ob p * p > 1000
    BHI enddo_01		; Wenn größer, dann Schleife beenden

; ------------------------------------------------
; If-Abfrage
; Prüfen ob p noch nicht gestrichen wurde
; ------------------------------------------------

if_01

    LDR r2, =istPrim 	; Adresse vom Feld in r2 laden
    LDRB r3, [r2, r0]	; Wert von istPrim[p] in r3 laden
    CMP r3, #0 			; prüfen ob istPrim[p] = 0 / Ist der Wert 0?
    BEQ endif_01 		; Wenn ja, dann zum nächsten p springen(Zahl übersprinegen)

; ------------------------------------------------
; p ist eine Primzahl, alle Vielfachen streichen
; ------------------------------------------------

then_01

    MOV r4, r1 			; vielfaches = p * p

; ------------------------------------------------
; Innere Schleife - Vielfache streichen
; ------------------------------------------------

until_02

    CMP r4, #1000 	   ; prüfen ob vielfaches > 1000
    BHI enddo_02 		; Wenn ja, dann innere Schleife beenden

; ------------------------------------------------
; Vielfaches streichen
; ------------------------------------------------

do_02

    MOV r5, #0 			; Wert 0 in r5 laden, 0 bedeutet: keine Primzahl
    STRB r5, [r2, r4]	; Die 0 aus r5 wird jetzt in das Feld istPrim geschrieben

; ------------------------------------------------
; nächstes Vielfaches berechnen
; ------------------------------------------------

step_02

    ADD r4, r4, r0 		; zum aktuellen Vielfachen wird p addiert, um zum nächsten Vielfachen zu kommen
    B until_02 			; zurück zum Anfang der inneren Schleife springen

; ------------------------------------------------
; Ende der inneren Schleife
; ------------------------------------------------

enddo_02

endif_01 				; alle Vielfachen von p wurden gestrichen, jetzt zum nächsten p springen
step_01 				; Ende der If-Abfrage, wenn p keine Primzahl ist, wird hier zum nächsten p gesprungen

; ------------------------------------------------
; Zum nächsten p wechseln
; ------------------------------------------------

    ADD r0, r0, #1 		; p um 1 erhöhen
    B until_01 			; zurück zum Anfang der äußeren Schleife springen, um zu prüfen, ob das neue p noch eine Primzahl ist

; ------------------------------------------------
; Ende der äußeren Schleife
; ------------------------------------------------

enddo_01

stop ; Das Sieb ist fertig und alle Primzahlen von 1 bis 1000 wurden gefunden. Jetzt wird das Programm angehalten.

    B stop			; Endlosschleife, damit das Programm nicht weiterläuft


END