/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:30:48 by ychibani          #+#    #+#             */
/*   Updated: 2022/10/04 13:50:38 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**__free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab || tab[i])
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
	}
	tab = NULL;
	return (NULL);
}

void	__clean_input(t_user_input *ui, char **inputs, char *line)
{
	(void)ui;
	if (inputs)
		__free_tab(inputs);
	free(line);
}