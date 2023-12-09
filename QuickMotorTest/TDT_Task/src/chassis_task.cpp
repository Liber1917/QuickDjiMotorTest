#include "chassis_task.h"
#include "dbus.h"
#include "pid.h"
#include "my_math.h"

/*
*
*
*Wheel[]�ǵ���
*Wheel1[]����̨
*
*/
/*
Chassis chassis ;
PTZ ptz ;
PidParam pidval,pp[2] ;             //����pid
PidParam pidparamin[2][2],pidparamout[2][2] ;  //��̨pid

float d1 = 0;


void Pattern_Judge(void)
{
	if(RC.Key.Z)
	{
		chassis.pattern = 1 ;
	}
	if(RC.Key.SW1 == RCS::Mid)
	{
		chassis.pattern = 2 ;
	}
	if(RC.Key.SW1 == RCS::Down)
	{
		chassis.pattern = 0 ;
	}
	if(RC.Key.C)
	{
		chassis.pattern = 3 ;
	}
	if(RC.Key.X)
	{
		chassis.pattern = 4 ;
	}
	
	switch(chassis.pattern){
		case 1: 
			Chassis_Task();
		  PTZ_Task() ;
		  break;
		case 2: 
			Chassis_Task2();
		  PTZ_Task2() ;
		  break;
		case 3: 
			Chassis_Task3();
		  PTZ_Task3() ;
		  break;
		case 4:
			Chassis_Task4();
		  PTZ_Task4() ;
		  break;
	}




}
*/
/*------------------------------����������-----------------------------------*/
/*
void Chassis_Task (void)
{
	chassis.remoteCtrlUpdate() ;
	chassis.motorCtrl() ;
}

void Chassis_Task2(void)         //ģʽ����Up
{
	chassis.remoteCtrlUpdate2() ;
	chassis.motorCtrl2() ;
}	

void Chassis_Task3(void)         //ģʽ����Down
{
	chassis.remoteCtrlUpdate4() ;
	chassis.motorCtrl4() ;
}	

void Chassis_Task4(void)    //ҡ��ģʽ
{
	chassis.remoteCtrlUpdate6() ;
	chassis.motorCtrl4() ;
}
*/
/*-----------------------------------���̳�ʼ��--------------------------*/
//float amp[4] = {2000,2000,2000,2000} ;
//int8_t drc[3][4] = {{1,1,-1,-1},{1,-1,1,-1},{-1,-1,-1,-1}} ;//��֮��
//Chassis::Chassis()
//{
//	pidval.kp = 20 ;
//	pidval.ki = 200 ;
//	pidval.kd = 0 ;
//	pidval.integralErrorMax = 2 ;
//	pidval.resultMax = 16000 ;
////	pp[0].kp = 10 ;
////	pp[0].ki = 200 ;
////	pp[0].kd = 0 ;
////	pp[0].integralErrorMax = 5 ;
////	pp[0].resultMax = 10000 ;
////	pp[1].kp = 10 ;
////	pp[1].ki = 20 ;
////	pp[1].kd = 0 ;
////	pp[1].integralErrorMax = 1 ;
////	pp[1].resultMax = 320 ;
//	for(u8 i = 0 ; i<4 ; i++)
//	{
//		//Wheel[i] = new Motor(M3508 ,CAN1,0X201+i) ;
//		Wheel[i]->pidInner.setPlanNum(2) ;
//		Wheel[i]->pidInner.fbValuePtr[0] = &Wheel[i]->canInfo.speed ;
//		Wheel[i]->pidInner.paramPtr = &pidval ;		
//	}
////	for(u8 i = 0 ; i<4 ;i++)
////	{
////		Wheel[i]->pidInner.fbValuePtr[1] = &Wheel[i]->canInfo.speed ;
////		Wheel[i]->pidInner.paramPtr = &pp[1] ;	
////		Wheel[i]->pidOuter.fbValuePtr[1] = &Wheel[i]->canInfo.totalAngle_f ;
////		Wheel[i]->pidOuter.paramPtr = &pp[2] ;	
////	}
//}

