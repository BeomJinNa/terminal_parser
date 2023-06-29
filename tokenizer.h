/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:32:35 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 20:48:25 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENZIER_H

char	**get_tokenized_array(const char *str)
int		get_number_of_tokens(const char *str);
char	*get_next_token(const char **str);
int		push_to_the_next_token(const char **str);
#endif
