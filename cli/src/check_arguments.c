/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:54:08 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/26 04:03:07 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cli.h"

int	check_arguments(t_data *data, int argc, char *argv[])
{
	if (argc == 2)
	{
		if (strstr(argv[1], "all"))
		{
			data->print_code = 1;
			return (TRUE);
		}
		else
			data->print_code = 0;
	}
	else if (argc == 3)
	{
		if (!strcmp(argv[1], "get") && !strcmp(argv[2], "/cartoon"))
		{
			data->print_code = 3;
			return (TRUE);
		}
		else if (!strcmp(argv[1], "get") && !strcmp(argv[2], "/"))
		{
			data->print_code = 2;
			return (TRUE);
		}
		else
			data->print_code = 0;
	}
	else
		data->print_code = 0;
	return (FALSE);
}
