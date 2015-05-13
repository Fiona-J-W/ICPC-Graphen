
APSP
====

Einleitung
----------

* Problem: SSSP - Algorithmen werden zu langsam, wenn man sie für alle Paare |V| - mal ausführen muss 
-> ungefähr O(|V|^4)?

<!-- Beispielgraph für unten -->

* Lösung: reine Rechenleistung? Ja, aber geschickt!

=> dynamic programming

* Idee: Man überführt den Graphen in eine Adjazenzmatrix und iteriert geschickt über diese, 
um statt der ursprünglichen Verbindung den kürzesten Pfand von i nach j zu haben.
-> Floyd-Warshall

Erklärung
---------

<!-- mündliche Erklärung anhand von Graphiken -->

Beispielgraph mit |V| ~= 6; durchexerzieren des Problems an diesem Beispiel.

<!-- Zeigen des Quellcodes -->

Code: 

´´´cpp
for (int k = 0; k < V; k++)
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
´´´

Weitere Anwendungen
---------------------

* Auch für SSSP - Probleme anwendbar (wenn |V| < 400)
* Detektion von negativen oder günstigsten Zyklen möglich
-> 
* Finden des Durchmessers eines Graphen (der längste der kürzesten Pfade)
* weiteres?

Beurteilung
-----------

* Assymptotische Komplexität $\in O(|V|^3)$ mit Speicher in O(|V|^2)
* Für andere Probleme nur günstig anzuwenden, wenn |V|< 400
* Sehr leicht zu implementieren (Vierzeiler)

Fazit
-----

> Macht das wenn |V| < 400, sonst überlegt euch was anderes.

Zusammenfassung
---------------

Tabelle mit Übersicht aus dem Buch Seite 161 ins deutsche.
