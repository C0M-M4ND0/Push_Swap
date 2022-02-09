/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 10:22:39 by oabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 14:40:22 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
void	ft_putendl_fd(char *s);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
long	ft_atoi(const char *str);
t_list	*creat_list_a(char **av);
void	swap_a(t_list **list_a, int order);
void	swap_b(t_list **list_b, int order);
void	push_a(t_list **list_a, t_list **list_b, int order);
void	push_b(t_list **list_b, t_list **list_a, int order);
void	rotate_a(t_list **list, int order);
void	rotate_b(t_list **list_b, int order);
void	reverse_rotate_a(t_list **list_a, int order);
void	reverse_rotate_b(t_list **list_b, int order);
void	sorting_small_list(t_list **list_a, int order);
void	sorting_medium_list(t_list **list_a,
			t_list **list_b, int limit, int order);
void	rotate_a_and_b(t_list **list_a, t_list **list_b, int order);
void	rverse_rotate_a_and_b(t_list **list_a, t_list **list_b, int order);
void	swap_a_and_b(t_list **list_a, t_list **list_b, int order);
void	operation_in_stack_a(t_list **list_a,
			t_list **list_b, int len, int order);
void	bubble_sort(int *arry, int n);
int		search(t_list *list, int key);
int		find_min_value(t_list *list_a);
int		is_sorted_b(t_list *list_b);
void	sort_rev_ord(t_list **list_b, t_list **list_a, int len, int order);
void	operation_in_stack_b(t_list **list_b,
			t_list **list_a, int len, int order);
int		is_sorted_a(t_list *list_a);
int		put_in_arry(t_list *list, t_list **list_a, t_list **list_b, int len);
char	**ft_split(char const *str, char c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);
int		ft_isduplicated(t_list *list, int len);
void	free_and_exit(t_list **list_a, t_list **list_b);
int		check_if_digit(char **list);
char	**get_list(char **av);
void	free_list(char **list);
int		check_args(char **args);

#endif
