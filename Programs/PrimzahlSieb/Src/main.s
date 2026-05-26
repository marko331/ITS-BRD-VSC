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