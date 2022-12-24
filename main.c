/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:01:41 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/23 18:47:05 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit(0);
	a = ft_makestack(ac, av);
	if (ft_doublecheck(a) == 1)
	{
		freestack(&a);
		exit(0);
	}
	a = ft_index(a);
	a = ft_stackhandler(a, b);
	freestack(&a);
	return (0);
}
