#pragma once
#include <string>

class ExportService {
public:
    static void exportData(const std::string& content, const std::string& filename);
};
