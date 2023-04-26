#include "UI.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;


UI::UI(Controller controller)
{
    this->controller = controller;
}


void UI::Menu()
{
    std::cout << std::endl;
    std::cout << "1. Add a player" << std::endl;
    std::cout << "2. Show all players" << std::endl;
    std::cout << "3. Show all players for a team" << std::endl;
    std::cout << "4. Exit" << std::endl;
}
void UI::printScorer(Scorer scorer)
{
    std::cout << scorer.getName() << " | " << scorer.getNationality() << " | " << scorer.getTeam() << " | " << scorer.getNrGoals() << std::endl;
}

void UI::printAllScorers()
{
    std::vector<Scorer> allScorers = this->controller.getAllController();
    for (int i = 0; i < allScorers.size(); i++)
    {
        printScorer(allScorers[i]);
    }
}

void UI::printSelectedTeams(std::string team)
{
    std::vector<Scorer> Scorers = this->controller.filterByGoals(team);
    for (int i = 0; i < Scorers.size(); i++)
    {
        printScorer(Scorers[i]);
    }
    int total_goals = this->controller.getTotalGoals(team);
    std::cout << total_goals << std::endl;
}


void UI::addScorer()
{
    int nr_goals;
    char name[100], nationality[100], team[100];

    std::cout << "Name: ";
    std::cin >> name;

    std::cout << "Nationality: ";
    std::cin >> nationality;

    std::cout << "Team: ";
    std::cin >> team;

    std::cout << "Number of goals: ";
    std::cin >> nr_goals;

    if (this->controller.addController(name, nationality, team, nr_goals))
        std::cout << "Scorer added" << std::endl;
    else 
        std::cout << "Scorer with the same naem already exists." << std::endl;
}

void UI::run()
{
    this->Menu();
    int command;
    std::cin >> command;
    while (command < 5 && command > 0)
    {
        switch (command)
        {
        case 1:
            this->addScorer();
            break;
        case 2:
            this->printAllScorers();
            break;
        case 3:
            char team[100];
            std::cout << "Team: ";
            std::cin >> team;
            this->printSelectedTeams(team);
            break;
        case 4:
            return;
        default:
            std::cout << "Try again" << std::endl;
            break;
        }
        this->Menu();
        std::cin >> command;
    }
}