/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "arm_math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/*
int16_t Sine_table[300]=
{0,235,469,703,937,1171,1404,1636,1868,2099,2329,2558,2785,3012,
	3237,3461,3683,3904,4123,4340,4555,4769,4980,5189,5396,5600,
	5802,6001,6198,6392,6583,6772,6957,7139,7318,7494,7667,7836,
	8002,8164,8323,8478,8630,8777,8921,9061,9197,9329,9456,9580,
	9699,9815,9925,10032,10134,10232,10325,10413,10498,10577,10652
	,10722,10787,10848,10904,10955,11002,11043,11080,11112,11139,
	11161,11178,11190,11198,11200,11198,11190,11178,11161,11139,
	11112,11080,11043,11002,10955,10904,10848,10787,10722,10652,
	10577,10498,10413,10325,10232,10134,10032,9925,9815,9699,9580,
	9456,9329,9197,9061,8921,8777,8630,8478,8323,8164,8002,7836,
	7667,7494,7318,7139,6957,6772,6583,6392,6198,6001,5802,5600,
	5396,5189,4980,4769,4555,4340,4123,3904,3683,3461,3237,3012,
	2785,2558,2329,2099,1868,1636,1404,1171,937,703,469,235,0,
	-235,-469,-703,-937,-1171,-1404,-1636,-1868,-2099,-2329,-2558,
	-2785,-3012,-3237,-3461,-3683,-3904,-4123,-4340,-4555,-4769,
	-4980,-5189,-5396,-5600,-5802,-6001,-6198,-6392,-6583,-6772,
	-6957,-7139,-7318,-7494,-7667,-7836,-8002,-8164,-8323,-8478,
	-8630,-8777,-8921,-9061,-9197,-9329,-9456,-9580,-9699,-9815,
	-9925,-10032,-10134,-10232,-10325,-10413,-10498,-10577,-10652,
	-10722,-10787,-10848,-10904,-10955,-11002,-11043,-11080,-11112,
	-11139,-11161,-11178,-11190,-11198,-11200,-11198,-11190,-11178,
	-11161,-11139,-11112,-11080,-11043,-11002,-10955,-10904,-10848,
	-10787,-10722,-10652,-10577,-10498,-10413,-10325,-10232,-10134,
	-10032,-9925,-9815,-9699,-9580,-9456,-9329,-9197,-9061,-8921,
	-8777,-8630,-8478,-8323,-8164,-8002,-7836,-7667,-7494,-7318,
	-7139,-6957,-6772,-6583,-6392,-6198,-6001,-5802,-5600,-5396,
	-5189,-4980,-4769,-4555,-4340,-4123,-3904,-3683,-3461,-3237,
	-3012,-2785,-2558,-2329,-2099,-1868,-1636,-1404,-1171,-937,-703,
	-469,-235};
	*/
	uint16_t sine_point_num = 360;
	float sine_360[360]={
	0,0.017452,0.034899,0.052336,0.069756,0.087156,0.104528,0.121869,0.139173,0.156434,
	0.173648,0.190809,0.207912,0.224951,0.241922,0.258819,0.275637,0.292372,0.309017,
	0.325568,0.34202,0.358368,0.374607,0.390731,0.406737,0.422618,0.438371,0.45399,
	0.469472,0.48481,0.5,0.515038,0.529919,0.544639,0.559193,0.573576,0.587785,
	0.601815,0.615661,0.62932,0.642788,0.656059,0.669131,0.681998,0.694658,0.707107,
	0.71934,0.731354,0.743145,0.75471,0.766044,0.777146,0.788011,0.798636,0.809017,
	0.819152,0.829038,0.838671,0.848048,0.857167,0.866025,0.87462,0.882948,0.891007,
	0.898794,0.906308,0.913545,0.920505,0.927184,0.93358,0.939693,0.945519,0.951057,
	0.956305,0.961262,0.965926,0.970296,0.97437,0.978148,0.981627,0.984808,0.987688,
	0.990268,0.992546,0.994522,0.996195,0.997564,0.99863,0.999391,0.999848,1,0.999848,
	0.999391,0.99863,0.997564,0.996195,0.994522,0.992546,0.990268,0.987688,0.984808,
	0.981627,0.978148,0.97437,0.970296,0.965926,0.961262,0.956305,0.951057,0.945519,
	0.939693,0.93358,0.927184,0.920505,0.913545,0.906308,0.898794,0.891007,0.882948,
	0.87462,0.866025,0.857167,0.848048,0.838671,0.829038,0.819152,0.809017,0.798636,
	0.788011,0.777146,0.766044,0.75471,0.743145,0.731354,0.71934,0.707107,0.694658,
	0.681998,0.669131,0.656059,0.642788,0.62932,0.615662,0.601815,0.587785,0.573576,
	0.559193,0.544639,0.529919,0.515038,0.5,0.48481,0.469472,0.453991,0.438371,0.422618,
	0.406737,0.390731,0.374607,0.358368,0.34202,0.325568,0.309017,0.292372,0.275637,
	0.258819,0.241922,0.224951,0.207912,0.190809,0.173648,0.156435,0.139173,0.121869,
	0.104529,0.087156,0.069757,0.052336,0.0349,0.017452,0,-0.017452,-0.034899,-0.052336,
	-0.069756,-0.087156,-0.104528,-0.121869,-0.139173,-0.156434,-0.173648,-0.190809,
	-0.207912,-0.224951,-0.241922,-0.258819,-0.275637,-0.292372,-0.309017,-0.325568,
	-0.34202,-0.358368,-0.374607,-0.390731,-0.406737,-0.422618,-0.438371,-0.45399,
	-0.469472,-0.48481,-0.5,-0.515038,-0.529919,-0.544639,-0.559193,-0.573576,
	-0.587785,-0.601815,-0.615661,-0.62932,-0.642788,-0.656059,-0.669131,-0.681998,
	-0.694658,-0.707107,-0.71934,-0.731354,-0.743145,-0.75471,-0.766044,-0.777146,
	-0.788011,-0.798635,-0.809017,-0.819152,-0.829038,-0.838671,-0.848048,-0.857167,
	-0.866025,-0.87462,-0.882948,-0.891006,-0.898794,-0.906308,-0.913545,-0.920505,
	-0.927184,-0.93358,-0.939693,-0.945519,-0.951056,-0.956305,-0.961262,-0.965926,
	-0.970296,-0.97437,-0.978148,-0.981627,-0.984808,-0.987688,-0.990268,-0.992546,
	-0.994522,-0.996195,-0.997564,-0.99863,-0.999391,-0.999848,-1,-0.999848,-0.999391,
	-0.99863,-0.997564,-0.996195,-0.994522,-0.992546,-0.990268,-0.987688,-0.984808,
	-0.981627,-0.978148,-0.97437,-0.970296,-0.965926,-0.961262,-0.956305,-0.951057,
	-0.945519,-0.939693,-0.93358,-0.927184,-0.920505,-0.913545,-0.906308,-0.898794,
	-0.891007,-0.882948,-0.87462,-0.866025,-0.857167,-0.848048,-0.838671,-0.829038,
	-0.819152,-0.809017,-0.798636,-0.788011,-0.777146,-0.766045,-0.75471,-0.743145,
	-0.731354,-0.71934,-0.707107,-0.694658,-0.681998,-0.669131,-0.656059,-0.642788,
	-0.62932,-0.615662,-0.601815,-0.587785,-0.573577,-0.559193,-0.544639,-0.529919,
	-0.515038,-0.5,-0.48481,-0.469472,-0.453991,-0.438371,-0.422618,-0.406737,-0.390731,
	-0.374607,-0.358368,-0.34202,-0.325568,-0.309017,-0.292372,-0.275637,-0.258819,
	-0.241922,-0.224951,-0.207912,-0.190809,-0.173648,-0.156435,-0.139173,-0.121869,
	-0.104529,-0.087156,-0.069757,-0.052336,-0.0349,-0.017453};

	uint16_t ADC1_RAW[2];//ADC采样原始数据
	float Voltage_IN_inst;//输入电压瞬时数据
	
	//SOGI变量包
	struct SOGI_variable
	{
		float alpha;
		float beta1;
		float beta2_Inv;
		float beta2;
	};
	struct SOGI_variable SOGIA;//定义A相变量
	
	//二阶广义积分计算 输入ADC采样值 输入单相正弦 输出alpha beta正弦
	void SOGI_cal(int16_t U_sine_in,struct SOGI_variable *SOGI,float sine_cycle_point_num,uint8_t Freq_div)
	//U_sine_in 读取的ADC采样值
	//SOGI_variable 选择的SOGI运算变量
	//sine_cycle_point_num 正弦波一周期的取点数
	//Freq_div 此函数(单相)相对于查表运行的分频数，如：查表3次，计算一次SOGI
	{
		SOGI->beta2_Inv = (U_sine_in - SOGI->alpha)*1.414 - SOGI->beta1;
		SOGI->alpha += SOGI->beta2_Inv * 6.283 * Freq_div / sine_cycle_point_num;
		SOGI->beta1 += SOGI->alpha * 6.283 * Freq_div / sine_cycle_point_num;
		SOGI->beta2 = -(SOGI->beta2_Inv);
	}
	
	
	/********************    坐标变换相关      **********************/
	//alpha-beta -> dq 坐标变换变量包
	struct dq_variable
	{
		float d;
		float q;
	};
	
	//dq归一化计算
	void dq_normalized(struct dq_variable dq_input , struct dq_variable *dq_normalized_output)
	{
		float modulus;
		float modulus_square;
		modulus_square = (dq_input.d)*(dq_input.d) + (dq_input.q)*(dq_input.q);
		arm_sqrt_f32(modulus_square,&modulus);
		dq_normalized_output ->d = (dq_input.d)/(modulus + 0.001);
		dq_normalized_output ->q = (dq_input.q)/(modulus + 0.001);
	}
	
	struct dq_variable phaseA_dq;
	struct dq_variable normalizedA_dq;
	
	float mode_SUM_dq;
	float mode_squrae_SUM_dq;

	//alpha-beta -> dq坐标变换计算
	void alphabeta_to_dq_cal(struct SOGI_variable SOGI,struct dq_variable *dq,float wt)
	//SOGI_variable 选择的SOGI运算变量 取其输出值
	//dq_variable	赋值的变量
	//设置的计算角度
	{
		//对齐
//		dq ->d = (arm_cos_f32(wt) * SOGI.alpha) + (arm_sin_f32(wt) * SOGI.beta2);
//		dq ->q = (arm_cos_f32(wt) * SOGI.beta2) - (arm_sin_f32(wt) * SOGI.alpha);
		//|Ud| | cos(wt)  sin(wt) 0||alpha|
		//|Uq|=|-sin(wt)  cos(wt) 0||beta |
		//|U0| |    0       0     1||  0  |
		
		
		//延迟pi/2
		dq ->d = (arm_sin_f32(wt) * SOGI.alpha) - (arm_cos_f32(wt) * SOGI.beta2);
		dq ->q = (arm_cos_f32(wt) * SOGI.alpha) + (arm_sin_f32(wt) * SOGI.beta2);
		//|Ud| |sin(wt) -cos(wt) 0||alpha|
		//|Uq|=|cos(wt)  sin(wt) 0||beta |
		//|U0| |   0       0     1||  0  |
	}
	
	
	/********************    PID相关      **********************/
	//PID变量包 增量式PID
	struct PID_variable
	{
		float ERR_t;//本次误差
		float ERR_t_1;//前1次误差
		float ERR_t_2;//前2误差
		float Inc_val;//Δu(t)
		
		float	Kp;
		float Ki;
		float Kd;
		
		float PID_out;//输出
		float upper_lim;//输出上限
		float lower_lim;//输出下限
	};
	//旋转坐标锁相PID，控制q轴分量为0 输出叠加前馈后为TIM1->ARR的值
	struct PID_variable PID_Eq_PLL = 
	{
		.Kp = 200,
		.Ki = 0.01,
		.Kd = 0,
		.upper_lim = 200,
		.lower_lim = -200
	};
	
	//PID计算函数
	//输入 计算需要的PID变量对应的结构体 给定值 反馈值
	void PID_Inc_cal(struct PID_variable *PID,float REF,float Feedback_REL)
	{
		PID -> ERR_t = REF - Feedback_REL;//本次误差
		
		PID->Inc_val = 
		(PID->Kp * (PID->ERR_t - PID->ERR_t_1)) + //比例
		(PID->Ki *  PID->ERR_t) + //积分
		(PID->Kd * (PID->ERR_t - 2*PID->ERR_t_1 + PID->ERR_t_2));//微分
		//U(k)-U(k-1) = Kp * (e(k) -e(k-1))+ Ki * e(k) + Kd * [e(k) - 2e(k-1)+e(k-2)]
		
		PID->ERR_t_2 = PID->ERR_t_1;
		PID->ERR_t_1 = PID->ERR_t;
		
		PID->PID_out += PID->Inc_val;
		
		//输出限幅
		if(PID->PID_out > PID->upper_lim)
		{
			PID->PID_out = PID->upper_lim;
		}
		else if(PID->PID_out < PID->lower_lim)
		{
			PID->PID_out = PID->lower_lim;
		}
	}
	
	uint16_t Lookup_pA = 0;
	int16_t sine_A_out;
	uint16_t DAC1_OUT;
	float wt;//计算相位角(rad)
	int16_t PLL_degree=0;//锁相偏移量
	
	
