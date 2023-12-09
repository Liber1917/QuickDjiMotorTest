#ifndef _CESHI_
#define _CESHI_

#include "board.h"
#include "motor.h"

class Ceshi
{
	public:
		enum DualPos{_L=0,_R=1};
	Ceshi();
	Motor *dianji;
	void judge(void);
};

void ceshi_task(void);
void ceshi_init(void);
int caloffset(void);
void offset_run(void);

extern Ceshi c1[4],c2,c3;
#endif