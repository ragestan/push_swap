/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:23:18 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/21 13:33:34 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findb(t_stack *a)
{
	int	i;
	int	j;
	int	k;
	int	f;

	k = 0;
	while (a->next)
	{
		j = a->content;
		i = 0;
		while (a->next != NULL && ft_strcmp(j, a->next->content) == 1)
		{
			a = a->next;
			i++;
		}
		i++;
		if (a != NULL && a->next != NULL)
		{
			f = k;
			k = k + i;
			a = a->next;
		}
	}
	return (f);
}

t_stack	*ft_all(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	if (a->next->next == NULL)
	{
		ft_sab(&a, 1);
		return (a);
	}
	while (a->next->next->next)
	{
		j = ft_number(a);
		i = ft_sir(a);
		if (i <= j / 2)
			while (i--)
				ft_rab(&a, 1);
		else
			while (i++ < j)
				ft_rrab(&a, 1);
		ft_pab(&b, &a, 2);
	}
	a = ft_three(a);
	while (b)
		ft_pab(&a, &b, 1);
	return (a);
}

int	ft_sir(t_stack *a)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = 0;
	while (a->next)
	{
		j = a->content;
		i = 0;
		while (a->next != NULL && ft_strcmp(j, a->next->content) == -1)
		{
			a = a->next;
			i++;
		}
		i++;
		if (a != NULL && a->next != NULL)
		{
			k = k + i;
			a = a->next;
		}
	}
	return (k);
}

int	ft_number(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_mine(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
