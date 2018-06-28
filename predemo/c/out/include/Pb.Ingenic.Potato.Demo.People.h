#ifndef __PB_INGENIC_POTATOL_DEMO_PEOPLE_H__
#define __PB_INGENIC_POTATOL_DEMO_PEOPLE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

int Pb_Ingenic_Potato_Demo_People_Set_Name(char *name);
int Pb_Ingenic_Potato_Demo_People_Set_ID(int id);
int Pb_Ingenic_Potato_Demo_People_Set_Mail(char *mail);
int Pb_Ingenic_Potato_Demo_People_Add_New_PAttr(int age, int gender);
int Pb_Ingenic_Potato_Demo_People_Data_Serialize(char *serialize_data);

int Pb_Ingenic_Potato_Demo_People_Data_Deserialize(char *serialize_data);
int Pb_Ingenic_Potato_Demo_People_Get_Name(char *name);
int Pb_Ingenic_Potato_Demo_People_Get_ID(void);
int Pb_Ingenic_Potato_Demo_People_Get_Mail(char *mail);
int Pb_Ingenic_Potato_Demo_People_Get_PAttr_Cnt(void);
int Pb_Ingenic_Potato_Demo_People_Get_PAttr(int num, int *age, int *gender);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_INGENIC_POTATOL_DEMO_PEOPLE_H__*/
