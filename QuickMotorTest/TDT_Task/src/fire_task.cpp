#include "fire_task.h"
#include "dbus.h"
#include "pid.h"
//fire f ;
//PidParam prmin , prmout ;

//int t = 0 ,m = 0 ;
//int last_key ;


//void Pattern2_Judge(void)
//{
//	switch(chassis.pattern){
//		case 1:
//			gun_task() ;
//		  fire_task() ;
//		  break ;
//		case 2:
//			gun_task2();
//		  break;
//		case 3:
//			gun_task2();
//	}
//}

//void fire_task(void)
//{
//	f.load() ;
//}

//fire::fire()
//{
//	gun = new Motor(M2006,CAN1,0x200+7) ;
//	prmin.kp = 5 ;
//	prmin.ki = 5 ;
//	prmin.kd = 0.01 ;
//	prmin.integralErrorMax =100 ;
//	prmin.resultMax = 100000 ;
//	prmout.kp = 15 ;//5
//	prmout.ki = 5 ;
//	prmout.kd = 0 ;
//	prmout.integralErrorMax =100 ;
//	prmout.resultMax = 10000 ;
//	
//	gun->pidInner.setPlanNum(1) ;
//	gun->pidInner.fbValuePtr[0] = &gun->canInfo.speed ;
//	gun->pidInner.paramPtr = &prmin ;
//	gun->pidOuter.setPlanNum(1) ;
//	gun->pidOuter.fbValuePtr[0] = &gun->canInfo.totalAngle_f ;
//	gun->pidOuter.paramPtr = &prmout ;
//}

//float elec = 0 ,elecabs = 0;
//void fire::load()
//{
//	if(RC.Key.CH[8]&&RC.Key.SHIFT)   //连发
//	{
//		if(!(i % 100))   
//		{
//			loadpos += 360 * 36 / 8 ;
//			elec = gun->canInfo.trueCurrent ;
//			elecabs = ABS(elec);
//			if (elecabs>9000)
//			{
//				loadpos -= 2 * 360 * 36 / 8 ;//
//			}
//			i = 0 ;
//			
//		}
//		gun->ctrlPosition(loadpos) ;
//		last_key = 1 ;
//	}
//	i++ ;
//	if(RC.Key.CH[8])  //单发
//	{
//		if(last_key != 3)
//		{
//			loadpos += 360 * 36 / 8 ;
//			elec = gun->canInfo.trueCurrent ;
//			elecabs = ABS(elec);
//			if (elecabs>9000)
//			{
//				loadpos -= 2 * 360 * 36 / 8 ;//
//			}
//		}
//		
//		last_key = 3 ;
//	}
//	if(RC.Key.CH[8] == 0)
//	{
//		last_key = 2 ;
//	}
//	gun->ctrlPosition(loadpos) ;
//	//	loadpos += m ;
//}








