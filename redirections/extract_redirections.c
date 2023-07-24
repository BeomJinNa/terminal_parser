/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:39:30 by bena              #+#    #+#             */
/*   Updated: 2023/07/24 14:08:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "brace.h"

void		dup_redirection(t_brace *brace, char **node);
void		remove_list(char ****list_ptr);
static int	get_number_of_redirections(char *str);
static void	scan_redirection(t_brace *brace);
static void	write_redirections_list(char ****list, char *str);
static void	copy_node(char **to, char **from);

char	***extract_redirections(char *str)
{
	char	***output;
	int		number_of_redirections;

	if (str == NULL)
		return (NULL);
	number_of_redirections = get_number_of_redirections(str);
	output = (char ***)malloc(sizeof(char **) * (number_of_redirections + 1));
	if (output == NULL)
		return (NULL);
	write_redirections_list(&output, str);
	return (output);
}

static int	get_number_of_redirections(char *str)
{
	int		count;
	t_brace	brace;

	init_brace(&brace, str);
	while (*brace.ptr)
	{
		if (*brace.ptr == '\'' && brace.in_double_brace == 0)
			brace.in_brace ^= 1;
		if (*brace.ptr == '\"' && brace.in_brace == 0)
			brace.in_double_brace ^= 1;
		if (brace.in_brace == 0 && brace.in_double_brace == 0)
			scan_redirection(&brace);
		brace.ptr++;
	}
	return (brace.count);
}

static void	scan_redirection(t_brace *brace)
{
	if (brace->on_redirection == 1 && *brace->ptr == ' ')
		brace->on_redirection = 0;
	if (brace->on_redirection == 0
		&& (*brace->ptr == '<' || *brace->ptr == '>'))
	{
		brace->on_redirection = 1;
		brace->count++;
	}
	while (brace->on_redirection == 1
		&& (*brace->ptr == '<' || *brace->ptr == '>'))
		brace->ptr++;
	while (brace->on_redirection == 1 && *brace->ptr == ' ')
		brace->ptr++;
}

static void	write_redirections_list(char ****list, char *str)
{
	char	***ptr;
	char	*redirection[2];
	t_brace	brace;

	ptr = *list;
	init_brace(&brace, str);
	while (*brace.ptr)
	{
		if (*brace.ptr == '\'' && brace.in_double_brace == 0)
			brace.in_brace ^= 1;
		if (*brace.ptr == '\"' && brace.in_brace == 0)
			brace.in_double_brace ^= 1;
		if (brace.in_brace == 0 && brace.in_double_brace == 0)
			dup_redirection(&brace, redirection);
		if (redirection[0] != NULL)
		{
			*ptr = (char **)malloc(sizeof(char *) * 3);
			if (*ptr == NULL)
				return (remove_list(list));
			copy_node(*ptr, redirection);
			ptr++;
		}
		brace.ptr++;
	}
	*ptr = NULL;
}

static void	copy_node(char **to, char **from)
{
	to[0] = from[0];
	to[1] = from[1];
	to[2] = NULL;
}
