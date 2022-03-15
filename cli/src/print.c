/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:05 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/26 04:06:39 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cli.h"

static void	print_all(t_data *data)
{
	printf("------------------------------------------------\n");
	printf("| TOTAL REQUESTS  | HTTP Method  |   Path      |\n");
	printf("|----------------------------------------------|\n");
	printf("|     %6d      |     GET      |     /       |\n", \
		data->count.get_root);
	printf("|----------------------------------------------|\n");
	printf("|     %6d      |     GET      |  /cartoon   |\n", \
		data->count.get_cartoon);
	printf("|----------------------------------------------|\n");
}

static void	print_get_root(t_data *data)
{
	printf("------------------------------------------------\n");
	printf("| TOTAL REQUESTS  | HTTP Method  |   Path      |\n");
	printf("|----------------------------------------------|\n");
	printf("|     %6d      |     GET      |      /      |\n", \
		data->count.get_root);
	printf("|----------------------------------------------|\n");
}

static void	print_get_secret(t_data *data)
{
	printf("------------------------------------------------\n");
	printf("| TOTAL REQUESTS  | HTTP Method  |   Path      |\n");
	printf("|----------------------------------------------|\n");
	printf("|     %6d      |     GET      |  /cartoon   |\n", \
		data->count.get_cartoon);
	printf("|----------------------------------------------|\n");
}

static void	print_help(t_data *data)
{
	bzero(data->art, 50);
	data->ascii_art = fopen(ASCII_ART, "r");
	if (!data->ascii_art)
	{
		perror("ERROR");
		exit(1);
	}
	while (fgets(data->art, 50, data->ascii_art))
		printf("\033[1;31m%s", data->art);
	fclose(data->ascii_art);
}

void	print_cli(t_data *data)
{
	if (data->print_code == 0)
		print_help(data);
	if (data->print_code == 1)
		print_all(data);
	if (data->print_code == 2)
		print_get_root(data);
	if (data->print_code == 3)
		print_get_secret(data);
}