///*-----------------------------�ٶ�ת��---------------------------------------*/
///*���������˶�*/
//void Chassis::remoteCtrlUpdate(void)
//{
//	chassisSpd[_X] = RC.Key.A - RC.Key.D ;
//	chassisSpd[_Y] = RC.Key.W - RC.Key.S ;
//	chassisSpd[_R] = RC.Key.Q - RC.Key.E ;
//	for(u8 i = 0 ; i<4 ;i++)
//	{
//		motorSpd[i] = chassisSpd[_X] * amp[i] * drc[_X][i] ;
//		motorSpd[i] += chassisSpd[_Y] * amp[i] * drc[_Y][i] ;
//		motorSpd[i] += chassisSpd[_R] * amp[i] * drc[_R][i] ;
//	}
//}
///*���̸��棨�ֶ�������*/
//void Chassis::remoteCtrlUpdate2(void)       //ģʽ����������������Up
//{
//	chassisSpd[_X] = RC.Key.CH[0];
//	chassisSpd[_Y] = RC.Key.CH[1] ;
//	chassisSpd[_R] = RC.Key.CH[11] ;
//	for(u8 i = 0 ; i<4 ;i++)
//	{
//		motorSpd[i] = chassisSpd[_X] * 5 * drc[_X][i] ;
//		motorSpd[i] += chassisSpd[_Y] * 5 * drc[_Y][i] ;
//	  motorSpd[i] += (chassisSpd[_R]+ptz.s4) * 5 * drc[_R][i] ; //�������̸���
//	}
//}
///*���̸��棨�����ǣ�*/
//void Chassis::remoteCtrlUpdate4(void)   //ģʽ������������Down
//{
//	chassisSpd[_X] = RC.Key.A - RC.Key.D ;
//	chassisSpd[_Y] = RC.Key.W - RC.Key.S ;
//	chassisSpd[_R] = RC.Key.Q - RC.Key.E ;
//	for(u8 i = 0 ; i<4 ;i++)
//	{
//		motorSpd[i] = chassisSpd[_X] * amp[i] * drc[_X][i] ;
//		motorSpd[i] += chassisSpd[_Y] * amp[i] * drc[_Y][i] ;
//	  motorSpd[i] += (chassisSpd[_R]-ptz.s8/400) * amp[i] * drc[_R][i] ; 
//	}
//}

////void Chassis::remoteCtrlUpdate4(void)   //ģʽ������������Down
////{
////	chassisSpd[_X] = RC.Key.CH[0] ;
////	chassisSpd[_Y] = RC.Key.CH[1] ;
////	chassisSpd[_R] = RC.Key.CH[11] ;
////	for(u8 i = 0 ; i<4 ;i++)
////	{
////		motorSpd[i] = chassisSpd[_X] * amp[i] * drc[_X][i] ;
////		motorSpd[i] += chassisSpd[_Y] * amp[i] * drc[_Y][i] ;
////	  motorSpd[i] += (300) * amp[i] * drc[_R][i] ; 
////	}
////}

//void Chassis::angle_judge(void)   //3000--6500
//{
//	float res = 0;
//	res = ptz.Wheel1[0]->canInfo.encoder - 3000;
//	chassis.angle = res/3500.0*3.14;
//	chassis.multipliter = my_sin(chassis.angle);
//	chassis.swing_speed = 1000.0*chassis.multipliter;
//	
//	if(ptz.Wheel1[0]->canInfo.encoder >= 5800)
//	{
//		chassis.swing_drc = -1;
//	}
//	if(ptz.Wheel1[0]->canInfo.encoder <= 3700)
//	{
//		chassis.swing_drc = 1;
//	}
//}


//void Chassis::remoteCtrlUpdate6(void)   //ģʽ������������ҡ��
//{
//	chassis.angle_judge();
//	chassisSpd[_X] = RC.Key.A - RC.Key.D ;
//	chassisSpd[_Y] = RC.Key.W - RC.Key.S ;
//	chassisSpd[_R] = RC.Key.Q - RC.Key.E ;
//	for(u8 i = 0 ; i<4 ;i++)
//	{
//		motorSpd[i] = chassisSpd[_X] * amp[i] * drc[_X][i] ;
//		motorSpd[i] += chassisSpd[_Y] * amp[i] * drc[_Y][i] ;
//		motorSpd[i] += chassisSpd[_R] * amp[i] * drc[_R][i] + chassis.swing_speed *chassis.swing_drc ;
//	}
//}

///*---------------------------�ٶ�ע��--------------------------------*/
//void Chassis::motorCtrl(void)
//{
//	for(u8 i = 0 ; i<4 ; i++)
//	{
//		Wheel[i] -> ctrlSpeed(motorSpd[i]) ;
//	}
//}
//void Chassis::motorCtrl2(void)
//{
//	for(u8 i = 0 ; i<4 ; i++)
//	{
//		Wheel[i] -> ctrlSpeed(motorSpd[i]) ;
//	}
//}
//void Chassis::motorCtrl4(void)
//{
//	for(u8 i = 0 ; i<4 ; i++)
//	{
//		Wheel[i] -> ctrlSpeed(motorSpd[i]) ;
//	}
//}




