/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:28:32 by ychibani          #+#    #+#             */
/*   Updated: 2022/10/25 19:30:04 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef int						t_bool;

typedef struct s_token
{
	char			*content;
	struct s_token	*next;
}	t_token;

typedef struct s_env
{
	char			*name;
	char			*value;
	int				env;
	int				order;
	struct s_env	*next;
}	t_env;

typedef struct s_lexer
{
	t_type			type;
	char			*token;
	int				hd_type;
	int				empty;
	struct s_lexer	*next;	
}	t_lexer;

typedef struct s_cmd
{
	int							redirection[2];
	int							pipe[2];
	int							index;
	int							nb_cmd;
	char						*path;
	char						**all_path;
	int							hd_count;
	t_env						*envp;
	char						**arg;
	struct s_program_data		*data;
	struct s_cmd				*next;
	struct s_redirect			*redirect;
}	t_cmd;

typedef struct s_user_input
{
	t_list		*token;
	t_lexer		*lexer;
	t_lexer		*error_delim;
	t_env		**test_env;
	char		**env;
	char		*to_tokenize;
	int			ret_token;
	int			ret_hd;
}	t_user_input;

typedef struct s_program_data
{
	int				rv;
	int				synthax_error;
	t_user_input	*ui;
	t_list			*token;	
	char			**all_inputs;
	char			***envp;
	char			**env;
}	t_program_data;

typedef struct s_redirect
{
	int					type;
	char				*file_name;
	struct s_redirect	*next;
}	t_redirect;

#endif