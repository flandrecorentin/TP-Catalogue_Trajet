/*************************************************************************
                           Code Main 
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par fLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr 
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <Xxx> (fichier Xxx.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
using namespace std;
//g++ -o TP2 Trajet.cpp Main.cpp
#include <iostream>

#include <cstring>

#include "Trajet.h"

#include "Catalogue.h"


#include "TS.h"

#include "TC.h"
 // #include "Xxx.h"Trajet_H

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void lireLigne(char * fichier){
  //Mode d'emploi:  Lecture d'une ligne jusqu'au retour à la ligne
  //                et pointeur de chaine entré en paramètre
  //Contrat:        L'allocation de l'espace de la chaine de
  //                caractères est déjà faite et l'espace prévu est
  //                suffisant pour ce que va entrer l'utilisateur
  char lecture;
  lecture=fgetc(stdin);
  int i=0;
  while(lecture!='\n' && lecture!=EOF){
    fichier[i]=lecture;
    i++;
    lecture=fgetc(stdin);
  }
  fichier[i]='\0';
} //----- Fin de lireLigne

int atoi(char * nombre){
  //Mode d'emploi:  Entrée d'une chaine de caractère de chiffres
  //                en paramètre, sortie de l'entier correspondant 
  //                en return
  //                La lecture de la chaine s'arrete au caractère \0
  //                ou pour tout caractère invalide
  //Contrat:        La chaine de caractère est une suite de chiffres
  //                ASCII terminant par le caractère \0
  int res=0;
  int i=0;
  int puissance=1;
  while(nombre[i]!='\0'&& nombre[i]>=48 && nombre[i]<=57){
    res=(nombre[i]-48)*puissance;
    puissance=puissance*10;
    i++;
  }
  return res;
} //----- Fin de atoi





int main()
// Algorithme :
// Classe Main permettant de faire la démo du TP 
// 'POO1-TP2-B3207-FLANDRE-THOMAS'  
{
  //10 décembre 12h00, dans le zip : code source + doc
  // make + ./sejours valgrind + ./sejours
  //cout <<"DEBUT DEMOs;lfjkkghslkd"<< endl; 
  Catalogue catalogue;
  /*TS TS1("Paris", "Marseille", "Bateau");
  Trajet * ptTS1 = & TS1;
  TS TS2("Lyon", "NLF", "Roulade arriere");
  Trajet * ptTS2 = & TS2;
  // TS1.Affichage();
  catalogue.AjouterUnTrajet(ptTS1);
  catalogue.AjouterUnTrajet(ptTS2);
  //catalogue.AffichageCatalogue();

  TC TC1("Paris", "NLF");
  TC1.AjouterTC(ptTS1);
  TC1.AjouterTC(ptTS2);
  //TC1.AfficherTC();

  catalogue.AjouterUnTrajet( & TC1);
  catalogue.AjouterUnTrajet(ptTS1);*/
  //catalogue.AffichageCatalogue();
  //cout <<"FIN DEMO"<< endl; 
  char lecture[100] ="Probleme";
  char lectureDepart[100] ="Probleme";
  char lectureArrivee[100] ="Probleme";
  char stockChar[100];
  char lectureLocomotion[100] ="Probleme";

  cout << endl << "Imprimer Catalogue : Ecrivez \"Catalogue\"" << endl;
  cout << "Ajouter un Trajet Simple : Ecrivez \"Simple\"" << endl;
  cout << "Ajouter un Trajet Complexe : Ecrivez \"Complexe\"" << endl;
  cout << "Chercher un Trajet : Ecrivez \"Chercher\"" << endl;
  cout << "Quitter : Ecrivez \"Quit\"" << endl << endl;

  lireLigne(lecture);
  while (strcmp(lecture, "Quit") != 0) {
    
    if (strcmp(lecture, "Catalogue") == 0) {
      catalogue.AffichageCatalogue();

    } else if (strcmp(lecture, "Simple") == 0) {
      cout << "Entrez un départ : " << endl;
      lireLigne(lectureDepart);

      cout << "Entrez une arrivée : " << endl;
      lireLigne(lectureArrivee);

      cout << "Entrez un moyen de locomotion : " << endl;
      lireLigne(lectureLocomotion);

      Trajet * ptTS1 = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
      catalogue.AjouterUnTrajet(ptTS1);

    } else if (strcmp(lecture, "Complexe") == 0) {
      cout << "Entrez un départ : " << endl;
      lireLigne(lectureDepart);

      cout << "Entrez une arrivée : " << endl;
      lireLigne(lectureArrivee);

      TC * ptTC1 = new TC(lectureDepart, lectureArrivee);
      strcpy(stockChar, lectureArrivee);

      cout << "Entrez le nombre de sous-trajets : " << endl;
      lireLigne(lecture);
      int val=atoi(lecture);
      TS * ptTS;

      for (int i = 0; i < val - 1; i++) {
        cout << "Entrez l'arrivée du sous-trajet :" << i + 1 << endl;
        lireLigne(lectureArrivee);

        cout << "Entrez le moyen de locomotion du sous trajet :" << i + 1 << endl;
        lireLigne(lectureLocomotion);

        ptTS = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
        ptTC1 -> AjouterTC(ptTS);
        strcpy(lectureDepart, lectureArrivee);
      }

      cout << "Entrez le moyen de locomotion du sous trajet :" << val << endl;
      lireLigne(lectureLocomotion);

      ptTS = new TS(lectureDepart, stockChar, lectureLocomotion);
      ptTC1 -> AjouterTC(ptTS);
      catalogue.AjouterUnTrajet(ptTC1);

    } else if (strcmp(lecture, "Chercher") == 0) {

      char lectureDepart[100];
      char lectureArrivee[100];
      cout << "Entrez le départ du trajet cherché :" << endl;
      lireLigne(lectureDepart);

      cout << "Entrez l'arrivée du trajet cherché :" << endl;
      lireLigne(lectureArrivee);


      catalogue.Chercher(lectureDepart, lectureArrivee);

    } else {
      cout << "Commande/Requête non reconnue\n\n" << endl;
    }
    cout << "\n\nImprimer Catalogue : Ecrivez \"Catalogue\"" << endl;
    cout << "Ajouter un Trajet Simple : Ecrivez \"Simple\"" << endl;
    cout << "Ajouter un Trajet Complexe : Ecrivez \"Complexe\"" << endl;
    cout << "Chercher un Trajet : Ecrivez \"Chercher\"" << endl;
    cout << "Quitter : Ecrivez \"Quit\"" << endl << endl;
    
    lireLigne(lecture);
  }
  return 0;
} //----- fin de Main


