#ifndef XY_VXWORKS_H
#define XY_VXWORKS_H

namespace xykj_vxworks_space
{
	typedef unsigned char	Byte ;
	typedef unsigned short	WORD ;
	typedef unsigned int	DWORD ;

	//board
	class Board
	{
	public:
		virtual void Init();
		virtual int SetIndex(int index);
		virtual int GetIndex(){return _index;};
		virtual int SetSpaceIndex(int spaceIndex);
		virtual int GetSpaceIndex(){return _spaceIndex;};
		virtual int ReadByte(int offset , Byte *data);
		virtual int WriteByte(int offset , Byte data);
		virtual int ReadWord(int offset , WORD *data);
		virtual int WriteWord(int offset , WORD data);
		virtual int ReadDword(int offset , DWORD *data);
		virtual int WriteDword(int offset , DWORD data);
		virtual int ReadBlock(int offset , char *data , int len);
		virtual int WriteBlock(int offset , char *data , int len);
	private:
		int _index;
		int _spaceIndex;
	} ;

	//board set 
	class Mode_Set
	{
	public:
		unsigned char	m_index;      /*�忨index*/     
		unsigned char	m_task_index; /*���������*/
		unsigned char	m_Read_Write; /*��д��־*/
		unsigned char	m_Run_type; /*ģ����������,��ҪΪ��ģ������Ϊ��Ӧ����ʱ�������У�-1��ʾʼ������*/
		unsigned int	m_startAddr; /*�忨FPGA��ʼ��ַ*/
		unsigned int	m_DMAStartAddr; /*�忨DMA��ʼ��ַ*/
		unsigned int	m_length; /*ģ�鳤��*/
		unsigned int	m_Enable_Addr; /*����ʹ�ܿ��ƣ�ֻ���ڴ�������*/
		unsigned int	m_Enable_Bit; /*����ʹ��ʱ������ֵ��ֻ���ڴ�������,��Ϊ0ʱ��ʾ����Ҫ����*/
		unsigned int	m_Enable_com ;/*����ʹ��*/	
		unsigned char	m_Borad_Init_Index;      /*�洢��VxWorks�忨����������ʼ��ַ*/

		unsigned char	m_Count;      /*ģ�����*/
		unsigned char	m_Cyclic_set; /*��������*/
		unsigned char	m_Borad_Set_Flag; /*ģ�����ÿ���*/
		unsigned char	m_Run_flag; /*ģ�����п���*/
		unsigned int	m_Mode_Addr_Spa; /*ģ������ַ*/
		unsigned char	m_mode_type; /*���Ƶ�ģ������*/
		unsigned char	m_Control_Count;/*���Ƶ�Board_init����*/
	};
}

#endif