#pragma once
#include <string>
#include <vector>
#include "Domain.h"

class Repository {
private:
    std::vector<Scorer> ScorerS;
public:
    Repository();
    bool add(std::string name,
        std::string nationality,
        std::string team,
        int nr_goals);

    bool validName(std::string& name);
    std::vector<Scorer> getAll();

    unsigned long int getSize();
};