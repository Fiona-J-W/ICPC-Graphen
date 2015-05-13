#Aussprache

Ein kurze Anmerkung dass es "Daikstra" ausgesprochen wird, und nicht anders.

#Anwendung

Hier wird ein Beispielgraph gezeigt, bei dem Breitensuche fehlschlägt.

```
    1
X-------a
|      /
| 3   /1
|    /
Y`__/
```


#Implementationsidee

* Dynamische Programmierung (markieren besuchter Knoten)
* PriorityQueue statt Queue. 

#Vorstellung der Implementierung

(commite ich heute abend)

#Durcharbeiten am Beispiel

Etwas größere Variante von: 

![Beispiel](http://upload.wikimedia.org/wikipedia/commons/b/be/Dijkstra%27s_algorithm.svg)

#Geht nicht bei negativen Kanten, überleitung


