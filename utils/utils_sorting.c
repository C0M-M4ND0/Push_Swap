/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:41:14 by oabdelha          #+#    #+#             */
/*   Updated: 2022/02/09 10:31:42 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search(t_list *list, int key)
{
	int	index;

	index = 0;
	while (list && list->content != key)
	{
		list = list->next;
		index++;
	}
	return (index);
}

int	find_min_value(t_list *list_a)
{
	int	value;

	value = list_a->content;
	while (list_a->next)
	{
		if (value > list_a->next->content)
			value = list_a->next->content;
		list_a = list_a->next;
	}
	return (value);
}

void	free_and_exit(t_list **list_a, t_list **list_b)
{
	ft_lstclear(list_a);
	ft_lstclear(list_b);
	write(2, "ERROR\n", 6);
	exit(0);
}

int	put_in_arry(t_list *list, t_list **list_a, t_list **list_b, int len)
{
	int	i;
	int	*arry;
	int	mid;

	i = 0;
	arry = malloc(sizeof(int) * len);
	if (!arry)
		free_and_exit(list_a, list_b);
	while (i < len)
	{
		arry[i] = list->content;
		list = list->next;
		i++;
	}
	bubble_sort(arry, i);
	mid = arry[len / 2];
	free(arry);
	return (mid);
}

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
}
