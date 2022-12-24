/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:37:18 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/23 22:16:34 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_makestack(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		j;
	char	**tmp;

	j = 0;
	i = ac - 1;
	check_digit(ac, av);
	a = NULL;
	while (i > 0)
	{
		j = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[j])
			j++;
		if (j == 0)
			ft_error();
		j--;
		while (j >= 0)
			a = ft_makestack2(a, ft_atoi(tmp[j--]));
		i--;
		ft_free(tmp);
	}
	ft_checkdouble(&a);
	return (a);
}

t_stack	*ft_index(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;
	int		j;

	j = 0;
	tmp = a;
	i = ft_mine(tmp);
	while (j++ < i)
	{
		tmp = a;
		while (tmp->index != 0)
			tmp = tmp->next;
		tmp2 = tmp;
		while (tmp->next)
		{
			if (tmp2->content > tmp->next->content && tmp->next->index == 0)
				tmp2 = tmp->next;
			tmp = tmp->next;
		}
		tmp2->index = j;
	}
	return (a);
}

t_stack	*ft_stackhandler(t_stack *a, t_stack *b)
{
	size_t	i;

	i = sizestack(a) + 1;
	if (i == 1)
		ft_sab(&a, 1);
	else if (i == 3)
		a = ft_three(a);
	else if (i <= 9)
		a = ft_all(a, b);
	else if (i < 150)
		a = ft_smallstack(a, b, i / 2, i / 8);
	else
		a = ft_smallstack(a, b, i / 2, i / 18);
	return (a);
}

t_stack	*ft_three(t_stack *a)
{
	int	i;
	int	j;
	int	k;

	i = a->content;
	j = a->next->content;
	k = a->next->next->content;
	if (ft_strcmp(i, j) == -1 && ft_strcmp(j, k) == 1 && ft_strcmp(k, i) == 1)
	{
		ft_sab(&a, 1);
		ft_rab(&a, 1);
	}
	if (ft_strcmp(i, j) == 1 && ft_strcmp(j, k) == -1 && ft_strcmp(k, i) == 1)
		ft_sab(&a, 1);
	if (ft_strcmp(i, j) == 1 && ft_strcmp(j, k) == -1 && ft_strcmp(k, i) == -1)
		ft_rab(&a, 1);
	if (ft_strcmp(i, j) == 1 && ft_strcmp(j, k) == 1 && ft_strcmp(k, i) == -1)
	{
		ft_sab(&a, 1);
		ft_rrab(&a, 1);
	}
	if (ft_strcmp(i, j) == -1 && ft_strcmp(j, k) == 1 && ft_strcmp(k, i) == -1)
		ft_rrab(&a, 1);
	return (a);
}

t_stack	*ft_smallstack(t_stack *a, t_stack *b, int middle, int offset)
{
	int		start;
	int		end;
	int		l;
	size_t	n;

	l = sizestack(a);
	start = middle - offset;
	end = middle + offset;
	while (a)
	{
		n = ft_9lab(a, start, end);
		if (n == sizestack(a))
		{
			ft_state(&start, &end, offset, l);
			if (n != 0)
				continue ;
		}
		ft_idk(&a, &b, n, middle);
	}
	while (b)
		ft_idk2(&a, &b, n, l);
	return (a);
}
