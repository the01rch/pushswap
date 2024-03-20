/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:25:21 by redrouic          #+#    #+#             */
/*   Updated: 2024/03/17 16:38:45 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9' || c == '+' || c == '-')
		return (1);
	return (0);
}

int count_rows(char *str)
{
	int	rows;

	rows = 0;
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str == ' ' && is_digit(*str + 1))
			rows++;
		str++;
	}
	return (rows + 1);
}

int	*count_cols(char *str)
{
	int	*cols;
	int	rows;

	rows = count_rows(str);
	cols = malloc(sizeof(int) * rows);
	if (!cols)
		return (0);
	while ()
	
}

char **str2tab(char *str)
{
	int		rows;
	char	**arr;
	int		x;
	int		y;

	rows = count_rows(str);
	arr = malloc(sizeof(char *) * (rows + 1));
	if (!arr)
		return (0);
	x = 0;
	y = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			x++;
		if (x > 0)
		{
			arr[y] = malloc(sizeof(char) * (x + 1));	
			if (!arr[y])
				return (0);
		}
		str++;
	}
	return (arr);
}
