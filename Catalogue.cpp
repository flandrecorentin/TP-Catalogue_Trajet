/*************************************************************************
                           Code Catalogue 
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
#include <iostream>
#include <cstring>
#include "Catalogue.h"
#include "ListeTrajet.h"
// #include "Xxx.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
Catalogue::Catalogue()
// Algorithme :
{
  size=0;
  maListeTrajet=ListeTrajet();

  #ifdef MAP
    cout << "Construction de Catalogue" << endl;
  #endif
}
Catalogue::~Catalogue()
// Algorithme :
{

  #ifdef MAP
    cout << "Destruction de Catalogue" << endl;
  #endif
}

void Catalogue::AjouterUnTrajet( Trajet * $unTrajet)
// Algorithme :
{
    size++; 
    maListeTrajet.Ajouter($unTrajet);
}

void Catalogue::Chercher(const char * Depart, const char * Arrivee)
{
  maListeTrajet.Chercher(Depart, Arrivee);
}

const void Catalogue::AffichageCatalogue(){
  cout << "\n\n*************************************************" <<endl;
  cout <<     "******** DEBUT CATALOGUE DU GROUPE B3207 ********" <<endl;
  cout <<     "************* Composé" ;
  ((size>1) ? ( cout<< "s ") : (cout<< " "));
  cout<<"de " << size << " trajet";
  ((size>1) ? ( cout<< "s ") : (cout<< "  "));
  cout<< "*************" <<endl;
  maListeTrajet.Affichage();
  cout << "\n-------------------------------------------" << endl;
      cout << "-------------------------------------------" << endl;
  cout <<     "\n*************************************************" <<endl;
  cout <<     "******** FIN CATALOGUE DU GROUPE B3207 **********" <<endl;
  cout <<     "*************************************************\n\n" <<endl;
}
//----- fin de AffichageCatalogue

