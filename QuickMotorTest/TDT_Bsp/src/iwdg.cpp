/******************************
File name: TDT_Bsp\src\iwdg.cpp
Description: 看门狗控制
function:
	——————————————————————————————————————————————————————————————————————————
	void TDT_IWDG_Init(u8 prer,u16 rlr)
	——————————————————————————————————————————————————————————————————————————
	void TDT_IWDG_Feed(void)
	——————————————————————————————————————————————————————————————————————————
Author: 祖传
Version: 1.1.1.191112_alpha
Date: 19.11.12
History: 
	——————————————————————————————————————————————————————————————————————————
	19.11.12 首次完成
	——————————————————————————————————————————————————————————————————————————
****************************  */
#include "iwdg.h"

/**
 * @ingroup TDT_BSP
 * @defgroup TDT_BSP_IWDG 独立看门狗
 * @brief 提供了独立看门狗的初始化和喂狗函数
 */

///@details 初始化独立看门狗
///@param[in] prer :分频数:0~7(只有低3位有效!)。分频因子=4*2^prer.但最大值只能是256!
///@param[in] rlr :自动重装载值,0~0XFFF。重装载寄存器值:低11位有效.
///@note 时间计算(大概):Tout=((4*2^prer)*rlr)/32 (ms).
void iwdgInit(u8 prer,u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //使能对IWDG->PR IWDG->RLR的写
	
	IWDG_SetPrescaler(prer); //设置IWDG分频系数

	IWDG_SetReload(rlr);   //设置IWDG装载值

	IWDG_ReloadCounter(); //reload
	
	IWDG_Enable();       //使能看门狗
}



///@details 喂独立看门狗
void iwdgFeed(void)
{
	IWDG_ReloadCounter();//reload
}
