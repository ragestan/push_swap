/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentalh <zbentalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:03:30 by zbentalh          #+#    #+#             */
/*   Updated: 2022/12/23 16:40:07 by zbentalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct a_list
{
	size_t			index;
	int				content;
	struct a_list	*next;
}					t_stack;
char				*get_next_line(int fd);
char				*line(char *str, int fd);
size_t				ft_strlen(char *a);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *str, int c);
char				*ft_line(char *str);
char				*mzl(char *src);
void				freestack(t_stack **stack);
t_stack				*ft_makestack2(t_stack *a, long long element);
void				ft_check(char **av, int j);
void				check_digit(int ac, char **av);
int					space(char *av);
char				**ft_split(char const *s, char c);
int					ft_isdigit(int c);
void				ft_error(void);
t_stack				*ft_lst(int content);
void				ft_add_front(t_stack **lst, t_stack *new);
t_stack				*ft_makestack(int ac, char **av);
int					ft_doublecheck(t_stack *next);
int					ft_strcmp(int i, int j);
long long			ft_atoi(const char *str);
int					rel7sab(char **av);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_index(t_stack *a);
t_stack				*ft_lstlast(t_stack *lst);
size_t				sizestack(t_stack *a);
int					markup(t_stack *a, int f);
void				ft_rab(t_stack **a, int i);
void				ft_pab(t_stack **a, t_stack **b, int i);
t_stack				*ft_clean(t_stack *a, t_stack *b, int i);
void				ft_putstr_fd(char *s, int fd);
t_stack				*ft_lstlas(t_stack *lst);
void				ft_sab(t_stack **a, int i);
t_stack				*ft_three(t_stack *a);
size_t				ft_9lab(t_stack *a, size_t start, size_t end);
void				ft_rrab(t_stack **a, int i);
t_stack				*ft_smallstack(t_stack *a, t_stack *b, int middle,
						int offset);
t_stack				*ft_stackhandler(t_stack *a, t_stack *b);
void				ft_checkb(t_stack **b, size_t middle);
int					ft_find(t_stack *a);
int					ft_indexup(t_stack *b);
int					ft_findb(t_stack *a);
t_stack				*ft_all(t_stack *a, t_stack *b);
int					ft_sir(t_stack *a);
int					ft_number(t_stack *a);
void				ft_free(char **str);
void				ft_rrr(t_stack **a, t_stack **b, int i);
void				ft_rr(t_stack **a, t_stack **b, int i);
void				ft_ss(t_stack **a, t_stack **b, int i);
void				ft_state(int *start, int *end, int offset, int l);
int					ft_mine(t_stack *a);
void				ft_idk(t_stack **a, t_stack **b, int n, int middle);
void				ft_idk2(t_stack **a, t_stack **b, size_t n, size_t l);
int					ft_heelp(t_stack **a, t_stack **b, size_t l);
int					ft_heelp2(t_stack **a, t_stack **b, size_t l, size_t *n);
void				ft_checkdouble(t_stack **a);
int					ft_strchekercmp(char *s1, char *s2);
void				ft_cheker(char *tmp, t_stack **a, t_stack **b);
void				ft_404(char *tmp, t_stack **a, t_stack **b);
#endif