#ifndef FIRE_TASK_
#define FIRE_TASK_

#include "board.h"
#include "can.h"
#include "motor.h"
#include "gun_task.h"
#include "chassis_task.h"

class fire
{
	public:
		fire();
	Motor *gun ;
	float loadpos = 0 ;
	int i = 0 ; 
	void load(void) ;
	void testing(void) ;
};
	
void fire_task(void) ;
void Pattern2_Judge(void);
fire extern f ;
extern Chassis chassis ;


#endif