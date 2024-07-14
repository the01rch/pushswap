/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:02:39 by redrouic          #+#    #+#             */
/*   Updated: 2024/07/10 17:45:03 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

void	move2a(t_stack **astack, t_stack **bstack, int len)
{
	int	mid;
	int	size;
	int	rrb;
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	rrb = 0;
	size = len;
	if (size > 2)
		mid = midpoint(*bstack, len);
	while (size > 2)
	{
		if ((*bstack)->data > mid)
		{
			push(bstack, astack, 'a');
			if ((*astack)->data > (*astack)->next->data)
				swap(astack, 'a');
			i++;
			cnt++;
		}
		else if ((*bstack)->data <= mid)
		{
			rotate(bstack, 'b');
			rrb++;
			cnt++;
		}
		if (cnt == size)
		{
			while (rrb > 0)
			{
				rev_rotate(bstack, 'b');
				rrb--;
			}
			cnt = 0;
			rrb = 0;
			size -= i;
			i = 0;
			if (size > 2)
				mid = midpoint(*bstack, size);
		}
	}
}
