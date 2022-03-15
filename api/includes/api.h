/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:57:15 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/26 22:32:05 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_H
# define API_H
# include "../mongoose/mongoose.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include <string.h>
# include <signal.h>
# include <mysql/mysql.h>
# include <stdio.h>
# include <stdlib.h>

# define HOST_HTTP "0.0.0.0:8000"
# define HOST_HTTPS "0.0.0.0:8443"
# define LOG_PATH "logs/log.log"
# define FALSE 0
# define TRUE 1

typedef struct s_api
{
	int		signal;
}	t_api;

extern t_api	g_api;

// reply with http message
void	reply(struct mg_connection *c, int status_code, char *reply1, char *reply2);

// open log, opens the log file
void	open_log(void);

// log message is responsible for printing all logs on the log file.
void	log_message(const char *filename, struct mg_http_message *request, int status);

// retrives json from mysql database
char	*retrieve(void);

// checks the routes and reply with the accordingly response
void	check_route(struct mg_connection *c, struct mg_http_message *request);

// handles ctrl + c signal
void	sigint(int signum);

// check if method is get
int		check_method(const char *ptr);

// -----LIBFT FUNCTIONS-----

// calculateS the length of a string.
size_t	ft_strlen(const char *string);

//  concatenates two strings.
char	*ft_strjoin(char const *s1, char const *s2);

// creates a duplicate for the string passed as a parameter.
char	*ft_strdup(const char *src);

#endif