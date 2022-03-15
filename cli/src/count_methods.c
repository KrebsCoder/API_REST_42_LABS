/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:51:24 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/26 04:06:15 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cli.h"

void	count_methods(t_data *data)
{
	bzero(data->buffer, 50);
	while (fgets(data->buffer, 50, data->log_file))
	{
		if (strstr(data->buffer, "GET / "))
			data->count.get_root++;
		if (strstr(data->buffer, "GET /cartoon"))
			data->count.get_cartoon++;
	}
}
