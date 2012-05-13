Libjpeg est un pack fourni pour Dev-C++.
Il permet de manipuler des images au format JPG, et il est obligatoire pour gérer ce type d'image, à moins de vouloir réécrire complémentement le code de compression et de décompression ;)

Malheureusement, j'ai du modifier une partie des headers pour pouvoir compiler mes sources en C ou en CPP. Ce ne sont donc pas tout à fait les originaux. Avec les headers standards, on ne peut compiler qu'en C.

J'ai aussi trouvé un autre libjpeg.a, bien mieux adapté (et plus léger), qui évite les "undefined error" avec les linkers. D'ailleurs, pour faire un link, il faut obligatoirement rajouter -ljpeg dans les options du projet.