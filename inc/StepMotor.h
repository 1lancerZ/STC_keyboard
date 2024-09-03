/**********************************StepMotor ˵�� ************************************************************************
StepMotor����STC-B����Ʋ�����������ṩ1������������3��Ӧ�ú�����
  (1)  StepMotorInit()���������ģ����������
  (2)  SetStepMotor(char StepMotor,unsigned char speed ,int steps )  ָ�������������ָ��ת���ٶȡ�ת��ָ����
           ����������StepMotor  ָ�����������ȡֵ��enum StepMotorName�ж��壩
				                   enumStepMotor1��  SM �ӿ��ϵĲ������
				                   enumStepMotor2��  ��ʱ����L0��L3�ĸ�LEDģ��һ��4�ಽ�����
				                   enumStepMotor3��  ��ʱ����L4��L7�ĸ�LEDģ��һ��4�ಽ�����
				             speed      �������ת���ٶȣ�0��255������λ����/S�� (ʵ��ÿ��ʱ��=int(1000mS/speed) mS�����������ٶȿ��ܴ���һ�����
				             steps      �������ת��������-32768��32767������ֵ��ʾ��ת
				   �������أ�enumSetStepMotorOK��  ���óɹ���enum StepMotorActName�ж��壩
				             enumSetStepMotorFail������ʧ�ܣ����������ָ����Χ����speed=0,�����ʱ����ת����
  ��3��EmStop(char StepMotor) ����ָֹͣ���������ת��
	           ����������StepMotor  ָ����������������������Խ�����0ֵ��
						 �������أ�ʣ��δת��Ĳ���
  ��4��GetStepMotorStatus(char StepMotor) ��ȡָ���������״̬
	           ����������StepMotor  ָ���������
					   �������أ�enumStepMotorFree:���ɣ�enum StepMotorActName�ж��壩
									     enumStepMotorBusy,æ������ת����
											 enumSetStepMotorFail������ʧ�ܣ��������������ָ����Χ��

��д����ɣ��绰18008400450��   2021��4��16����ƣ�2021��4��18�ո���
*/

#ifndef _StepMotor_H_			
#define _StepMotor_H_		

extern void StepMotorInit();										                              //  �������ģ���ʼ��
extern char SetStepMotor(char StepMotor,unsigned char speed ,int steps );     //  ָ�������������ָ��ת���ٶȡ�ת��ָ����
																																									//  ����������StepMotor  ָ�����������ȡֵ��enum StepMotorName�ж��壩
																																									//              enumStepMotor1��  SM �ӿ��ϵĲ������
																																									//              enumStepMotor2��  ��ʱ����L0��L3�ĸ�LEDģ��һ��4�ಽ�����
																																									//              enumStepMotor3��  ��ʱ����L4��L7�ĸ�LEDģ��һ��4�ಽ�����
																																									//            speed      �������ת���ٶȣ�0��255������λ����/S   (ʵ��ÿ��ʱ��=int(1000mS/speed) mS�����������ٶȿ��ܴ���һ�����
																																									//            steps      �������ת��������-32768��32767������ֵ��ʾ��ת
																																									//  �������أ�
																																									//              enumSetStepMotorOK�����óɹ�   
																																									//              enumSetStepMotorFail������ʧ�ܣ����������ָ����Χ����speed=0,�����ʱ����ת����
extern int EmStop(char StepMotor);                                            //  ����ָֹͣ���������ת��
	                                                                                //  ����������StepMotor  ָ���������(�����������Խ�����0ֵ)
																																									//  �������أ�ʣ��δת��Ĳ���
extern unsigned char GetStepMotorStatus(char StepMotor);                      //  ��ȡָ���������״̬
	                                                                                //  ����������StepMotor  ָ���������
																																									//  �������أ�enumStepMotorFree:����
																																									//            enumStepMotorBusy,æ������ת����
																																									//            enumSetStepMotorFail������ʧ�ܣ��������������ָ����Χ��
enum StepMotorName    {enumStepMotor1=0,enumStepMotor2,enumStepMotor3}; 
enum StepMotorActName {enumStepMotorFree,enumStepMotorBusy,enumSetStepMotorOK,enumSetStepMotorFail}; 

#endif