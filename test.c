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
	if (str == NULL)
		return (0);
	tokens = get_tokenized_array(str, '|');
	ptr = tokens;
	while (*ptr != NULL)
	{
		printf("%s\n", *ptr);
		free(*ptr);
		ptr++;
	}
	free(tokens);
	return (0);
}
