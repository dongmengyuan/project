#ifndef LOGIN_UI_H_
#define LOGIN_UI_H_

#include<gtk/gtk.h>

GtkWidget *text_user;//用户名文本输入框
GtkWidget *text_pass;//密码文本输入框

//创建登录页面
GtkWidget* Login_UI_MgtEntry();

//用户登录验证 并进入功能界面
void Login_UI_Think(GtkWidget *button ,gpointer userdate);



#endif
