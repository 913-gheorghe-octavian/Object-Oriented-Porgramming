#include "Controller.h"
using namespace std;

Controller::Controller(const Repository& repository)
{
    this->repository = repository;
}

Controller::Controller()
{
    this->repository = Repository();
}

bool Controller::addController(std::string name, std::string nationality, std::string team, int nr_goals)
{
    /*
    * Receives from UI (WRITTEN BY THE USER) the name, nationality, team, and number of goals of a player
    * it checks if there exists a player with a same name using another function from the repository. If the name is not there, then
    * the data is good to be added to the repository, so it is sent to the add function in repository
    */
    if (this->repository.validName(name))
    {
        return false;
    }
    return this->repository.add(name, nationality, team, nr_goals);
}

int Controller::validController(std::string name)
{
    return this->repository.validName(name);
}

std::vector<Scorer> Controller::getAllController()
{
    return this->repository.getAll();
}

std::vector<Scorer> Controller::filterByGoals(std::string team)
{
    /*
    * This function works alongside the getTotalGoals function.
    * inside the allScorers it puts the data for all players up until now. It then goes through all of them, and if it they have
    * the team name entered as input by the user, then the function adds it to the "goodScorers" vector, using push_back
    * The function then goes through all of the "goodScorers" sorting them by how many goals they got
    * The function returns the vector with the selected scorers
    * 
    */
    std::vector<Scorer> goodScorers;
    std::vector<Scorer> allScorers = this->repository.getAll();
    for (auto& Scorer : allScorers)
    {
        if (Scorer.getTeam() == team)
        {
            goodScorers.push_back(Scorer);
        }
    }
    for (int i = 0; i < goodScorers.size()-1; i++)
        for(int j = i+1; j < goodScorers.size(); j++)
        {
            if (goodScorers[i].getNrGoals() > goodScorers[j].getNrGoals())
            {
                std::vector<Scorer> temp;
                temp.push_back(goodScorers[i]);
                goodScorers[i] = goodScorers[j];
                goodScorers[j] = temp[0];
            }
        }
    return goodScorers;
}

int Controller::getTotalGoals(std::string team)
{
    /*
    * a name is given as imput by the user in UI. We go through the data of all players inside the repository. If any of them
    * are of the selected team, we add their number of goals to the "total_goals" variable. The program then returns the total_goals
    */
    int total_goals = 0;
    std::vector<Scorer> allScorers = this->repository.getAll();
    for (auto& Scorer : allScorers)
    {
        if (Scorer.getTeam() == team)
        {
            total_goals += Scorer.getNrGoals();
        }
    }
    return total_goals;
}

int Controller::getSizeController()
{
    return this->repository.getSize();
}