//定时器参数
uint16_t TIM_Ctrl_ARR = 8000-1;//TIM1中断计数值
//uint16_t TIM_PWM_ARR = 5600;// 
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//ADC转换完成中断
//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
//{
//	//ADC数据处理
//	Voltage_IN_inst = (ADC1_RAW[0] - ADC1_RAW[1]) * (3.3/4096.0) * (400.0/2.0);
//}

uint8_t SOGI_cnt = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef*htim)
{
	SOGI_cnt++;
	//LED电平翻转
	HAL_GPIO_TogglePin(GPIOC , GPIO_PIN_6);
	
	
	
	if(SOGI_cnt >= 3)
	{
		//ADC数据处理
		Voltage_IN_inst = (ADC1_RAW[0] - ADC1_RAW[1]) * (3.3/4096.0) * (400.0/1.0);
		//SOGI计算
		SOGI_cal(Voltage_IN_inst,&SOGIA,sine_point_num,3);
		//坐标变换
		wt=(Lookup_pA * 6.2832/sine_point_num )+ (PLL_degree * 3.1415/180.0) ;//计算坐标变换角度(rad)
		alphabeta_to_dq_cal(SOGIA,&phaseA_dq,wt);
		dq_normalized(phaseA_dq,&normalizedA_dq);
		
		
		PID_Inc_cal(&PID_Eq_PLL,0,(normalizedA_dq.q));
		TIM_Ctrl_ARR = 8000 + PID_Eq_PLL.PID_out;
	
		TIM1->ARR = TIM_Ctrl_ARR;//TIM计数周期写入
		
		SOGI_cnt = 0;
	}
	

	

	
	//DAC输出
	DAC1_OUT = (uint16_t)(sine_360[Lookup_pA]*1024.0 + 2048);
//	DAC1_OUT = (uint16_t)(SOGIA.alpha/311.0 * 1024.0 + 2048);
	HAL_DAC_SetValue(&hdac1,DAC_CHANNEL_1,DAC_ALIGN_12B_R,DAC1_OUT);//DAC输出函数
	
	//查表指针
	Lookup_pA++;
	if(Lookup_pA >= 360)
	{Lookup_pA = 0;}
	
	//

}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_DAC1_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	HAL_ADC_Start_DMA(&hadc1,(uint32_t *)ADC1_RAW,2);
	HAL_TIM_Base_Start_IT(&htim1);
	
	HAL_DAC_Start(&hdac1,DAC1_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 36;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
