#include <string>
#include <Ingenic.Potato.Demo.People.pb.h>

using namespace std;
demo::People p_serial;
demo::People p_deserial;

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

int Pb_Ingenic_Potato_Demo_People_Set_Name(char *name)
{
	if (name == NULL)
		return -1;

	p_serial.set_name(name);
	return 0;
}

int Pb_Ingenic_Potato_Demo_People_Set_ID(int id)
{
	if (id < 0)
		return -1;

	p_serial.set_id(id);
	return 0;
}

int Pb_Ingenic_Potato_Demo_People_Set_Mail(char *mail)
{
	if (mail == NULL)
		return -1;

	p_serial.set_email(mail);
	return 0;
}

int Pb_Ingenic_Potato_Demo_People_Add_New_PAttr(int age, int gender)
{
	demo::People::PAttr *pattr;
	pattr = p_serial.add_people_attr();
	pattr->set_age(age);;
	pattr->set_gender(gender);;

	return 0;
}

int Pb_Ingenic_Potato_Demo_People_Data_Serialize(char *serialize_data)
{
	if (serialize_data == NULL)
		return -1;

	string data;
	p_serial.SerializeToString(&data);
	strcpy(serialize_data, data.c_str());

	return 0;
}

int Pb_Ingenic_Potato_Demo_People_Data_Deserialize(char *serialize_data)
{
	if (serialize_data == NULL)
		return -1;

	p_deserial.ParseFromString(serialize_data);  

	return 0;
}

int Pb_Ingenic_Potato_Demo_People_Get_Name(char *name)
{
	if (name == NULL)
		return -1;

	string data;
	data = p_deserial.name();  
	strcpy(name, data.c_str());

	return 0;
}

int Pb_Ingenic_Potato_Demo_People_Get_ID(void)
{
	return p_deserial.id();
}

int Pb_Ingenic_Potato_Demo_People_Get_Mail(char *mail)
{
	if (mail == NULL)
		return -1;

	string data;
	data = p_deserial.email();  
	strcpy(mail, data.c_str());

	return 0;
}

int Pb_Ingenic_Potato_Demo_People_Get_PAttr_Cnt(void)
{
	return p_deserial.people_attr_size();
}

int Pb_Ingenic_Potato_Demo_People_Get_PAttr(int num, int *age, int *gender)
{
	if((p_deserial.people_attr_size() - 1) < num )
		return -1;

	demo::People::PAttr pattr = p_deserial.people_attr(num);
	*age =  pattr.age();
	*gender = pattr.gender();

	return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
