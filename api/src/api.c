/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:53:58 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/27 12:49:58 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/api.h"

t_api	g_api;

static void	api(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
	struct mg_http_message	*request = (struct mg_http_message *) ev_data;

	if (ev == MG_EV_HTTP_MSG)
	{
		if (check_method(request->method.ptr))
		{
			check_route(c, request);
		}
		else
		{
			reply(c, 501, "{\"error\": %s}", "\"Method not implemented\"");
			log_message(LOG_PATH, request, 501);
		}
	}
	(void)fn_data;
}

int	main(void)
{
	struct mg_mgr	mgr;
	g_api.signal = 0;
	signal(SIGINT, sigint);
	open_log();
	mg_mgr_init(&mgr);
	mg_http_listen(&mgr, HOST_HTTP, api, NULL);
	//mg_http_listen(&mgr, HOST_HTTPS, api, (void *) 1);
	while (!g_api.signal)
		mg_mgr_poll(&mgr, 1000);
	mg_mgr_free(&mgr);
	return (EXIT_SUCCESS);
}
