#include<gtk/gtk.h>
#include"Window_UI.h"

//销毁窗体
void destroy(GtkWidget *button,GtkWidget *window)
{
	gtk_widget_destroy(window);
}

//由系统管理员页面转至放映厅管理页面
void Admin_Menu_to_Studio(GtkWidget *button ,gpointer userdate)
{
	gtk_widget_hide(menu_window);
	studio_window = Studio_UI_MgtEntry();
	gtk_widget_show_all(studio_window);
}

//由放映厅管理页面转至系统管理员页面
void Studio_to_Admin_Menu(GtkWidget *button,gpointer data)
{
	gtk_widget_destroy(studio_window);
	gtk_widget_show_all(menu_window);
}

//由系统管理员页面转至用户管理页面
void Admin_Menu_to_Account(GtkWidget *button ,gpointer userdate)
{
	gtk_widget_hide(menu_window);
	account_window = Account_UI_MgtEntry();
	gtk_widget_show_all(account_window);
}

//由放映厅管理页面转至系统管理员页面
void Account_to_Admin_Menu(GtkWidget *button,gpointer data)
{
	gtk_widget_destroy(account_window);
	gtk_widget_show_all(menu_window);
}

//由售票员页面转至增加演出计划页面
void Clerk_Menu_to_Schedule_add(GtkWidget *button,gpointer data)
{
	gtk_widget_hide(menu_window);
	schedule_add_window = Schedule_UI_Add();
	gtk_widget_show_all(schedule_add_window);
}

//由售票员页面转至查询演出页面
void Clerk_Menu_to_Play_find(GtkWidget *button,gpointer data)
{
	gtk_widget_hide(menu_window);
	play_find_window = Play_UI_find();
	gtk_widget_show_all(play_find_window);
}

//由查询演出页面转至售票员页面
void Play_find_to_Clerk_Menu(GtkWidget *button,gpointer data)
{
	gtk_widget_destroy(play_find_window);
	gtk_widget_show_all(menu_window);
}

//由经理页面转至剧目管理页面
void Mang_Menu_to_Play(GtkWidget *button ,gpointer userdate)
{
	gtk_widget_hide(menu_window);
	//play_window = Play_UI_MgtEntry();
	gtk_widget_show_all(play_window);
}

//由剧目管理页面转至经理页面
void Play_to_Mang_Menu(GtkWidget *button ,gpointer userdate)
{
	gtk_widget_destroy(play_window);
	gtk_widget_show_all(menu_window);
}

//由经理页面转至票房排行页面
void Mang_Menu_to_Sale(GtkWidget *button ,gpointer userdate)
{
	gtk_widget_hide(menu_window);
	sale_window = Sale_UI_MgtEntry();
	gtk_widget_show_all(sale_window);
}

//由票房排行页面转至经理页面
void Sale_to_Mang_Menu(GtkWidget *button,gpointer data)
{
	gtk_widget_destroy(sale_window);
	gtk_widget_show_all(menu_window);
}

//转到演出信息输出页面
void print_play(GtkWidget *button,gpointer data)
{
	
}
