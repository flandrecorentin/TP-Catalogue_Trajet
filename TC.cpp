/*************************************************************************
                           TC  -  Objet Trajet Complexe
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <TC> (fichier TC.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "TC.h"
#include "Trajet.h"
#include "TS.h"
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
TC::TC(const char* $Depart, const char* $Arrivee)
// Algorithme :
//   
: Trajet($Depart, $Arrivee)
{
  
  #ifdef MAP
    cout << "Construction de TC" << endl;
  #endif
} //----- fin de constructeur

TC::~TC()
{

  #ifdef MAP
    cout << "Destruction de TC" << endl;
  #endif
} //----- fin de destructeur

void TC::AjouterTC(Trajet * $unTrajet)
{
  maListeTrajet.Ajouter($unTrajet);
} //----- fin de AjouterTC

const void TC::Affichage(){
  Trajet::Affichage();
  cout << "  Trajet Complexe composé de : "<< endl;
  maListeTrajet.AffichageTC();
} 

