#include "ExportService.h"
#include <fstream>
#include <iostream>

void ExportService::exportData(const std::string& content, const std::string& filename) {
    std::ofstream file(filename);
    if(file.is_open()) {
        file << content;
        file.close();
        std::cout << "Export terminé : " << filename << "\n";
    } else {
        std::cout << "Erreur ouverture fichier !\n";
    }
}
