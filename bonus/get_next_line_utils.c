/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:37:29 by asyani            #+#    #+#             */
/*   Updated: 2024/12/02 15:16:46 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * ft_strlen - the fucntion to get length of strings
 * @str: the string that we want to get length
 *
 * return: the length of string
 */

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

/**
 * ft_strcat - the function to concat two strings
 * @dest: the first string and the dest that will concat two str
 * @src: the second string
 *
 * return: the concat of these two strings
 */

void	ft_strcat(char *concat, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
}

/**
 * ft_strchr - the function that search for a character
 * @str: string that we will look on it
 * @c: the character that we look for
 *
 * return: on success_ -from the begining to the char on failure_ -NULL
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i + 1);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

/**
 * ft_strdup - the function to duplicat the string
 * @s: the string that we want to duplicate
 *
 * return: the dup string
 */
char	*ft_strdup(char *s)
{
	size_t	i;
	char	*dup;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	dup = malloc(sizeof(char) * s_len + 1);
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/**
 * ft_strncpy - function to copy from src to dest beased on n
 * @dest: the destination buffer
 * @src: the src that we want to  copy
 * @n: the size that we want to copy
 *
 * return: the copied string
 */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
