/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:02:39 by redrouic          #+#    #+#             */
/*   Updated: 2024/04/05 20:27:57 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"
#include <stdio.h>
		
int	*chunk(int len)
{
	int *arr;
	int size;
	int i;

	i = 1;
	size = len / 2;
	while (size != 1)
	{
		size /= 2;
		i++;
	}
	arr = malloc(sizeof(int) * i);
	if (!arr)
		return (0);
	while (i >= 0)
	{
		arr[i] = len / 2;
		len /= 2;
		i--;
	}
	return (arr);
}

/*
int	is_biggest(t_stack *stack, int mid)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data < mid)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	move2a(t_stack **astack, t_stack **bstack)
{
	int	mid;
	int	len;
	int	i;

	i = 0;
	mid = midpoint(*astack);
	len = stack_len(*astack);
	while (len > 2)
	{
		if ((*astack)->data > mid)
		{
			pa(astack, bstack);
			i++;
		}
		else if ((*astack)->data <= mid && is_biggest(*astack, mid))
			rrb(astack);
		else if ((*astack)->data <= mid)
			rb(astack);
		if (i == len / 2)
		{
			i = 0;
			mid = midpoint(*astack);
			len = stack_len(*astack);
		}
	}
}
*/
