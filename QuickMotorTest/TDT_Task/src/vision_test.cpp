//#include "vision_test.h"
//#include "pid.h"
//#include "dbus.h"

//test ready ;
//PidParam PP ;
//PidParam PP1 ;
//float amp2[4] = {1,1,1,1} ;

//void test_Task (void)
//{
//	ready.remoteCtrlUPD() ;
//	ready.moterCtrl2() ;
//}

//test::test() 
//{
//	PP.kp = 5 ;
//	PP.ki = 100 ;
//	PP.kd = 0 ;
//	PP.integralErrorMax = 5 ;
//	PP.resultMax = 7000 ;
//	PP1.kp = 15 ;
//	PP1.ki = 200 ;
//	PP1.kd = 0 ;
//	PP1.integralErrorMax = 5 ;
//	PP1.resultMax = 15000 ;
//	X[0] = new Motor(M3508,CAN2,0x201) ;
//	X[1] = new Motor(M3508,CAN2,0x203) ;
//	X[2] = new Motor(M3508,CAN2,0x204) ;
//	X[3] = new Motor(M3508,CAN2,0x202) ;
//	int16_t avgerr = 0 ;
//	float eacherr[2] ;
//	for(u8 i = 0 ; i<2 ; i++)
//	{
//		X[i]->pidInner.setPlanNum(1) ;
//		eacherr[i] = X[i]->canInfo.speed ;
//		X[i]->pidInner.paramPtr = &PP ;
//	}
//	for(u8 i = 2 ; i<4 ; i++)
//	{
//		X[i]->pidInner.setPlanNum(1) ;
//		X[i]->pidInner.fbValuePtr[0] = &X[i]->canInfo.speed ;
//		X[i]->pidInner.paramPtr = &PP1 ;
//	}
//	for(u8 i = 0 ; i<2 ; i++)
//	{
//		avgerr += eacherr[i] ;
//	}
//	avgerr /= 2 ;
//	for(u8 i = 0 ; i<2 ; i++)
//	{
//		X[i]->pidInner.fbValuePtr[0] = &avgerr ;
//	}
//}

//void test::remoteCtrlUPD(void)
//{
//	rckey[0] = RC.Key.CH[11] ;
//	rckey[1] = RC.Key.CH[0] ;
//	rckey[2] = RC.Key.CH[2] ;
//	for(u8 i = 0 ; i<2 ; i++)
//	{
//		eachmotorspd[i] = rckey[0] * amp2[i] ;
//	}
//	for(u8 i = 2 ; i<4 ; i++)
//	{
//		eachmotorspd[i] = rckey[i-1] * amp2[i] ;
//	}
//}
//void test::moterCtrl2(void)
//{
//	for(u8 i = 0 ; i<4 ; i++)
//	{
//		X[i]->ctrlSpeed(eachmotorspd[i]) ; 
//	}
//}
