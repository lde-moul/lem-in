#include "libft.h"

int assert_lst(t_list *list)
{
	while (list)
	{
		if (!list->content)
			return (0);
		list = list->next;
	}
	return (1);
}
