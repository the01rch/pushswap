/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:55:44 by redrouic          #+#    #+#             */
/*   Updated: 2024/05/27 14:22:38 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

t_stack	*init_astack(int ac, char **av)
{
	t_stack	*astack;
	t_stack	*tmp;
	int		i;
	int		*error;

	error = 0;
	i = ac - 1;
	astack = NULL;
	while (i > -1)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->data = ft_atoi(av[i], error);
		tmp->next = astack;
		astack = tmp;
		i--;
	}
	return (astack);
}

int	is_smallest(t_stack *stack, int value)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->data < value)
		return (1);
	return (0);
}

#include <stdio.h>
void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		printf("%d-data: %d\n", i, stack->data);
		stack = stack->next;
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	move2b(t_stack **astack, t_stack **bstack)
{
	int	mid;
	int	len;
	int	i;

	i = 0;
	len = stack_len(*astack);
	mid = midpoint(*astack, len);
	while (len > 2)
	{
		if ((*astack)->data < mid)
		{
			push(astack, bstack, 'b');
			i++;
		}
		else if ((*astack)->data >= mid && is_smallest(*astack, mid))
			rev_rotate(astack, 'a');
		else if ((*astack)->data >= mid)
			rotate(astack, 'a');
		if (i == len / 2)
		{
			i = 0;
			len = stack_len(*astack);
			mid = midpoint(*astack, len);
		}
	}
}
