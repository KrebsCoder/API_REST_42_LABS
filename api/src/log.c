/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:33:39 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/25 18:42:00 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/api.h"

void	log_message(const char *filename, struct mg_http_message *request, int status)
{
	FILE	*fp;
	time_t	curtime;

	time(&curtime);
	fp = fopen(filename, "a");
	if (fp != NULL)
	{
		fprintf(fp, "%.*s ", (int)request->method.len, request->method.ptr);
		fprintf(fp, "%.*s ", (int)request->uri.len, request->uri.ptr);
		fprintf(fp, "%d ", status);
		fprintf(fp, "%s", ctime(&curtime));
		fclose(fp);
	}
}

void	open_log(void)
{
	int	log_client;

	log_client = open(LOG_PATH, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (log_client == -1)
	{
		dprintf(2, "ERROR: No log file on log directory\n");
		exit (1);
	}
}
