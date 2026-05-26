* Analyse der Aufgabe 

Das Programm soll Primzahlen von 2 bis 1000 finden.
Dafür wird das Sieb des Eratosthenes benutzt.
Dabei werden zuerst alle Zahlen als Primzahlen betrachtet danach werden die Vielfachen von Primzahlen gestrichen.
Am Ende bleiben nur Primzahlen übrig.


* Verwendete felder

Es wird ein feld verwendet:
boolean[] prim
Das Feld speichert:
-> true = Primzahl
-> false = keine Primzahl

Der Index ist die Zahl selbst.
Beispiel:
prim[5] = true
prim[8] = false


* Java Code

// Primzahlen von 2 bis 1000 finden

int max = 1000;

boolean[] prim = new boolean[max + 1];

// Alle Zahlen zuerst als Primzahlen markieren

for (int i = 2; i <= max; i++) {

    prim[i] = true;

}

// Vielfache streichen

for (int p = 2; p * p <= max; p++) {

    if (prim[p]) {

        for (int j = p * p; j <= max; j += p) {

            prim[j] = false;

        }
    }
}

// Primzahlen ausgeben

for (int i = 2; i <= max; i++) {

    if (prim[i]) {

        System.out.println(i);

    }

}


* Speicheraufbau
Index: 2 3 4 5
Wert:  1 1 0 1
4 wurde gestrichen und ist deshalb keine Primzahl  