#ifndef ACCOUNT_UI_H_
#define ACCOUNT_UI_H_
#include"../Service/Account.h"

#include<gtk/gtk.h>

gint account_now;//用户列表当前行号
gint account_num;//用户列表总行数

GtkWidget* account_list;

GtkWidget* text_type;
GtkWidget* text_user;
GtkWidget* text_pass;

//用户管理页面
GtkWidget* Account_UI_MgtEntry();

//创建功能回调函数
GtkWidget* Account_Menu(GtkWidget *button,gpointer data);

//创建用户添加页面
GtkWidget* Account_UI_Add();

//创建用户修改页面
GtkWidget* Account_UI_Change();

//将新增数据加入列表
void to_add_list_account(GtkWidget *button ,gpointer userdate);

//将修改的数据加入列表
void to_change_list_account(GtkWidget *button ,gpointer userdate);

//从列表中删除数据
void list_delete_account(GtkButton *button, gpointer userdate);

//用户列表初始化
void Account_Clist_Make(GtkWidget *Clist, account_list_t head);

//定位用户列表界面选中行
void selection_made_account( GtkWidget *list,gint row,gint column,GdkEventButton *event,gpointer userdate);

#endif
