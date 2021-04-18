/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:16:52 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/16 23:01:32 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

int		return_handler(int nread);
size_t	ft_strlen_and_cntrl(char const *s1);
char	*ft_strjoin_and_cntrl(char *s1, char const *s2);
char	*get_remaining_string(char *readstr, char **line);
int		get_next_line(int fd, char **line);

#endif
