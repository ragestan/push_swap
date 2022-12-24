/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:17:10 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/21 18:45:57 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	sizestack(t_stack *a)
{
	size_t	i;

	i = 0;
	while (a->next)
	{
		a = a->next;
		i++;
	}
	return (i);
}

size_t	ft_9lab(t_stack *a, size_t start, size_t end)
{
	int	i;
	int	k;

	k = 0;
	i = sizestack(a);
	while (a->next)
	{
		if (a->index <= end && a->index >= start)
			break ;
		k++;
		a = a->next;
	}
	return (k);
}

void	ft_state(int *start, int *end, int offset, int l)
{
	*start -= offset;
	if (*start < 0)
		*start = 0;
	*end += offset;
	if (*end > l + 1)
		*end = l + 1;
}

void	ft_checkb(t_stack **b, size_t middle)
{
	if ((*b)->next && (*b)->index <= middle)
		ft_rab(b, 2);
}

int	ft_find(t_stack *a)
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
		while (a->next != NULL && ft_strcmp(j, a->next->content) == 1)
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
