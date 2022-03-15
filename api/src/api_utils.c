/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:40:56 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/26 03:14:22 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/api.h"

t_api	g_api;

int	check_method(const char *ptr)
{
	if (!strstr(ptr, "GET"))
		return (FALSE);
	return (TRUE);
}

void	sigint(int signum)
{
	(void)signum;
	g_api.signal = 1;
}
