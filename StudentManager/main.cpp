#include <iostream>
#include <vector>
#include <algorithm>
#include "User.h"
#include "Student.h"
#include "Note.h"
#include "AuthService.h"
#include "ExportService.h"

using namespace std;

void adminMenu(vector<Student>& students) {
    int choice;
    do {
        cout << "\n--- MENU ADMIN ---\n";
        cout << "1. Voir etudiants\n";
        cout << "2. Ajouter etudiant\n";
        cout << "3. Supprimer etudiant\n";
        cout << "0. Quitter\n";
        cout << "Choix: ";
        cin >> choice;

        if(choice == 1) {
            for(const auto& s : students)
                cout << s.getId() << " | " << s.getName() << " | " << s.getEmail() << endl;
        }
        else if(choice == 2) {
            int id;
            string name, email;
            cout << "ID: "; cin >> id;
            cout << "Nom: "; cin >> name;
            cout << "Email: "; cin >> email;
            students.push_back(Student(id, name, email));
            cout << "Etudiant ajoute.\n";
        }
        else if(choice == 3) {
            int id;
            cout << "ID a supprimer: ";
            cin >> id;
            students.erase(remove_if(students.begin(), students.end(),
                [id](Student& s) {
                    return s.getId() == id;
                }), students.end());
            cout << "Suppression effectuee.\n";
        }

    } while(choice != 0);
}

void profMenu(vector<Note>& notes) {
    int choice;
    do {
        cout << "\n--- MENU PROF ---\n";
        cout << "1. Voir notes\n";
        cout << "2. Ajouter note\n";
        cout << "3. Modifier note\n";
        cout << "4. Supprimer note\n";
        cout << "0. Quitter\n";
        cout << "Choix: ";
        cin >> choice;

        if(choice == 1) {
            for(const auto& n : notes)
                cout << "Student " << n.getStudentId()
                     << " | Note " << n.getValue() << endl;
        }
        else if(choice == 2) {
            int sId;
            float value;
            cout << "Student ID: "; cin >> sId;
            cout << "Note: "; cin >> value;
            notes.push_back(Note(sId, value));
            cout << "Note ajoutee.\n";
        }
        else if(choice == 3) {
            int sId;
            float newValue;
            cout << "Student ID: "; cin >> sId;
            for(auto& n : notes) {
                if(n.getStudentId() == sId) {
                    cout << "Nouvelle note: ";
                    cin >> newValue;
                    n.setValue(newValue);
                    cout << "Note modifiee.\n";
                }
            }
        }
        else if(choice == 4) {
            int sId;
            cout << "Student ID: "; cin >> sId;
            notes.erase(remove_if(notes.begin(), notes.end(),
                [sId](Note& n) {
                    return n.getStudentId() == sId;
                }), notes.end());
            cout << "Note supprimee.\n";
        }

    } while(choice != 0);
}

void studentMenu(User* user, const vector<Note>& notes) {
    int choice;
    do {
        cout << "\n--- MENU ETUDIANT ---\n";
        cout << "1. Voir mes notes\n";
        cout << "0. Quitter\n";
        cout << "Choix: ";
        cin >> choice;

        if(choice == 1) {
            for(const auto& n : notes) {
                if(n.getStudentId() == user->getId()) {
                    cout << "Note: " << n.getValue() << endl;
                }
            }
        }

    } while(choice != 0);
}

int main() {

    vector<User> users = {
        User(1, "admin", "1234", ADMIN),
        User(2, "prof", "abcd", PROF),
        User(3, "yanis", "pass", STUDENT),
        User(4, "apon", "pass2", STUDENT)
    };

    vector<Student> students = {
        Student(3, "Yanis", "yanis@mail.com"),
        Student(4, "Apon", "apon@mail.com")
    };

    vector<Note> notes = {
        Note(3, 15),
        Note(3, 17),
        Note(4, 12)
    };

    bool running = true;

    while(running) {
        string username, password;
        cout << "\nUsername: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        User* currentUser = AuthService::login(users, username, password);

        if(!currentUser) {
            cout << "Login echoue.\n";
            continue;
        }

        cout << "Connecte : " << currentUser->getUsername() << endl;

        if(currentUser->getRole() == ADMIN)
            adminMenu(students);
        else if(currentUser->getRole() == PROF)
            profMenu(notes);
        else
            studentMenu(currentUser, notes);

        delete currentUser;
    }

    return 0;
}