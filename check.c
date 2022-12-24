/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:11:21 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/24 00:13:48 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	check_digit(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		ft_check(ft_split(av[i--], ' '), 0);
	}
}

void	ft_check(char **av, int j)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	i--;
	while (i >= 0)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (j && !av[i][j])
			ft_error();
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				ft_error();
			j++;
		}
		i--;
	}
	ft_free(av);
}

void	freestack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	while ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		free(temp);
		temp = *stack;
	}
}

void	ft_checkdouble(t_stack **a)
{
	t_stack	*temp;
	t_stack	*save;

	save = *a;
	while ((*a))
	{
		temp = (*a)->next;
		while (temp)
		{
			if ((*a)->content != temp->content)
			{
				temp = temp->next;
			}
			else if ((*a) && temp)
			{
				freestack(a);
				ft_error();
			}
		}
		(*a) = (*a)->next;
	}
	*a = save;
}
