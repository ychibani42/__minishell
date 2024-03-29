/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:36:41 by caubry            #+#    #+#             */
/*   Updated: 2022/10/13 16:07:28 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	
// lofjdlkjfsdkljfsdklf
// kjfhsfs

char	*ft_getpwd(t_user_input *ui)
{
	t_env	*tmp;

	tmp = *(ui->test_env);
	while (tmp)
	{
		if (!__strcmp(tmp->name, "PWD"))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_pwd(t_user_input *ui)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = __strdup(ft_getpwd(ui));
	__putstr_fd(pwd, STDOUT_FILENO);
	__putstr_fd("\n", STDOUT_FILENO);
	free(pwd);
}
