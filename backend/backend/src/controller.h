#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "entities.h"

class ReporterController{
	private:
		Reporter* user;
	public:
		Reporter* get_user();
		void set_user(Reporter*);
};

#endif
