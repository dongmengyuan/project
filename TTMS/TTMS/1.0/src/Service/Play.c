#include "Play.h"
#include "../Common/List.h"
#include "../Persistence/Play_Persist.h"
#include <string.h>

//新增剧目服务
inline int Play_Srv_Add(const play_t *data) 
{
	return Play_Perst_Insert(data);
}

//修改剧目服务
inline int Play_Srv_Modify(const play_t *data) 
{
	return Play_Perst_Update(data);
}

//根据ID删除剧目服务
inline int Play_Srv_DeleteByID(int ID) 
{
	return Play_Perst_DeleteByID(ID);
}

//根据ID获取剧目服务
inline int Play_Srv_FetchByID(int ID, play_t *buf)
{	
	return Play_Perst_SelectByID(ID,buf);
}

//获取所有剧目服务
inline int Play_Srv_FetchAll(play_list_t list) 
{
	return Play_Perst_SelectAll(list);
}

//根据剧目名称载入剧目，返回载入的剧目数量
int Play_Srv_FetchByName(play_list_t list, char condt[])
{
	return Play_Perst_SelectByName(list,condt);
}

//根据剧目名称过滤词filter对list进行过滤，返回过滤后剩余的剧目数量
int Play_Srv_FilterByName(play_list_t list, char filter[])
{
	play_list_t buf;
	int i,j,found=0;
	buf=list->next;
	while(buf!=list)
	{
		found++;
		for(i=0;i<strlen(buf->data.name);i++)
		{
			if(buf->data.name[i]==filter[0])
			{
				for(j=0;j<strlen(filter);j++)
				{
					if(buf->data.name[i+j]!=filter[j])
					{
						break;
					}
				}				
				if(j==strlen(filter))
				{
					found--;
					break;
				}
			}
		}
		buf=buf->next;	
	}
	return found;
}