/////*
////* ��⵽������̨��ʼ��λ
////* ��⵽���Сʱֹͣ
////*/
////void Pattern_Task(void)
////{
////   
////	ptz.h3 = ABS(ptz.h1-95);
////	
////	if(RC.SW1Tick == RCS::Mid_Up||ptz.judge == 2)
////	{
////		 if(ptz.h3<2)
////			 ptz.judge = 2;
////		 else
////		 ptz.Wheel1[0]->ctrlPosition(95);
////			 
////	 } 
////		
////	 
////}



///*-----------------------------������---------------------------------*/
//void PTZ_Task (void)
//{
//	ptz.remoteCtrlUpdate1() ;
//	ptz.motorCtrl1() ;
//}

//void PTZ_Task2(void)            //ģʽ����Up
//{
//	ptz.remoteCtrlUpdate3() ;
//	ptz.motorCtrl3() ;
//}

//void PTZ_Task3(void)            //ģʽ����Down
//{
//	ptz.remoteCtrlUpdate5() ;
//	ptz.motorCtrl5() ;
//}

//void PTZ_Task4(void)            //ģʽ����ҡ��
//{
//	ptz.remoteCtrlUpdate7() ;
//	ptz.motorCtrl5() ;
//}

///*----------------------------��ʼ��---------------------------------*/
//void PTZ::Ptz_Task_Init(void)
//{
//	pidparamin[0][0].kp = 280 ;
//	pidparamin[0][0].ki = 100 ;
//	pidparamin[0][0].kd = 0.01 ;
//	pidparamin[0][0].integralErrorMax = 1 ;
//	pidparamin[0][0].resultMax = 30000 ;
//	pidparamout[0][0].kp = 12 ;
//	pidparamout[0][0].ki = 10 ;
//	pidparamout[0][0].kd = 0 ;
//	pidparamout[0][0].integralErrorMax = 1 ;
//	pidparamout[0][0].resultMax = 320 ;
//	
//	pidparamin[0][1].kp = 200 ;
//	pidparamin[0][1].ki = 2 ;
//	pidparamin[0][1].kd = 0 ;
//	pidparamin[0][1].integralErrorMax = 5 ;
//	pidparamin[0][1].resultMax = 10000 ;
//	pidparamout[0][1].kp = 20 ;
//	pidparamout[0][1].ki = 2 ;
//	pidparamout[0][1].kd = 0 ;
//	pidparamout[0][1].integralErrorMax = 5 ;
//	pidparamout[0][1].resultMax = 300 ;
//	
//	
//	pidparamin[1][0].kp = 280 ;
//	pidparamin[1][0].ki = 100 ;
//	pidparamin[1][0].kd = 0.01 ;
//	pidparamin[1][0].integralErrorMax = 1 ;
//	pidparamin[1][0].resultMax = 30000 ;
//	pidparamout[1][0].kp = 12 ;
//	pidparamout[1][0].ki = 10 ;
//	pidparamout[1][0].kd = 0 ;
//	pidparamout[1][0].integralErrorMax = 1 ;
//	pidparamout[1][0].resultMax = 320 ;
//	
//	pidparamin[1][1].kp = 200 ;
//	pidparamin[1][1].ki = 2 ;
//	pidparamin[1][1].kd = 0 ;
//	pidparamin[1][1].integralErrorMax = 5 ;
//	pidparamin[1][1].resultMax = 10000 ;
//	pidparamout[1][1].kp = 20 ;
//	pidparamout[1][1].ki = 2 ;
//	pidparamout[1][1].kd = 0 ;
//	pidparamout[1][1].integralErrorMax = 5 ;
//	pidparamout[1][1].resultMax = 300 ;
//	
//	
//	
//	for(u8 i = 0 ; i<2 ;i++)
//	{
//		Wheel1[i] = new Motor(GM6020,CAN1,0x205+i) ;
//	}
//	Wheel1[0]->setZeroValue(4700) ;
//	Wheel1[1]->setZeroValue(700) ;
//		
//	Wheel1[0]->pidInner.setPlanNum(2);
//	Wheel1[0]->pidInner.fbValuePtr[0] = &Wheel1[0]->canInfo.speed;
////	Wheel1[0]->pidInner.fbValuePtr[0] = &boardImu->gyro.dps.data[2];
//	Wheel1[0]->pidInner.paramPtr = &pidparamin[0][0] ;
//	Wheel1[0]->pidOuter.setPlanNum(2);
//	Wheel1[0]->pidOuter.fbValuePtr[0] = &Wheel1[0]->canInfo.totalAngle_f; 
////	Wheel1[0]->pidOuter.fbValuePtr[0] = &boardImu->Angle.yaw; //Imuy
//	Wheel1[0]->pidOuter.paramPtr = &pidparamout[0][0] ; 
//	
//	Wheel1[1]->pidInner.setPlanNum(2);
//	Wheel1[1]->pidInner.fbValuePtr[0] = &Wheel1[1]->canInfo.speed;
////	Wheel1[1]->pidInner.fbValuePtr[0] = &boardImu->gyro.dps.data[2];
//	Wheel1[1]->pidInner.paramPtr = &pidparamin[1][0] ;
//	Wheel1[1]->pidOuter.setPlanNum(2);
//	Wheel1[1]->pidOuter.fbValuePtr[0] = &Wheel1[1]->canInfo.totalAngle_f;
//	Wheel1[1]->pidOuter.paramPtr = &pidparamout[1][0] ; 
//	
//	
//	
//	
//	

