/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:42:17 by bena              #+#    #+#             */
/*   Updated: 2023/07/23 10:03:44 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	get_remaining_string_length(char *str);

char	*remove_redirections(char *str)
{
	char			*output;
	unsigned int	size;

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

static unsigned int	get_remaining_string_length(char *str)
{
	unsigned int	count;
	int				on_remaining_character;
	char			*ptr;

	count = 0;
	ptr = str;
	on_remaining_character = 0;
	while (*ptr)
	{
		if (on_remaining_character == 0 && (*ptr == '<' || *ptr == '>'))
			on_remaining_character = 1;
		if (on_remaining_character == 0)
			count++;
		ptr++;
	}
	return (count);
}
