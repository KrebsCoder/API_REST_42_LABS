/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:23:09 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/26 04:01:32 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cli.h"

int	init_cli(t_data *data, int argc, char *argv[])
{
	data->count.get_root = 0;
	data->count.get_cartoon = 0;
	if (check_arguments(data, argc, argv))
	{
		data->log_file = fopen(PATH_LOG, "r");
		if (!data->log_file)
		{
			perror("ERROR");
			exit(1);
		}
		count_methods(data);
		fclose(data->log_file);
	}
	print_cli(data);
	return (EXIT_SUCCESS);
}
