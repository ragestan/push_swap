/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toools.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:47:59 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/24 22:30:01 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sab(t_stack **a, int i)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!*a)
		return ;
	tmp1 = (*a)->next->next;
	tmp = *a;
	tmp = tmp->next;
	(*a)->next = NULL;
	tmp->next = *a;
	tmp->next->next = tmp1;
	(*a) = tmp;
	if (i == 1)
		ft_putstr_fd("sa\n", 1);
	else if (i == 2)
		ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **a, t_stack **b, int i)
{
	ft_sab(a, 2);
	ft_sab(b, 2);
	if (i == 1)
		ft_putstr_fd("ss\n", 1);
}

void	ft_pab(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	(*b) = tmp;
	if (i == 1)
		ft_putstr_fd("pa\n", 1);
	else if (i == 2)
		ft_putstr_fd("pb\n", 1);
}

void	ft_rab(t_stack **a, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	tmp2 = ft_lstlas(*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	if (i == 1)
		ft_putstr_fd("ra\n", 1);
	else if (i == 2)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rrab(t_stack **a, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	tmp2 = *a;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	(*a) = ft_lstlas(*a);
	(*a)->next = tmp;
	tmp2->next = NULL;
	if (i == 1)
		ft_putstr_fd("rra\n", 1);
	else if (i == 0)
		ft_putstr_fd("rrb\n", 1);
}
