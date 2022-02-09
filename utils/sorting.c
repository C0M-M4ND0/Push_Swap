/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:48:45 by oabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 13:36:15 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting_small_list(t_list **list_a, int order)
{
	if ((*list_a)->content > (*list_a)->next->content)
		swap_a(list_a, order);
	if (ft_lstsize(*list_a) > 2)
	{
		if ((*list_a)->next->content > (*list_a)->next->next->content)
			reverse_rotate_a(list_a, order);
		if ((*list_a)->content > (*list_a)->next->content)
			swap_a(list_a, order);
	}
}

void	sorting_medium_list(t_list **list_a,
			t_list **list_b, int limit, int order)
{
	int	position;
	int	i;

	i = 0;
	while (i++ < limit)
	{
		position = search(*list_a, find_min_value(*list_a));
		if (position <= 2)
		{
			while (search((*list_a), find_min_value(*list_a)))
				rotate_a(list_a, order);
		}
		else
		{
			while (position > 2 && search(*list_a, find_min_value(*list_a)))
				reverse_rotate_a(list_a, order);
		}
		if (search(*list_a, find_min_value(*list_a)) == 0)
			push_b(list_b, list_a, order);
	}
	sorting_small_list(list_a, order);
	i = 0;
	while (i++ < limit)
		push_a(list_a, list_b, order);
}

void	sort_rev_ord(t_list **list_b, t_list **list_a, int len, int order)
{
	if (len == 1)
		push_a(list_a, list_b, order);
	else if (len == 2)
	{
		if ((*list_b)->content < (*list_b)->next->content)
			swap_b(list_b, order);
		while (len--)
			push_a(list_a, list_b, order);
	}
	else if (len == 3)
	{
		if ((*list_b)->content < (*list_b)->next->content)
			swap_b(list_b, order);
		if ((*list_b)->next->content < (*list_b)->next->next->content)
		{
			rotate_b(list_b, order);
			swap_b(list_b, order);
			reverse_rotate_b(list_b, order);
		}
		if ((*list_b)->content < (*list_b)->next->content)
			swap_b(list_b, order);
		while (len--)
			push_a(list_a, list_b, order);
	}
}
