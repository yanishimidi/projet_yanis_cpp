===================================================
YANISMANAGER - TP CPP 
===================================================

Présentation :
---------------
YanisManager est une application console en C++ pour gérer des étudiants et leurs notes.
Chaque utilisateur possède un rôle spécifique : ADMIN, PROF, STUDENT.

Fonctionnalités par rôle :
- ADMIN : voir, ajouter, supprimer des étudiants (affichage des emails optionnel).
- PROF : voir, ajouter, modifier, supprimer des notes.
- STUDENT : voir uniquement ses propres notes.

Utilisateurs par défaut :
---------------------------
| Rôle     | ID  | Username | Password |
|----------|-----|----------|----------|
| ADMIN    | -   | admin    | 1234     |
| PROF     | -   | prof     | abcd     |
| STUDENT  | 1   | yanis    | pass     |
| STUDENT  | 2   | apon     | pass2    |

Installation et lancement :
-----------------------------
1. Cloner le dépôt GitHub :
   git clone https://github.com/yanishimidi/projet_yanis_cpp.git

2. Entrer dans le dossier du projet :
   cd projet_yanis_cpp/StudentManager

3. Compiler avec C++17 :
   g++ -std=c++17 main.cpp AuthService.cpp ExportService.cpp -o YanisManager
   (Si vous ne précisez pas -o YanisManager, l'exécutable s'appellera a.out)

4. Lancer le programme :
   ./YanisManager
   ou ./a.out si vous avez compilé sans nom de sortie.

Utilisation :
--------------
- Lancez le programme, connectez-vous avec un des comptes.
- Suivez les menus proposés selon votre rôle.
- Pour revenir à l'écran de connexion, choisissez l'option 0 (quitter) dans le menu principal.

Structure du projet (dossier StudentManager) :
-----------------------------------------------
- main.cpp                : point d'entrée
- AuthService.cpp/.h      : gestion de l'authentification
- ExportService.cpp/.h    : export des données
- Student.h, Course.h, Note.h, User.h : modèles
- README.md               : ce fichier (en version markdown)
- export.txt              : exemple de fichier généré


- Assurez-vous d'avoir g++ installé et compatible C++17.

Bon courage avec YanisManager !
