/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:33:33 by ychibani          #+#    #+#             */
/*   Updated: 2022/09/20 16:59:55 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_program_data	*init_data_struct(t_program_data *data)
{
	data->all_inputs = NULL;
	data->token = NULL;
	data->ui = NULL;
	return (data);
}

t_user_input	*init_user_input_struct(t_user_input *ui)
{
	ui->token = NULL;
	ui->to_tokenize = NULL;
	ui->ret_hd = 0;
	ui->ret_token = 0;
	return (ui);
}

void	__init_structs(t_program_data *data, t_user_input *ui)
{
	__memset(&data, 0, sizeof(data));
	__memset(&ui, 0, sizeof(ui));
}