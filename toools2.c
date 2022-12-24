/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toools2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:34:34 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/23 14:51:23 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack **a, t_stack **b, int i)
{
	ft_rrab(a, 2);
	ft_rrab(b, 2);
	if (i == 1)
		ft_putstr_fd("rrr\n", 1);
}

void	ft_rr(t_stack **a, t_stack **b, int i)
{
	ft_rab(a, 0);
	ft_rab(b, 0);
	if (i == 1)
		ft_putstr_fd("rr\n", 1);
}
