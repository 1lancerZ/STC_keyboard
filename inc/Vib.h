/**********************************�񶯴�����SV V2.0 ˵�� ************************************************************************
SV���ڻ�ȡ"STC-Bѧϰ��"��Vib������״̬.�ṩһ��ģ����غ�����һ��Ӧ�ú���,һ��Vib�¼�enumEventVib��
  (1)  VibInit()���񶯴�����Vibģ���ʼ��������
  (2)  char GetVibAct()����ȡVib�¼���
			  ��������ֵ�����ص�ǰVib�������¼�������ֵ��enumVibNull�����ޣ�enumVibQuake������������
        ��ѯһ�κ�,�¼�ֵ���	enumVibNull	(����ѯһ����Ч)									
  (3)  Vib�������¼�enumEventVib��
          ��Vib��⵽�С��񶯡��¼�ʱ��������һ�������¼�������Ӧ�¼����û����������û���д,
				����sys���ṩ��SetEventCallBack()��������.	 
				 
��д����ɣ��绰18008400450��   2021��3��5����ƣ�2021��3��26�ո���
*/

#ifndef _Vib_H_
#define _Vib_H_

extern void VibInit();
extern unsigned char GetVibAct(void) reentrant;        //��ȡVib�¼�							 	                    
enum VibActName {enumVibNull,enumVibQuake};            //����ֵ��enuVibNull�����ޣ�enuVibQuake������������

#endif