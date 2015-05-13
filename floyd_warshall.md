
APSP 
====
*(All pairs shortest paths)*

Einleitung
----------

* Problem: Finde so schnell es geht alle kürzesten Verbindungen zwischen allen Knoten
* 1. Lösung: SSSP - Algorithmen sind langsam, weil man sie für alle Paare |V| - mal ausführen muss 

-> |V| * O ((|E| + |V|) * log(|V|)) = |V| * O ((|V|^2 + |V|) * log(|V|))
    				    = |V| * O ((|V|^2) * log(|V|)) 
    				    = O ((|V|^3) * log(|V|))
    
-> geht es schneller?

<!-- Beispielgraph für unten -->

* Lösung: Ja, mit DP!

 *(dynamic programming)*

* Idee: Man überführt den Graphen in eine Adjazenzmatrix und iteriert geschickt über diese, 
um statt der ursprünglichen Verbindung den kürzesten Pfand von i nach j zu haben.
-> Floyd-Warshall

Erklärung
---------

<!-- mündliche Erklärung anhand von Graphiken -->

> Beispielgraph mit |V| ~= 5; durchexerzieren des Problems an diesem Beispiel.

<!-- Zeigen des Quellcodes -->

Code: 

```cpp
for (int k = 0; k < V; k++)
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
```

Aufwand: O(|V|^3)

Weitere Anwendungen
---------------------

* Auch für SSSP - Probleme anwendbar (wenn |V| < 400)
* Detektion von negativen oder günstigsten Zyklen möglich
-> mit setzen auf hohen Wert auf der Diagonalen
* Finden des Durchmessers eines Graphen (der längste der kürzesten Pfade)
* Minimax, Maximin
* Transitive Hülle berechnen (wer ist mit wen verbunden -> bits)
* Finden von starken Zusammenhangskomponenten
* evtl. weitere Anwendungen in konkreten Fällen

Beurteilung
-----------

* Asymptotische Komplexität $\in O(|V|^3)$ mit Speicher in O(|V|^2)
* Für andere Probleme nur günstig anzuwenden, wenn |V|< 400
* Sehr leicht zu implementieren (Vierzeiler)

Fazit
-----

* Gut für das ürsprüngliche Problem
* Auch gut für andere Probleme, sofern |V| < 400, ansonsten andere Algorithmen.

Zusammenfassung
---------------

Tabelle mit Übersicht aus dem Buch Seite 161 ins deutsche.
