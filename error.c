/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:16:10 by asyani            #+#    #+#             */
/*   Updated: 2025/02/01 09:18:30 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_perror(char **dup)
{
	ft_putstr("Error\n");
	free_split_result(dup);
	exit(1);
}

void	ft_error(char *str)
{
	free(str);
	write(2, "Error\n", 6);
	exit(1);
}
