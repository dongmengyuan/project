/*
 * Account_UI.c
 *
 *  Created on: 2015年5月8日
 *      Author: Administrator
 */

#include "Account_UI.h"

#include "../Common/List.h"
#include "../Service/Account.h"
#include "../Service/EntityKey.h"
#include "Account_UI.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

int SysLogin() {
	char user[30],pass[30];
	printf("请输入账号：");
	scanf("%s",user);
	printf("请输入密码：");
	scanf("%s",pass);
	getchar();
	if(Account_Srv_Verify(user,pass))
	{
		return 1;
	}
        return 0;
}

//管理系统用户功能入口函数，显示用户账号管理菜单
void Account_UI_MgtEntry() {
	int i, id;
	char userName[30];
	char choice;

	account_list_t head;
	account_node_t *pos;
	Pagination_t paging;

	List_Init(head, account_node_t);
	paging.offset = 0;
	paging.pageSize = ACCOUNT_PAGE_SIZE;

	//载入数据
	paging.totalRecords = Account_Srv_FetchAll(head);
	Paging_Locate_FirstPage(head, paging);

	do {
		/*system("cls");*/
		printf("\n==================================================================\n");
		printf(
				"********************** Projection Account List **********************\n");
		printf("%10s  %18s  %18s\n", "ID", "UserName", "PassWord");
		printf(
				"------------------------------------------------------------------\n");
		//显示数据
		Paging_ViewPage_ForEach(head, paging, account_node_t, pos, i){
			printf("%10d  %18s  %18s\n", pos->data.id,pos->data.username, pos->data.password);
		}

		printf("------- Total Records:%2d ----------------------- Page %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf("******************************************************************\n");
		printf("[P]revPage | [N]extPage | [A]dd | [D]elete | [U]pdate | [R]eturn");
		printf("\n==================================================================\n");
		printf("Your Choice:");
		choice = getchar();
 		//scanf("%*c");
		//fflush(stdin);

		switch (choice) {
		case 'a':
		case 'A':
			if (Account_UI_Add(NULL)) //新添加成功，跳到最后一页显示
			{
				paging.totalRecords = Account_Srv_FetchAll(head);
				Paging_Locate_LastPage(head, paging, account_node_t);
			}
			break;
		case 'u':
		case 'U':
			printf("输入要修改的用户名:");
			scanf("%s",userName);
			if (Account_UI_Modify(NULL, userName))//从新载入数据
			{
				paging.totalRecords = Account_Srv_FetchAll(head);
				List_Paging(head, paging, account_node_t);
			}
			break;
		case 'd':
		case 'D':
			printf("Input the userName:");
			scanf("%s",userName);
			getchar();
			if (Account_UI_Delete(NULL, userName))//从新载入数据
			{	
				paging.totalRecords = Account_Srv_FetchAll(head);
				List_Paging(head, paging, account_node_t);
			}
			break;
		case 's':
		case 'S':
			/*printf("Input the room ID:");
			scanf("%d", &id);
			getchar();
			Seat_UI_MgtEntry(id);
			paging.totalRecords = Account_Srv_FetchAll(head);
			List_Paging(head, paging, account_node_t);
			*/break;
		case 'p':
		case 'P':
			if (!Pageing_IsFirstPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, account_node_t);
			}
			break;
		case 'n':
		case 'N':
			if (!Pageing_IsLastPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, account_node_t);
			}
			break;
		}
	} while (choice != 'r' && choice != 'R');
	//释放链表空间
	List_Destroy(head, account_node_t);
}


//添加一个用户账号信息
int Account_UI_Add(account_list_t list ) {
	int type;	
	account_t data;
	do {
		printf("\n=======================================================\n");
		printf("****************  Add New Account  ****************\n");
		printf("-------------------------------------------------------\n");
		fflush(stdin);
		printf("请选择账号类型： [0]匿名\t[1]销售员\t[2]经理\t[9]系统管理员\n");
		printf("=======================================================\n");
		scanf("%d",&type);
		getchar();
	}
	while(type!=0 && type!=1 && type!=2 && type!=9);
	data.type = type;
	data.id = EntKey_Srv_CompNewKey("Account");
	printf("请输入账号：");
	scanf("%s",data.username);
	getchar();
	printf("请输入密码：");
	scanf("%s",data.password);
	getchar();
	if(Account_Srv_Add(&data))
	{
		printf("添加成功\n");
		return 1;
	}
	printf("添加失败\n");
	return 0;
}

//根据用户账号名修改用户账号密码，不存在这个用户账号名，提示出错信息
int Account_UI_Modify(account_list_t list ,char usrName[]) {
      	account_list_t head;
	account_list_t data = (account_list_t)malloc(sizeof(account_node_t));
	//puts("123");


	List_Init(head, account_node_t);
	Account_Srv_FetchAll(head);
	data=Account_Srv_FindByUsrName(head, usrName);
	//puts("456");	
	if(data == NULL)
	{
		printf("该账号不存在\n");
		return 0;
	}
	printf("请输入新密码：");
	scanf("%s",data->data.password);
	getchar();
	Account_Srv_Modify(&(data->data));
	printf("修改成功\n");
	return 1;
}

//根据用户账号名删除一个已经存在的用户账号信息，如果不存在这个用户账号名，提示出错信息
int Account_UI_Delete(account_list_t list ,char usrName[]) {
	account_t buf;
	if(Account_Srv_FetchByName(usrName, &buf))
	{
		Account_Srv_DeleteByID(buf.id);
		printf("删除成功\n");
		return 1;
	}
	printf("该账号不存在\n");
       	return  0;
}
//根据用户账号名查找该用户账号是否存在，存在返回1，否则返回0，并提示错误信息
int Account_UI_Query(account_list_t  list ,char usrName[]) {
	account_t buf;
	if(Account_Srv_FetchByName(usrName, &buf))
	{
		return 1;
	}
	printf("该账号不存在\n");
       	return  0;
}


