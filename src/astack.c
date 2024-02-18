/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:55:44 by redrouic          #+#    #+#             */
/*   Updated: 2024/02/18 01:26:32 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/pushswap.h"

t_stack	*init_astack(int ac, char **av)
{
	t_stack	*astack;
	t_stack	*tmp;
	int		i;

	i = ac - 1;
	astack = NULL;
	while (i > 0)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->data = ft_atoi(av[i]);
		tmp->next = astack;
		astack = tmp;
		i--;
	}
	return (astack);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putstr("data: ");
		ft_putnbr(stack->data);
		ft_putchar('\n');
		stack = stack->next;
	}
}	

void	sa(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
	ft_putstr("sa\n");
}

void	pb(t_stack **astack, t_stack **bstack)
{
	t_stack	*tmp;

	if (*astack)
	{
		tmp = *astack;
		*astack = (*astack)->next;
		tmp->next = *bstack;
		*bstack = tmp;
	}
	ft_putstr("pb\n");
}

void	ra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp2->next)
			tmp2 = tmp2->next;
		*stack = tmp->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
	ft_putstr("ra\n");
}

void	rra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp2->next->next = tmp;
		*stack = tmp2->next;
		tmp2->next = NULL;
	}
	ft_putstr("rra\n");
}

int		is_smallest(t_stack *stack, int value)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->data < value)
		return (1);
	return (0);
}

int		is_sorted(t_stack *stack)
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

void sort_a(t_stack **astack)
{
    t_stack *ptr;
	int smallest;

    if (*astack == NULL || (*astack)->next == NULL)
        return;
    smallest = (*astack)->data;
    ptr = *astack;
    while (ptr != NULL)
    {
        if (ptr->data < smallest)
            smallest = ptr->data;
        ptr = ptr->next;
    }
    while ((*astack)->data != smallest)
    {
        if ((*astack)->next->data == smallest)
            ra(astack);
        else
            rra(astack);
    }
    if ((*astack)->data > (*astack)->next->data)
        sa(astack);
}

void move2b(t_stack *astack, t_stack *bstack)
{
	int	mid;
	int	len;
	int i;

	mid = midpoint(astack);
	i = 0;
	ft_putstr("midpoint = ");
	ft_putnbr(mid);
	ft_putchar('\n');
	len = stack_len(astack);
	while (1)
	{
		ft_putstr("\n======\n");
		ft_putstr("\nbstack=\n");
		print_stack(bstack);
		ft_putstr("\nastack=\n");
		print_stack(astack);
		if (len == 3 || len == 0)
			break ;
		if (astack->data < mid)
		{
			pb(&astack, &bstack);
			i++;
		} 
		else if (astack->data >= mid && is_smallest(astack, mid))
			rra(&astack);
		else if (astack->data >= mid)
			ra(&astack);
		if (i == len / 2)
		{
			i = 0;
			mid = midpoint(astack);
			ft_putstr("midpoint = ");
			ft_putnbr(mid);
			ft_putchar('\n');
			len = stack_len(astack);
		}
		//sleep(1);
		ft_putstr("\n======\n");
	}
	sort_a(&astack);
	ft_putstr("\nastack=\n");
	print_stack(astack);
}
