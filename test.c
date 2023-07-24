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
	char	***list_of_redirections;
	char	***list;

	str = readline("command : ");
	while (str != NULL)
	{
		add_history(str);
		replace_white_spaces(str);
		list_of_redirections = extract_redirections(str);
		str = remove_redirections(str);
		tokens = get_tokenized_array(str, '|');
		//commands <= get_tokenized_array(tokens, ' ');
		//extend_env_variables(commands, redirections)
		//remove_quotes(commands, redirections)
		printf("COMMANDS\n");
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
		printf("REDIRECTIONS\n");
		list = list_of_redirections;
		if (list != NULL)
		{
			while (*list != NULL)
			{
				ptr = *list;
				while (*ptr != NULL)
					printf("%s ", *ptr++);
				printf("\n");
				list++;
			}
		}
		remove_list(&list_of_redirections);
		str = readline("command : ");
	}
	return (0);
}
