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
		unsigned char	m_index;      /*板卡index*/     
		unsigned char	m_task_index; /*所属任务号*/
		unsigned char	m_Read_Write; /*读写标志*/
		unsigned char	m_Run_type; /*模块运行类型,主要为在模块设置为相应类型时进行运行，-1表示始终运行*/
		unsigned int	m_startAddr; /*板卡FPGA起始地址*/
		unsigned int	m_DMAStartAddr; /*板卡DMA起始地址*/
		unsigned int	m_length; /*模块长度*/
		unsigned int	m_Enable_Addr; /*串口使能控制，只用于串口类型*/
		unsigned int	m_Enable_Bit; /*串口使能时的设置值，只用于串口类型,若为0时表示不需要控制*/
		unsigned int	m_Enable_com ;/*串口使能*/	
		unsigned char	m_Borad_Init_Index;      /*存储在VxWorks板卡相关数组的起始地址*/

		unsigned char	m_Count;      /*模块个数*/
		unsigned char	m_Cyclic_set; /*周期设置*/
		unsigned char	m_Borad_Set_Flag; /*模块设置开关*/
		unsigned char	m_Run_flag; /*模块运行开关*/
		unsigned int	m_Mode_Addr_Spa; /*模块间隔地址*/
		unsigned char	m_mode_type; /*控制的模块类型*/
		unsigned char	m_Control_Count;/*控制的Board_init个数*/
	};
}

#endif