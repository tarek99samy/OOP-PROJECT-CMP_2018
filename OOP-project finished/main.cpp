#include "ApplicationManager.h"


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{
		
		ActType = AppManager.GetUserAction(); //Step I: Get User Input&Map to Action Type 

		//Exexute the action
		AppManager.ExecuteAction(ActType); //Step II: Create Corresponding Action Object & Step III: Execute the Created Action

		//Now Action is complete but not  reflected yet to GUI
		AppManager.UpdateInterface();	//Step IV: Update Interface

	}while(ActType != EXIT);
	
	return 0;
}