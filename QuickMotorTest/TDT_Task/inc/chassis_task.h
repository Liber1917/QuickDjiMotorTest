#ifndef _CHASSIS_
#define _CHASSIS_

#include "board.h"
#include "motor.h"
#include "imu.h"
#include "imu_task.h"

void Pattern_Judge(void);  //中心函数





class Chassis 
{
	public:
		Chassis() ;
		Motor *Wheel[4] ;
	 int pattern = 0 , swing_drc = 1;
	 float angle = 0;
	 float multipliter = 0 , swing_speed = 0;
		enum dir
		{
			_X = 0 ,
			_Y = 1 ,
			_R = 2
		} ;
		float motorSpd[4] ;
		float chassisSpd[3] ;
		void remoteCtrlUpdate(void) ;
	  void remoteCtrlUpdate2(void) ;
		void remoteCtrlUpdate4(void) ;
		void remoteCtrlUpdate6(void) ; //摇摆
		void angle_judge(void);
		void motorCtrl(void) ;
		void motorCtrl2(void) ;
		void motorCtrl4(void) ;
};
void Chassis_Task(void) ;
void Chassis_Task2(void); 
void Chassis_Task3(void); 
void Chassis_Task4(void); 

//void Pattern_Task(void);  //模式转换




class PTZ
{
	public :
		PTZ() ;
	  void Ptz_Task_Init(void);
		Motor *Wheel1[2] ;
		float s1 = 0 , s2 = 0 , s3 = 0,s4 = 0,s5 = 0,s6 = 0,s7 = 0,s8 = 0,s9 = 0;
	  float h1 = 0, h2 = 0, h3 = 0;
	  float judge = 0;
		float motorPos1[6] ;
		float PTZPos[2] ;
		void remoteCtrlUpdate1(void) ;
	  void remoteCtrlUpdate3(void);
	  void remoteCtrlUpdate5(void);
	  void remoteCtrlUpdate7(void);  //摇摆（云台位置不变）
		void motorCtrl1(void) ;
 		void motorCtrl3(void) ;
	  void motorCtrl5(void) ;
};
extern PTZ ptz;
void PTZ_Task(void) ;
void PTZ_Task2(void) ;
void PTZ_Task3(void) ;
void PTZ_Task4(void) ;  //摇摆
#endif



