#pragma once
#include <string>

class Scorer {
private:
    std::string name;
    std::string nationality;
    std::string team;
    int nr_goals;

public:
    Scorer();
    Scorer(
        std::string& name,
        std::string& nationality,
        std::string& team,
        int nr_goals
    );

    std::string getName() const;
    std::string getNationality();
    std::string getTeam();
    int getNrGoals();


};