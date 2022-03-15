/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:49:09 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/27 11:27:12 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# define FALSE 0
# define TRUE 1
# define PATH_LOG "../api/logs/log.log"
# define ASCII_ART "ascii_art/art.txt"

typedef struct s_count
{
	int	get_root;
	int	get_cartoon;
}	t_count;

typedef struct s_data
{
	FILE	*log_file;
	FILE	*ascii_art;
	int		print_code;
	char	buffer[50];
	char	art[50];
	t_count	count;
}	t_data;

void	count_methods(t_data *data);
void	print_cli(t_data *data);
int		init_cli(t_data *data, int argc, char *argv[]);
int		check_arguments(t_data *data, int argc, char *argv[]);

#endif