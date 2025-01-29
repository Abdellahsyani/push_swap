/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:34:24 by asyani            #+#    #+#             */
/*   Updated: 2024/12/02 15:17:55 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char **static_str);
size_t	ft_strlen(char *str);
void	ft_strcat(char *concat, char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif
