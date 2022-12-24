/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:28:09 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/24 22:32:32 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*tmp;

	b = NULL;
	a = ft_makestack(ac, av);
	tmp = NULL;
	if (ac == 1)
		return (0);
	tmp = get_next_line(0);
	while (tmp)
	{
		ft_cheker(tmp, &a, &b);
		free(tmp);
		tmp = get_next_line(0);
		ac--;
	}
	free(tmp);
	if (ft_doublecheck(a) == 1 && b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	freestack(&a);
	freestack(&b);
	return (0);
}

void	ft_cheker(char *tmp, t_stack **a, t_stack **b)
{
	if (ft_strchekercmp(tmp, "sa\n") == 0)
		ft_sab(a, 0);
	else if (ft_strchekercmp(tmp, "sb\n") == 0)
		ft_sab(b, 0);
	else if (ft_strchekercmp(tmp, "ss\n") == 0)
		ft_ss(a, b, 0);
	else if (ft_strchekercmp(tmp, "pa\n") == 0)
		ft_pab(a, b, 0);
	else if (ft_strchekercmp(tmp, "pb\n") == 0)
		ft_pab(b, a, 0);
	else if (ft_strchekercmp(tmp, "ra\n") == 0)
		ft_rab(a, 0);
	else if (ft_strchekercmp(tmp, "rb\n") == 0)
		ft_rab(b, 0);
	else if (ft_strchekercmp(tmp, "rr\n") == 0)
		ft_rr(a, b, 0);
	else if (ft_strchekercmp(tmp, "rra\n") == 0)
		ft_rrab(a, 2);
	else if (ft_strchekercmp(tmp, "rrb\n") == 0)
		ft_rrab(b, 2);
	else if (ft_strchekercmp(tmp, "rr\n") == 0)
		ft_rr(a, b, 2);
	else
		ft_404(tmp, a, b);
}

void	ft_404(char *tmp, t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	free(tmp);
	freestack(a);
	freestack(b);
	exit(1);
}

int	ft_strchekercmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
		{
			return (-1);
		}
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
