/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:02:39 by redrouic          #+#    #+#             */
/*   Updated: 2024/05/31 15:54:37 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"
#include <stdio.h>
		
void	chunk_of_two(t_stack **astack, t_stack **bstack)
{
	if ((*bstack)->data < (*bstack)->next->data)
		swap(bstack, 'b');
	push(bstack, astack, 'a');
	push(bstack, astack, 'a');
}

int size_chunk(int len)
{
	int	size;
	int	i;

	i = 1;
	size = len / 2;
	while (size != 1)
	{
		size /= 2;
		i++;
	}
	return (i);
}

int	*chunk(int len)
{
	int *arr;
	int i;

	i = size_chunk(len);
	arr = malloc(sizeof(int) * (i + 1));
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

int	is_biggest(t_stack *stack, int mid, int len)
{
	t_stack	*tmp;
	int	i;

	tmp = stack;
	i = 0;
	while (i < len)
	{
		if (tmp->data < mid)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	is_desorted(t_stack *stack, int len)
{
	t_stack	*tmp;
	int	i;

	i = 0;
	tmp = stack;
	while (i < len)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	move2a(t_stack **astack, t_stack **bstack, int len)
{
	int	mid;
	int	size;
	int	i;
	int	rrb;
	int	u;

	i = 0;
	rrb = 0;
	mid = midpoint(*bstack, len);
	size = len;
	u = 0;
	while (size > 2)
	{
		if ((*bstack)->data > mid)
		{
			push(bstack, astack, 'a');
			i++;
		}
		else if ((*bstack)->data <= mid && is_biggest(*bstack, mid, size))
			rev_rotate(bstack, 'b');
		else if ((*bstack)->data <= mid)
		{
			rotate(bstack, 'b');
			rrb++;
		}
		if (i >= (size / 2) - 1)
		{
			size = size - i;
			i = 0;
			if (is_desorted(*bstack, size))
			{
				while (u < size)	
				{
					u++;
					push(bstack, astack, 'a');
				}
				u = 0;
			}
			else
				mid = midpoint(*bstack, size);
		}
	}
	while (rrb > 0)
	{
		rev_rotate(bstack, 'b');
		rrb--;
	}
}

void	algo(int ac, char **arr)
{
	t_stack	*astack;
	t_stack	*bstack;
	int		*test;
	int		i;

	i = 1;
	astack = NULL;
	bstack = NULL;
	astack = init_astack(ac, arr);
	if (is_sorted(astack))
		return ;
	move2b(&astack, &bstack);
	if (!is_sorted(astack))
		rotate(&astack, 'a');
	test = chunk(ac); 
	if (!test)
		return ;
	while (i <= size_chunk(ac))
	{
		if (test[i] == 1)
		{
			push(&bstack, &astack, 'a');
			i++;
			continue ;
		}
		if (test[i] == 2)
		{
			chunk_of_two(&astack, &bstack);
			i++;
			continue ;
		}
		if (test[i] > 2)
		{
			move2a(&astack, &bstack, test[i]);
			chunk_of_two(&astack, &bstack);
			i++;
			continue ;
		}
	}
	return ;
}
