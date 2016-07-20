/*
 * account.c
 *
 *  Created on: 2015��6��12��
 *      Author: Administrator
 */
#include "Account.h"
#include "EntityKey.h"
#include "../Common/list.h"
#include "../Persistence/Account_Persist.h"
#include <string.h>
#include <stdlib.h>
#include<stdio.h>

extern account_t gl_CurUser;

//����ϵͳ��ʼ���˺�admin
void Account_Srv_InitSys(){
	char entName[8];
	if(Account_Perst_CheckAccFile());
	else
		{
			account_t data_admin;
			data_admin.id=EntKey_Srv_CompNewKey(entName);//���ú�����ȡ�û�id
			scanf("%s",data_admin.username);//Ϊdata_admin�˺Ÿ�ֵ��Ա��Ϣ 
			scanf("%d",&data_admin.type);
			scanf("%s",data_admin.password);
			Account_Srv_Add(&data_admin);//���½�data_admin�˺�д���ļ� 
		}

}

//��֤��¼�˺��Ƿ��Ѵ��ڣ����ڣ������¼�û���Ϣ��ȫ�ֱ���gl_CurUser��return 1������return 0
inline int Account_Srv_Verify(char usrName[], char pwd[]){
	account_t usr;
	int n=0;
	
	if(Account_Perst_SelByName(usrName,&usr))
	{
		if(strcmp(pwd,usr.password)==0){
			n=1;
			gl_CurUser.id=usr.id;
			strcpy(gl_CurUser.password,usr.password);
			gl_CurUser.type=usr.type;
			strcpy(gl_CurUser.username,usr.username);
		}
	}
	return n;
}

//��֤�û����Ƿ���ڣ�����list�������ڣ����ض�Ӧ���ָ�룻���򣬷���null
account_node_t * Account_Srv_FindByUsrName(account_list_t list, char usrName[]) {
	assert(NULL!=list);//��������������ش�������ֹ�����ִ�� 
	account_node_t *pos=list->next;
	while(pos!=list){
		if(pos->data.username==usrName)
			return pos;
		else
			return NULL;
	} 
}

//���һ���û��˺ţ�ͨ������Account_Perst_Insert(data)����ʵ��
inline int Account_Srv_Add(const account_t *data){
	 return Account_Perst_Insert(data);	 
}

//�޸�һ���û��˺ţ�ͨ������Account_Perst_Update(data)����ʵ��
inline int Account_Srv_Modify(const account_t *data){
	return Account_Perst_Update(data);
}

//ɾ��һ���û��˺ţ�ͨ������Account_Perst_DeleteByID(usrID)����ʵ��
inline int Account_Srv_DeleteByID(int usrID){
	return Account_Perst_DeleteByID(usrID);	
}

//��ȡusrID��Ӧ���û��˺���Ϣ��ͨ������Account_Perst_SelectByID(usrID, buf)����ʵ��
inline int Account_Srv_FetchByID(int usrID, account_t *buf){
	return Account_Perst_SelectByID(usrID, buf);	
}

//��ȡusrName��Ӧ���û��˺���Ϣ��ͨ������Account_Perst_SelByName(usrName, buf)����ʵ��
inline int Account_Srv_FetchByUsrName(char usrName[], account_t *buf){
	return Account_Perst_SelByName(usrName, buf);
}

//��ȡ�����û��˺���Ϣ�����浽list�����У�ͨ������Account_Perst_SelectAll(list)����ʵ��
inline int Account_Srv_FetchAll(account_list_t list){
	return Account_Perst_SelectAll(list);
}

