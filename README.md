# TP-Catalogue_Trajet

Ce projet "TP-Catalogue_Trajet" est un TP (Travaux Pratiques) réalisé dans 
le cadre me des études (3° année INSA Lyon). Ce TP a pour but de mettre
en oeuvre les  connaissances apprises en cours (sur le langage C++).
L'application de gestion de trajets doit se faire uniquement via commandes
(sans interface graphique) et doit respecter les consignes des sujets de TP
La mise en oeuvre de ce TP se fait en deux temps:

1: Réaliser une application permettant de gérer des trajets (simples ou
complexes), tout cela dans un catalogue. Seule l'utilisation des 
bibliothèques iostream (pour cin, cout, cerr) et cstring (pour strlen, 
strcpy) sont autorisées, d'où la conception du projet difficile à mettre
en place. Voir le sujet du TP2 dans l'archive.

2: Réalisation de deux commandes/deux nouvelles fonctionnalités qui 
sont -chargement d'un catalogue de trajets (lecture d'un fichier) 
-sauvegarde du catalogue courant (écriture dans un fichier). La 
sauvegarde ou le chargement de ces catalogues sauvegardés se font
selon 4 différents modes (sans critères de sélection, selon le 
type de trajets (Simple ou Complexe), selon la ville de départ et/ou
arrivée, puis selon les index des trajets entre les indicdes n et m 
[n;m]).

Pour tester le programme, il est possible d'éxecuter les commandes 
"make" puis "./sejours" (ou "valgrind ./sejours")
