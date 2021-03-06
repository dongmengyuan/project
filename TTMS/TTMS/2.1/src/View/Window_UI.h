#ifndef WINDOW_UI_H_
#define WINDOW_UI_H_

#include<gtk/gtk.h>

GtkWidget *login_window;//用户登录窗口
GtkWidget *menu_window;//用户功能窗口
GtkWidget *studio_window;//放映厅管理页面
GtkWidget *seat_window;//座位管理页面
GtkWidget *account_window;//用户管理页面
GtkWidget *play_window;//剧目管理页面
GtkWidget *sale_window;//票房排行页面
GtkWidget *studio_menu;//放映厅功能页面
GtkWidget *account_menu;//用户功能页面
GtkWidget *schedule_add_window;//添加演出计划页面
GtkWidget *play_find_window;//查询演出计划页面


//销毁窗体
void destroy(GtkWidget *button,GtkWidget *window);

//由经理页面转至剧目管理页面
void Mang_Menu_to_Play(GtkWidget *button ,gpointer userdate);

//由剧目管理页面转至经理页面
void Play_to_Mang_Menu(GtkWidget *button ,gpointer userdate);

//由系统管理员页面转至放映厅管理页面
void Admin_Menu_to_Studio(GtkWidget *button ,gpointer userdate);

//由放映厅管理页面转至系统管理员页面
void Studio_to_Admin_Menu(GtkWidget *button,gpointer data);

//由系统管理员页面转至用户管理页面
void Admin_Menu_to_Account(GtkWidget *button ,gpointer userdate);

//由用户管理页面转至系统管理员页面
void Account_to_Admin_Menu(GtkWidget *button,gpointer data);

//由售票员页面转至增加演出计划页面
void Clerk_Menu_to_Schedule_add(GtkWidget *button,gpointer data);

//由售票员页面转至查询演出页面
void Clerk_Menu_to_Play_find(GtkWidget *button,gpointer data);

//由查询演出页面转至售票员页面
void Play_find_to_Clerk_Menu(GtkWidget *button,gpointer data);

//由经理页面转至票房排行页面
void Mang_Menu_to_Sale(GtkWidget *button ,gpointer userdate);

//由票房排行页面转至经理页面
void Sale_to_Mang_Menu(GtkWidget *button,gpointer data);

//转到演出信息输出页面
void print_play(GtkWidget *button,gpointer data);

#endif
