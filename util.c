/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:22:44 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/22 12:20:53 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

t_stack	*ft_lst(int content)
{
	t_stack	*l;

	l = malloc(sizeof(t_stack));
	if (!l)
		return (0);
	else
	{
		l->index = 0;
		l->content = content;
		l->next = NULL;
		return (l);
	}
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (lst)
	{
		if (*lst)
		{
			ptr = ft_lstlast(*lst);
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_strcmp(int i, int j)
{
	if (i < j)
	{
		return (-1);
	}
	else if (i > j)
	{
		return (1);
	}
	else
		return (0);
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long	c;
	int			i;

	i = 1;
	c = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			i = -i;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		c = c * 10 + *str++ - '0';
		if (c * i > 2147483647)
			return (2147483648);
		if (c * i < -2147483648)
			return (-2147483649);
	}
	c = c * i;
	i = c;
	return (i);
}
