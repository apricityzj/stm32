#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "led.h"

/*****************辰哥单片机设计******************
											STM32
 * 项目			:	OLED显示屏(7针SPI)实验                     
 * 版本			: V1.0
 * 日期			: 2024.9.12
 * MCU			:	STM32F103C8T6
 * 接口			:	参看oled.h										
 * IP账号		:	辰哥单片机设计（同BILIBILI|抖音|快手|小红书|CSDN|公众号|视频号等）
 * 作者			:	辰哥 
 * 工作室		: 异方辰电子工作室
 * 讲解视频	:	https://www.bilibili.com/video/BV1dt4He7EqC/?share_source=copy_web
 * 官方网站	:	www.yfcdz.cn

**********************BEGIN***********************/

int main(void)
{
	SystemInit();//配置系统时钟为72M	
	delay_init(72);
	LED_Init();
	LED_On();
	
	delay_ms(500);  // 等待OLED上电稳定
	
	OLED_Init();
	delay_ms(100);
	
	//先清屏测试
	OLED_Clear();
	delay_ms(500);
	
	//测试显示一个点
	OLED_DrawPoint(64, 32);  //在屏幕中间画一个点
	OLED_Refresh();
	delay_ms(1000);
	
	OLED_Clear();
	
	//OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1) 
	//x,y:起点坐标 num:汉字对应的序号 
	OLED_ShowChinese(0,0,0,16); 	//你
	OLED_ShowChinese(32,0,1,16);	//好
	OLED_ShowChinese(64,0,2,16); 	//世
	OLED_ShowChinese(96,0,3,16);	//界
	
	//OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1);
	//x,y:起点坐标 size1:字体大小 *chr:字符串起始地址 
	//OLED_ShowString(0,16,"HELLO",16);
		
		
	//OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1);
	//x,y :起点坐标 num :要显示的数字 len :数字的位数 size:字体大小 
	//OLED_ShowNum(0,32,6666,4,24);
	
	//OLED_Clear();
	//OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[])
	//x,y：起点坐标 sizex,sizey,图片长宽 BMP[]：要写入的图片数组
	//OLED_ShowPicture(0,0,128,8,BMP5);
	//delay_ms(1000);
	while(1)
	{
		LED_Toggle();
		delay_ms(500);
	}
}

