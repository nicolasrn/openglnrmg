Libjpeg est un pack fourni pour Dev-C++.
Il permet de manipuler des images au format JPG, et il est obligatoire pour g�rer ce type d'image, � moins de vouloir r��crire compl�mentement le code de compression et de d�compression ;)

Malheureusement, j'ai du modifier une partie des headers pour pouvoir compiler mes sources en C ou en CPP. Ce ne sont donc pas tout � fait les originaux. Avec les headers standards, on ne peut compiler qu'en C.

J'ai aussi trouv� un autre libjpeg.a, bien mieux adapt� (et plus l�ger), qui �vite les "undefined error" avec les linkers. D'ailleurs, pour faire un link, il faut obligatoirement rajouter -ljpeg dans les options du projet.