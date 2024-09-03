/********************************** EXT V1.0 ˵�� ***********************************************

EXTģ�����ڿ��ơ�STC-Bѧϰ�塱����չ�ӿ�EXT����ز�����
EXTģ�����Ӧ����Ҫ���������Ӧģ��򲿼��󣬿�ʵ�ֶ�����Ӧ���ܡ������ṩ����Ӧ��������API������
EXTģ�������ṩ1���������������ɸ�Ӧ�ò�API������
EXTģ���API��������ͬʱ��Ч�ģ����Ǹ��ݳ�ʼ������������ͬ���ֱ���Ч��

  (1) void EXTInit(char EXTfunction)��EXT��ʼ��������
	      ����������EXTfunction������EXT�ӿڹ���
				          EXTfunction ȡֵ��enumEXTWeight�����أ���HX710��HX711��ɵĵ��ӳӣ�
									                  enumEXTPWM   ��������ƣ������ڿ���ֱ���������ת���ٶȣ������ȵȣ�
																	  enumEXTDecode������ʽ������
																		enumEXTUltraSonic ����������ࣩ  
				��������ֵ����		
     ע�⣺��EXT��չ�ӿ����ڴ���2ʱ��TTL Uart�������ڴ���ͨ�š�����ģ�����ӵȣ�����ʹ��Uart2Init()������ʼ��EXT�󣬲�Ҫ��ʹ��EXTInit()���������������ܳ�ͻ

	(2)API����
		(a) ���ӳӡ���EXTInit(char EXTfunction)ʹ��enumEXTWeight����ʱ��GetWeight������Ч��
         int GetWeight(void)		//��ȡ���ӳ�ADC�������ݣ�16bit��������������δ���㡢δ�궨���μ�HX710��HX711�����ֲᣨ��16bit����
		
		(b) PWM��������������EXTInit(char EXTfunction)ʹ��enumEXTPWM����ʱ��SetPWM������Ч��
				 void SetPWM(unsigned char PWM1, unsigned char freq1, unsigned char PWM2, unsigned char freq2);  
                     //����EXT�����PWM������PWMΪռ�ձȣ�����ߵ�ƽʱ��ı�������0��100,��λ%����freqxΪƵ�ʣ�1��255Hz��
										 //ʵ��Ƶ�� = 1000/int(1000/freqx)������1000/i=4��5��6...1000����250��200��167��143��125��111��100��91��83...1 
                     //�����ڿ���ֱ���������ת��ת�٣����H����ʽ��·���������ȣ���
										 
		(c) ��ת��������������ʽ����������EXTInit(char EXTfunction)ʹ��enumEXTDecode����ʱ��GetDecode������Ч��
		     int GetDecode(void);         //��ȡ��������������ֵ������ϴζ�ȡ�����������
		
		(d) ��������ࡣ��EXTInit(char EXTfunction)ʹ��enumEXTUltraSonic����ʱ��GetUltraSonic������Ч��
		     int GetUltraSonic(void);     //��ȡ���������ֵ��ÿ��5�β���������ֵ��λ��cm��
				 
		(e) RFID�������ݻ���
		(g) �����������ڣ�������2
		(h) �����������ݲɼ������ӳߡ����£���ADC
���ע�����
      
			
��д����ɣ��绰18008400450��   2021��8��24�����
*/

#ifndef _EXT_H_
#define _EXT_H_

extern void EXTInit(char EXTfunction);    //��չ�ӿڳ�ʼ��
enum EXTname {enumEXTWeight       //���ӳ�
             ,enumEXTPWM,         //PWM������ֱ�����ת�����򡢿���
             ,enumEXTDecode       //����ʽ��������ת��������
	           ,enumEXTUltraSonic   //���������
                                  //����2����������uart2ģ��
                                  //���������ݲɼ������ӳߡ�����ǹ�ȣ���ADC  
             };   
extern int GetWeight(void);         //��ȡ���ӳ�ADC�������ݣ�HX710��HX711�����16bit����������������δ���㡢δ�궨��
extern int GetDecode(void);         //��ȡ��������������ֵ������ϴζ�ȡ�����������
extern int GetUltraSonic(void);     //��ȡ���������ֵ��ÿ��5�β���������ֵ��λ��cm��
extern void SetPWM(unsigned char PWM1, unsigned char freq1, unsigned char PWM2, unsigned char freq2);  
                     //����EXT�����PWM������PWMΪռ�ձȣ�����ߵ�ƽʱ��ı�������0��100,��λ%����freqxΪƵ�ʣ�1��255Hz��
										 //ʵ��Ƶ�� = 1000/int(1000/freqx)������1000/i=4��5��6...1000����250��200��167��143��125��111��100��91��83...1 
                     //�����ڿ���ֱ���������ת��ת�٣����H����ʽ��·���������ȣ���

 


#endif