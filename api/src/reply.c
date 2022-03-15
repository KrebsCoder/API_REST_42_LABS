/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:26:12 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/26 03:51:35 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/api.h"

void	reply(struct mg_connection *c, int status_code, char *reply1, char *reply2)
{
	if (reply2 == NULL)
	{
		mg_http_reply(c, status_code, "Content-Type: application/json\n\
Connection: closed\r\nAllow: GET\r\n", reply1);
	}
	else
	{
	mg_http_reply(c, status_code,  "Content-Type: application/json\n\
Connection: closed\r\nAllow: GET\r\n", reply1, reply2);
	}
}
