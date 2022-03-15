/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:17:54 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/26 04:01:19 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cli.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (init_cli(&data, argc, argv) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