//  Wheel1[0]->pidInner.fbValuePtr[1] = &boardImu->gyro.dps.data[2];//yaw����ٶ�
//  Wheel1[0]->pidOuter.fbValuePtr[1] = &boardImu->Angle.yaw; //Imuy
//	
//	

//	Wheel1[1]->pidInner.fbValuePtr[1] = &Wheel1[1]->canInfo.speed;
//  Wheel1[1]->pidOuter.fbValuePtr[1] = &boardImu->Angle.roll; //Imuy

//	
//	
//	
//	
//	h1 = Wheel1[0]->canInfo.totalAngle_f;
//}



//PTZ::PTZ()
//{
//}


///*----------------------------�ٶ�ת��----------------------------------------*/
///*���̶���̨��ת+��̨���أ��ֶ���*/
//void PTZ::remoteCtrlUpdate1(void)
//{
//	s1 = RC.Key.F - RC.Key.G ;
//	s2 = RC.Key.R - RC.Key.V ;
//	s3 = RC.Key.Q - RC.Key.E ;
//	motorPos1[0] += (s1-s3)*300/66000*18 ;
//	motorPos1[1] += s2*300/3000 ;
//}
///*���̸�����̨+��̨���أ��ֶ���*/
///*void PTZ::remoteCtrlUpdate3(void)    //ģʽ����Up 
//{
//	s4 = RC.Key.F - RC.Key.G ;
//	s5 = RC.Key.R - RC.Key.V ;
//	s6 = RC.Key.Q - RC.Key.E ;
//	motorPos1[2] += s4*300/28000*18 ;
//	motorPos1[3] += s5*300/3000 ;
//}*/

///*void PTZ::remoteCtrlUpdate3(void)    //ģʽ����Up (������)
//{
//	s4 = RC.Key.CH[6];
//	s5 = RC.Key.CH[7];
//	
//	motorPos1[2] += s4/66000*18 ;
//	motorPos1[3] += s5/3000 ;
//}*/

//void PTZ::remoteCtrlUpdate3(void)    //ģʽ����Up 
//{
//	s4 = RC.Key.CH[2];
//	s5 = RC.Key.CH[3];
//	
//	motorPos1[2] += s4/66000*18 ;
//	motorPos1[3] += s5/5000 ;
//}

//void PTZ::remoteCtrlUpdate5(void)   //ģʽ����Down
//{
//	d1 = boardImu->Angle.yaw;  //ȷ����̨�������
//	motorPos1[4] = d1;
//	motorPos1[5] = 800;
//	s7 = Wheel1[0]->canInfo.totalAngle_f;
//	s8 = s7 - 0 ;
//	if(s8>=-5&&s8<=5)
//	{
//		s8 = 0;
//	}

//}

//void PTZ::remoteCtrlUpdate7(void)   //ģʽ����ҡ��
//{
//	motorPos1[4] = boardImu->Angle.yaw; 
//	motorPos1[5] = 700;
//}

///*---------------------------�ٶ�ע��----------------------------------------*/
//void PTZ::motorCtrl1(void)
//{
//	for(u8 i = 0 ; i<2 ; i++)
//	{
//		Wheel1[i]->ctrlPosition(motorPos1[i]) ;
//	}
//}

//void PTZ::motorCtrl3(void)   //ģʽ��������Up
//{
//	for(u8 i = 0 ; i<2 ; i++)
//	{
//		Wheel1[i]->ctrlPosition(motorPos1[i+2]) ;
//	}
//}

//void PTZ::motorCtrl5(void)   //ģʽ��������Down
//{
//	for(u8 i = 0 ; i<2 ; i++)
//	{
//		Wheel1[i]->ctrlPosition(motorPos1[i+4],1) ;
//	}
//}


