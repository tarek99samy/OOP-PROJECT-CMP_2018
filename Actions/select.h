#pragma once
#include"Action.h"


class AddSelectAction :public Action {
	private:
		Point p;
	public:
		AddSelectAction(ApplicationManager* ps);
		void ReadActionParameters();
		void Execute();
		~AddSelectAction();
};
