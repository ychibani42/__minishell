/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fonctions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:42:53 by ychibani          #+#    #+#             */
/*   Updated: 2022/09/19 16:08:50 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FONCTIONS_H
# define MINISHELL_FONCTIONS_H

/*
**		Init
*/

t_program_data	*init_data_struct(t_program_data *data);
t_user_input	*init_user_input_struct(t_user_input *ui);

/*
**		Cd
*/

int				change_directory(char *path);

/*
**		Tokenizer Utils
*/

t_state			return_quoted_state(char c, t_state state, t_state quoted);
void			skip_spaces(char *str, int *i);
int				adjust_i(char *str, int i, int state);
int				__is_operator(char c);

/*
**		Tokenizer
*/

int				tokenize(char *to_tokenize, t_list **token_list);
int				add_char_token(char c, char **token);
int				add_token(char *token, t_list **begin);
int				get_operator(char **token, char *str, int i);
int				get_word(char **token, char *str, int i);

/*
**		Lexer
*/

int				lexer(t_list *token, t_lexer **lexer);

/*
**		Parsing
*/

int				treat_usr_inputs(char *user_input,
					t_program_data *data, t_user_input *ui);

/*
**		Signals
*/

void			treat_signal(int sig);
void			hd_signal(int sig);
void			init_signals(void);
void			ctrld_signal(int sig);
void			__signal(int sig);

/*
**		Clean
*/

char			**__free_tab(char **tab);
void			__lexer_clear(t_lexer **lst, void (*del)(void*));
t_lexer			*synthax_checker(t_lexer **lexer, t_program_data *data);

/*
**		Exit
*/

void			__exit(t_program_data *data, t_user_input *ui, int rv);

/*
**		Utils
*/

void			print_data(t_program_data *data, t_user_input *ui);
void			print_linked_list(t_list *list);

#endif