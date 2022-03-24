/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:39:10 by oabdelha          #+#    #+#             */
/*   Updated: 2022/03/24 09:32:58 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*get_line(int fd)
{
	int		i;
	char	buff[1];
	char	str[9999];
	char	*line;

	i = 0;
	str[0] = '\0';
	while ((read(fd, buff, 1)) != 0)
	{	
		str[i] = buff[0];
		str[i + 1] = '\0';
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[0] == '\0')
		return (NULL);
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

int	apply(char *stru, t_list **list_a, t_list **list_b, int order)
{
	if (ft_strcmp("sa\n", stru) == 0)
		swap_a(list_a, order);
	else if (ft_strcmp("sb\n", stru) == 0)
		swap_b(list_b, order);
	else if (ft_strcmp("ss\n", stru) == 0)
		swap_a_and_b(list_a, list_b, order);
	else if (ft_strcmp("pa\n", stru) == 0)
		push_a(list_a, list_b, order);
	else if (ft_strcmp("pb\n", stru) == 0)
		push_b(list_b, list_a, order);
	else if (ft_strcmp("ra\n", stru) == 0)
		rotate_a(list_a, order);
	else if (ft_strcmp("rb\n", stru) == 0)
		rotate_b(list_b, order);
	else if (ft_strcmp("rr\n", stru) == 0)
		rotate_a_and_b(list_a, list_b, order);
	else if (ft_strcmp("rra\n", stru) == 0)
		reverse_rotate_a(list_a, order);
	else if (ft_strcmp("rrb\n", stru) == 0)
		reverse_rotate_b(list_b, order);
	else if (ft_strcmp("rrr\n", stru) == 0)
		rverse_rotate_a_and_b(list_a, list_b, order);
	else
		return (2);
	return (0);
}

int	read_from_standard_input(t_list **list_a, t_list **list_b)
{
	char	*read;
	int		order;

	order = -1;
	read = "";
	while (read)
	{
		read = get_line(0);
		if (read == NULL)
			break ;
		if (apply(read, list_a, list_b, order) == 2)
			return (write(2, "ERROR\n", 6), free(read), ft_lstclear(list_a), 1);
	}
	free(read);
	if (is_sorted_a(*list_a) == 1)
		return (ft_putendl_fd("OK"), ft_lstclear(list_a), 0);
	else
		return (ft_putendl_fd("KO"), ft_lstclear(list_a), 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	char	**list;

	if (ac < 2)
		return (0);
	list = get_list(av);
	if (check_args(av) == 1)
		return (write(2, "ERROR\n", 6), 0);
	list_a = creat_list_a(list);
	if (check_if_digit(list) == 1
		|| ft_isduplicated(list_a, ac - 1) == 1)
		return (write(2, "ERROR\n", 6), ft_lstclear(&list_a), 0);
	list_b = NULL;
	read_from_standard_output(&list_a, &list_b);
	return (0);
}
