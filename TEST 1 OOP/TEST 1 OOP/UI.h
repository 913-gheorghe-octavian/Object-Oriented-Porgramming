#pragma once 
#include <string>
#include <iostream>
#include "Controller.h"
#include "Domain.h"
#include "Repository.h"

class UI
{
private:
    Controller controller;
public:
    UI(Controller controller);
    void Menu();

    void printAllScorers();
    void printSelectedTeams(std::string team);
    void printScorer(Scorer scorer);
    void run();
    void addScorer();
};