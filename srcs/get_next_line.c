/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:15:33 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/16 00:44:34 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	return_handler(int nread)
{
	if (nread == 0)
		return (0);
	return (1);
}

size_t	ft_strlen_and_cntrl(char const *s1)
{
	if (!s1)
		return (0);
	return (ft_strlen(s1));
}

char	*ft_strjoin_and_cntrl(char *s1, char const *s2)
{
	char	*del;
	char	*ret;

	if (!s1)
		return (ft_strdup(s2));
	del = s1;
	ret = ft_strjoin(s1, s2);
	free(del);
	return (ret);
}

char	*get_remaining_string(char *readstr, char **line)
{
	int		pos;
	char	*del;

	pos = ft_memchr_pos(readstr, '\n', ft_strlen(readstr));
	del = readstr;
	if (pos >= 0)
	{
		*line = ft_substr(readstr, 0, pos);
		readstr = ft_substr(readstr, pos + 1, ft_strlen(readstr) - pos);
		if (del)
			free(del);
	}
	else
		*line = readstr;
	return (readstr);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*readstr;
	int				nread;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = ft_strnew(BUFFER_SIZE);
	if (!buff)
		return (-1);
	nread = 1;
	while (!ft_memchr(readstr, '\n', ft_strlen_and_cntrl(readstr)) && nread)
	{
		nread = read(fd, buff, BUFFER_SIZE);
		if (nread == -1)
		{
			free(buff);
			return (-1);
		}
		buff[nread] = '\0';
		readstr = ft_strjoin_and_cntrl(readstr, buff);
	}
	free(buff);
	readstr = get_remaining_string(readstr, line);
	return (return_handler(nread));
}
