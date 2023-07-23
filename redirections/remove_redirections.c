/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   remove_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:42:17 by bena              #+#    #+#             */
/*   Updated: 2023/07/23 11:35:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_remaining_string_length(char *str);
static void	take_remaining_string(char *remain, char *original);

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

	count = 0;
	on_redirection = 0;
	while (*str)
	{
		if (on_redirection == 1 && *str == ' ')
			on_redirection = 0;
		if (on_redirection == 0 && (*str == '<' || *str == '>'))
			on_redirection = 1;
		while (on_redirection == 1 && (*str == '<' || *str == '>'))
			str++;
		while (*on_redirection == 1 && str == ' ')
			str++;
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

	ptr_from = original;
	ptr_to = remain;
	on_redirection = 0;
	while (*ptr_from)
	{
		if (on_redirection == 1 && *ptr_from == ' ')
			on_redirection = 0;
		if (on_redirection == 0 && (*ptr_from == '<' || *ptr_from == '>'))
			on_redirection = 1;
		while (on_redirection == 1 && (*ptr_from == '<' || *ptr_from == '>'))
			ptr_from++;
		while (on_redirection == 1 && *ptr_from == ' ')
			ptr_from++;
		if (on_redirection == 0)
			*ptr_to++ = *ptr_from;
		ptr_from++;
	}
}
