/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:02:39 by redrouic          #+#    #+#             */
/*   Updated: 2024/05/27 16:38:37 by redrouic         ###   ########.fr       */
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
/*
void	move2a(t_stack **astack, t_stack **bstack, int len)
{
	int	mid;
	int	size;
	int	i;

	i = 0;
	(void)bstack;
	mid = midpoint(*astack, len);
	size = len;
	return ;
	while (size > 2)
	{
		if ((*astack)->data > mid)
		{
			push(astack, bstack, 'a');
			i++;
		}
		else if ((*astack)->data <= mid && is_biggest(*astack, mid, size))
			rev_rotate(astack, 'b');
		else if ((*astack)->data <= mid)
			rotate(astack, 'b');
		if (i == size / 2)
		{
			size = size - i;
			i = 0;
			mid = midpoint(*astack, size);
		}
	}
}
*/

void	algo(int ac, char **arr)
{
	t_stack	*astack;
	t_stack	*bstack;
	int		*test;
	int		mid;

	(void)mid;
	astack = NULL;
	bstack = NULL;
	astack = init_astack(ac, arr);
	if (is_sorted(astack))
	{
		ft_putstr("OK\n");
		return ;
	}
	move2b(&astack, &bstack);
	if (!is_sorted(astack))
		rotate(&astack, 'a');
	test = chunk(ac); 
	test++;
	while (*test)
	{
		if (*test == 1)
		{
			push(&bstack, &astack, 'a');
			printf("we we \n");
			test++;
			continue ;
		}
		if (*test == 2)
		{
			chunk_of_two(&bstack, &astack);
			test++;
			continue ;
		}
		if (*test > 2)
		{
			//mid = midpoint(bstack, *test);
			printf("test : %d\n", *test);
			ft_putstr("==bstack==\n");
			print_stack(bstack);
			ft_putstr("==astack==\n");
			print_stack(astack);
			//move2a(&bstack, &astack, *test);
			//chunk_of_two(&bstack, &astack);
			//test++;
			//continue ;
			return ;
		}
	}
	ft_putstr("astack\n");
	print_stack(astack);
	ft_putstr("bstack\n");
	print_stack(bstack);
	return ;
}
