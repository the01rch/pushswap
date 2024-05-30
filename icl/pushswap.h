/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:33:05 by redrouic          #+#    #+#             */
/*   Updated: 2024/05/29 14:46:05 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# define MAX_INT 2147483647
# define MAX_NEG -2147483648

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

int				ft_strlen(char *str);

long long int	ft_atoi(const char *nptr);

void			ft_putchar(char c);

void			ft_putnbr(int n);

void			print_stack(t_stack *stack);

int				midpoint(t_stack *stack, int len);

void			ft_putstr(char *str);

void			move2b(t_stack **astack, t_stack **bstack);

void			move2a(t_stack **astack, t_stack **bstack, int len);

int				stack_len(t_stack *stack);

void			swap(t_stack **stack, char c);

void			push(t_stack **stack1, t_stack **stack2, char c);

void			rotate(t_stack **stack, char c);

void			rev_rotate(t_stack **stack, char c);

int				is_sorted(t_stack *stack);

char			**str2arr(char *str);

int				count_rows(char *str);

int				is_format(char c);

void			print_stack(t_stack *stack);	

int				*chunk(int len);

void			algo(int ac, char **arr);

t_stack			*init_astack(int ac, char **av);

#endif
