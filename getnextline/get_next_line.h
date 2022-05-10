/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:32:52 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/05/06 14:08:52 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
int		ft_strchr_gnl(char *str, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_save_static(char *sta);
char	*ft_line(char *str);
char	*ft_read(int fd, char *sta);

#endif