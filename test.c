#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include "terminal_parser.h"

int	main(void)
{
	char	*str;
	char	**tokens;
	char	**ptr;

	str = readline("command : ");
	while (str != NULL)
	{
		add_history(str);
		replace_white_spaces(str);
		str = remove_redirections(str);
		tokens = get_tokenized_array(str, '|');
		if (tokens != NULL)
		{
			ptr = tokens;
			while (*ptr != NULL)
			{
				printf("%s\n\n", *ptr);
				free(*ptr);
				ptr++;
			}
			free(tokens);
		}
		str = readline("command : ");
	}
	return (0);
}
