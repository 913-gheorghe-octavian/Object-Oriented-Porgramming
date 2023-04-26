#include "Domain.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
using namespace std;

int main()
{
	Repository repository;
	Controller controller(repository);
	UI ui(controller);
	ui.run();
}