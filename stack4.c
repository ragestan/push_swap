/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:36:30 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/22 17:07:38 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_idk(t_stack **a, t_stack **b, int n, int middle)
{
	int	l;

	l = sizestack(*a);
	if (n <= l / 2)
	{
		while (n > 0)
		{
			ft_rab(a, 1);
			n--;
		}
		ft_pab(b, a, 2);
	}
	else
	{
		while (n <= l)
		{
			ft_rrab(a, 1);
			n++;
		}
		ft_pab(b, a, 2);
	}
	ft_checkb(b, middle);
}

void	ft_idk2(t_stack **a, t_stack **b, size_t n, size_t l)
{
	int	i;

	i = 0;
	l = sizestack(*b);
	n = ft_find(*b);
	if (n <= sizestack(*b) / 2 || n == 1)
	{
		while (n-- > 0)
			i += ft_heelp(a, b, l);
	}
	else
	{
		while (n++ <= sizestack(*b))
		{
			i += ft_heelp2(a, b, l, &n);
		}
	}
	ft_pab(a, b, 1);
	if (i)
		ft_sab(a, 1);
}

int	ft_heelp(t_stack **a, t_stack **b, size_t l)
{
	int	i;

	i = 0;
	if ((*b)->index == l)
	{
		ft_pab(a, b, 1);
		i++;
	}
	else
		ft_rab(b, 2);
	return (i);
}

int	ft_heelp2(t_stack **a, t_stack **b, size_t l, size_t *n)
{
	int	i;

	i = 0;
	if ((*b)->index == l)
	{
		ft_pab(a, b, 1);
		i++;
		*n -= 1;
	}
	ft_rrab(b, 0);
	return (i);
}

t_stack	*ft_makestack2(t_stack *a, long long content)
{
	t_stack	*next;

	if (content > INT_MAX || content < INT_MIN)
	{
		freestack(&a);
		ft_error();
	}
	next = ft_lst((int)content);
	ft_add_front(&a, next);
	return (a);
}
