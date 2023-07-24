/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:32:35 by bena              #+#    #+#             */
/*   Updated: 2023/07/24 14:04:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_PARSER_H
# define TERMINAL_PARSER_H

char	**get_tokenized_array(const char *str, char delimiter);
void	replace_white_spaces(char *str);
char	*remove_redirections(char *str);
int		get_number_of_tokens(const char *str, char delimiter);
char	*get_next_token(const char **str, char delimiter);
int		push_to_the_next_token(const char **str, char delimiter);
void	remove_list(char ****list_ptr);
char	***extract_redirections(char *str);
#endif
