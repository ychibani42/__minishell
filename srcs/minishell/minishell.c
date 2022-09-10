/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:46:01 by ychibani          #+#    #+#             */
/*   Updated: 2022/09/10 18:12:27 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_es;

char	**__free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}


int main(int ac, char **av, char **env)
{
	t_program_data	data;
	t_user_input	ui;
	char			**inputs;
	char			*line;
	int				i;
	(void)av;
	(void)env;

	if (ac > 1)
		return (__putstr_fd("usage <./minishell>\n", 2), 2);
	while (1)
	{
		init_signals();
		line = readline("minishell ~ ");
		g_es = 0;
		add_history(line);
		if (line == NULL)
			break ;
		signal(SIGINT, ctrld_signal);
		inputs = __split(line, '\n');
		if (!inputs)
			return (__putstr_fd("can't split inputs", 2), 2);
		data.all_inputs = inputs;
		i = -1;
		while (inputs[++i])
			treat_usr_inputs(inputs[i], &data, &ui);
		__free_tab(inputs);
		free(line);
	}
	printf("exit\n");
	exit(g_es);
	return (1);
}