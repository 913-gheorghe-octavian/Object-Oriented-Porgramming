#include <string>
#include "Domain.h"

Scorer::Scorer() {
    this->name = "NULL";
    this->nationality = "NULL";
    this->team = "NULl";
    this->nr_goals = 0;
}
Scorer::Scorer(std::string& name, std::string& nationality, std::string& team, int nr_goals)
{
    this->name = name;
    this->nationality = nationality;
    this->team = team;
    this->nr_goals = nr_goals;
}

std::string Scorer::getName() const
{
    return this->name;
}

std::string Scorer::getNationality()
{
    return this->nationality;
}

std::string Scorer::getTeam()
{
    return this->team;
}

int Scorer::getNrGoals()
{
    return this->nr_goals;
}

