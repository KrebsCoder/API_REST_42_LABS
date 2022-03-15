/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysql.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:44:05 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/27 10:43:11 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/api.h"

void	finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

char	*retrieve(void)
{
	MYSQL		*con;
	MYSQL_RES	*result;
	MYSQL_ROW	row;
	char		*str;
	char		*tmp;
	char		*aux;

	con = mysql_init(NULL);
	if (con == NULL)
	{
		fprintf(stderr, "mysql_init() failed\n");
		exit(1);
	}
	if (mysql_real_connect(con, getenv("DBHOST"), getenv("DBUSER"), getenv("DBPASS"),\
		getenv("DBNAME"), (unsigned int)atoi(getenv("DBPORT")), NULL, 0) == NULL)
		finish_with_error(con);

	if (mysql_query(con, "SELECT * FROM cartoons"))
		finish_with_error(con);

	result = mysql_store_result(con);
	if (result == NULL)
		finish_with_error(con);

	str = ft_strdup("");
	while ((row = mysql_fetch_row(result)))
	{
		if (row != NULL)
		{
			tmp = str;
			str = ft_strjoin(str, row[0]);
			aux = str;
			str = ft_strjoin(str, ",");
			free(aux);
			free(tmp);
		}
		else
			str = NULL;
	}
	mysql_library_end();
	mysql_free_result(result);
	mysql_close(con);
	return (str);
}
