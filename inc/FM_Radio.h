/********************************** FMRadio V1.1 ˵�� ************************************************************************
FMRadioģ�����ڿ��ơ�STC-Bѧϰ�塱��FM������������
FMRadioģ��ģ�鹲�ṩ1����ʼ��������2��Ӧ�ú���								
	
	(1)  void FMRadioInit(struct_FMRadio FMRadio); //������ģ���ʼ���������ú���ִֻ��һ�Ρ���ʼ�������¸�Ӧ�ú���������ȷʹ�á�
				����������FMRadio (���ṹstruct_FMRadio����)
				��������ֵ����
				
	(2)  void SetFMRadio(struct_FMRadio FMRadio);  //����FM���������Ʋ�����
	      ����������FMRadio (���ṹstruct_FMRadio����)
				��������ֵ����
				
 ��3�� struct_FMRadio GetFMRadio(void);          //��ȡ��ǰFM������������
        ������������
				��������ֵ������FM����ģ������(���ṹstruct_FMRadio����)

�ṹstruct_FMRadio���壺	
    	typedef struct          //FM����������ģ��
					{ unsigned int frequency;	  // FM����������Ƶ��   (frequency������Χ��887��1080����λ��0.1MHz����887����88.7MHz�����������������뵱ǰֵ�ޱ仯��������
						unsigned char volume;	    // FM����������       (volume������Χ��0��15��0Ϊ��С���������������������뵱ǰֵ�ޱ仯��������
						unsigned char GP1;        // FMָʾ��1��  =0 ����ͣ�GP1����  !=0 ����ߣ�GP1��
						unsigned char GP2;        // FMָʾ��2��  =0 ����ͣ�GP1����  !=0 ����ߣ�GP1��	  
						unsigned char GP3;        // FMָʾ��3��  =0 ����ͣ�GP1����  !=0 ����ߣ�GP1��		  		  		
					} struct_FMRadio;

���ע�����
       1�����汾��δ�����г���Զ���������̨�źŵȿ��ƺ�״̬��Ϣ����ˣ��ݲ�������Զ�������̨�����������ܡ�
			 2��FM����������USBת����ģ�飨CH340��ʱ�ӣ�Ӳ�����ԭ�򣩣���Ҫ����USB�ӿڣ����硢ͨ�ţ���USB���豸��CH340����ʱ�Ӳ����������
			    ��STC-Bѧϰ���USB�ӿ���Ҫ���ӵ�һ��USB���豸������������USB����ʱ����USB��籦������������ʱ��USB�ӿڣ���FM���������ܲ�����
			 
��д����ɣ��绰18008400450��   2021��8��10����ƣ�2021��8��16�ոĽ�
*/

#ifndef _FM_Radio_H_
#define _FM_Radio_H_

typedef struct           //FM����������ģ��
  { unsigned int frequency;		    // FM����������Ƶ��   (frequency������Χ��887��1080����λ��0.1MHz����887����88.7MHz�����������������뵱ǰֵ�ޱ仯��������
    unsigned char volume;	        // FM����������       (volume������Χ��0��15��0Ϊ��С���������������������뵱ǰֵ�ޱ仯��������
    unsigned char GP1;            // FMָʾ��1��  =0 ����ͣ�GP1����  !=0 ����ߣ�GP1��
    unsigned char GP2;            // FMָʾ��2��  =0 ����ͣ�GP1����  !=0 ����ߣ�GP1��	  
    unsigned char GP3;            // FMָʾ��3��  =0 ����ͣ�GP1����  !=0 ����ߣ�GP1��		  		  		
  } struct_FMRadio;
	
extern void FMRadioInit(struct_FMRadio FMRadio); //������ģ���ʼ������������FM����ģ�����ݣ��޷���ֵ����ʼ�������¸�Ӧ�ú���������ȷʹ��
extern void SetFMRadio(struct_FMRadio FMRadio);  //����FM���������Ʋ���������FM����ģ�����ݣ��޷���ֵ��
extern struct_FMRadio GetFMRadio(void);          //��ȡ��ǰFM���������������������������FM����ģ������

#endif