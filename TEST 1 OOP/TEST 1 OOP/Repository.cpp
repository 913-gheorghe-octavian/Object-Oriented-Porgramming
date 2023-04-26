#include "Repository.h"
#include <string>

Repository::Repository() {
    this->add("Nora", "NOR", "Larvik", 20);
    this->add("Isabelle", "SWE", "Bucurest", 80);
    this->add("Allison", "RUS", "Larvik", 10);
    this->add("Cristina", "ROU", "Rostov", 50);
    this->add("Nerea", "FRA", "Larvik", 10);
}

bool Repository::add(std::string name, std::string nationality, std::string team, int nr_goals)
{
    /*
    * RECEIVES FROM THE CONTROLLER THE DATA FOR THE NAME, NATIONALITY, TEAM, AND GOALS
    * It createw a scorer using the data given as parameters (data that has already been checked by name) and then adds it
    * to the end of the list of players using the push_back function. If the operation was succesful (we check if the name has been added)
    * then we return "true", else "false"
    */
    Scorer scorer(name, nationality, team, nr_goals);
    this->ScorerS.push_back(scorer);
    if (this->validName(name)) {
        return true;
    }
    return false;
}


bool Repository::validName(std::string& name)
{
    for (auto& trenchCoat : this->ScorerS) {
        if (trenchCoat.getName() == name) {
            return true;
        }
    }
    return false;
}

std::vector<Scorer> Repository::getAll()
{
    return this->ScorerS;
}

unsigned long int Repository::getSize()
{
    return this->ScorerS.size();
}
