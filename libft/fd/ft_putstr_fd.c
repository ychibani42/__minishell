/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:12:06 by ychibani          #+#    #+#             */
/*   Updated: 2021/11/23 16:05:10 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, __strlen(s));
}