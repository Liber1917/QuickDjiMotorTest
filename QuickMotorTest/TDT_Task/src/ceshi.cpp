#include "ceshi.h"
#include "dbus.h"
#include "pid.h"
#include "can.h"

Ceshi c1[4],c2,c3;
PidParam pidval1,pidval2 ;
u8 test[8]={1,144,1,144,1,144,1,144};
u8 _test[8]={254,112,254,112,254,112,254,112};
int changeDirCount=0;

void ceshi_task(void)
{
	changeDirCount++;
//	c1.judge();
	if(changeDirCount%1000<500)
	{
		Can_Tx(test,0x200,8);
		if(changeDirCount%1000<150)
		{Can_Tx(test,0x1FF,8);}
		else
		{
		for(u8 i=0;i<4;i++){
		c1[i].dianji ->ctrlSpeed(400);}			
		}
		Can_Tx(test,0x2FF,8);		

	}
	else
	{
		Can_Tx(_test,0x200,8);
		if(changeDirCount%1000<650)
		{Can_Tx(_test,0x1FF,8);}
		else
		{
		for(u8 i=0;i<4;i++){
		c1[i].dianji ->ctrlSpeed(-400);}			
		}		
		Can_Tx(_test,0x2FF,8);
	}
//			c1.dianji ->ctrlSpeed(-400); 
			c2.dianji ->ctrlSpeed(700);
//			if(ABS(c3.dianji->canInfo.totalEncoder+6270)>5)
//			c3.dianji ->ctrlPosition(-6270);
//	c3.dianji->ctrlSpeed(700);
//offset_run();
}

Ceshi::Ceshi()
{
	pidval1.kp = 10 ;
	pidval1.ki = 0 ;
	pidval1.kd = 0 ;
	pidval1.integralErrorMax = 200 ; 
	pidval1.resultMax = 16384 ;
	pidval2.kp = 10 ;
	pidval2.ki = 0 ;
	pidval2.kd = 0 ;
	pidval2.integralErrorMax = 200 ; 
	pidval2.resultMax = 2000 ; 
	                     
	
}
void ceshi_init(void)
{
	for(u8 i=0;i<4;i++)
	{
		c1[i].dianji = new Motor(GM6020,CAN1,0x205+i) ;
		c1[i].dianji->pidInner.setPlanNum(1) ;
		c1[i].dianji->pidInner.fbValuePtr[0] = &c1[i].dianji->canInfo.speed ;
		c1[i].dianji->pidInner.paramPtr = &pidval1 ;	
	}
		c2.dianji = new Motor(GM6020,CAN2,0x201) ;
		c2.dianji->pidInner.setPlanNum(1) ;
		c2.dianji->pidInner.fbValuePtr[0] = &c2.dianji->canInfo.speed ;
		c2.dianji->pidInner.paramPtr = &pidval1 ;	
		c3.dianji = new Motor(M2006,CAN2,0x203) ;
		c3.dianji->pidInner.setPlanNum(1) ;
		c3.dianji->pidInner.fbValuePtr[0] = &c3.dianji->canInfo.speed ;
		c3.dianji->pidInner.paramPtr = &pidval1 ;
		c3.dianji->pidOuter.setPlanNum(1) ;
		c3.dianji->pidOuter.fbValuePtr[0] = &c3.dianji->canInfo.totalEncoder ;
		c3.dianji->pidOuter.paramPtr = &pidval2 ;

}
uint16_t offsetTimes=0;
int offsetPos,Rota=141605;
u8 Offseting=1;
u8 LeftFlag =0;
int caloffset(void)
{
		if (offsetTimes < 20)//У׼����
	{
		c3.dianji->ctrlSpeed(1500);//�ٶȿ�����У׼�趨���ֵ
		if (c3.dianji->canInfo.lostFlag != 1 && 
			ABS(c3.dianji->canInfo.totalEncoder - c3.dianji->canInfo.lastTotalEncoder) < 5)//δ�����ҵ��δת��
		{
			offsetPos = c3.dianji->canInfo.totalEncoder;
			offsetTimes++;
		}
		else
		{
			offsetTimes = 0;//У׼��������
			return false;//У׼δ�ɹ�
		}
		
	}
	offsetTimes = 0;//У׼��������
	return true;//У׼�ɹ�
}
void offset_run(void)
{
	if (deforceFlag)//��������
	{
		c3.dianji->pidOuter.Clear();
		c3.dianji->pidInner.Clear();
		offsetTimes = 0;
		
		Offseting=1;
		offsetTimes=0;
		return;
	}
	else 
	{
//		if(RC.Key.CH[11]>500) LeftFlag=1;//̧����־λ��Ϊ1
//		else if(RC.Key.CH[11]<-500) LeftFlag=0;
	}
			
	if (Offseting)//���λ�ò�Ϊ0����
	{
		if (caloffset())//У׼ֵ��Ϊ0����
		{
			Offseting = 0;//��� λ����Ϊ0����
			LeftFlag = 0;
		}
		return;//ǿ�ƽ�����ǰ����ִ�еĺ�����\
		��������Ȩ���ظ����ô˺����ĺ���
	}
	
	if (LeftFlag)
	{
			c3.dianji->ctrlPosition(offsetPos - Rota);//λ�ÿ���

	
	}
	else
	{
		
		if(ABS(c3.dianji->canInfo.totalEncoder-offsetPos)>200)
			c3.dianji->ctrlPosition(offsetPos);//λ�ÿ��������λ�ô����ֶ�������ֹ����ﲻ����е��λ

		
	}
}

