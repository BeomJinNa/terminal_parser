#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include "terminal_parser.h"

int	main(void)
{
	char	*str;
	char	**tokens;
	char	***commands;
	char	***redirections;
	char	***ptr;
	char	**ptr_sub;

	printf("=====================================================\n");
	str = readline("command : ");
	while (str != NULL)
	{
		add_history(str);
		replace_white_spaces(str);
		if (get_number_of_tokens(str, ' ') < 0)
			printf("quotation marks are not closed\n");
		else
		{
			redirections = extract_redirections(str);
			str = remove_redirections(str);
			printf("redirection removed : %s\n", str);
			tokens = get_tokenized_array(str, '|');
			commands = convert_tokens_to_board(tokens, ' ');
			remove_tokens(&tokens);
			//extend_env_variables(commands, redirections)
			//remove_quotes(commands, redirections)
			printf("-----------------------------------------------------\n");
			printf("COMMANDS\n");
			ptr = commands;
			if (ptr != NULL)
			{
				while (*ptr != NULL)
				{
					ptr_sub = *ptr;
					while (*ptr_sub != NULL)
					{
						printf("%s ", *ptr_sub);
						ptr_sub++;
					}
					printf("\n");
					ptr++;
				}
			}
			remove_board(&commands);
			printf("\nREDIRECTIONS\n");
			ptr = redirections;
			if (ptr != NULL)
			{
				while (*ptr != NULL)
				{
					ptr_sub = *ptr;
					while (*ptr_sub != NULL)
					{
						printf("%s ", *ptr_sub);
						ptr_sub++;
					}
					printf("\n");
					ptr++;
				}
			}
			remove_board(&redirections);
		}
		free(str);
		printf("=====================================================\n");
		str = readline("command : ");
	}
	return (0);
}
