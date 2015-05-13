MST
=====
Problem
--------
* "billigstes" Netzwerk

* gegben ein ungerichteter verbunder gewichteter Graph: finde verbindenden Baum mit geringstem Gewicht (MST)

Lösung
-------
* Greedy Ansatz:
	* betrachte die Kante mit niedrigstem Gewicht
	* überprüfe, ob hinzufügen der Kante zu einem Zyklus führt:
        * ja: verwerfe Kante
        * nein : füge Kante zum Baum hinzu
	* starte oben mit restlichen Kanten bis alle Kanten abgearbeitet
	* Baum ist MST
	
Vorführung am Graphen
-----------------
*kleiner Graph, vorführen der ersten paar Schritte*

Implementierung
---------------
* sortiere Kanten nach Gewicht
* benutze Union-Find um Zyklen zu verhindern
* Laufzeit: O(E*log(E) + E*(~1))=O(E*log(E))=O(E*log(V^2))=O(E*log(V))

Quellcode
---------
[Code](kruskal.cpp)

Weitere Probleme
-----------------
* vorgegebene Kanten
* "Minimum Spanning Forest": mehrere Bäume
* minmax - Problem: längsten Pfad minimieren