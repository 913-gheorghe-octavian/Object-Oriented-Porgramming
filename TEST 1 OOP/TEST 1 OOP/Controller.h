#pragma once
#include <string>
#include <vector>
#include "Repository.h"

class Controller {
private:
    Repository repository;

public:
    Controller(const Repository& repository);
    Controller();
    bool addController(std::string name,
        std::string nationality,
        std::string team,
        int nr_goals);

    int validController(std::string name);

    std::vector<Scorer> getAllController();
    std::vector<Scorer> filterByGoals(std::string team);
    int getTotalGoals(std::string team);
    int getSizeController();
};