/**********************************DS1302 V1.1 ˵�� ************************************************************************
DS1302ģ�����ڿ��ơ�STC-Bѧϰ�塱��DS1302оƬ������
DS1302�ṩRTC��ʵʱʱ�ӣ���NVM������ʧ�洢�������ܣ��ϵ��RTC��NVM������Ŧ�۵��BATά�ֹ����ģ������У�
    RTC�ṩ���ꡢ�¡��ա����ڡ�ʱ���֡��빦��
		NVM�ṩ��31 Bytes����ʧ�洢������(��ַΪ��0��30�������У���ַΪ30�ĵ�Ԫ��DS1302Init()�������ڼ��DS1302�Ƿ���磬�û�����ʹ��)
DS1302ģ�鹲�ṩ1������������4��Ӧ�ú�����

  (1)  void DS1302Init(struct_DS1302_RTC time)��DS1302����������ʹ��DS1302�����øú�����ʼ��������һ��
	      �����������ṹstruct_DS1302_RTC time
				          ���DS1302���磨��ʼ��ʱ���RTC����ʧЧ�������Բ���time�����ʱ���ʼ��RTC
				��������ֵ����					
	
  (2)  struct_DS1302_RTC RTC_Read(void)����ȡDS1302�ڲ�ʵʱʱ��RTC����
        ������������
			  ��������ֵ���ṹstruct_DS1302�����ṹstruct_DS1302���壩
										
	(3)  void RTC_Write(struct_DS1302_RTC time) ��дDS1302�ڲ�ʵʱʱ��RTC����
	      �����������ṹstruct_DS1302 time�����ṹstruct_DS1302���壩
			  ��������ֵ����	
										
	(4)  unsigned char NVM_Read(unsigned char NVM_addr):	��ȡNVMһ��ָ����ַ����
	      ����������  
				      NVM_addr��ָ������ʧ�洢��Ԫ��ַ����Чֵ0��30����31����Ԫ��
	      ��������ֵ����������������ʱ������NVM�ж�Ӧ��Ԫ�Ĵ洢��ֵ��1Byte��
				            ��������������ʱ������enumDS1302_error
				
	(5)  unsigned char NVM_Write(unsigned char NVM_addr, unsigned char NVM_data)����NVMһ��ָ����ַд����ֵ
	      ����������  
				      NVM_addr��ָ������ʧ�洢��Ԫ��ַ����Чֵ��0��30����31����Ԫ�����У���30��Ԫ��DS1302Init()�������ڼ��DS1302�Ƿ���磬�û�����ʹ��)��
	            NVM_data����д��NVM��Ԫ����ֵ��1Byte��
			  ��������ֵ����������������ʱ������enumDS1302_OK		
				            ��������������ʱ������enumDS1302_error	

�ṹstruct_DS1302_RTC���壺���μ�DS1302Z�����ֲᣩ
typedef struct 
  { unsigned char second;		    //�루BCD�룬���¾�ΪBCD�룩
    unsigned char minute;	      //��
    unsigned char hour;         //ʱ
    unsigned char day;		      //��
    unsigned char month;		    //��
    unsigned char week;		      //����
    unsigned char year;		  		//��
  } struct_DS1302_RTC;    

����DS1302�ڲ�����ʧ�Դ洢������˵����
      DS1302�ṩ�ķ���ʧ�Դ洢��Ϊ�͹���RAM�ṹ����Ŧ�۵�ر��ֵ������洢���ݲ��䡣
			��M24C01��������С����31�ֽڣ������ޡ�д���������⣬��д���ں̣ܶ��ɺ��ԣ�������д����֮������ȴ�����
			����дDS1302�ڲ�NVMÿһ���ֽھ���Ҫ����һ������ʱ�䣨��ʮuS����
			������Ҫʱʹ�����϶���д������д��Ҫ���ض��ֽ����ݣ�Ӧ������������Ч���������ظ�������
			
��д����ɣ��绰18008400450��   2021��8��5����ƣ�2021��8��15�ոĽ�
*/

#ifndef _DS1302_H_
#define _DS1302_H_

typedef struct 
  { unsigned char second;		    //�루BCD�룬���¾�ΪBCD�룩
    unsigned char minute;	      //��
    unsigned char hour;         //ʱ
    unsigned char day;		      //��
    unsigned char month;		    //��
    unsigned char week;		      //����
    unsigned char year;		  		//��
  } struct_DS1302_RTC;    

extern void DS1302Init(struct_DS1302_RTC time);                 //DS1302��ʼ��
extern struct_DS1302_RTC RTC_Read(void);                                         //��RTC����RTCʱ�����ݣ�
extern void RTC_Write(struct_DS1302_RTC time);                                   //дRTC��У��RTCʱ�ӣ�
extern unsigned char NVM_Read(unsigned char NVM_addr);                           //��NVM����DS1302�еķ���ʧ�洢��Ԫ���ݣ�
extern unsigned char NVM_Write(unsigned char NVM_addr, unsigned char NVM_data);  //дNVM��дDS1302�еķ���ʧ�洢��Ԫ��

enum DS1302name {enumDS1302_OK,enumDS1302_error};

#endif