/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:41:58 by asyani            #+#    #+#             */
/*   Updated: 2025/01/11 10:01:27 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * count_words _ teh function to count how many word we have in the array
 * @str: the array that we want
 * @set: the delimeter to count
 *
 * return: how many word we have
 */
static int	count_words(const char *str, char set)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != set && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == set)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

/**
 * ft_fillstr _ function to fill the main array by strings
 * @s: the strings that we want to fill
 * @len: the size of the array
 *
 * return: dup array filled
 */
static char	*ft_fillstr(const char *s, int len)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

/**
 * ft_free _ function to free array
 * @dups: array to free
 * @i: the size of array
 *
 * return: NULL
 */
static	void	*ft_free(char **dups, int i)
{
	if (!dups)
		return (NULL);
	while (i > 0)
	{
		if (dups[i - 1])
			free(dups[i - 1]);
		i--;
	}
	free(dups);
	return (NULL);
}

/**
 * super_split _ helper fucntion to handle parsing
 * @dup: the full line that we parse
 * @s: the strings inside the line
 * @c: the delimeter
 * @strings_s: the size of line
 *
 * return: line parsed
 */
static char	**super_split(char **dups, char const *s, char c, int strings_s)
{
	int	start;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < strings_s)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		dups[i] = ft_fillstr(s + start, j - start);
		if (dups[i] == NULL)
			return (ft_free(dups, i));
		i++;
	}
	dups[i] = NULL;
	return (dups);
}

/**
 * ft_split _ the function that parse line
 * @s: the line that we want to parse
 * @c: delimeter to parse line
 *
 * return: the line parsing
 */
char	**ft_split(char const *s, char c)
{
	int		strings_s;
	char	**dups;

	if (s == NULL)
		return (NULL);
	strings_s = count_words(s, c);
	dups = malloc(sizeof(char *) * (strings_s + 1));
	if (!dups)
	{
		return (NULL);
	}
	return (super_split(dups, s, c, strings_s));
}
