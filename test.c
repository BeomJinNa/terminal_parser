/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:24:24 by bena              #+#    #+#             */
/*   Updated: 2023/07/29 19:15:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 1. readline 으로 명령어 받기
 * 2. add_history 로 히스토리 등록
 * 3. white spaces 처리(리터럴 처리되지 않은 white spaces는 전부 공백으로 치환)
 * 4. 따옴표 문법 검사 (따옴표가 닫혀있지 않은 경우 에러)
 * 5. 리다이렉션 검사 (<, <<, >, >> 이외 기호가 쓰였거나 있으면 안되는 위치에 <, > 존재)
 * 6. 리다이렉션 추출
 * 7. 원래 문자열에서 리다이렉션 문자열 제거
 * 8. 파이프 기호를 기준으로 문자열 분리 (명령어 별로 나누기)
 * 9. 환경변수 확장 (zsh의 경우는 환경변수 확장을 공백 기준으로 분리한 이후에 처리함)
 * 10. 공백 기준으로 문자열 분리 (배열 형태로 분리되고, 명령어의 인자로 들어감)
 * 11. 동적 메모리 할당 해제
 */
// 라이브러리 사용시 Makefile, test.c만 제거한 뒤, terminal_parser.h를 사용하면 됨
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include "terminal_parser.h"

static char	*process_str(char *str);
static void	print_board(char ***board);

int	main(void)
{
	char	*str;

	printf("=====================================================\n");
	str = readline("command : ");
	while (str != NULL)
	{
		add_history(str);
		replace_white_spaces(str);
		str = process_str(str);
		free(str);
		printf("=====================================================\n");
		str = readline("command : ");
	}
	return (0);
}

static char	*process_str(char *str)
{
	char	**tokens;
	char	***commands;
	char	***redirections;

	// 따옴표가 닫히지 않으면 -1 반환 (get_number_of_tokens)
	if (get_number_of_tokens(str, '\0') < 0)
	{
		printf("\033[33mquotation marks are not closed.\033[0m\n");
		return (str);
	}
	redirections = extract_redirections(str);
	if (are_any_syntax_errors_in_redirections(redirections))
	{
		printf("\033[33msyntax errors exist in redirection.\033[0m\n");
		return (str);
	}
	str = remove_redirections(str);
	tokens = get_tokenized_array(str, '|');
	//
	//bash는 공백 분리 이전에 변수 확장, zsh는 공백 분리 이후에 변수 확장
	extend_env_variables_board(&redirections);
	extend_env_variables_token(&tokens);
	//
	if (are_any_syntax_errors_in_extensions_token(tokens)
			|| are_any_syntax_errors_in_extensions_board(redirections))
	{
		printf("\033[33msyntax errors exist near '{'.\033[0m\n");
		return (str);
	}
	commands = convert_tokens_to_board(tokens, ' ');
	remove_tokens(&tokens);
	remove_quotes(commands);
	remove_quotes(redirections);
	printf("-----------------------------------------------------\n");
	printf("COMMANDS\n");
	print_board(commands);
	remove_board(&commands);
	printf("\nREDIRECTIONS\n");
	print_board(redirections);
	remove_board(&redirections);
	return (str);
}

static void	print_board(char ***board)
{
	char	***ptr;
	char	**ptr_sub;

	ptr = board;
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
}
