/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:57:57 by bena              #+#    #+#             */
/*   Updated: 2023/07/23 15:59:23 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_remaining_string_length(char *str);
static void	take_remaining_string(char *remain, char *original);
static void	scan_redirection(int *flag, char **ptr);

char	*remove_redirections(char *str)
{
	char	*output;
	int		size;

	if (str == NULL)
		return (NULL);
	size = get_remaining_string_length(str);
	output = (char *)malloc(sizeof(char) * (size + 1));
	if (output == NULL)
		return (NULL);
	take_remaining_string(output, str);
	free(str);
	return (output);
}

static int	get_remaining_string_length(char *str)
{
	int	count;
	int	on_redirection;
	int	in_brace;
	int	in_double_brace;

	count = 0;
	on_redirection = 0;
	in_brace = 0;
	in_double_brace = 0;
	while (*str)
	{
		if (*str == '\'' && in_double_brace == 0)
			in_brace ^= 1;
		if (*str == '\"' && in_brace == 0)
			in_double_brace ^= 1;
		if (in_brace == 0 && in_double_brace == 0)
			scan_redirection(&on_redirection, &str);
		if (on_redirection == 0)
			count++;
		str++;
	}
	return (count);
}

static void	take_remaining_string(char *remain, char *original)
{
	int		on_redirection;
	char	*ptr_from;
	char	*ptr_to;
	int		in_brace;
	int		in_double_brace;

	ptr_from = original;
	ptr_to = remain;
	on_redirection = 0;
	in_brace = 0;
	in_double_brace = 0;
	while (*ptr_from)
	{
		if (*ptr_from == '\'' && in_double_brace == 0)
			in_brace ^= 1;
		if (*ptr_from == '\"' && in_brace == 0)
			in_double_brace ^= 1;
		if (in_brace == 0 && in_double_brace == 0)
			scan_redirection(&on_redirection, &ptr_from);
		if (on_redirection == 0)
			*ptr_to++ = *ptr_from;
		ptr_from++;
	}
}

static void	scan_redirection(int *flag, char **ptr)
{
	if (*flag == 1 && **ptr == ' ')
		*flag = 0;
	if (*flag == 0 && (**ptr == '<' || **ptr == '>'))
		*flag = 1;
	while (*flag == 1 && (**ptr == '<' || **ptr == '>'))
		(*ptr)++;
	while (*flag == 1 && **ptr == ' ')
		(*ptr)++;
}
