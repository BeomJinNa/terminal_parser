/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:39:30 by bena              #+#    #+#             */
/*   Updated: 2023/07/23 15:29:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_number_of_redirections(char *str);
static void	write_redirecetions_list(char ***list, char *str);
static char	**get_next_redirection(char **str);

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
	write_redirections_list(output, str);
	return (output);
}

static int	get_number_of_redirections(char *str)
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
		{
			on_redirection = 1;
			count++;
		}
		while (on_redirection == 1 && (*str == '<' || *str == '>'))
			str++;
		while (*on_redirection == 1 && str == ' ')
			str++;
		str++;
	}
	return (count);
}

static void	write_redirecetions_list(char ***list, char *str)
{
	char	***ptr;
	char	**redirection;

	redirection = get_next_redirection(&str);
	while (redirection != NULL)
	{
		*ptr++ = redirection;
		redirection = get_next_redirection(&str);
	}
	*ptr = NULL;
}

static char	**get_next_redirection(char **str)
{
	char	**output;

	output = (char **)malloc(sizeof(char *) * 3);
	if (output == NULL)
	{
		*str = NULL;
		return (NULL);
	}

}
