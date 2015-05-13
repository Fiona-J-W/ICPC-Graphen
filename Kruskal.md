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
	* falls hinzufügen der Kante zu Zyklus führt --> verwerfe Kante
		* sonst füge zum Baum hinzu
	* starte oben mit restlichen Kanten bis alle Kanten abgearbeitet
	* -> Baum ist MST
	
Vorführung am Graphen
-----------------

Implementierung
---------------
* sortiere Kanten nach Gewicht
* benutze Union-Find
* Laufzeit: O(E log(E) + E * alpha)=O(ElogE)=O(ElogV^2)=O(ElogV)

Quellcode
---------

Weitere Probleme
-----------------
* vorgegebene Kanten
* "Minimum Spanning Forest"
* minmax - Problem