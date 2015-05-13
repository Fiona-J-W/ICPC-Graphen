#Aussprache

Ein kurze Anmerkung dass es "Daikstra" ausgesprochen wird, und nicht anders.

#Anwendung

Breitensuche geht bei gewichten Graphen nicht. Beispielgraph, bei dem Breitensuche fehlschlägt (Von `X` nach `Y`)

```
    1
X-------a
|      /
| 3   /1
|    /
Y___/
```


#Implementierungsonsidee

Es ist grundsätzlich wie die Breitensuche, aber 

* Dynamische Programmierung (markieren besuchter Knoten):
    Dadurch kann vorzeitig abgebrochen werden, besser bei Beispiel zu sehen
* PriorityQueue statt Queue:
    Damit macht man eine Breitensuche nach Kantengewichten

#Vorstellung der Implementierung

(commite ich heute abend)

#Durcharbeiten am Beispiel

Etwas größere Variante von: 

![Beispiel](http://upload.wikimedia.org/wikipedia/commons/b/be/Dijkstra%27s_algorithm.svg)

#Geht nicht bei negativen Kanten, überleitung


