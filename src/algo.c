/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:46:10 by redrouic          #+#    #+#             */
/*   Updated: 2024/07/12 16:07:27 by redrouic         ###   ########.fr       */
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

int	size_chunk(int len)
{
	int	size;
	int	sum;
	int	i;

	size = len;
	sum = 0;
	i = 0;
	while (sum != len - 2)
	{
		size /= 2; 
		sum += size;
		if (size == 0)
			sum++;
		i++;
	}
	return (i);
}

int	*chunk(int ac)
{
	int	*arr;
	int	csize;
	int	size;
	int	i;
	
	i = 0;
	size = ac;
	csize = size_chunk(ac);
	arr = malloc(sizeof(int) * size);
	while (i < csize)
	{
		size /= 2;
		arr[i] = size;
		if (size == 0)
			arr[i] = 1;
		i++;
	}
	return (arr);
}

void	print_stack(t_stack **astack)
{
	t_stack	*tmp;

	tmp = *astack;
	while (tmp)
	{
		ft_putstr("data = ");
		ft_putnbr(tmp->data);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void	print_array(int *arr, int ac)
{
	int	i;

	i = size_chunk(ac) - 1;
	while (i > -1)
	{
		ft_putstr("arr[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(arr[i]);
		ft_putchar('\n');
		i--;
	}
}

int gest_ones(t_stack **astack, t_stack **bstack, int *chunk, int ac)
{
	int size;
	int i;
	int cnt;

	size = size_chunk(ac);
	cnt = 0;
	i = 0;
	while (i < size)
	{
		if (chunk[i] == 1)
			cnt++;
		i++;
	}
	if (cnt > 2)
	{
		move2a(astack, bstack, cnt);
		chunk_of_two(astack, bstack);
		return (cnt);
	}
	else
	{
		push(bstack, astack, 'a');
		if (!is_sorted((*astack), stack_len((*astack))))
			swap(astack, 'a');
		if ((*bstack)->data > (*astack)->data)
		{
			push(bstack, astack, 'a');
			swap(astack, 'a');
			push(astack, bstack, 'b');
		}
		if (!is_sorted((*astack), stack_len((*astack))))
			swap(astack, 'a');
		return (1);
	}
}

void	chunk_loop(int ac, int *test, t_stack **astack, t_stack **bstack)
{
	int	i;
	int	cnt;

	i = size_chunk(ac) - 1;
	while (i > -1)
	{
		if (test[i] == 1)
		{
			i -= gest_ones(astack, bstack, test, ac);
			if ((*bstack)->data > (*astack)->data)
			{
				push(bstack, astack, 'a');
				swap(astack, 'a');
				push(astack, bstack, 'b');
			}
			if (!is_sorted((*astack), stack_len((*astack))))
				swap(astack, 'a');
			continue ;
		}
		if (test[i] == 2)
		{
			chunk_of_two(astack, bstack);
			if ((*bstack)->data > (*astack)->data)
			{
				push(bstack, astack, 'a');
				swap(astack, 'a');
				push(astack, bstack, 'b');
			}
			if (!is_sorted((*astack), 3))
			{
				cnt = move2b(astack, bstack, 3);
				while (cnt > 0)
				{
					rev_rotate(astack, 'a');
					cnt--;
				}
				cnt = 0;
				push(astack, bstack, 'b');
				push(astack, bstack, 'b');
				if (is_sorted((*bstack), 1))
					swap(bstack, 'b');
				push(bstack, astack, 'a');
				if (is_sorted((*bstack), 2))
					swap(bstack, 'b');
				push(bstack, astack, 'a');
				push(bstack, astack, 'a');
			}
			i--;
			continue ;
		}
		if (test[i] > 2)
		{
			move2a(astack, bstack, test[i]);
			chunk_of_two(astack, bstack);
			if (!is_sorted((*astack), test[i]))
			{
				cnt = move2b(astack, bstack, test[i]);
				while (cnt > 0)
				{
					rev_rotate(astack, 'a');
					cnt--;
				}
				push(astack, bstack, 'b');
				push(astack, bstack, 'b');
				cnt = 0;
				move2a(astack, bstack, test[i]);
				chunk_of_two(astack, bstack);
			}
			i--;
		}
	}
}

void	algo(int ac, t_stack **astack, t_stack **bstack)
{
	int		*test;

	if (is_sorted((*astack), stack_len(*astack)) || !(*astack))
	{
		free_stack(astack);
		return ;
	}
	test = chunk(ac);
	if (!test)
		return ;
	move2b(astack, bstack, stack_len(*astack));
	if (!is_sorted((*astack), stack_len(*astack)))
		rotate(astack, 'a');
	if (ac == 2)
		return ;
	chunk_loop(ac, test, astack, bstack);
	//print_array(test, ac);
	//printf("\nastack\n");
	//print_stack(astack);
	//printf("\nbstack\n");
	//print_stack(bstack);
	if (!is_sorted(*astack, stack_len(*astack)))
		algo(ac, astack, bstack);
	free(test);
	free_stack(astack);
	free_stack(bstack);
}
