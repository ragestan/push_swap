/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:19:14 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/22 12:37:32 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_doublecheck(t_stack *next)
{
	while (next->next)
	{
		if (ft_strcmp(next->content, next->next->content) != -1)
			break ;
		next = next->next;
	}
	if (next->next == NULL)
		return (1);
	return (0);
}
