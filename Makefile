SOURCE =	test.c \
			convert_tokens_to_board.c \
			get_tokenized_array.c \
			init_brace.c \
			merge_tokens.c \
			redirections/are_any_syntax_errors_in_redirections.c \
			redirections/dup_redirection.c \
			redirections/extract_redirections.c \
			redirections/remove_redirections.c \
			remove_board_and_tokens.c \
			remove_quotes.c \
			replace_white_spaces.c \
			variable_extension/are_any_syntax_errors_in_extensions.c \
			variable_extension/divide_variables.c \
			variable_extension/extend_env_variables.c \
			variable_extension/replace_variables.c \
			variable_extension/va_strndup.c \
			variable_extension/variable.c

.PHONY: all
all :
	make parser

parser :
	gcc -g -o parser -lreadline $(SOURCE)

.PHONY: clean
clean :
	rm -f parser
	rm -rf parser.dSYM

.PHONY: fclean
fclean :
	rm -f parser
	rm -rf parser.dSYM

.PHONY: re
re :
	rm -f parser
	rm -rf parser.dSYM
	make all
