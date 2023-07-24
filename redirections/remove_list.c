/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:52:18 by bena              #+#    #+#             */
/*   Updated: 2023/07/24 14:07:17 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	remove_list(char ****list_ptr)
{
	char	***list;
	char	***ptr;
	char	**ptr_sub;

	if (list_ptr == NULL)
		return ;
	list = *list_ptr;
	ptr = list;
	while (*ptr != NULL)
	{
		ptr_sub = *ptr;
		while (*ptr_sub != NULL)
			free(*ptr_sub++);
		free(*ptr++);
	}
	free(list);
	*list_ptr = NULL;
}
