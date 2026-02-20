# YanisManager

## Présentation

YanisManager est un projet C++ permettant de gérer des étudiants et leurs notes.
Chaque utilisateur possède un rôle : ADMIN, PROF ou STUDENT.

Fonctionnalités :

- ADMIN : voir, ajouter et supprimer des étudiants, ainsi que consulter leurs emails.
- PROF : voir, ajouter, modifier et supprimer des notes.
- STUDENT : voir uniquement ses propres notes.

---

## Utilisateurs par défaut

ADMIN
username : admin
password : 1234

PROF
username : prof
password : abcd

STUDENT
username : yanis
password : pass

STUDENT
username : apon
password : pass2

---

## Installation et lancement

1) Cloner le projet :

git clone https://github.com/yanishimidi/projet_yanis_cpp
cd YanisManager

2) Compiler :

g++ -std=c++17 main.cpp AuthService.cpp ExportService.cpp -o YanisManager

3) Lancer le programme :

./YanisManager

---

## Utilisation

- Se connecter avec un des comptes ci-dessus.
- Utiliser le menu correspondant au rôle.
- Pour revenir à l’écran de connexion, choisir l’option 0. Quitter.
- Le programme reste actif après déconnexion.

---

## Informations complémentaires

- Les notes sont directement associées aux étudiants.
- Les données sont stockées en mémoire.
- Aucune base de données n’est utilisée.
