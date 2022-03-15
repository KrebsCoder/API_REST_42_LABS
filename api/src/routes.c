/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:51:11 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/27 12:20:30 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/api.h"

void	check_route(struct mg_connection *c, struct mg_http_message *request)
{
	char	*str;

	if (mg_http_match_uri(request, "/cartoon"))
	{
		log_message(LOG_PATH, request, 200);
		str = retrieve();
		reply(c, 200, str, NULL);
		free(str);
	}
	else if (mg_http_match_uri(request, "/"))
	{
		log_message(LOG_PATH, request, 200);
		reply(c, 200, "{\"result:\": %s}", "\"home\"");
	}
	else
	{
		log_message(LOG_PATH, request, 400);
		reply(c, 404, "{\"error:\": %s}", "\"Bad Request\"");
	}
}
