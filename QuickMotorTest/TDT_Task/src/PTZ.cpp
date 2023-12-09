//#include "PTZ.h"
//#include "dbus.h"
//#include "pid.h"
//#include "chassis_task.h"




//PTZ ptz ;
//PidParam pidparamin1,pidparamout1,pidparamin2,pidparamout2 ;



//_RC  RC2;
//void Pattern_Task(void)
//{
//   
//	ptz.h3 = ABS(ptz.h1-100);
//	
//	if(RC2.SW1Tick == RCS::Mid_Up||ptz.judge == 2)
//	 {
//		 if(ptz.h3<3)
//		 {
//			 ptz.judge = 1;
//			 ptz.Wheel1[0]->ctrlPosition(95);
//			 
//		 } 
//		 else
//			 ptz.judge = 2;
//		 
//	 }
//}

//void Pattern_Task2(void)
//{
//	
//	if(RC2.Key.SW1 == RCS::Up)
//	{
//	 chassis.remoteCtrlUpdate2();
//	chassis.motorCtrl2();	
//	}
//}




//void PTZ_Task (void)
//{
//	ptz.remoteCtrlUpdate1() ;
//	ptz.motorCtrl1() ;
//}

//PTZ::PTZ()
//{
//	pidparamin1.kp = 280 ;
//	pidparamin1.ki = 100 ;
//	pidparamin1.kd = 0.01 ;
//	pidparamin1.integralErrorMax = 1 ;
//	pidparamin1.resultMax = 30000 ;
//	
//	pidparamout1.kp = 12 ;
//	pidparamout1.ki = 10 ;
//	pidparamout1.kd = 0 ;
//	pidparamout1.integralErrorMax = 1 ;
//	pidparamout1.resultMax = 320 ;
//	
//	pidparamin2.kp = 20 ;
//	pidparamin2.ki = 10 ;
//	pidparamin2.kd = 0 ;
//	pidparamin2.integralErrorMax = 5 ;
//	pidparamin2.resultMax = 10000 ;
//	
//	pidparamout2.kp = 20 ;
//	pidparamout2.ki = 10 ;
//	pidparamout2.kd = 0 ;
//	pidparamout2.integralErrorMax = 5 ;
//	pidparamout2.resultMax = 10000 ;
//	
//	for(u8 i = 0 ; i<2 ;i++)
//	{
//		Wheel1[i] = new Motor(GM6020,CAN2,0x205+i) ;
//	}
//	Wheel1[0]->setZeroValue(2133) ;
//	Wheel1[1]->setZeroValue(3500) ;
//		
//	Wheel1[0]->pidInner.setPlanNum(1);
//	Wheel1[0]->pidInner.fbValuePtr[0] = &Wheel1[0]->canInfo.speed;
//	Wheel1[0]->pidInner.paramPtr = &pidparamin1 ;
//	Wheel1[0]->pidOuter.setPlanNum(1);
//	Wheel1[0]->pidOuter.fbValuePtr[0] = &Wheel1[0]->canInfo.totalAngle_f;
//	Wheel1[0]->pidOuter.paramPtr = &pidparamout1 ; 
//	
//	Wheel1[1]->pidInner.setPlanNum(1);
//	Wheel1[1]->pidInner.fbValuePtr[0] = &Wheel1[1]->canInfo.speed;
//	Wheel1[1]->pidInner.paramPtr = &pidparamin2 ;
//	Wheel1[1]->pidOuter.setPlanNum(1);
//	Wheel1[1]->pidOuter.fbValuePtr[0] = &Wheel1[1]->canInfo.totalAngle_f;
//	Wheel1[1]->pidOuter.paramPtr = &pidparamout2 ; 
//}

//void PTZ::remoteCtrlUpdate1(void)
//{
//	s1 = RC.Key.CH[2] ;
//	s2 = RC.Key.CH[3] ;
//	s3 = RC.Key.CH[11] ;
//	motorPos1[0] += -(s1-s3)/66000*18 ;
//	motorPos1[1] += s2/3000 ;
//}

//void PTZ::motorCtrl1(void)
//{
//	for(u8 i = 0 ; i<2 ; i++)
//	{
//		Wheel1[i]->ctrlPosition(motorPos1[i]) ;
//	}
//}