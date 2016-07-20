#include "Ticket_UI.h"

#include "../Common/List.h"
#include "../Service/Ticket.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Service/Studio.h"

#include <stdio.h>
#include <stdlib.h>

//根据票ID打印票
void Ticket_UI_Print(int ID){
	ticket_t buf;	
	Ticket_Srv_FetchByID(ID,  &buf);
	printf("\n==================================================================\n");
		printf("********************** Ticket **********************\n");
		printf("%10s  %10s  %10s  %10s  %10s\n", "ID", "演出计划ID", "票对应座位ID","票价","票的状态");
		printf(
				"------------------------------------------------------------------\n");
		//显示数据
		printf("%10d  %10d  %10d  %10d  %10s\n", buf.id , buf.schedule_id, buf.seat_id, buf.price,Ticket_UI_Status2Char(buf.status));

		printf("\n==================================================================\n");

}

//根据状态返回对应表示状态符号
inline char Ticket_UI_Status2Char(ticket_status_t status) {

	if(status == 0)
	{
		return 'O';
	}
	if(status == 1)
	{
		return 'X';
	}
	if(status == 9)
	{
       		return 'V';
	}
}

//根据计划ID显示所有票
void Ticket_UI_ListBySch(const schedule_t *sch,	ticket_list_t tickList, seat_list_t seatList) {
	//Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id);
}

void ListTickets(void){
	// 请补充完整
}


int UpdateTicket(int id){
	// 请补充完整
       return 1;
}


int QueryTicket(int id){

	// 请补充完整
       return 1;
}
